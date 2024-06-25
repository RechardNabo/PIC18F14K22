/*
#define ADC_ANALOG_00                         (0b0000)
#define ADC_ANALOG_01                         (0b0001)
#define ADC_ANALOG_02                         (0b0010)
#define ADC_ANALOG_03                         (0b0011)
#define ADC_ANALOG_04                         (0b0100)
#define ADC_ANALOG_05                         (0b0101)
#define ADC_ANALOG_06                         (0b0110)
#define ADC_ANALOG_07                         (0b0111)
#define ADC_ANALOG_08                         (0b1000)
#define ADC_ANALOG_09                         (0b1001)
#define ADC_ANALOG_10                         (0b1010)
#define ADC_ANALOG_11                         (0b1011)

#define NEGATIVE_VOLTAGE_REF_VSS              (0b00)
#define NEGATIVE_VOLTAGE_REF_VREF_PIN         (0b01)

#define POSITIVE_VOLTAGE_REF_VDD              (0b00)
#define POSITIVE_VOLTAGE_REF_VREF_PIN         (0b01)
#define POSITIVE_VOLTAGE_REF_FVR              (0b10)

#define ADC_CLOCK_FOSC_DIV_02                 (0b000)
#define ADC_CLOCK_FOSC_DIV_04                 (0b100)
#define ADC_CLOCK_FOSC_DIV_08                 (0b001)
#define ADC_CLOCK_FOSC_DIV_16                 (0b101)
#define ADC_CLOCK_FOSC_DIV_32                 (0b010)
#define ADC_CLOCK_FOSC_DIV_64                 (0b110)
#define ADC_CLOCK_FOSC_INTERNAL_01            (0b011)
#define ADC_CLOCK_FOSC_INTERNAL_02            (0b111)

#define ADC_AQUISITION_00T                    (0b000)
#define ADC_AQUISITION_02T                    (0b001)
#define ADC_AQUISITION_04T                    (0b010)
#define ADC_AQUISITION_06T                    (0b011)
#define ADC_AQUISITION_08T                    (0b100)
#define ADC_AQUISITION_12T                    (0b101)
#define ADC_AQUISITION_16T                    (0b110)
#define ADC_AQUISITION_20T                    (0b111)

#define ADC_RIGHT_ADJUSTED                    (0b0)
#define ADC_LEFT_ADJUSTED                     (0b1)

#define ADC_PIN_RC3                           (0b0000)
#define ADC_PIN_RC2                           (0b0001)
#define ADC_PIN_RC1                           (0b0010)
#define ADC_PIN_RC0                           (0b0011)
#define ADC_PIN_RA4                           (0b0100)
#define ADC_PIN_RA2                           (0b0101)
#define ADC_PIN_RA1                           (0b0110)
#define ADC_PIN_RA0                           (0b0111)
#define ADC_PIN_RB5                           (0b1000)
#define ADC_PIN_RB4                           (0b1001)
#define ADC_PIN_RC7                           (0b1010)
#define ADC_PIN_RC6                           (0b1011)

void ADC_Initialize(byte ADC_Pin,
                    byte Channel, 
                    byte Positive_Voltage_Ref,
                    byte Negative_Voltage_Ref, 
                    byte Conversion_Clock, 
                    byte Aquisition_time, 
                    byte Conversion_adjustment){
    switch(ADC_Pin){
        case ADC_PIN_RC3:
            ANSELbits.ANS7 = 0b1;
            break;
        case ADC_PIN_RC2:
            ANSELbits.ANS6 = 0b1;
            break;
        case ADC_PIN_RC1:
            ANSELbits.ANS5 = 0b1;
            break;
        case ADC_PIN_RC0:
            ANSELbits.ANS4 = 0b1;
            break;
        case ADC_PIN_RA4:
            ANSELbits.ANS3 = 0b1;
            break;
        case ADC_PIN_RA2:
            ANSELbits.ANS2 = 0b1;
            break;
        case ADC_PIN_RA1:
            ANSELbits.ANS1 = 0b1;
            break;
        case ADC_PIN_RA0:
            ANSELbits.ANS0 = 0b1;
            break;
        case ADC_PIN_RB5:
            ANSELHbits.ANS11 = 0b1;
            break;
        case ADC_PIN_RB4:
            ANSELHbits.ANS10 = 0b1;
            break;
        case ADC_PIN_RC7:
            TRISCbits.TRISC7 = 0b1;
            ANSELHbits.ANS9 = 0b1;
            break;
        case ADC_PIN_RC6:
            TRISCbits.TRISC6 = 0b1;
            ANSELHbits.ANS8 = 0b1;
            break;
    }
    switch(Channel){
        
        case ADC_ANALOG_00:
            ADCON0bits.CHS = ADC_ANALOG_00;
            break;
        case ADC_ANALOG_01:
            ADCON0bits.CHS = ADC_ANALOG_01;
            break;
        case ADC_ANALOG_02:
            ADCON0bits.CHS = ADC_ANALOG_02;
            break;
        case ADC_ANALOG_03:
            ADCON0bits.CHS = ADC_ANALOG_03;
            break;
        case ADC_ANALOG_04:
            ADCON0bits.CHS = ADC_ANALOG_04;
            break;
        case ADC_ANALOG_05:
            ADCON0bits.CHS = ADC_ANALOG_05;
            break;
        case ADC_ANALOG_06:
            ADCON0bits.CHS = ADC_ANALOG_06;
            break;
        case ADC_ANALOG_07:
            ADCON0bits.CHS = ADC_ANALOG_07;
            break;
        case ADC_ANALOG_08:
            ADCON0bits.CHS = ADC_ANALOG_08;
            break;
        case ADC_ANALOG_09:
            ADCON0bits.CHS = ADC_ANALOG_09;
            break;
        case ADC_ANALOG_10:
            ADCON0bits.CHS = ADC_ANALOG_10;
            break;
        case ADC_ANALOG_11:
            ADCON0bits.CHS = ADC_ANALOG_11;
            break;
    }
    
    
    switch(Positive_Voltage_Ref){
        case POSITIVE_VOLTAGE_REF_VDD:
            ADCON1bits.PVCFG = POSITIVE_VOLTAGE_REF_VDD;
            break;
        case POSITIVE_VOLTAGE_REF_FVR:
            ADCON1bits.PVCFG = POSITIVE_VOLTAGE_REF_FVR;
            break;
        case POSITIVE_VOLTAGE_REF_VREF_PIN:
            ADCON1bits.PVCFG = POSITIVE_VOLTAGE_REF_VREF_PIN;
            break;
    }
    
    
    switch(Negative_Voltage_Ref){
        
        case NEGATIVE_VOLTAGE_REF_VSS:
            ADCON1bits.NVCFG = NEGATIVE_VOLTAGE_REF_VSS;
            break;
        case NEGATIVE_VOLTAGE_REF_VREF_PIN:
            ADCON1bits.NVCFG = NEGATIVE_VOLTAGE_REF_VSS;
            break;
    }
    
    
    switch(Conversion_Clock){
        case ADC_CLOCK_FOSC_DIV_02:
            ADCON2bits.ADCS = ADC_CLOCK_FOSC_DIV_02;
            break;
        case ADC_CLOCK_FOSC_DIV_04:
            ADCON2bits.ADCS = ADC_CLOCK_FOSC_DIV_04;
            break;
        case ADC_CLOCK_FOSC_DIV_08:
            ADCON2bits.ADCS = ADC_CLOCK_FOSC_DIV_08;
            break;
        case ADC_CLOCK_FOSC_DIV_16:
            ADCON2bits.ADCS = ADC_CLOCK_FOSC_DIV_16;
            break;
        case ADC_CLOCK_FOSC_DIV_32:
            ADCON2bits.ADCS = ADC_CLOCK_FOSC_DIV_32;
            break;
        case ADC_CLOCK_FOSC_DIV_64:
            ADCON2bits.ADCS = ADC_CLOCK_FOSC_DIV_64;
            break;
        case ADC_CLOCK_FOSC_INTERNAL_01:
            ADCON2bits.ADCS = ADC_CLOCK_FOSC_INTERNAL_01;
            break;
        case ADC_CLOCK_FOSC_INTERNAL_02:
            ADCON2bits.ADCS = ADC_CLOCK_FOSC_INTERNAL_02;
            break;
    }
    
    
    switch(Aquisition_time){
        case ADC_AQUISITION_00T:
            ADCON2bits.ACQT = ADC_AQUISITION_00T;
            break;
        case ADC_AQUISITION_02T:
            ADCON2bits.ACQT = ADC_AQUISITION_02T;
            break;
        case ADC_AQUISITION_04T:
            ADCON2bits.ACQT = ADC_AQUISITION_04T;
            break;
        case ADC_AQUISITION_06T:
            ADCON2bits.ACQT = ADC_AQUISITION_06T;
            break;
        case ADC_AQUISITION_08T:
            ADCON2bits.ACQT = ADC_AQUISITION_08T;
            break;
        case ADC_AQUISITION_12T:
            ADCON2bits.ACQT = ADC_AQUISITION_12T;
            break;
        case ADC_AQUISITION_16T:
            ADCON2bits.ACQT = ADC_AQUISITION_16T;
            break;
        case ADC_AQUISITION_20T:
            ADCON2bits.ACQT = ADC_AQUISITION_20T;
            break;
    }
    
    switch(Conversion_adjustment){
        case ADC_RIGHT_ADJUSTED:
            ADCON2bits.ADFM = ADC_RIGHT_ADJUSTED;
            break;
        case ADC_LEFT_ADJUSTED:
            ADCON2bits.ADFM = ADC_LEFT_ADJUSTED;
            break;
    }
    ADCON0bits.ADON = 0b1;
    
}


_2_bytes ADC_read(){
  __delay_ms(2);
  ADCON0bits.GO_nDONE = 0b1;
  while(ADCON0bits.GO_nDONE);
  return ((ADRESH<<0b1000)+ADRESL);
}*/

