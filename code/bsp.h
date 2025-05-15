#ifndef *bsp*H_  ;if not defined
#define *bsp*H_
;#include <msp430g2553.h>     ;msp430x2xx
#include  <msp430xG46x.h>   ;msp430x4xx - Lab

;-------------------------------------------------------------------------------
; Constants
;-------------------------------------------------------------------------------
#define  DebounceVal  280    ; Debounce delay value for push buttons
#define  T0           R11    ; Register for storing first timer capture value
#define  T1           R12    ; Register for storing second timer capture value

;-------------------------------------------------------------------------------
; Push Buttons Configuration - P2 Port
;-------------------------------------------------------------------------------
#define   PBPort      &P2IN    ; Push button input register
#define   PBDIR       &P2DIR   ; Push button direction register
#define   PBSEL       &P2SEL   ; Push button function select register
#define   PBEdgeT     &P2IES   ; Push button interrupt edge select
#define   PBIntEn     &P2IE    ; Push button interrupt enable
#define   PBIntFlag   &P2IFG   ; Push button interrupt flag

;-------------------------------------------------------------------------------
; LCD Interface Configuration
;-------------------------------------------------------------------------------  
#define   LCData      &P1OUT   ; LCD data port (P1)
#define   LCData_SEL  &P1SEL   ; LCD data selection register
#define   LCData_DIR  &P1DIR   ; LCD data direction register
#define   LCDCtrl     &P2OUT   ; LCD control port (P2.5-P2.7)
#define   LCDCtrl_SEL &P2SEL   ; LCD control selection register
#define   LCDCtrl_DIR &P2DIR   ; LCD control direction register

;-------------------------------------------------------------------------------
; Timer A Abstraction
;-------------------------------------------------------------------------------
#define   Timer_A_Ctl      &TACTL    ; Timer A control register
#define   Timer_A_CC0_Ctl  &TACCTL0  ; Timer A capture/compare 0 control
#define   Timer_A_CC0_Reg  &TACCR0   ; Timer A capture/compare 0 register

;-------------------------------------------------------------------------------
; Timer A1 Abstraction for Different MSP430 Families
;-------------------------------------------------------------------------------
;--------- Timers for msp430x2xx (commented out) ----
;#define   Timer_A1_Ctl    &TA1CTL
;#define   Timer_A1_Flag   &TAIV
;#define   Timer_A1_CC2_Ctl &TA1CCTL2
;#define   Timer_A1_CC2_Reg &TA1CCR2
;#define   TB_CLOCK        0x10

;---- Timers for msp430x4xx - Used in Lab ----
#define   Timer_A1_Ctl    &TBCTL     ; Timer B control register (used as Timer A1)
#define   Timer_A1_Flag   &TBIV      ; Timer B interrupt vector
#define   Timer_A1_CC2_Ctl &TBCCTL2  ; Timer B capture/compare 2 control
#define   Timer_A1_CC2_Reg &TBCCR2   ; Timer B capture/compare 2 register
#define   TB_CLOCK        0x08       ; Timer B clock select bit in port selection

#endif  ; End of include guard