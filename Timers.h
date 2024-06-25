
#define TIMER_0_PRESCALER_2            (0x01)
#define TIMER_0_PRESCALER_4            (0x02)
#define TIMER_0_PRESCALER_8            (0x03)
#define TIMER_0_PRESCALER_16           (0x04)
#define TIMER_0_PRESCALER_32           (0x05)
#define TIMER_0_PRESCALER_64           (0x06)
#define TIMER_0_PRESCALER_128          (0x07)
#define TIMER_0_PRESCALER_256          (0x08)

#define TIMER_1_PRESCALER_1             (0x01)
#define TIMER_1_PRESCALER_2             (0x02)
#define TIMER_1_PRESCALER_4             (0x03)
#define TIMER_1_PRESCALER_8             (0x04)


#define TIMER_2_PRESCALER_1         (0x01)
#define TIMER_2_PRESCALER_4         (0x02)
#define TIMER_2_PRESCALER_16        (0x03)

#define TIMER_2_POSTSCALER_1        (0x00)
#define TIMER_2_POSTSCALER_2        (0x01)
#define TIMER_2_POSTSCALER_3        (0x02)
#define TIMER_2_POSTSCALER_4        (0x03)
#define TIMER_2_POSTSCALER_5        (0x04)
#define TIMER_2_POSTSCALER_6        (0x05)
#define TIMER_2_POSTSCALER_7        (0x06)
#define TIMER_2_POSTSCALER_8        (0x07)
#define TIMER_2_POSTSCALER_9        (0x08)
#define TIMER_2_POSTSCALER_10       (0x09)
#define TIMER_2_POSTSCALER_11       (0x0A)
#define TIMER_2_POSTSCALER_12       (0x0B)
#define TIMER_2_POSTSCALER_13       (0x0C)
#define TIMER_2_POSTSCALER_14       (0x0D)
#define TIMER_2_POSTSCALER_15       (0x0E)
#define TIMER_2_POSTSCALER_16       (0x0F)

#define TIMER_3_PRESCALER_1          (0x00)
#define TIMER_3_PRESCALER_2          (0x01)
#define TIMER_3_PRESCALER_4          (0x02)
#define TIMER_3_PRESCALER_8          (0x03)

#define TIMER_0_COUNTER_OPERATION_8BIT        (0x08)
#define TIMER_0_COUNTER_OPERATION_16BIT       (0x10)
#define _8BIT_                                (0xFF)
#define _16BIT_                               (0xFFFF)


void GPIO_Init(void){TRISBbits.TRISB7 = 0;PORTBbits.RB7 = OFF;}

void Timer_0_Initialize(int_fast8_t bit_counter_timer,int_fast8_t prescaler){
    switch(prescaler){
        case TIMER_0_PRESCALER_2:
            T0CONbits.T0PS0 = 0;
            T0CONbits.T0PS1 = 0;
            T0CONbits.T0PS2 = 0;
            break;
        case TIMER_0_PRESCALER_4:
            T0CONbits.T0PS0 = 1;
            T0CONbits.T0PS1 = 0;
            T0CONbits.T0PS2 = 0;
            break;
        case TIMER_0_PRESCALER_8:
            T0CONbits.T0PS0 = 0;
            T0CONbits.T0PS1 = 1;
            T0CONbits.T0PS2 = 0;
            break;
        case TIMER_0_PRESCALER_16:
            T0CONbits.T0PS0 = 1;
            T0CONbits.T0PS1 = 1;
            T0CONbits.T0PS2 = 0;
            
            break;
        case TIMER_0_PRESCALER_32:
            T0CONbits.T0PS0 = 0;
            T0CONbits.T0PS1 = 0;
            T0CONbits.T0PS2 = 1;
            break;
        case TIMER_0_PRESCALER_64:
            T0CONbits.T0PS0 = 1;
            T0CONbits.T0PS1 = 0;
            T0CONbits.T0PS2 = 1;
            break;
        case TIMER_0_PRESCALER_128:
            T0CONbits.T0PS0 = 0;
            T0CONbits.T0PS1 = 1;
            T0CONbits.T0PS2 = 1;
            break;
        case TIMER_0_PRESCALER_256:
            T0CONbits.T0PS0 = 1;
            T0CONbits.T0PS1 = 1;
            T0CONbits.T0PS2 = 1;
            break;           
    }
   
   switch(bit_counter_timer){
       case TIMER_0_COUNTER_OPERATION_8BIT:
           T0CONbits.T08BIT = 1;
           TMR0 = _8BIT_;
           break;
       case TIMER_0_COUNTER_OPERATION_16BIT:
           T0CONbits.T08BIT = 0;
           TMR0 = _16BIT_;
           break;
   }
   T0CONbits.PSA = 0;
   T0CONbits.T0SE = 0;
   T0CONbits.T0CS = 0;
   
   INTCONbits.TMR0IF = 0;
   INTCONbits.TMR0IE = 1;
   INTCONbits.GIEL = 1;
   INTCONbits.GIE = 1;
   T0CONbits.TMR0ON = 1;
}
void Timer_1_Initialize_16Bit(int_fast8_t prescaler){
    switch(prescaler){
        case TIMER_1_PRESCALER_1:
            T1CONbits.T1CKPS0 = 0;
            T1CONbits.T1CKPS1 = 0;
            break;
        case TIMER_1_PRESCALER_2:
            T1CONbits.T1CKPS0 = 1;
            T1CONbits.T1CKPS1 = 0;
            break;
        case TIMER_1_PRESCALER_4:
            T1CONbits.T1CKPS0 = 0;
            T1CONbits.T1CKPS1 = 1;
            break;
        case TIMER_1_PRESCALER_8:
            T1CONbits.T1CKPS0 = 1;
            T1CONbits.T1CKPS1 = 1;
            break;
    }
    TMR1 = _16BIT_;
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1SYNC = 0;
    T1CONbits.T1OSCEN = 1;
    T1CONbits.T1RUN = 0;
    T1CONbits.T1RD16 = 1; 
    
    IPR1bits.TMR1IP = 0;
    PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    T1CONbits.TMR1ON = 1;
}

