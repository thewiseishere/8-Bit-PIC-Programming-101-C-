
#include <xc.h>

// Konfigürasyon bitleri
#pragma config FOSC = INTIO67   // Dahili osilatör kullan (8 MHz)
#pragma config WDTEN = OFF      // Watchdog Timer devre d???
#pragma config PBADEN = OFF     // PORTB'nin analog giri?leri devre d???
#pragma config LVP = ON        // Dü?ük Voltaj Programlama devre d???

#define _XTAL_FREQ 8000000    // Dahili osilatör frekans? (8S MHz)

void main(void) {
    TRISAbits.TRISA1 = 0;   // RA1 pinini ç?k?? olarak ayarla
    TRISAbits.TRISA2 = 0;   // RA2 pinini ç?k?? olarak ayarla

    while(1) {
        LATAbits.LATA1 = 1;  // RA1 pinini yüksek yap (RA1'e ba?l? LED'i yak)
        __delay_ms(2000);     // 500 ms bekle

        LATAbits.LATA1 = 0;  // RA1 pinini dü?ük yap (RA1'e ba?l? LED'i söndür)
        LATAbits.LATA2 = 1;  // RA2 pinini yüksek yap (RA2'ye ba?l? LED'i yak)
        __delay_ms(3000);     // 500 ms bekle

        LATAbits.LATA2 = 0;  // RA2 pinini dü?ük yap (RA2'ye ba?l? LED'i söndür)
        __delay_ms(2000);     // 500 ms bekle
    }
}