
#include "ksarm64.h"

        TEXTAREA

;++
;
; AfxDispatchCall(AFX_PMSG pfn, void *pArgs, UINT nSizeArgs, double *FpBuffer);
;

        LEAF_ENTRY  _AfxDispatchCall

        mov     x16, x0                 ; save pfn in x16
        subs    x2, x2, #8*8            ; account for 8 parameters we load into registers
        ldp     d0, d1, [x3, #0*8]      ; load FP parameters from the buffer
        ldp     d2, d3, [x3, #2*8]      ;
        ldp     d4, d5, [x3, #4*8]      ;
        ldp     d6, d7, [x3, #6*8]      ;
        bgt     _AfxDispatchCallNested  ; if we have more than that, take the slow path
        ldp     x6, x7, [x1, #6*8]      ; load x0-x7 from the argument list
        ldp     x4, x5, [x1, #4*8]      ;
        ldp     x2, x3, [x1, #2*8]      ;
        ldp     x0, x1, [x1, #0*8]      ;
        br      x16                     ; branch to the function

        LEAF_END    _AfxDispatchCall
        
        
        NESTED_ENTRY _AfxDispatchCallNested
        
        PROLOG_SAVE_REG_PAIR fp, lr, #-16!
        
        ;
        ; On entry:
        ;   x1 = pointer to parameter list
        ;   x2 = bytes worth of stack parameters to copy
        ;   x16 = pointer to function to call
        ;   d0-d7 = floating point parameters
        ;
        
        sub     x8, sp, x2              ; allocate space for stack parameters
        and     x8, x8, #0xfffffffffffffff0 ; ensure we are aligned
        mov     sp, x8                  ; set the new stack pointer
        add     x0, x1, #8*8            ; point r0 to the source stack parameters
1
        subs    x2, x2, #8              ; decrement the count
        ldr     x3, [x0, x2]            ; load from source parameters
        str     x3, [sp, x2]            ; store to new stack location
        bgt     %B1                     ; loop while we still have data to copy

        ldp     x6, x7, [x1, #6*8]      ; load x0-x7 from the argument list
        ldp     x4, x5, [x1, #4*8]      ;
        ldp     x2, x3, [x1, #2*8]      ;
        ldp     x0, x1, [x1, #0*8]      ;
        
        blr     x16                     ; call the function

        mov     sp, fp                  ; recover SP
        EPILOG_RESTORE_REG_PAIR fp, lr, #16!
        EPILOG_RETURN

        NESTED_END   _AfxDispatchCallNested

        END
