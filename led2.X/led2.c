
#include <xc.h>

// Konfig�rasyon bitleri
#pragma config FOSC = INTIO67   // Dahili osilat�r kullan (8 MHz)
#pragma config WDTEN = OFF      // Watchdog Timer devre d???
#pragma config PBADEN = OFF     // PORTB'nin analog giri?leri devre d???
#pragma config LVP = ON        // D�?�k Voltaj Programlama devre d???

#define _XTAL_FREQ 8000000    // Dahili osilat�r frekans? (8S MHz)

void main(void) {
    TRISAbits.TRISA1 = 0;   // RA1 pinini �?k?? olarak ayarla
    TRISAbits.TRISA2 = 0;   // RA2 pinini �?k?? olarak ayarla

    while(1) {
        LATAbits.LATA1 = 1;  // RA1 pinini y�ksek yap (RA1'e ba?l? LED'i yak)
        __delay_ms(2000);     // 500 ms bekle

        LATAbits.LATA1 = 0;  // RA1 pinini d�?�k yap (RA1'e ba?l? LED'i s�nd�r)
        LATAbits.LATA2 = 1;  // RA2 pinini y�ksek yap (RA2'ye ba?l? LED'i yak)
        __delay_ms(3000);     // 500 ms bekle

        LATAbits.LATA2 = 0;  // RA2 pinini d�?�k yap (RA2'ye ba?l? LED'i s�nd�r)
        __delay_ms(2000);     // 500 ms bekle
    }
}