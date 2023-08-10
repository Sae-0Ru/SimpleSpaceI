/*** Autogenerated by WIDL 8.12 from include/robuffer.idl - Do not edit ***/

#ifdef _WIN32
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif
#include <rpc.h>
#include <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __robuffer_h__
#define __robuffer_h__

#ifndef __WIDL_INLINE
#if defined(__cplusplus) || defined(_MSC_VER)
#define __WIDL_INLINE inline
#elif defined(__GNUC__)
#define __WIDL_INLINE __inline__
#endif
#endif

/* Forward declarations */

#ifndef ____x_Windows_CStorage_CStreams_CIBufferByteAccess_FWD_DEFINED__
#define ____x_Windows_CStorage_CStreams_CIBufferByteAccess_FWD_DEFINED__
typedef interface __x_Windows_CStorage_CStreams_CIBufferByteAccess __x_Windows_CStorage_CStreams_CIBufferByteAccess;
#ifdef __cplusplus
#define __x_Windows_CStorage_CStreams_CIBufferByteAccess Windows::Storage::Streams::IBufferByteAccess
namespace Windows {
    namespace Storage {
        namespace Streams {
            interface IBufferByteAccess;
        }
    }
}
#endif /* __cplusplus */
#endif

/* Headers for imported files */

#include <objidl.h>

#ifdef __cplusplus
extern "C" {
#endif

#if NTDDI_VERSION >= NTDDI_WIN8
/*****************************************************************************
 * IBufferByteAccess interface
 */
#ifndef ____x_Windows_CStorage_CStreams_CIBufferByteAccess_INTERFACE_DEFINED__
#define ____x_Windows_CStorage_CStreams_CIBufferByteAccess_INTERFACE_DEFINED__

DEFINE_GUID(IID___x_Windows_CStorage_CStreams_CIBufferByteAccess, 0x905a0fef, 0xbc53, 0x11df, 0x8c,0x49, 0x00,0x1e,0x4f,0xc6,0x86,0xda);
#if defined(__cplusplus) && !defined(CINTERFACE)
} /* extern "C" */
namespace Windows {
    namespace Storage {
        namespace Streams {
            MIDL_INTERFACE("905a0fef-bc53-11df-8c49-001e4fc686da")
            IBufferByteAccess : public IUnknown
            {
                virtual HRESULT STDMETHODCALLTYPE Buffer(
                    byte **value) = 0;

            };
        }
    }
}
extern "C" {
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(__x_Windows_CStorage_CStreams_CIBufferByteAccess, 0x905a0fef, 0xbc53, 0x11df, 0x8c,0x49, 0x00,0x1e,0x4f,0xc6,0x86,0xda)
#endif
#else
typedef struct __x_Windows_CStorage_CStreams_CIBufferByteAccessVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        __x_Windows_CStorage_CStreams_CIBufferByteAccess *This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        __x_Windows_CStorage_CStreams_CIBufferByteAccess *This);

    ULONG (STDMETHODCALLTYPE *Release)(
        __x_Windows_CStorage_CStreams_CIBufferByteAccess *This);

    /*** IBufferByteAccess methods ***/
    HRESULT (STDMETHODCALLTYPE *Buffer)(
        __x_Windows_CStorage_CStreams_CIBufferByteAccess *This,
        byte **value);

    END_INTERFACE
} __x_Windows_CStorage_CStreams_CIBufferByteAccessVtbl;

interface __x_Windows_CStorage_CStreams_CIBufferByteAccess {
    CONST_VTBL __x_Windows_CStorage_CStreams_CIBufferByteAccessVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define __x_Windows_CStorage_CStreams_CIBufferByteAccess_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define __x_Windows_CStorage_CStreams_CIBufferByteAccess_AddRef(This) (This)->lpVtbl->AddRef(This)
#define __x_Windows_CStorage_CStreams_CIBufferByteAccess_Release(This) (This)->lpVtbl->Release(This)
/*** IBufferByteAccess methods ***/
#define __x_Windows_CStorage_CStreams_CIBufferByteAccess_Buffer(This,value) (This)->lpVtbl->Buffer(This,value)
#else
/*** IUnknown methods ***/
static __WIDL_INLINE HRESULT __x_Windows_CStorage_CStreams_CIBufferByteAccess_QueryInterface(__x_Windows_CStorage_CStreams_CIBufferByteAccess* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static __WIDL_INLINE ULONG __x_Windows_CStorage_CStreams_CIBufferByteAccess_AddRef(__x_Windows_CStorage_CStreams_CIBufferByteAccess* This) {
    return This->lpVtbl->AddRef(This);
}
static __WIDL_INLINE ULONG __x_Windows_CStorage_CStreams_CIBufferByteAccess_Release(__x_Windows_CStorage_CStreams_CIBufferByteAccess* This) {
    return This->lpVtbl->Release(This);
}
/*** IBufferByteAccess methods ***/
static __WIDL_INLINE HRESULT __x_Windows_CStorage_CStreams_CIBufferByteAccess_Buffer(__x_Windows_CStorage_CStreams_CIBufferByteAccess* This,byte **value) {
    return This->lpVtbl->Buffer(This,value);
}
#endif
#ifdef WIDL_using_Windows_Storage_Streams
#define IID_IBufferByteAccess IID___x_Windows_CStorage_CStreams_CIBufferByteAccess
#define IBufferByteAccessVtbl __x_Windows_CStorage_CStreams_CIBufferByteAccessVtbl
#define IBufferByteAccess __x_Windows_CStorage_CStreams_CIBufferByteAccess
#define IBufferByteAccess_QueryInterface __x_Windows_CStorage_CStreams_CIBufferByteAccess_QueryInterface
#define IBufferByteAccess_AddRef __x_Windows_CStorage_CStreams_CIBufferByteAccess_AddRef
#define IBufferByteAccess_Release __x_Windows_CStorage_CStreams_CIBufferByteAccess_Release
#define IBufferByteAccess_Buffer __x_Windows_CStorage_CStreams_CIBufferByteAccess_Buffer
#endif /* WIDL_using_Windows_Storage_Streams */
#endif

#endif

#endif  /* ____x_Windows_CStorage_CStreams_CIBufferByteAccess_INTERFACE_DEFINED__ */

STDAPI RoGetBufferMarshaler(IMarshal **bufferMarshaler);
#endif
/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __robuffer_h__ */