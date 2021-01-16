/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jan 03 19:02:09 2005
 */
/* Compiler settings for C:\unigrafwd\Test\Test.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Test_h__
#define __Test_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __Iunigrafwd_FWD_DEFINED__
#define __Iunigrafwd_FWD_DEFINED__
typedef interface Iunigrafwd Iunigrafwd;
#endif 	/* __Iunigrafwd_FWD_DEFINED__ */


#ifndef __unigrafwd_FWD_DEFINED__
#define __unigrafwd_FWD_DEFINED__

#ifdef __cplusplus
typedef class unigrafwd unigrafwd;
#else
typedef struct unigrafwd unigrafwd;
#endif /* __cplusplus */

#endif 	/* __unigrafwd_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __Iunigrafwd_INTERFACE_DEFINED__
#define __Iunigrafwd_INTERFACE_DEFINED__

/* interface Iunigrafwd */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_Iunigrafwd;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8D4B6860-170B-4A58-B2B5-8097A861544D")
    Iunigrafwd : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Convert( 
            /* [in] */ BSTR path,
            /* [in] */ BSTR scrap,
            /* [in] */ long resolution,
            /* [in] */ long top,
            /* [in] */ long left,
            /* [in] */ long bottom,
            /* [in] */ long right,
            /* [retval][out] */ long __RPC_FAR *status) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Cleanup( 
            /* [in] */ BSTR scrap,
            /* [retval][out] */ long __RPC_FAR *status) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Resolution( 
            /* [retval][out] */ long __RPC_FAR *number) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Top( 
            /* [retval][out] */ long __RPC_FAR *number) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Left( 
            /* [retval][out] */ long __RPC_FAR *number) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Bottom( 
            /* [retval][out] */ long __RPC_FAR *number) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Right( 
            /* [retval][out] */ long __RPC_FAR *number) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IunigrafwdVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            Iunigrafwd __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            Iunigrafwd __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            Iunigrafwd __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            Iunigrafwd __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            Iunigrafwd __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            Iunigrafwd __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            Iunigrafwd __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Convert )( 
            Iunigrafwd __RPC_FAR * This,
            /* [in] */ BSTR path,
            /* [in] */ BSTR scrap,
            /* [in] */ long resolution,
            /* [in] */ long top,
            /* [in] */ long left,
            /* [in] */ long bottom,
            /* [in] */ long right,
            /* [retval][out] */ long __RPC_FAR *status);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Cleanup )( 
            Iunigrafwd __RPC_FAR * This,
            /* [in] */ BSTR scrap,
            /* [retval][out] */ long __RPC_FAR *status);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Resolution )( 
            Iunigrafwd __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *number);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Top )( 
            Iunigrafwd __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *number);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Left )( 
            Iunigrafwd __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *number);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Bottom )( 
            Iunigrafwd __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *number);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Right )( 
            Iunigrafwd __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *number);
        
        END_INTERFACE
    } IunigrafwdVtbl;

    interface Iunigrafwd
    {
        CONST_VTBL struct IunigrafwdVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Iunigrafwd_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define Iunigrafwd_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define Iunigrafwd_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define Iunigrafwd_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define Iunigrafwd_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define Iunigrafwd_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define Iunigrafwd_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define Iunigrafwd_Convert(This,path,scrap,resolution,top,left,bottom,right,status)	\
    (This)->lpVtbl -> Convert(This,path,scrap,resolution,top,left,bottom,right,status)

#define Iunigrafwd_Cleanup(This,scrap,status)	\
    (This)->lpVtbl -> Cleanup(This,scrap,status)

#define Iunigrafwd_Resolution(This,number)	\
    (This)->lpVtbl -> Resolution(This,number)

#define Iunigrafwd_Top(This,number)	\
    (This)->lpVtbl -> Top(This,number)

#define Iunigrafwd_Left(This,number)	\
    (This)->lpVtbl -> Left(This,number)

#define Iunigrafwd_Bottom(This,number)	\
    (This)->lpVtbl -> Bottom(This,number)

#define Iunigrafwd_Right(This,number)	\
    (This)->lpVtbl -> Right(This,number)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Iunigrafwd_Convert_Proxy( 
    Iunigrafwd __RPC_FAR * This,
    /* [in] */ BSTR path,
    /* [in] */ BSTR scrap,
    /* [in] */ long resolution,
    /* [in] */ long top,
    /* [in] */ long left,
    /* [in] */ long bottom,
    /* [in] */ long right,
    /* [retval][out] */ long __RPC_FAR *status);


void __RPC_STUB Iunigrafwd_Convert_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Iunigrafwd_Cleanup_Proxy( 
    Iunigrafwd __RPC_FAR * This,
    /* [in] */ BSTR scrap,
    /* [retval][out] */ long __RPC_FAR *status);


void __RPC_STUB Iunigrafwd_Cleanup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Iunigrafwd_Resolution_Proxy( 
    Iunigrafwd __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *number);


void __RPC_STUB Iunigrafwd_Resolution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Iunigrafwd_Top_Proxy( 
    Iunigrafwd __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *number);


void __RPC_STUB Iunigrafwd_Top_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Iunigrafwd_Left_Proxy( 
    Iunigrafwd __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *number);


void __RPC_STUB Iunigrafwd_Left_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Iunigrafwd_Bottom_Proxy( 
    Iunigrafwd __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *number);


void __RPC_STUB Iunigrafwd_Bottom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Iunigrafwd_Right_Proxy( 
    Iunigrafwd __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *number);


void __RPC_STUB Iunigrafwd_Right_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __Iunigrafwd_INTERFACE_DEFINED__ */



#ifndef __TESTLib_LIBRARY_DEFINED__
#define __TESTLib_LIBRARY_DEFINED__

/* library TESTLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TESTLib;

EXTERN_C const CLSID CLSID_unigrafwd;

#ifdef __cplusplus

class DECLSPEC_UUID("29EAFE44-6650-4AC3-9772-B29C821CD6F7")
unigrafwd;
#endif
#endif /* __TESTLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
