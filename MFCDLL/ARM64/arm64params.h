//
// arm64params.h
//
// Inline helper functions to map parameters to ARM64's EABI
//
// Copyright Microsoft Corporation
//

#ifndef __ARM64PARAMS__
#define __ARM64PARAMS__

//
// Dummy macros so we can use these on all platforms
//

#ifdef _ARM64_

//
// Actual ARM implementation
//

typedef struct _ARM64_PARAMS
{
    UINT16      IntsUsed;
    UINT16      DoublesUsed;
    UINT64      IntValues[8];
    double      DoubleValues[8];
} UNSUPPORTEDPLAT_PARAMS, *PUNSUPPORTEDPLAT_PARAMS;


//
// Macros which map to the inline primitives below
//

#define Arm64ParamsAddInt8(p, d)    Arm64ParamsAddInt(p, (INT8)(d))
#define Arm64ParamsAddUInt8(p, d)   Arm64ParamsAddInt(p, (UINT8)(d))
#define Arm64ParamsAddInt16(p, d)   Arm64ParamsAddInt(p, (INT16)(d))
#define Arm64ParamsAddUInt16(p, d)  Arm64ParamsAddInt(p, (UINT16)(d))
#define Arm64ParamsAddInt32(p, d)   Arm64ParamsAddInt(p, (INT32)(d))
#define Arm64ParamsAddUInt32(p, d)  Arm64ParamsAddInt(p, (UINT32)(d))
#define Arm64ParamsAddInt64(p, d)   Arm64ParamsAddInt(p, (INT64)(d))
#define Arm64ParamsAddUInt64(p, d)  Arm64ParamsAddInt(p, (UINT64)(d))

#define ArmParamsAddPtr(p, d)       Arm64ParamsAddInt(p, (UINT64)(d))


//
// Reset the parameter block to a basic state
//

FORCEINLINE
VOID
Arm64ParamsReset(
    __inout PUNSUPPORTEDPLAT_PARAMS Params)
{
    Params->IntsUsed = 0;
    Params->DoublesUsed = 0;
}


//
// Add an integer by populating the 8 integer register parameters. 
// Returns TRUE if the data fit in registers, or FALSE if it must 
/// be added to the stack.
//

FORCEINLINE
BOOL
Arm64ParamsAddInt(
    __inout PUNSUPPORTEDPLAT_PARAMS Params,
    __in UINT64 Data)
{
    if (Params->IntsUsed < 8) {
        Params->IntValues[Params->IntsUsed++] = Data;
        return TRUE;
    }
    return FALSE;
}


//
// Add a 32-bit floating point value by populating the 8 VFP
// register parameters. Returns TRUE if the data fit in registers, 
// or FALSE if it must be added to the stack.
//

FORCEINLINE
BOOL
Arm64ParamsAddFloat(
    __inout PUNSUPPORTEDPLAT_PARAMS Params,
    __in float Data)
{
    if (Params->DoublesUsed < 8) {
        float* pf = (float*)&(Params->DoubleValues[Params->DoublesUsed++]);
        *pf = Data;
        //((float *)Params->DoubleValues)[Params->DoublesUsed++] = Data;
        return TRUE;
    }
    return FALSE;
}


//
// Add a 64-bit floating point value by populating the 8 VFP
// register parameters. Returns TRUE if the data fit in registers, 
// or FALSE if it must be added to the stack.
//

FORCEINLINE
BOOL
Arm64ParamsAddDouble(
    __inout PUNSUPPORTEDPLAT_PARAMS Params,
    __in double Data)
{
    if (Params->DoublesUsed < 8) {
        ((double *)Params->DoubleValues)[Params->DoublesUsed++] = Data;
        return TRUE;
    }
    return FALSE;
}

#endif

#endif
