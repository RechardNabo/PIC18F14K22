#define SPI_MASTER_MODE_FOSCO_64                            (0b0010)
#define SPI_MASTER_MODE_FOSCO_16                            (0b0001)
#define SPI_MASTER_MODE_FOSCO_04                            (0b0000)
#define SPI_MASTER_MODE_FOSCO_TMR2                          (0b0011)
#define SPI_SLAVE_MODE_SS_ENABLED                           (0b0100)  
#define SPI_SALVE_MODE_SS_DISABLED                          (0b0101)

#define SPI_IDLE_STATE_HIGH                                 (0b0000)
#define SPI_IDLE_STATE_LOW                                  (0b0001)

#define SPI_PORT_ENABLE                                     (0b0001)
#define SPI_PORT_DISABLE                                    (0b0000)

#define SPI_COLLISION_DET_CLEAR                             (0b0000)

#define SPI_SDO                                             (TRISCbits.TRISC7) 
#define SPI_SCK                                             (TRISBbits.TRISB6)
#define SPI_SS                                              (TRISCbits.TRISC6)
#define SPI_SDI                                             (TRISBbits.TRISB4)

#define I2C_SCL                                             (TRISBbits.TRISB6)
#define I2C_SDA                                             (TRISBbits.TRISB4)
#define I2C_SLAVE_7BIT                                      (0b0110)
#define I2C_SLAVE_10BIT                                     (0b0111)
#define I2C_MASTER_CLOCK                                    (0b1000)
#define I2C_MASTER_FIRMWARE                                 (0b1011)
#define I2C_SLAVE_7BIT_INTERRUPT_ENABLED                    (0b1110)
#define I2C_SLAVE_10BIT_INTERRUPT_ENABLED                   (0b1111)
#define I2C_MASTER                                          (0b0)
#define I2C_SLAVE                                           (0b1)
#define I2C_SLAVE_ADDRESS                                   (0x4)
#define FSCL_1MHz                                           (1000000)
#define FSCL_400kHz                                         (400000)
#define FSCL_100kHz                                         (100000)


//###############################[SPI Start here]##############################

void SPI_Master_Initialize(int_fast8_t SPI_MODE,
                    int_fast8_t SPI_IDLE, 
                    int_fast8_t SPI_SERIAL_PORT_ENABLE){
    SPI_SDO = 0;                //RC7 (MOSI) <-> (MISO)
    SPI_SDI = 1;                //RB4 (MISO) <-> (MOSI)
    SPI_SCK = 0;                //RB6 (SCK))
    SPI_SS  = 1;                //RC6 (SS))
    switch(SPI_MODE){
    
        case SPI_MASTER_MODE_FOSCO_04:
            SSPCON1bits.SSPM0 = 0 ;
            SSPCON1bits.SSPM1 = 0 ;
            SSPCON1bits.SSPM2 = 0 ;
            SSPCON1bits.SSPM3 = 0 ;
            break;
            
        case SPI_MASTER_MODE_FOSCO_16:
            SSPCON1bits.SSPM0 = 1 ;
            SSPCON1bits.SSPM1 = 0 ;
            SSPCON1bits.SSPM2 = 0 ;
            SSPCON1bits.SSPM3 = 0 ;
            break;
            
        case SPI_MASTER_MODE_FOSCO_64:
            SSPCON1bits.SSPM0 = 0 ;
            SSPCON1bits.SSPM1 = 1 ;
            SSPCON1bits.SSPM2 = 0 ;
            SSPCON1bits.SSPM3 = 0 ;
            break;
            
        case SPI_MASTER_MODE_FOSCO_TMR2:
            SSPCON1bits.SSPM0 = 1 ;
            SSPCON1bits.SSPM1 = 1 ;
            SSPCON1bits.SSPM2 = 0 ;
            SSPCON1bits.SSPM3 = 0 ;
            break;
            
        case SPI_SLAVE_MODE_SS_ENABLED:
            SSPCON1bits.SSPM0 = 0 ;
            SSPCON1bits.SSPM1 = 0 ;
            SSPCON1bits.SSPM2 = 1 ;
            SSPCON1bits.SSPM3 = 0 ;
            break;
        case SPI_SALVE_MODE_SS_DISABLED:
            SSPCON1bits.SSPM0 = 1 ;
            SSPCON1bits.SSPM1 = 0 ;
            SSPCON1bits.SSPM2 = 1 ;
            SSPCON1bits.SSPM3 = 0 ;
            break;
    }
    
    switch(SPI_IDLE){
        case SPI_IDLE_STATE_LOW:
            SSPCON1bits.CKP = SPI_IDLE_STATE_LOW;
            break;
            
        case SPI_IDLE_STATE_HIGH:
            SSPCON1bits.CKP = SPI_IDLE_STATE_HIGH;
            break;
    }
    
    switch(SPI_SERIAL_PORT_ENABLE){
        case SPI_PORT_DISABLE:
            SSPCON1bits.SSPEN = SPI_PORT_DISABLE;
            break;
            
        case SPI_PORT_ENABLE:
            SSPCON1bits.SSPEN = SPI_PORT_ENABLE;
            break;
    }
    SSPCON1bits.SSPOV = 0;
    SSPSTATbits.SMP = 0;
    SSPSTATbits.CKE = 1;
}

