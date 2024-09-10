void EUSART_Init(void) {
    // Set baud rate
     SPBRG = 103;             // Baud rate = 9600, FOSC = 64 MHz (Refer to datasheet for calculation)


    // Enable Asynchronous Serial Port (TX and RX)
    TXSTAbits.SYNC = 0;       // Asynchronous mode
    TXSTAbits.BRGH = 1;       // High Baud Rate Select bit

    RCSTAbits.SPEN = 1;       // Enable serial port (configures RX/DT and TX/CK pins as serial port pins)
    TXSTAbits.TXEN = 1;       // Enable transmitter
    RCSTAbits.CREN = 1;       // Enable receiver (optional if you also want to receive data)
    
    // Set up pins for TX/RX
    TRISCbits.TRISC6 = 0;     // TX pin set as output
    TRISCbits.TRISC7 = 1;     // RX pin set as input
}

void EUSART_SendChar(char data) {
    while(!TXSTAbits.TRMT);   // Wait until the transmit buffer is empty
    TXREG = data;             // Load the character into the transmit register
}

void EUSART_SendString(const char* str) {
    while (*str != '\0') {     // Loop until the null terminator is reached
        EUSART_SendChar(*str); // Send each character
        str++;                 // Move to the next character
    }
}

char EUSART_ReceiveChar(void) {
    while(!PIR1bits.RCIF);   // Wait for data to be received
    if (RCSTAbits.OERR) {    // Check for overrun error
        RCSTAbits.CREN = 0;  // Reset continuous receive
        RCSTAbits.CREN = 1;  // Enable continuous receive again
    }
    return RCREG;            // Return the received character
}

void EUSART_ReceiveString(char* buffer, unsigned int len) {
    unsigned int i;
    for(i = 0; i < len - 1; i++) {
        buffer[i] = EUSART_ReceiveChar();  // Receive each character
        if(buffer[i] == '\n' || buffer[i] == '\r') break;  // Stop on newline or carriage return
    }
    buffer[i] = '\0';  // Null-terminate the string
}