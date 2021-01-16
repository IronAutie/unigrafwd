// File:      OLEClient.cpp
//
// Purpose:   OLE client for rendering a graphics file into image.
//
// Project:   unigrafwd:  Universal Graphics Import Filter for Word
//
// Citations: 1) Bret S. Pehrson.  "Documenting the Graphic Import Filter Interface"
//               C/C++ Users Journal March 2001
//
//			  2) Kevin P. Welch. "Creating Graphics Import Filter Libraries for 
//               Windows Applications," Microsoft Systems Journal, January-February 
//				 issue, 1992. Pages 101-107. M&T Press.
//
//            3) Tursi (tursi at harmlesslion.com) for his donationware
//               code samples and his advice based on his own independent research.
//        
//			  4) IronAutie (i.am.extremely.useful@gmail.com), for creating
//               the Universal Graphics Import Filter for Word.
//
// Copyright: (C) 2020 assigned by IronAutie to The Free Software Foundation
//
// 			     This library is free software; you can redistribute it and/or
// 			     modify it under the terms of the GNU Lesser General Public
// 			     License as published by the Free Software Foundation; either
// 			     version 2.1 of the License, or (at your option) any later version.
//
// 			     This library is distributed in the hope that it will be useful,
// 			     but WITHOUT ANY WARRANTY; without even the implied warranty of
// 			     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// 			     Lesser General Public License for more details.
//
// 			     You should have received a copy of the GNU Lesser General Public
// 			     License along with this library; if not, write to the Free Software
// 			     Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

#include "OLEClient.h"
#include <comdef.h>
#include <atlbase.h>


// Connect to OLE server method to convert graphic file to wmf scrap
static
DWORD 
Convert   (IDispatch                        *server, 
		   UnigrafwdFileSpecificationPointer s,
		   UnigrafwdPicturePointer           p,
		   UnigrafwdOptionPointer            o,
		   _bstr_t					 	     scrapname)
{
	VARIANTARG arguments   [7];
	OLECHAR   *member  = L"Convert";
	DWORD      status  = S_FALSE;
	DISPID     method;
	DISPPARAMS parameters;
	VARIANT    value;
	HRESULT    result;

	result = server->GetIDsOfNames (IID_NULL, 
		                            &member, 
									1, 
									LOCALE_USER_DEFAULT,
                                    &method);

	if (result != S_OK) return S_FALSE;   // problem connecting to server?

	VariantInit(&arguments [0]);
	VariantInit(&value);

	parameters.rgvarg            = arguments;
	parameters.rgdispidNamedArgs = NULL;
	parameters.cArgs             = 7;
	parameters.cNamedArgs        = 0;

	arguments[0].vt              = VT_I4;
	arguments[0].lVal            = p->extent.right;

	arguments[1].vt              = VT_I4;
	arguments[1].lVal            = p->extent.bottom;

	arguments[2].vt              = VT_I4;
	arguments[2].lVal            = p->extent.left;

	arguments[3].vt              = VT_I4;
	arguments[3].lVal            = p->extent.top;

	arguments[4].vt              = VT_I4;
	arguments[4].lVal            = p->resolution;

	arguments[5].vt              = VT_BSTR;
	arguments[5].bstrVal         = scrapname;

	arguments[6].vt              = VT_BSTR;
	arguments[6].bstrVal         = _bstr_t (s->path);

	result = server->Invoke (method, 
		                     IID_NULL, 
                             LOCALE_USER_DEFAULT,
                             DISPATCH_METHOD, 
						    &parameters, 
						    &value, 
                             NULL, 
						     NULL);

	if (result != S_OK) return S_FALSE;   // problem connecting to server?
	if (value.lVal)     return S_FALSE;   // server didn't like what we gave it?
	return S_OK;
}


// Connect to OLE server to call a method to obtain a value
static
DWORD 
Query (IDispatch *server, OLECHAR  *key, long *value)
{
	DWORD      status  = S_FALSE;
	DISPID     method;
	VARIANT    returned;
	HRESULT    result;
	DISPPARAMS parameters;

	VariantInit(&returned);

	parameters.rgvarg            = NULL;
	parameters.rgdispidNamedArgs = NULL;
	parameters.cArgs             = 0;
	parameters.cNamedArgs        = 0;

	result = server->GetIDsOfNames (IID_NULL, 
		                           &key, 
									1, 
									LOCALE_USER_DEFAULT,
                                   &method);

	if (result != S_OK)  return S_FALSE;   // problem connecting to server?

	result = server->Invoke (method, 
		                   IID_NULL, 
                           LOCALE_USER_DEFAULT,
                           DISPATCH_METHOD, 
						   &parameters, 
						   &returned, 
                           NULL, 
						   NULL);

	if (result != S_OK) return S_FALSE;   // problem connecting to server?
   *value = returned.lVal;
	return S_OK;
}


