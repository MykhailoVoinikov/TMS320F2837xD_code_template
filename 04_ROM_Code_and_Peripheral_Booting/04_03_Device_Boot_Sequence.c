#include "04_03_Device_Boot_Sequence.h"

void DeviceBootSequence (void)
{
	CPU1_fuseErrorRegisterCheck();
	CPU1_clockFlashConfiguration();
	CPU1_deviceConfigRegistersOTP();
	CPU1_initCPURAMS();
	CPU1_pendingNMI();
	CPU1_DCSMinitSeqExe();
	CPU1_bringCPU2outOfReset();
	/*
	CPU2_clockFlashConfiguration();
	CPU2_deviceConfigRegistersOTP();
	CPU2_initCPURAMS();
	CPU2_pendingNMI();
	CPU2_DCSMinitSeqExe();
	CPU2_bootSeqExe();
	*/
	CPU1_bootSeqExe();
}