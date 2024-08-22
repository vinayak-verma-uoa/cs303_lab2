#include <system.h>
#include <altera_avalon_pio_regs.h>
#include <stdio.h>
#include "sccharts.h"

#define GETBIT(var, bit)  (((var) >> (bit) )& 1)
#define SETBIT(var, bit)  var |= (1<<(bit))
#define CLRBIT(var, bit)  var &= (~(1 << (bit)))

int main()
{
// Create the struct
TickData data;
// Initialise
reset(&data);

unsigned int Buttons = 0;

	while(1)
	{
		// Fetch button inputs
		// A is Key 2, B is Key 1, R is Key 0
		Buttons = ~IORD_ALTERA_AVALON_PIO_DATA(KEYS_BASE);

		data.A = GETBIT(Buttons, 2);
		data.B = GETBIT(Buttons, 1);
		data.R = GETBIT(Buttons, 0);

		// Remember that keys are active low
		// Do a tick!
		tick(&data);
		// Output O to Red LED
		if(data.O == 1)
		{
			int current = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, SETBIT(current, 0));
		} else {
			int current = IORD_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE);
			IOWR_ALTERA_AVALON_PIO_DATA(LEDS_RED_BASE, CLRBIT(current, 0));
		}
	}
	return 0;
}
