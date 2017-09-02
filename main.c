//include files
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>

#include "driverlib/sysctl.h"
#include "utils/uartstdio.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"

//include BSP
#include "bsp.h"

//include LCD driver
#include "display.h"

void main(void) {
	// Set the clocking to run directly from the external crystal/oscillator.
//	SysCtlClockSet(
//	SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_OSC_INT | SYSCTL_XTAL_16MHZ);

//	SysCtlClockSet(
//	SYSCTL_SYSDIV_8 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

	//initialize I2C module 0
	InitI2C0();

	//initialize LCD
	initLCD();

	//initialize UART
	ConfigureUART();

	SetTimeDate(50, 41, 22, 2, 29, 11, 16);

	//initialize SysTick
	SysTickPeriodSet(SysCtlClockGet());
	SysTickIntRegister(SysTick_Handler);
	IntMasterEnable();
	SysTickEnable();
	SysTickIntEnable();

	while (1) {

	}
}

