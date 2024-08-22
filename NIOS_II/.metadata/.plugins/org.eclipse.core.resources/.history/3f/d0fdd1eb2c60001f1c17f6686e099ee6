#include <system.h>
#include <altera_avalon_pio_regs.h>
#include <stdio.h>
#include "sccharts.h"

// ISR needs to capture the button pressed
// Set flag based on button ID
// Then change ABRO based on this.
// flag will be button ID as int or something
void button_interupts_function(void* context, alt_u32 id)
{
	int* temp = (int*) context;



}



int main()
{
// Create the struct
TickData data;
// Initialise
reset(&data);
	while(1)
	{
		// Fetch button inputs
		// A is Key 2, B is Key 1, R is Key 0
		// Remember that keys are active low
		// Do a tick!
		tick(&data);
		// Output O to Red LED
	}
	return 0;
}
