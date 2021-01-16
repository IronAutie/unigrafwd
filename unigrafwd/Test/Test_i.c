/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jan 03 19:02:09 2005
 */
/* Compiler settings for C:\unigrafwd\Test\Test.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID IID_Iunigrafwd = {0x8D4B6860,0x170B,0x4A58,{0xB2,0xB5,0x80,0x97,0xA8,0x61,0x54,0x4D}};


const IID LIBID_TESTLib = {0xB5679FC4,0x1605,0x4726,{0x82,0x02,0x86,0x11,0xC5,0x94,0x56,0xD2}};


const CLSID CLSID_unigrafwd = {0x29EAFE44,0x6650,0x4AC3,{0x97,0x72,0xB2,0x9C,0x82,0x1C,0xD6,0xF7}};


#ifdef __cplusplus
}
#endif

