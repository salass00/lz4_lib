#ifndef PROTO_LZ4_H
#define PROTO_LZ4_H

/*
**	$Id$
**
**	Prototype/inline/pragma header file combo
**
**	Copyright (c) 2010 Hyperion Entertainment CVBA.
**	All Rights Reserved.
*/

#ifndef LIBRARIES_LZ4_H
#include <libraries/lz4.h>
#endif

/****************************************************************************/

#ifndef __NOLIBBASE__
 #ifndef __USE_BASETYPE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::Library * LZ4Base;
  #else
   extern struct Library * LZ4Base;
  #endif
 #else
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::LZ4Base * LZ4Base;
  #else
   extern struct LZ4Base * LZ4Base;
  #endif
 #endif /* __USE_BASETYPE__ */
#endif /* __NOLIBBASE__ */

/****************************************************************************/

#ifdef __amigaos4__
 #include <interfaces/lz4.h>
 #ifdef __USE_INLINE__
  #include <inline4/lz4.h>
 #endif /* __USE_INLINE__ */
 #ifndef CLIB_LZ4_PROTOS_H
  #define CLIB_LZ4_PROTOS_H 1
 #endif /* CLIB_LZ4_PROTOS_H */
 #ifndef __NOGLOBALIFACE__
  #if defined(__cplusplus) && defined(__USE_AMIGAOS_NAMESPACE__)
   extern struct AmigaOS::LZ4IFace * ILZ4;
  #else
   extern struct LZ4IFace * ILZ4;
  #endif
 #endif /* __NOGLOBALIFACE__ */
#else /* __amigaos4__ */
 #ifndef CLIB_LZ4_PROTOS_H
  #include <clib/lz4_protos.h>
 #endif /* CLIB_LZ4_PROTOS_H */
 #if defined(__GNUC__)
  #ifndef __PPC__
   #include <inline/lz4.h>
  #else /* __PPC__ */
   #include <ppcinline/lz4.h>
  #endif /* __PPC__ */
 #elif defined(__VBCC__)
  #ifndef __PPC__
   #include <inline/lz4_protos.h>
  #endif /* __PPC__ */
 #else /* __GNUC__ */
  #include <pragmas/lz4_pragmas.h>
 #endif /* __GNUC__ */
#endif /* __amigaos4__ */

/****************************************************************************/

#endif /* PROTO_LZ4_H */
