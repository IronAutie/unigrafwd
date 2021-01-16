// File:      OLEClient.h
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


#ifndef _H_UNIGRAFWD_OLECLIENT
#define _H_UNIGRAFWD_OLECLIENT

#include "Option.h"
#include "Picture.h"
#include "Specify.h"

extern DWORD OLEClient (UnigrafwdFileSpecificationPointer,
						UnigrafwdPicturePointer,
						UnigrafwdOptionPointer);

#endif // _H_UNIGRAFWD_OLECLIENT
