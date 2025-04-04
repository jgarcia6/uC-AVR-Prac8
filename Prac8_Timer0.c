#include <avr/io.h>
#include "Timer0.h"
/* incluir lo necesario para hacer uso de UART0 */

/* Implementar */
void UART0_AutoBaudRate(void);
void Clock_Ini(uint64_t millis);
void Clock_Date_Display();

int main()
{
    /* llamar a función para inicializar puertos E/S */
    /* llamar a función para inicializar UART0 */

    UART0_AutoBaudRate();

    UART_clrscr(0);
    UART_gotoxy(0,5,1);
    UART_puts(0,"Autobauding done. UBRR0=");
    itoa(UBRR0,str,10);
    UART_puts(0,str);
    UART_puts(0,'\n\r');

    Timer0_Ini(); /* Inicializar contador de millis.*/
    Clock_Ini(1744376390000);

    while(1)
    { /* == main loop == */
        if( Timer0_SecFlag() )
        { /* ¿ha pasado un Segundo? */
            UART_gotoxy(0,5,2);
            Clock_Display();
            UART_gotoxy(0,5,3);
        }
    } /* fin del loop principal */
    return 0; /* <-- no se llega aquí */
}