volatile unsigned char SPI_Get_Data(void){
    SSPBUF  = 0b00000000;
    while(!(SSPSTATbits.BF));
    PIR1bits.SSPIF = 0;
    SSPCON1bits.SSPOV = 0;
    return (SSPBUF);
}

void SPI_Send_Data(byte Data){
    SSPBUF =  (unsigned char)Data;
    while(!(SSPSTATbits.BF));
    PIR1bits.SSPIF = 0;
}

void SPI_Send_String(unsigned char *s){
    while(*s) {
        SPI_Send_Data((byte)*s++);
    }
}

//###########################[SPI Ends Here]###################################


//###########################[I2C Start Here]##################################

signed char SSPADD_Value(long FSCL){
    signed char BRG = (signed char)((((double)_XTAL_FREQ)/(4.0*(double)FSCL)) - 1);
    return (BRG);
}

void I2C_Initialize(byte I2C_MODE,byte I2C_BIT_MODE, long I2C_SPEED ){
    I2C_SDA = 0b1;
    I2C_SCL = 0b1;
    
    switch(I2C_MODE){
        case I2C_MASTER:
            break;
        case I2C_SLAVE:
            SSPCON2bits.GCEN = 0b1;
            SSPMSKbits.MSK  = 0b11111111;
            break;
    }
    
    switch(I2C_BIT_MODE){
        case I2C_SLAVE_7BIT:
            SSPCON1bits.SSPM = I2C_SLAVE_7BIT;
            SSPCON1bits.CKP = 0b0;
            SSPADD = I2C_SLAVE_ADDRESS;
            break;
        case I2C_SLAVE_10BIT:
            SSPCON1bits.SSPM = I2C_SLAVE_10BIT;
            SSPCON1bits.CKP = 0b0;
            SSPADD = I2C_SLAVE_ADDRESS;
            break;
        case I2C_MASTER_CLOCK:
            SSPCON1bits.SSPM = I2C_MASTER_CLOCK;
            SSPADD = (unsigned char)SSPADD_Value(I2C_SPEED);
            break;
        case I2C_MASTER_FIRMWARE:
            SSPCON1bits.SSPM = I2C_MASTER_FIRMWARE;
            break;
        case I2C_SLAVE_7BIT_INTERRUPT_ENABLED:
            SSPCON1bits.SSPM = I2C_SLAVE_7BIT_INTERRUPT_ENABLED;
            SSPCON1bits.CKP = 0b0;
            SSPADD = I2C_SLAVE_ADDRESS;
            break;
        case I2C_SLAVE_10BIT_INTERRUPT_ENABLED:
            SSPCON1bits.SSPM = I2C_SLAVE_10BIT_INTERRUPT_ENABLED;
            SSPCON1bits.CKP = 0b0;
            SSPADD = I2C_SLAVE_ADDRESS;
            break;
    }
    SSPSTATbits.BF      = 0b0;
    SSPSTATbits.UA      = 0b0;
    SSPSTATbits.RW      = 0b0;
    SSPSTATbits.S       = 0b0;
    SSPSTATbits.P       = 0b0;
    SSPSTATbits.DA      = 0b0;
    SSPSTATbits.SMP     = 0b0;
    SSPSTATbits.CKE     = 0b0;
    
    SSPCON1bits.SSPOV   = 0b0;
    SSPCON1bits.WCOL    = 0b0;
    SSPCON1bits.SSPEN   = 0b1;
    
    SSPCON2bits.RSEN    = 0b0;
    SSPCON2bits.GCEN    = 0b0;
}

