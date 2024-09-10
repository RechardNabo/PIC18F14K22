void Comparactor_Initialize(void){
    // Set up interrupts
    PIE2bits.C1IE = 1; // Enable Comparator1 interrupt
    PIE2bits.C2IE = 1; // Enable Comparator2 interrupt
    PIE1bits.CCP1IE = 1; // Enable CCP1 interrupt

    // Configure interrupts using per-bit settings
    INTCONbits.GIE = 1;  // Enable global interrupts
    INTCONbits.PEIE = 1; // Enable peripheral interrupts
}

void setupComparator1(void) {
    // Configure Comparator1
    CM1CON0 = 0x00;   // Reset settings
    CM1CON0bits.C1ON = 1; // Enable Comparator1
    CM1CON0bits.C1CH = 0b00; // Select C1IN0 and C1IN1 as inputs
    CM1CON0bits.C1POL = 0; // Non-inverted output
    CM1CON0bits.C1OUT = 0; // Output disabled for initial setup
}

void setupComparator2(void) {
    // Configure Comparator2
    CM2CON0 = 0x00;   // Reset settings
    CM2CON0bits.C2ON = 1; // Enable Comparator2
    CM2CON0bits.C2CH = 0b00; // Select C2IN0 and C2IN1 as inputs
    CM2CON0bits.C2POL = 0; // Non-inverted output
    CM2CON0bits.C2OUT = 0; // Output disabled for initial setup
}