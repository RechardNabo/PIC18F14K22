#define RESET_8BIT_REGISTER                         (0x00)
#define RESET_16BIT_REGISTER                        (0x0000)

void GPIO_Toogle(){PORTBbits.RB7 = ~PORTBbits.RB7;}
void Delay(unsigned long long Max_Delay){for(unsigned long long counter = 0x00 ; counter < Max_Delay ; counter++);}
void Timer_0_Interrupt_Function(void){/*GPIO_Toogle();Delay(249999);*/}
void Timer_1_Interrupt_Function(void){/*GPIO_Toogle();Delay(249999);*/}
void Timer_2_Interrupt_Function(void){/*GPIO_Toogle()*/};
void Timer_3_Interrupt_Function(void){/*GPIO_Toogle()*/};

void __interrupt() ISR(void) {
    
    if(INTCONbits.TMR0IF){
        Timer_0_Interrupt_Function();
        TMR0 = RESET_16BIT_REGISTER;
        INTCONbits.TMR0IF = 0x00;
    }
    if(PIR1bits.TMR1IF){
        Timer_1_Interrupt_Function();
        PIR1bits.TMR1IF = 0;
        TMR1 = RESET_16BIT_REGISTER;
    }
    
    if(PIR1bits.TMR2IF){
        Timer_2_Interrupt_Function();
        PIR1bits.TMR2IF = 0;
        TMR2 = RESET_8BIT_REGISTER;
    }
    if(PIR2bits.TMR3IF){
        Timer_3_Interrupt_Function();
        PIR2bits.TMR3IF = 0;
        TMR3 = RESET_16BIT_REGISTER;
    }
    
    if(PIR1bits.CCP1IF){
        GPIO_Toogle();
        TMR1 = RESET_16BIT_REGISTER;
        PIR1bits.CCP1IF = 0x00;
    }
    
    
}