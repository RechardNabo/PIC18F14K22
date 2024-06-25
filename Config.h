
// PIC18F14K22 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config FOSC = IRCCLKOUT // Oscillator Selection bits (Internal RC oscillator, CLKOUT function on OSC2)
#pragma config PLLEN = ON       // 4 X PLL Enable bit (Oscillator multiplied by 4)
#pragma config PCLKEN = ON      // Primary Clock Enable bit (Primary clock enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor disabled)
#pragma config IESO = ON        // Internal/External Oscillator Switchover bit (Oscillator Switchover mode enabled)
// CONFIG2L
#pragma config PWRTEN = ON      // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 19        // Brown Out Reset Voltage bits (VBOR set to 1.9 V nominal)

// CONFIG2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable bit (WDT is controlled by SWDTEN bit of the WDTCON register)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config HFOFST = ON      // HFINTOSC Fast Start-up bit (HFINTOSC starts clocking the CPU without waiting for the oscillator to stablize.)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled, RA3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled)
#pragma config BBSIZ = OFF      // Boot Block Size Select bit (1kW boot block size)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block not protected from table reads executed in other blocks)

#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define TRUE                                        (0x01)
#define FALSE                                       (~TRUE)
#define OFF                                         (0x00)
#define ON                                          (0x01)
#define GPIO_OUTPUT                                 (0x00)
#define GPIO_INPUT                                  (0x01)
#define _XTAL_FREQ                                  (1000000)
typedef int_fast8_t  byte;
typedef int_fast16_t _2_bytes;
/*When OSC2 is
configured as CLKOUT, the frequency at the pin is the
frequency of the Internal Oscillator divided by 4
 *  */
//#######################[ProtoType]#############################
//void Internal_OSC_Config(unsigned int Frequency);
//###############################################################
void Internal_OSC_Config(int16_t Frequency){
    
    OSCCONbits.OSTS = 0x00;
    OSCCONbits.SCS1 = 0x00;
    OSCCONbits.SCS0 = 0x00;
    OSCCONbits.HFIOFS = 0x01;
    
    OSCTUNEbits.TUN0 = 0x01;
    OSCTUNEbits.TUN1 = 0x01;
    OSCTUNEbits.TUN2 = 0x01;
    OSCTUNEbits.TUN3 = 0x01;
    OSCTUNEbits.TUN4 = 0x01;
    OSCTUNEbits.TUN5 = 0x00;
    OSCTUNEbits.PLLEN = 0x01;
    switch(Frequency){
        case 31:
            #undef _XTAL_FREQ
            #define _XTAL_FREQ                      (31000)
            OSCCONbits.IRCF2 = 0x00;
            OSCCONbits.IRCF1 = 0x00;
            OSCCONbits.IRCF0 = 0x00;
            break;
        case (int)250:
            #undef _XTAL_FREQ
            #define _XTAL_FREQ                      (250000)
            OSCCONbits.IRCF2 = 0x00;
            OSCCONbits.IRCF1 = 0x00;
            OSCCONbits.IRCF0 = 0x01;
            break;
            
        case 500:
            #undef _XTAL_FREQ
            #define _XTAL_FREQ                      (500000)
            OSCCONbits.IRCF2 = 0x00;
            OSCCONbits.IRCF1 = 0x01;
            OSCCONbits.IRCF0 = 0x00;
            break;
        case 1:
            #undef _XTAL_FREQ
            #define _XTAL_FREQ                      (1000000)
            OSCCONbits.IRCF2 = 0x00;
            OSCCONbits.IRCF1 = 0x01;
            OSCCONbits.IRCF0 = 0x01;
            break;
        case 2:
            #undef _XTAL_FREQ
            #define _XTAL_FREQ                      (2000000)
            OSCCONbits.IRCF2 = 0x01;
            OSCCONbits.IRCF1 = 0x00;
            OSCCONbits.IRCF0 = 0x00;
            break;
        case 4:
            #undef _XTAL_FREQ
            #define _XTAL_FREQ                      (4000000)
            OSCCONbits.IRCF2 = 0x01;
            OSCCONbits.IRCF1 = 0x00;
            OSCCONbits.IRCF0 = 0x01;
            break;
        case 8:
            #undef _XTAL_FREQ
            #define _XTAL_FREQ                      (8000000)
            OSCCONbits.IRCF2 = 0x01;
            OSCCONbits.IRCF1 = 0x01;
            OSCCONbits.IRCF0 = 0x00;
            break;
        case 16:
            #undef _XTAL_FREQ
            #define _XTAL_FREQ                      (16000000)
            OSCCONbits.IRCF2 = 0x01;
            OSCCONbits.IRCF1 = 0x01;
            OSCCONbits.IRCF0 = 0x01;
            break;
        default:
            #undef _XTAL_FREQ
            #define _XTAL_FREQ                      (1000000)
            OSCCONbits.IRCF2 = 0x00;
            OSCCONbits.IRCF1 = 0x01;
            OSCCONbits.IRCF0 = 0x01;
            
   } 
}