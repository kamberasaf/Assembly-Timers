#ifndef _bsp_H_  ;if not defined
#define _bsp_H_

;#include <msp430g2553.h>     ;msp430x2xx
#include  <msp430xG46x.h>   ;msp430x4xx - Lab

#define  DebounceVal  280
#define  T0           R11
#define  T1           R12


;--- Push Buttons ---
#define   PBPort      &P2IN
#define   PBDIR       &P2DIR
#define   PBSEL       &P2SEL
#define   PBEdgeT     &P2IES  ; falling or rising edge
#define   PBIntEn     &P2IE   
#define   PBIntFlag   &P2IFG


;----- LCD -----------  
#define   LCData      &P1OUT
#define   LCData_SEL  &P1SEL
#define   LCData_DIR  &P1DIR
#define   LCDCtrl     &P2OUT
#define   LCDCtrl_SEL &P2SEL
#define   LCDCtrl_DIR &P2DIR


;------- Timers Abstraction -----
#define   Timer_A_Ctl      &TACTL
#define   Timer_A_CC0_Ctl  &TACCTL0
#define   Timer_A_CC0_Reg  &TACCR0

;--------- Timers msp430x2xx ----
;#define   Timer_A1_Ctl    &TA1CTL
;#define   Timer_A1_Flag   &TAIV
;#define   Timer_A1_CC2_Ctl &TA1CCTL2
;#define   Timer_A1_CC2_Reg &TA1CCR2
;#define   TB_CLOCK        0x10


;---- Timers msp430x4xx - Lab ----
#define   Timer_A1_Ctl    &TBCTL
#define   Timer_A1_Flag   &TBIV
#define   Timer_A1_CC2_Ctl &TBCCTL2
#define   Timer_A1_CC2_Reg &TBCCR2
#define   TB_CLOCK        0x08


#endif