
#define GND_VREF_N                                          (0x01)
#define GND_VSS                                             (0x00)

#define DAC_SUPPLY_VDD                                      (0x00)
#define DAC_SUPPLY_VREF_P                                   (0x02)
#define DAC_SUPPLY_FVR1BUF                                  (0x03)

#define DAC_CONNECT_CVREF                                   (0x01)
#define DAC_DISCONNECT_CVREF                                (0x00)

#define DAC_POSOTIVE_REF_SOURCE                             (0x01)
#define DAC_NEGATIVE_REF_SOURCE                             (0x00)
#define DAC_ENABLE                                          (0x01)
#define DAC_DISABLE                                         (0x00)

#define DAC_OUT_0_000V                                      (0x00)
#define DAC_OUT_0_156V                                      (0x01)
#define DAC_OUT_0_312V                                      (0x02)
#define DAC_OUT_0_469V                                      (0x03)
#define DAC_OUT_0_625V                                      (0x04)
#define DAC_OUT_0_782V                                      (0x05)
#define DAC_OUT_0_938V                                      (0x06)
#define DAC_OUT_1_094V                                      (0x07)
#define DAC_OUT_1_250V                                      (0x08)
#define DAC_OUT_1_406V                                      (0x09)
#define DAC_OUT_1_563V                                      (0x0A)
#define DAC_OUT_1_719V                                      (0x0B)
#define DAC_OUT_1_875V                                      (0x0C)
#define DAC_OUT_2_031V                                      (0x0D)
#define DAC_OUT_2_188V                                      (0x0E)
#define DAC_OUT_2_344V                                      (0x0F)
#define DAC_OUT_2_250V                                      (0x10)
#define DAC_OUT_2_656V                                      (0x11)
#define DAC_OUT_2_813V                                      (0x12)
#define DAC_OUT_2_969V                                      (0x13)
#define DAC_OUT_3_125V                                      (0x14)
#define DAC_OUT_3_281V                                      (0x15)
#define DAC_OUT_3_438V                                      (0x16)
#define DAC_OUT_3_594V                                      (0x17)
#define DAC_OUT_3_750V                                      (0x18)
#define DAC_OUT_3_906V                                      (0x19)
#define DAC_OUT_4_063V                                      (0x1A)
#define DAC_OUT_4_219V                                      (0x1B)
#define DAC_OUT_4_375V                                      (0x1C)
#define DAC_OUT_4_531V                                      (0x1D)
#define DAC_OUT_4_688V                                      (0x1E)
#define DAC_OUT_4_844V                                      (0x1F)

void DAC_Initialize(int_fast8_t Dac_Posative_Source, 
                    int_fast8_t Dac_Negative_Source,
                    int_fast8_t Dac_CVREF, 
                    int_fast8_t Dac_Rev_Source,
                    int_fast8_t Dac_Enable){
    
    switch(Dac_Enable){
            case DAC_ENABLE:
                VREFCON1bits.D1EN = 1;
                break;
            case DAC_DISABLE:
                VREFCON1bits.D1EN = 0;
                break;
        }
    
    
    switch(Dac_Rev_Source){
        case DAC_POSOTIVE_REF_SOURCE:
            VREFCON1bits.D1LPS = 1;
            break;
        case DAC_NEGATIVE_REF_SOURCE:
            VREFCON1bits.D1LPS = 0;
            break;
     }
    
    switch(Dac_Posative_Source){
        case DAC_SUPPLY_VDD:
            VREFCON1bits.D1PSS0 = 0;
            VREFCON1bits.D1PSS1 = 0;
            break;
        case DAC_SUPPLY_VREF_P:
            VREFCON1bits.D1PSS0 = 1;
            VREFCON1bits.D1PSS1 = 0;
            break;
        case DAC_SUPPLY_FVR1BUF:
            VREFCON1bits.D1PSS0 = 0;
            VREFCON1bits.D1PSS1 = 1;
            break;
    }
    
    switch(Dac_Negative_Source){
        case GND_VREF_N:
            VREFCON1bits.D1NSS = (int_fast8_t)GND_VREF_N;
            break;
        case GND_VSS:
            VREFCON1bits.D1NSS = (int_fast8_t)GND_VSS;
            break;
    }
    
    
    switch(Dac_CVREF){
        case DAC_CONNECT_CVREF:
            VREFCON1bits.DAC1OE = 1;
            break;
        case DAC_DISCONNECT_CVREF:
            VREFCON1bits.DAC1OE = 0;
            break;
    }
    
}


