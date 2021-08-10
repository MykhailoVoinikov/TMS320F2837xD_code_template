#include "03_01_System_Control_Introduction.h"

//#pragma DATA_SECTION(device_id, ".section")
DeviceID_t device_id;

uint32_t System_Control_Functional_Description (void)
{
	uint32_t res=0;
	
	peripheralSoftwareReset ();
	
	//device identification
	deviceIdentification (&device_id);

	//Device Configuration Registers
	res = eFuseErrorStatus();
	if (res != 0) return res|0x03024000;
	res = checkDeviceCapability();
	if (res != 0xaaaa) return res|0x03023000;
	res = selectCPUForPeripherals();
	if (res != 0xaaaa) return res|0x03022000; //03022 - chapter(0302)+subchapter(2)
	
	return 0xaaaa;
}
