#ifndef _3_2_SYSTEM_CONTROL_SYSTEM_CONTROL_FUNCTIONAL_DESCRIPTION_H_
#define _3_2_SYSTEM_CONTROL_SYSTEM_CONTROL_FUNCTIONAL_DESCRIPTION_H_

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_nmi.h"
#include "inc/hw_sysctl.h"
#include "inc/hw_types.h"
#include "cpu.h"
#include "debug.h"
#include "interrupt.h"

#define UID_REGS_BASE               0x000703C0U
#define UID_CPUID_BASE              0x0007026DU

#define UID_PSRAND0_O_UID_REGS          0x0U     //UID Psuedo-random 192 bit number
#define UID_PSRAND1_O_UID_REGS          0x2U     //UID Psuedo-random 192 bit number
#define UID_PSRAND2_O_UID_REGS          0x4U     //UID Psuedo-random 192 bit number
#define UID_PSRAND3_O_UID_REGS          0x6U     //UID Psuedo-random 192 bit number
#define UID_PSRAND4_O_UID_REGS          0x8U     //UID Psuedo-random 192 bit number
#define UID_PSRAND5_O_UID_REGS          0xAU     //UID Psuedo-random 192 bit number
#define UID_UNIQUE_O_UID_REGS           0xCU     //UID Unique 32 bit number
#define UID_CHECKSUM_O_UID_REGS         0xEU     //UID Checksum

typedef struct
{
    uint32_t FormatRevision;
    uint32_t FlashSize;
    uint32_t Instaspin;
    uint32_t PinCount;
    uint32_t Qual;
    uint32_t ClassID;
    uint32_t PartNo;
    uint32_t Family;
    uint32_t RevID;
    uint32_t UID_PsRand0;
    uint32_t UID_PsRand1;
    uint32_t UID_PsRand2;
    uint32_t UID_PsRand3;
    uint32_t UID_PsRand4;
    uint32_t UID_PsRand5;
    uint32_t UID_Unique;
    uint32_t UID_CheckSum;
    uint32_t CPU_ID;
}DeviceID_t;

//device identification
void deviceIdentification (DeviceID_t* device_id);

//Device Configuration Registers



#endif /* _3_2_SYSTEM_CONTROL_SYSTEM_CONTROL_FUNCTIONAL_DESCRIPTION_H_ */