void I2C_Wait(void){
    /*while( ((SSPSTATbits.BF     && 0x00) ||
            (SSPSTATbits.UA     && 0x00) ||
            (SSPSTATbits.RW     && 0x01) ||
            (SSPSTATbits.S      && 0x00) ||
            (SSPSTATbits.P      && 0x00) ||
            (SSPSTATbits.DA     && 0x00) ||
            (SSPSTATbits.CKE    && 0x00) ||
            (SSPSTATbits.SMP    && 0x00) )
                      ||
           ((SSPCON2bits.SEN    && 0x01) ||
            (SSPCON2bits.RSEN   && 0x01) ||
            (SSPCON2bits.PEN    && 0x01) ||
            (SSPCON2bits.RCEN   && 0x01) ||
            (SSPCON2bits.ACKEN  && 0x01) ||
            (SSPCON2bits.ACKDT  && 0x00) ||
            (SSPCON2bits.ACKSTAT&& 0x00) ||
            (SSPCON2bits.GCEN   && 0x00))
          );*/
    while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Start(void){
    I2C_Wait();
    SSPCON2bits.SEN     = 0b1;
}

void I2C_Stop(void){
    I2C_Wait();
    SSPCON2bits.PEN      = 0b1;
}

void I2C_Restart(void){
    I2C_Wait();
    SSPCON2bits.RSEN  = 0b1;
}

void I2C_Acknw(){
    I2C_Wait();
    SSPCON2bits.ACKDT = 0b0;
    SSPCON2bits.ACKEN = 0b1;    
}

void I2C_Nacknw(void){
    I2C_Wait();
    SSPCON2bits.ACKDT = 0b1;
    SSPCON2bits.ACKEN = 0b1;
}

void I2C_Write(byte DATA){
    I2C_Wait();
    SSPBUF = (unsigned char)DATA;
}
void I2C_Write_String(unsigned char *s){
    while(*s) {
        I2C_Write((byte)*s++);
    }
}
unsigned short I2C_Read(unsigned short Acknowledge_BIT){
    unsigned short DATA;
    I2C_Wait();
    
    SSPCON2bits.RCEN = 0b1;
    I2C_Wait();
    
    DATA = SSPBUF;
    I2C_Wait();
    
    SSPCON2bits.ACKDT = (Acknowledge_BIT) ? 0b0:0b1;
    SSPCON2bits.ACKEN = 0b1; ;
    return (DATA);
}

void I2C_Send_String(byte command ,unsigned char * data){
    I2C_Start();
    I2C_Write(command);
    I2C_Write_String(data);
    I2C_Stop();
    __delay_ms(10);
}
void I2C_Send_Byte(byte command ,byte data){
    I2C_Start();
    I2C_Write(command);
    I2C_Write(data);
    I2C_Stop();
    __delay_ms(10);
}
unsigned char I2C_Receive(byte command){
    I2C_Start();
    I2C_Write(command);
    return (unsigned char)I2C_Read(0);
    I2C_Stop();
    __delay_ms(10);
}