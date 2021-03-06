#include "08_02_GPIO_Configuration_Overview.h"

//use OTP when sure

void _8_2_GPIO_Configuration_Overview (void)
{
	EALLOW;
	
	//Selects which master's GPIODAT/SET/CLEAR/TOGGLE registers controls this GPIO pins
	HWREG(GPIOCTRL_BASE + GPIO_O_GPACSEL1) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPACSEL2) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPACSEL3) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPACSEL4) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBCSEL1) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBCSEL2) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBCSEL3) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBCSEL4) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCCSEL1) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCCSEL2) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCCSEL3) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCCSEL4) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDCSEL1) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDCSEL2) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDCSEL3) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDCSEL4) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPECSEL1) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPECSEL2) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPECSEL3) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPECSEL4) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFCSEL1) = 0x00000000; 
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFCSEL2) = 0x00000000;

	/*plan the device pinout
	Make a list of all required peripherals for the application. Using the peripheral mux information in the
	device data manual, choose which GPIOs to use for the peripheral signals. Decide which of the
	remaining GPIOs to use as inputs and outputs for each CPU and CLA.
	Once the peripheral muxing has been chosen, it should be implemented by writing the appropriate
	values to the GPyMUX1/2 and GPyGMUX1/2 registers. When changing the GPyGMUX value for a pin,
	always set the corresponding GPyMUX bits to zero first to avoid glitching in the muxes. By default, all
	pins are general-purpose I/Os, not peripheral signals.
	*/
	HWREG(GPIOCTRL_BASE + GPIO_O_GPAMUX1) = 0x00000000;  //set the corresponding GPyMUX bits to zero first
	HWREG(GPIOCTRL_BASE + GPIO_O_GPAGMUX1) = 0x00000000; //changing the GPyGMUX value
	HWREG(GPIOCTRL_BASE + GPIO_O_GPAMUX1) = 0x00000000;	 //changing the GPyMUX value
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBGMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCGMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDGMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPEMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPEGMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPEMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFGMUX1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFMUX1) = 0x00000000;
	
	//Input Polarity Invert
	HWREG(GPIOCTRL_BASE + GPIO_O_GPAINV) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBINV) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCINV) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDINV) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPEINV) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFINV) = 0x00000000;
	
	//enable internal pinup resistors
	HWREG(GPIOCTRL_BASE + GPIO_O_GPAPUD) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBPUD) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCPUD) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDPUD) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPEPUD) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFPUD) = 0x00000000;
	
	//select Sampling Period
	HWREG(GPIOCTRL_BASE + GPIO_O_GPACTRL) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBCTRL) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCCTRL) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDCTRL) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPECTRL) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFCTRL) = 0x00000000;
	//select input qualification
	HWREG(GPIOCTRL_BASE + GPIO_O_GPAQSEL1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPAQSEL2) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBQSEL1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBQSEL2) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCQSEL1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCQSEL2) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDQSEL1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDQSEL2) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPEQSEL1) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPEQSEL2) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFQSEL1) = 0x00000000;
	
	EDIS;
	
	/*select the direction of any general purpose IO pins
	For each pin configured as a GPIO, specify the direction of the pin as either input or output using the
	GPyDIR registers. By default, all GPIO pins are inputs. Before changing a pin to an output, load the
	output latch with the value to be driven by writing that value to the GPySET, GPyCLEAR, or GPyDAT
	registers. Once the latch is loaded, write to GPyDIR to change the pin direction. By default, all output
	latches are zero.
	*/
	HWREG(GPIOCTRL_BASE + GPIO_O_GPAODR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBODR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCODR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDODR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPEODR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFODR) = 0x00000000;
	
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBAMSEL) = 0x00000000; //USB pins
	
	HWREG(GPIOCTRL_BASE + GPIO_O_GPASET) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPACLEAR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBSET) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBCLEAR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCSET) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCCLEAR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDSET) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDCLEAR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPESET) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPECLEAR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFSET) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFCLEAR) = 0x00000000;
	
	EALLOW;
	
	HWREG(GPIOCTRL_BASE + GPIO_O_GPADIR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBDIR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCDIR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDDIR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPEDIR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFDIR) = 0x00000000;
	
	//select low power mode wakeup sources
	HWREG(GPIOCTRL_BASE + SYSCTL_O_GPIOLPMSEL0) = 0x00000000;
	HWREG(GPIOCTRL_BASE + SYSCTL_O_GPIOLPMSEL1) = 0x00000000;
	
	//lock and commit
	HWREG(GPIOCTRL_BASE + GPIO_O_GPALOCK) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPACR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBLOCK) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPBCR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCLOCK) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPCCR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDLOCK) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPDCR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPELOCK) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPECR) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFLOCK) = 0x00000000;
	HWREG(GPIOCTRL_BASE + GPIO_O_GPFCR) = 0x00000000;
	
	EDIS;
}