void DAC_Vout(int_fast8_t voltage){
    switch(voltage){
        case DAC_OUT_0_000V:
            VREFCON2bits.DAC1R = DAC_OUT_0_000V;
            break;
        case DAC_OUT_0_156V:
            VREFCON2bits.DAC1R = DAC_OUT_0_156V;
            break;
        case DAC_OUT_0_312V:
            VREFCON2bits.DAC1R = DAC_OUT_0_312V;
            break;
        case DAC_OUT_0_469V:
            VREFCON2bits.DAC1R = DAC_OUT_0_469V;
            break;
        case DAC_OUT_0_625V:
            VREFCON2bits.DAC1R = DAC_OUT_0_625V;
            break;
        case DAC_OUT_0_782V:
            VREFCON2bits.DAC1R = DAC_OUT_0_782V;
            break;
        case DAC_OUT_0_938V:
            VREFCON2bits.DAC1R = DAC_OUT_0_938V;
            break;
        case DAC_OUT_1_094V:
            VREFCON2bits.DAC1R = DAC_OUT_1_094V;
            break;
        case DAC_OUT_1_250V:
            VREFCON2bits.DAC1R = DAC_OUT_1_250V;
            break;
        case DAC_OUT_1_406V:
            VREFCON2bits.DAC1R = DAC_OUT_1_406V;
            break;
        case DAC_OUT_1_563V:
            VREFCON2bits.DAC1R = DAC_OUT_1_563V;
            break;
        case DAC_OUT_1_719V:
            VREFCON2bits.DAC1R = DAC_OUT_1_719V;
            break;
        case DAC_OUT_1_875V:
            VREFCON2bits.DAC1R = DAC_OUT_1_875V;
            break;
        case DAC_OUT_2_031V:
            VREFCON2bits.DAC1R = DAC_OUT_2_031V;
            break;
        case DAC_OUT_2_188V:
            VREFCON2bits.DAC1R = DAC_OUT_2_188V;
            break;
        case DAC_OUT_2_344V:
            VREFCON2bits.DAC1R = DAC_OUT_2_344V;
            break;
        case DAC_OUT_2_250V:
            VREFCON2bits.DAC1R = DAC_OUT_2_250V;
            break;
        case DAC_OUT_2_656V:
            VREFCON2bits.DAC1R = DAC_OUT_2_656V;
            break;
        case DAC_OUT_2_813V:
            VREFCON2bits.DAC1R = DAC_OUT_2_813V;
            break;
        case DAC_OUT_2_969V:
            VREFCON2bits.DAC1R = DAC_OUT_2_969V;
            break;
        case DAC_OUT_3_125V:
            VREFCON2bits.DAC1R = DAC_OUT_3_125V;
            break;
        case DAC_OUT_3_281V:
            VREFCON2bits.DAC1R = DAC_OUT_3_281V;
            break;
        case DAC_OUT_3_438V:
            VREFCON2bits.DAC1R = DAC_OUT_3_438V;
            break;
        case DAC_OUT_3_594V:
            VREFCON2bits.DAC1R = DAC_OUT_3_594V;
            break;
        case DAC_OUT_3_750V:
            VREFCON2bits.DAC1R = DAC_OUT_3_750V;
            break;
        case DAC_OUT_3_906V:
            VREFCON2bits.DAC1R = DAC_OUT_3_906V;
            break;
        case DAC_OUT_4_063V:
            VREFCON2bits.DAC1R = DAC_OUT_4_063V;
            break;
        case DAC_OUT_4_219V:
            VREFCON2bits.DAC1R = DAC_OUT_4_219V;
            break;
        case DAC_OUT_4_375V:
            VREFCON2bits.DAC1R = DAC_OUT_4_375V;
            break;
        case DAC_OUT_4_531V:
            VREFCON2bits.DAC1R = DAC_OUT_4_531V;
            break;
        case DAC_OUT_4_688V:
            VREFCON2bits.DAC1R = DAC_OUT_4_688V;
            break;
        case DAC_OUT_4_844V:
            VREFCON2bits.DAC1R = DAC_OUT_4_844V;
            break;
    }
}