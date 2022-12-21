// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// Platform specific defines

#if defined _X86_
#define _STACK_CHAR     long
#define _STACK_SHORT    long
#define _STACK_LONG     long
#define _STACK_LONGLONG __int64
#define _STACK_FLOAT    float
#define _STACK_DOUBLE   double
#define _STACK_PTR      void*
#define _SCRATCH_SIZE   16
#define _STACK_OFFSET   0
#define _STACK_MIN      0

#elif defined _AMD64_
#define _ALIGN_STACK    8
#define _STACK_CHAR     __int64
#define _STACK_SHORT    __int64
#define _STACK_LONG     __int64
#define _STACK_LONGLONG __int64
#define _STACK_FLOAT    float
#define _STACK_DOUBLE   double
#define _STACK_PTR      void*
#define _SCRATCH_SIZE   32
#define _STACK_OFFSET   0
#define _STACK_MIN      0

#elif defined _ARM_
#define _ALIGN_STACK    4
#define _STACK_CHAR     long
#define _STACK_SHORT    long
#define _STACK_LONG     long
#define _STACK_LONGLONG __int64
#define _STACK_FLOAT    float
#define _STACK_DOUBLE   double
#define _STACK_PTR      void*
#define _SCRATCH_SIZE   16
#define _STACK_OFFSET   0
#define _STACK_MIN      0

#elif defined _M_ARM64
#define _STACK_CHAR     __int64
#define _STACK_SHORT    __int64
#define _STACK_INT      __int64
#define _STACK_LONG     __int64
#define _STACK_LONGLONG	__int64
#define _STACK_FLOAT    float
#define _STACK_DOUBLE   double
#define _STACK_PTR      void*
#define _SCRATCH_SIZE   32
#define _STACK_OFFSET   0
#define _STACK_MIN      0
#define _ALIGN_STACKPOINTER	16
#define _ALIGN_STACK	8
#include "dispimpl_supporting.h"

#else
#error Unsupported target platform

#endif

/////////////////////////////////////////////////////////////////////////////
