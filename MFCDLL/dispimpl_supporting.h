


typedef struct _ARM64_PARAMS
{
	unsigned short IntsUsed;
	unsigned short DoublesUsed;
	unsigned __int64 IntValues[8];
	double DoubleValues[8];
} ARM64_PARAMS, UNSUPPORTEDPLAT_PARAMS, * PARM64_PARAMS, * PUNSUPPORTEDPLAT_PARAMS;


inline void UnsupportedplatParamsReset(UNSUPPORTEDPLAT_PARAMS * p)
{
	p->IntsUsed = 0;
	p->DoublesUsed = 0;
};

inline BOOL UnsupportedplatParamsAddFloat(UNSUPPORTEDPLAT_PARAMS* p, FLOAT f)
{
	float * pf = (float*) &(p->DoubleValues[p->DoublesUsed]);
	*pf = f;
	p->DoublesUsed++;
	return TRUE;
};

inline BOOL UnsupportedplatParamsAddDouble(UNSUPPORTEDPLAT_PARAMS* p, DOUBLE f)
{
	p->DoubleValues[p->DoublesUsed] = f;
	p->DoublesUsed++;
	return TRUE;
};

void _AfxParseCall(AFX_PMSG pfn, void* pStack, UINT nSizeArgs)
{}