void ADC_Init(){
    TRISCbits.TRISC3 = 0x01;
    ANSELbits.ANS7 = 0x01;
    ADCON0bits.ADON = 0x01;
    ADCON0bits.CHS0 = 0x00;
    ADCON0bits.CHS1 = 0x00;
    ADCON0bits.CHS2 = 0x00;
    ADCON0bits.CHS3 = 0x00;
    
    ADCON1bits.PVCFG = 0b00; 
    ADCON1bits.NVCFG = 0b00;
  
 
    ADCON2bits.ADFM = 0x01;
    ADCON2bits.ADCS0 = 0;
    ADCON2bits.ADCS1 = 1;
    ADCON2bits.ADCS2 = 0;
    ADRESH = 0x00;
    ADRESL = 0x00;
}


int ADC_Read(int channel){
    int digital;
    ADCON0 =(ADCON0 & 0b11000011)|((channel<<2) & 0b00111100); /*channel 0 is selected i.e (CHS3CHS2CHS1CHS0=0000)
    and ADC is disabled i.e ADON=0*/
    ADCON0 |= ((1<<ADON)|(1<<GO)); /*Enable ADC and start conversion*/
    while(ADCON0bits.GO_nDONE==1); /*wait for End of conversion i.e. Go/done'=0 conversion completed*/
    digital = (ADRESH*256) | (ADRESL); /*Combine 8-bit LSB and 2-bit MSB*/
    return(digital);
}