// Connect to OLE server method to convert graphic file to wmf scrap
static
DWORD 
Cleanup (IDispatch *server, _bstr_t scrapname)
{
	VARIANTARG arguments   [1];
	DWORD      status  = S_FALSE;
	OLECHAR   *member  = L"Cleanup";
	DISPID     method;
	DISPPARAMS parameters;
	VARIANT    value;
	HRESULT    result;

	VariantInit(&arguments [0]);
	VariantInit(&value);

	parameters.rgvarg            = arguments;
	parameters.rgdispidNamedArgs = NULL;
	parameters.cArgs             = 1;
	parameters.cNamedArgs        = 0;
	arguments[0].vt              = VT_BSTR;
	arguments[0].bstrVal         = scrapname;

	result = server->GetIDsOfNames (IID_NULL, 
		                           &member, 
									1, 
									LOCALE_USER_DEFAULT,
                                    &method);

	if (!result)    return S_FALSE;   // problem connecting to server?

	result = server->Invoke (method, 
		                       IID_NULL, 
                               LOCALE_USER_DEFAULT,
                               DISPATCH_METHOD, 
						      &parameters, 
						      &value, 
                               NULL, 
						       NULL);

	if (!result)    return S_FALSE;   // problem connecting to server?
	if (value.lVal) return S_FALSE;   // server didn't like what we gave it?
	return S_OK;
}



// Connect to OLE server methods to get final dimensions and resolution of conversion.
static
DWORD
Response (IDispatch *server, UnigrafwdPicturePointer p)
{
	long  value      = 0;
	DWORD status     = S_FALSE;
	status           = Query (server, OLESTR ("Top"),        &value);
    if (status) return status;
	p->extent.top    = (value >= 0) ? value : 0;
	status           = Query (server, OLESTR ("Left"),       &value);
    if (status) return status;
	p->extent.left   = (value >= 0) ? value : 0;
	status           = Query (server, OLESTR ("Bottom"),     &value);
    if (status) return status;
	p->extent.bottom = (value > 0)  ? value : 256;
	status           = Query (server, OLESTR ("Right"),      &value);
    if (status) return status;
	p->extent.right  = (value > 0)  ? value : 256;
	status           = Query (server, OLESTR ("Resolution"), &value);
    if (status) return status;
	p->resolution    = (value > 0)  ? value : 100;
	return S_OK;
}



// Fill picture information with results from OLE server
static
DWORD
Fill (IDispatch *server, UnigrafwdPicturePointer p, char *scrappath)
{
	                                  // Get picture dimensions
	if (Response (server, p)) return S_FALSE;
	
									  // roundabout manner to copy wmf scrap from
									  // disk to metafile image in memory.
	HMETAFILE metafile  = GetMetaFile    (scrappath);
	if (!metafile) return S_FALSE;
	HDC    context      = CreateMetaFile (NULL);
	if (!context)  return S_FALSE;
	SetMapMode      (context, MM_ANISOTROPIC);
	BOOL   result       = PlayMetaFile   (context, metafile);
	DeleteMetaFile  (metafile);
	metafile           =  CloseMetaFile  (context);
	DeleteDC       (context);
	if (!result)   return S_FALSE;
	if (!metafile) return S_FALSE;	  
	p->metafile         = (HANDLE) metafile;			 
	return S_OK;
}



static
DWORD
Transact (IDispatch *server,
		  UnigrafwdFileSpecificationPointer s,
		  UnigrafwdPicturePointer           p,
		  UnigrafwdOptionPointer            o)
{
	DWORD    status;
	char    *scrappath = _tempnam ("C:\\", "ugfscrap");
    if (!scrappath) return S_FALSE;   
	_bstr_t  scrapname = _bstr_t (scrappath);
	status             = Convert (server, s, p, o, scrapname);
	if (status) return status;
	status             = Fill    (server, p, scrappath);
	if (status) return status;
	status             = Cleanup (server, scrapname);
	return S_OK;		// cleanup status is unimportant except for internal debugging
}



// Client stub to communicate with a graphics conversion engine over a COM interface
// User may set environment variable, UNIGRAFWD_SERVER, to override the server name.

DWORD 
OLEClient (UnigrafwdFileSpecificationPointer s,
		   UnigrafwdPicturePointer           p,
		   UnigrafwdOptionPointer            o)
{
	DWORD      status           = S_FALSE;
	wchar_t   *server_tag       = (wchar_t *) OLESTR ("UNIGRAFWD_SERVER");
	wchar_t   *server_default   = (wchar_t *) OLESTR ("Unigrafwd.Server");
	wchar_t   *server_name      = _wgetenv (server_tag);
	wchar_t   *server_used      = server_name ? server_name : server_default;
	HRESULT    hr               = NULL;
	BOOL       result           = FALSE;
	IUnknown  *unknown          = FALSE;
	IDispatch *dispatch         = FALSE;
	CLSID      clsid;

	CoInitialize   (0);
	hr     = CLSIDFromProgID  (server_used, &clsid);
    if (hr != S_OK) goto error;
	hr     = CoCreateInstance (clsid, NULL, CLSCTX_SERVER, IID_IUnknown, (void **) &unknown);
	if (hr != S_OK) goto error;
	hr     = unknown->QueryInterface (IID_IDispatch, (void **) &dispatch);
	if (hr != S_OK) goto error;
	status = Transact         (dispatch, s, p, o);

error:
	if (unknown) unknown->Release ();
	CoUninitialize ();
	return status;
}
