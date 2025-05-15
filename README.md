# Assembly-Timers

This repository contains our implementation of Basic and Advanced Timers in MSP430 assembly language for Lab 5 of the "Introduction to Computers" course.

## Repository Contents

### Code Files
- [API Module (api.s43)](./code/api.s43) - High-level functions for timer applications (frequency counting, one-minute count, PWM)
- [BSP Header (bsp.h)](./code/bsp.h) - Board Support Package definitions for timers and GPIO
- [BSP Module (bsp.s43)](./code/bsp.s43) - Hardware configuration and timer setup functions
- [HAL Module (hal.s43)](./code/hal.s43) - Hardware Abstraction Layer with LCD routines and timer ISRs
- [Main Program (main.s43)](./code/main.s43) - Main application with finite state machine

### Documentation
- [Pre-lab Assignment](./docs/lab5_pre_assignment.pdf) - Initial preparation for timer programming
- [Preparation Report](./docs/lab5_preparation_report.pdf) - Detailed documentation of lab preparation
- [Final Lab Report](./docs/lab5_final_report.pdf) - Complete analysis and results of the implementation

## System Architecture

The code is organized in a layered architecture following embedded systems best practices:

1. **BSP (Board Support Package)**: Hardware-specific definitions and timer configurations
2. **HAL (Hardware Abstraction Layer)**: LCD control, timer ISRs, and utility functions
3. **API (Application Programming Interface)**: Implementation of timer applications
4. **Main Application**: Implements the finite state machine to select different timer features

## Key Features

### 1. Timer-Based Applications

The system implements three timer-based applications:

#### One-Minute Countdown (Task 1)
```assembly
OneMinCount  
           call #LCD_START          ; Initialize LCD
           call #NewCount           ; Setup new countdown
           call #StartCount         ; Begin one-minute countdown
           cmp  #1,state
           jne  goout
           mov  #0,state
goout      ret
```
*Uses Timer_A with up/down mode to implement a one-minute countdown displayed on LCD*

#### Frequency Measurement (Task 2)
```assembly
FreqCount  call #LCD_START          ; Initialize LCD
           call #task2_title        ; Display title
           call #Timer_A1_Setup     ; Configure timer for capture mode
task2_loop cmp  #2,state
           JNE  exit_state
           MOV.W  #TASSEL_2+MC_2+ID_3,Timer_A1_Ctl      ; SMCLK, continuous mode
           MOV.W  #CM_1+SCS+CAP+CCIE+CCIS_0,Timer_A1_CC2_Ctl ; Capture rising edges
           bis  #CPUOFF+GIE,SR      ; Enter LPM with interrupts
           call #calculate_freq     ; Calculate frequency from captures
           call #print_freq         ; Display frequency on LCD
           jmp  task2_loop
```
*Uses Timer_B in capture mode to measure input signal frequency*

#### PWM Generation (Task 3)
```assembly
PWM        
Task3Loop  MOV     DutyCycle,R7     ; Point to duty cycle array
           MOV.B   length,R6        ; Load array length
RUN_DC     CMP     #3,state
           JNE     out
           CALL    #Timer_A1_Setup_3 ; Configure timer for PWM mode
           MOV.W   #CCIE+OUTMOD_7,Timer_A1_CC2_Ctl ; Set output mode
           MOV.W   @R7+,Timer_A1_CC2_Reg ; Set duty cycle
           call    #state3delay      ; Delay between duty cycle changes
           DEC     R6
           CMP     #0,R6
           JEQ     Task3Loop         ; Restart from beginning of array
           JMP     RUN_DC           ; Continue with next duty cycle
```
*Generates variable duty cycle PWM signal using Timer_B in up mode*

### 2. LCD Interface

The system includes comprehensive LCD control capabilities:
- Character and command macros
- Cursor positioning
- Multi-line text display
- Custom formatting for frequency and countdown display

### 3. Timer Configurations

The code demonstrates multiple timer operating modes:
- **Up Mode**: For PWM generation with variable duty cycle
- **Continuous Mode**: For frequency measurement
- **Up/Down Mode**: For accurate timing in countdown application
- **Capture Mode**: For measuring external signal frequency

## Usage

1. Connect the MSP430 development board to your computer
2. Connect an LCD display according to the pin definitions in bsp.h
3. Build and flash the code using IAR Embedded Workbench
4. The system begins in idle state (State 0)
5. Press the push buttons to activate different functions:
   - PB0 (P2.0): Activate State 1 - One-minute countdown on LCD
   - PB1 (P2.1): Activate State 2 - Frequency measurement on LCD
   - PB4 (P2.4): Activate State 3 - PWM generation with varying duty cycle

## Hardware Requirements

- MSP430xG46x microcontroller
- LCD display (HD44780 compatible)
- Push buttons connected to P2.0, P2.1, and P2.4
- Signal source connected to P2.3 for frequency measurement
- Oscilloscope to visualize PWM output

## Authors

Created by Asaf Kamber and Aviv Primor

## Course Information

- Course: Introduction to Computers
- Lab: Basic and Advanced Timers (Lab 5)