void Timer_2_Initialize_8Bit(int_fast8_t prescaler,int_fast8_t postscaler){
    switch(prescaler){
        case TIMER_2_PRESCALER_1:
            T2CONbits.T2CKPS0 = 0;
            T2CONbits.T2CKPS1 = 0;
            break;
        case TIMER_2_PRESCALER_4:
            T2CONbits.T2CKPS0 = 1;
            T2CONbits.T2CKPS1 = 0;
            break;
        case TIMER_2_PRESCALER_16:
            T2CONbits.T2CKPS0 = 1;
            T2CONbits.T2CKPS1 = 1;
            break;
    }
    switch(postscaler){
        case TIMER_2_POSTSCALER_1:
            T2CONbits.T2OUTPS0 = 0;
            break;
        case TIMER_2_POSTSCALER_2:
            T2CONbits.T2OUTPS = 0x01;
            break;
        case TIMER_2_POSTSCALER_3:
            T2CONbits.T2OUTPS = 0x02;
            break;
        case TIMER_2_POSTSCALER_4:
            T2CONbits.T2OUTPS = 0x03;
            break;
        case TIMER_2_POSTSCALER_5:
            T2CONbits.T2OUTPS = 0x04;
            break;
        case TIMER_2_POSTSCALER_6:
            T2CONbits.T2OUTPS = 0x05;
            break;
        case TIMER_2_POSTSCALER_7:
            T2CONbits.T2OUTPS = 0x06;
            break;
        case TIMER_2_POSTSCALER_8:
            T2CONbits.T2OUTPS = 0x07;
            break;
        case TIMER_2_POSTSCALER_9:
            T2CONbits.T2OUTPS = 0x08;
            break;
        case TIMER_2_POSTSCALER_10:
            T2CONbits.T2OUTPS = 0x09;
            break;
        case TIMER_2_POSTSCALER_11:
            T2CONbits.T2OUTPS = 0x0A;
            break;
        case TIMER_2_POSTSCALER_12:
            T2CONbits.T2OUTPS = 0x0B;
            break;
        case TIMER_2_POSTSCALER_13:
            T2CONbits.T2OUTPS = 0x0C;
            break;
        case TIMER_2_POSTSCALER_14:
            T2CONbits.T2OUTPS = 0x0D;
            break;
        case TIMER_2_POSTSCALER_15:
            T2CONbits.T2OUTPS = 0x0E;
            break;
        case TIMER_2_POSTSCALER_16:
            T2CONbits.T2OUTPS = 0x0F;
            break;
    }
    TMR2 = _8BIT_;
    IPR1bits.TMR2IP = 0;
    PIE1bits.TMR2IE = 1;
    PIR1bits.TMR2IF = 0;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    T2CONbits.TMR2ON = 1;
}
void Timer_3_Initialize_16Bit(int_fast8_t prescaler){
    switch(prescaler){
        case TIMER_3_PRESCALER_1:
            T3CONbits.T3CKPS = 0x00;
            break;
        case TIMER_3_PRESCALER_2:
            T3CONbits.T3CKPS = 0x01;
            break;
        case TIMER_3_PRESCALER_4:
            T3CONbits.T3CKPS = 0x02;
            break;
        case TIMER_3_PRESCALER_8:
            T3CONbits.T3CKPS = 0x03;
            break;
    }
    TMR3 = _16BIT_;
    T3CONbits.TMR3CS = 0;
    T3CONbits.RD16 = 1;

    IPR2bits.TMR3IP = 0;
    PIE2bits.TMR3IE = 1;
    PIR2bits.TMR3IF = 0;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
    T3CONbits.TMR3ON = 1;
}
