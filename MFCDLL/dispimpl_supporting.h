


typedef struct _ARM64_PARAMS
{
	unsigned short IntsUsed;
	unsigned short DoublesUsed;
	unsigned __int64 IntValues[8];
	double DoubleValues[8];
} ARM64_PARAMS, UNSUPPORTEDPLAT_PARAMS, * PARM64_PARAMS, * PUNSUPPORTEDPLAT_PARAMS;

inline BOOL UnsupportedplatParamsReset(UNSUPPORTEDPLAT_PARAMS * p)
{
	return TRUE;
};

inline BOOL UnsupportedplatParamsAddFloat(UNSUPPORTEDPLAT_PARAMS* p, FLOAT f)
{
	return TRUE;
};

inline BOOL UnsupportedplatParamsAddDouble(UNSUPPORTEDPLAT_PARAMS* p, DOUBLE f)
{
	return TRUE;
};

void _AfxParseCall(AFX_PMSG pfn, void* pStack, UINT nSizeArgs)
{}
