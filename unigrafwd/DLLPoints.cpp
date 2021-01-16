// File:      DLLPoints.cpp
//
// Purpose:   Dynamic-Link Library access points.
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
 

#include "Option.h"
#include "Picture.h"
#include "Specify.h"
#include "OLEClient.h"



// DLL callback entry point when Word attaches the DLL to its process space

BOOL APIENTRY DllMain          (HANDLE module, 
                                DWORD  reason, 
                                LPVOID reserved
					           )
{
    return TRUE;      // No special actions needed for any reason.
}


// DLL callback entry point when Word requests information about this filter 
//
// The opportunity is also taken for this DLL to allocate its own private storage
// for options, which could be unlocked by one of the other routines into something
// like a pointer to struct.  
//
// It is strongly suggested to never depend on storage declared in the C extern
// block, as it is not guaranteed to be thread safe!

DWORD __stdcall GetFilterInfo (DWORD    version, 
							   DWORD    reserved_1, 
							   HGLOBAL *option, 
							   DWORD    reserved_2) 
{
	typedef enum
	{
		FAILURE,
		TEXT,
		GRAPHIC,
	}
	FilterType;

	const  unsigned UsesAldus16BitProtocol = 2;
	// version should already have value of UsesAldus16BitProtocol 
   *option = GlobalAlloc (GMEM_FIXED, sizeof (UnigrafwdOption));   
	return GRAPHIC;
}


// DLL callback entry point when Word requests user options about this filter
// This gives the user the opportunity to set items in private storage that
// where allocated in the above call to GetFilterInfo.  A dialog could be 
// launched from this point, environment variables could be set, etc...

DWORD __stdcall SetFilterPref (HGLOBAL  option, 
							   LPCSTR   key, 
							   LPCSTR   value, 
							   DWORD    reserved_1, 
							   DWORD    reserved_2) 
{
	return S_OK;  // No special action needed.
}



// DLL callback entry point when Word wants to transform a file specification
// into a picture for pasting into the current document.   
//
// NOTE:  the file path in 'specify' is a DOS mapping of the Win32 path of the file.

DWORD __stdcall ImportGr      (DWORD                             reserved, 
							   UnigrafwdFileSpecificationPointer specify, 
							   UnigrafwdPicturePointer           picture, 
							   HGLOBAL                           option) 
{
	DWORD status    = OLEClient  (specify, 
		                          picture, 
							      (UnigrafwdOptionPointer) GlobalLock (option)
							     );
	(void) GlobalUnlock (option);
	return status;
}



// No meaningful documentation available, sorry!
DWORD __stdcall ExportGr (void)
{
	return S_FALSE;
}
