#ifndef _3_3_RESETS_
#define _3_3_RESETS_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_nmi.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "cpu.h"
#include "debug.h"
#include "interrupt.h"
#include "sysctl.h"

//Reset Sources
void chiplevelResets (void);
void CPU1_SystemResets (void);
void CPU2_SubsystemResets (void);
void specialResets (void);

//read RESC by SysCtl_getResetCause()
//clear RESC by SysCtl_clearResetCause(uint32_t)

//External Reset
//Power-On Reset 
//Debugger Reset
//Watchdog Reset
//NMI Watchdog Reset 
//DCSM Safe Code Copy Reset
//Hibernate Reset 
//Hardware BIST Reset 
//Test Reset


#endif /* _3_3_RESETS_ */
