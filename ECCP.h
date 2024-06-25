#include "Timers.h"
#define PWN_PIN_P1X_ALL                             (0x01)
#define PWM_PIN_P1D_RC2                             (0x02)          
#define PWM_PIN_P1C_RC3                             (0x03)        
#define PWM_PIN_P1B_RC4                             (0x04)
#define PWM_PIN_P1A_RC5                             (0x05)


#define CAPTURE_FALLING_EDGE                        (0x01)
#define CAPTURE_RISING_EDGE                         (0x02)
#define CAPTURE_4TH_RISING_EDGE                     (0x03)
#define CAPTURE_16TH_RISING_EDGE                    (0x04)

#define COMPARE_MODE_SET_OUTPUT                     (0x01)
#define COMPARE_MODE_CLEAR_OUTPUT                   (0x02)
#define COMPARE_MODE_SOFTWARE_INTERRUPT             (0x03)
#define COMPARE_MODE_TRIGGER_EVENT                  (0x04)

#define INPUT                                       (0x01)
#define OUTPUT                                      (0x00)

void EPWM_Initialize(int_fast8_t output_pin,int_fast8_t timer2_prescaler , int_fast8_t timer2_postscaler){
    
    Timer_2_Initialize_8Bit(timer2_prescaler,timer2_postscaler);
    
    CCP1CONbits.CCP1M0 = 0;
    CCP1CONbits.CCP1M1 = 0;
    CCP1CONbits.CCP1M2 = 1;
    CCP1CONbits.CCP1M3 = 1;
    
    CCP1CONbits.DC1B0 = 0;
    CCP1CONbits.DC1B1 = 0;
    
    CCP1CONbits.P1M0 = 0;
    CCP1CONbits.P1M1 = 0;
    
    switch(output_pin){
        case PWN_PIN_P1X_ALL:
            TRISCbits.TRISC2 = 0;
            TRISCbits.TRISC3 = 0;
            TRISCbits.TRISC4 = 0;
            TRISCbits.TRISC5 = 0;
            
            PSTRCONbits.STRA = 1;
            PSTRCONbits.STRB = 1;
            PSTRCONbits.STRC = 1;
            PSTRCONbits.STRD = 1;
            break;
        case PWM_PIN_P1D_RC2:
            TRISCbits.RC2 = 0;
            PSTRCONbits.STRD = 1;
            break;
        case PWM_PIN_P1C_RC3:
            TRISCbits.TRISC3 = 0;
            PSTRCONbits.STRC = 1;
            break;
        case PWM_PIN_P1B_RC4:
            TRISCbits.TRISC4 = 0;
            PSTRCONbits.STRB = 1;
            break;
        case PWM_PIN_P1A_RC5:
            TRISCbits.TRISC5 = 0;
            PSTRCONbits.STRA = 1;
            break;
    }PSTRCONbits.STRSYNC = 0;
}

void EPWM_Start( int_fast8_t frequency, int_fast8_t duty_cycle){
    PR2 = (unsigned char)frequency; // Set period (frequency) (MIN => MAX 255 > 0xFF))
    CCPR1L = (unsigned char)duty_cycle; // Set duty cycle (MAX 255 Recommended => 128))
}





void ECAPTURE_GPIO(void){TRISBbits.TRISB7 = 0;PORTBbits.RB7 = 0;}
void ECAPTURE_Initialize(int_fast8_t mode, int_fast8_t timer_1_prescaler){
   
    Timer_1_Initialize_16Bit(timer_1_prescaler);
    TRISCbits.TRISC5 = INPUT;
    switch(mode){
        case CAPTURE_FALLING_EDGE:      //PA1 assigned as Capture/Compare input/ Compare output
            CCP1CONbits.CCP1M0 = 0;
            CCP1CONbits.CCP1M1 = 0;
            CCP1CONbits.CCP1M2 = 1;
            CCP1CONbits.CCP1M3 = 0;
            break;
        case CAPTURE_RISING_EDGE:       //PA1 assigned as Capture/Compare input/ Compare output
            CCP1CONbits.CCP1M0 = 1;
            CCP1CONbits.CCP1M1 = 0;
            CCP1CONbits.CCP1M2 = 1;
            CCP1CONbits.CCP1M3 = 0;
            break;
        case CAPTURE_4TH_RISING_EDGE:   //PA1 assigned as Capture/Compare input/ Compare output
            CCP1CONbits.CCP1M0 = 0;
            CCP1CONbits.CCP1M1 = 1;
            CCP1CONbits.CCP1M2 = 1;
            CCP1CONbits.CCP1M3 = 0;
            break;
        case CAPTURE_16TH_RISING_EDGE:  //PA1 assigned as Capture/Compare input/ Compare output
            CCP1CONbits.CCP1M0 = 1;
            CCP1CONbits.CCP1M1 = 1;
            CCP1CONbits.CCP1M2 = 1;
            CCP1CONbits.CCP1M3 = 0;
            break;
    }
}

void ECOMPARE_Initialize( int_fast8_t compare_mode, int_fast8_t timer_3_prescaler){
    
    Timer_3_Initialize_16Bit(timer_3_prescaler);
    CCPR1 = 0xFFFF;
    
    switch(compare_mode){
        case COMPARE_MODE_CLEAR_OUTPUT: 
            CCP1CONbits.CCP1M0 = 0;
            CCP1CONbits.CCP1M1 = 0;
            CCP1CONbits.CCP1M2 = 0;
            CCP1CONbits.CCP1M3 = 1;
            break;
        case COMPARE_MODE_SET_OUTPUT:   
            CCP1CONbits.CCP1M0 = 1;
            CCP1CONbits.CCP1M1 = 0;
            CCP1CONbits.CCP1M2 = 0;
            CCP1CONbits.CCP1M3 = 1;
            break;
        case COMPARE_MODE_SOFTWARE_INTERRUPT:  // CCPI1 not affected or changed only the CCP1IF is affected 
            CCP1CONbits.CCP1M0 = 0;
            CCP1CONbits.CCP1M1 = 1;
            CCP1CONbits.CCP1M2 = 0;
            CCP1CONbits.CCP1M3 = 1;
            break;
        case COMPARE_MODE_TRIGGER_EVENT:    
            CCP1CONbits.CCP1M0 = 1;
            CCP1CONbits.CCP1M1 = 1;
            CCP1CONbits.CCP1M2 = 0;
            CCP1CONbits.CCP1M3 = 1;
            break;
    }
}
