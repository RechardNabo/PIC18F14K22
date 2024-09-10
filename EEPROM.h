#define EEPROM_SIZE             (256)
void EEPROM_Write(unsigned char address, unsigned char data) {
    // Set address to write to
    EEADR = address;
    // Set the data to be written
    EEDATA = data;
    // Access EEPROM memory
    EECON1bits.EEPGD = 0; // Point to data memory
    EECON1bits.CFGS = 0;  // Access EEPROM
    // Allow writes to EEPROM
    EECON1bits.WREN = 1;  // Enable EEPROM write
    // Disable interrupts during write
    INTCONbits.GIE = 0;   // Disable global interrupts
    // Write sequence
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1;    // Initiate write
    // Wait for write completion
    while (EECON1bits.WR); // Wait for the WR bit to clear (write complete)
    // Disable write to EEPROM
    EECON1bits.WREN = 0;  // Disable EEPROM write
    // Re-enable interrupts
    INTCONbits.GIE = 1;   // Enable global interrupts
}

unsigned char EEPROM_Read(unsigned char address) {
    // Set address to read from
    EEADR = address;
    // Access EEPROM memory
    EECON1bits.EEPGD = 0; // Point to data memory
    EECON1bits.CFGS = 0;  // Access EEPROM
    // Initiate read
    EECON1bits.RD = 1;    // Start reading
    // Return the read data
    return EEDATA;
}

// Function to check if EEPROM addresses are populated and free memory available
unsigned int EEPROM_CheckFreeMemory(void) {
    unsigned int freeMemory = 0;
    for (unsigned char i = 0; i < (unsigned char)EEPROM_SIZE; i++) {
        unsigned char data = EEPROM_Read(i);
        if (data == 0xFF) { // Unwritten locations are typically 0xFF
            freeMemory++;   // Count unpopulated memory locations
        }
    }
    return freeMemory;      // Return the number of free locations
}

// Function to display which addresses are populated (non-0xFF)
void EEPROM_DisplayPopulatedAddresses(void) {
    for (unsigned char i = 0; i < (unsigned char)EEPROM_SIZE; i++) {
        unsigned char data = EEPROM_Read(i);
        if (data != 0xFF) {
            // Populated address found
            // For example, output the populated address and data (you can adapt to your output method)
            // Use some output function or debug method to print this (e.g., UART or LEDs)
        }
    }
}