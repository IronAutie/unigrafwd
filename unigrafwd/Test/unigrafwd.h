// unigrafwd.h : Declaration of the Cunigrafwd

#ifndef __UNIGRAFWD_H_
#define __UNIGRAFWD_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Cunigrafwd
class ATL_NO_VTABLE Cunigrafwd : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<Cunigrafwd, &CLSID_unigrafwd>,
	public IDispatchImpl<Iunigrafwd, &IID_Iunigrafwd, &LIBID_TESTLib>
{
public:
	Cunigrafwd()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_UNIGRAFWD)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(Cunigrafwd)
	COM_INTERFACE_ENTRY(Iunigrafwd)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// Iunigrafwd
public:
	STDMETHOD(Right)(/*[out, retval]*/ long *number);
	STDMETHOD(Bottom)(/*[out, retval]*/ long *number);
	STDMETHOD(Left)(/*[out, retval]*/ long *number);
	STDMETHOD(Top)(/*[out, retval]*/ long *number);
	STDMETHOD(Resolution)(/*[out, retval]*/ long *number);
	STDMETHOD(Cleanup)(/*[in]*/ BSTR scrap, /*[out, retval]*/ long * status);
	STDMETHOD(Convert)(/*[in]*/ BSTR path, /*[in]*/ BSTR scrap, /*[in]*/ long resolution, /*[in]*/ long top, /*[in]*/ long left, /*[in]*/ long bottom, /*[in]*/ long right, /*[out, retval]*/ long *status);
};

#endif //__UNIGRAFWD_H_
