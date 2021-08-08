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
#include "sysctl.h"

/************************* SELECT PERIPH CPU START **********************/
#define SELECT_CPU_EPWM1                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM2                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM3                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM4                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM5                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM6                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM7                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM8                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM9                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM10               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM11               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EPWM12               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ECAP1                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ECAP2                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ECAP3                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ECAP4                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ECAP5                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ECAP6                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EQEP1                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EQEP2                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_EQEP3                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_SD1                  SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_SD2                  SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_SCI_A                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_SCI_B                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_SCI_C                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_SCI_D                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_SPI_A                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_SPI_B                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_SPI_C                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_I2C_A                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_I2C_B                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CAN_A                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CAN_B                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_MCBSP_A              SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_MCBSP_B              SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ADC_A                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ADC_B                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ADC_C                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_ADC_D                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CMPSS1               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CMPSS2               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CMPSS3               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CMPSS4               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CMPSS5               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CMPSS6               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CMPSS7               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_CMPSS8               SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_DAC_A                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_DAC_B                SYSCTL_CPUSEL_CPU1
#define SELECT_CPU_DAC_C                SYSCTL_CPUSEL_CPU1

#define SELECT_CPU_SELECT_LOCK
/************************* SELECT PERIPH CPU END **********************/




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

#define SELECT_CPU_EPWM  \
((SELECT_CPU_EPWM1<<0)|(SELECT_CPU_EPWM2<<1)|(SELECT_CPU_EPWM3<<2)|(SELECT_CPU_EPWM4<<3)|(SELECT_CPU_EPWM5<<4)|(SELECT_CPU_EPWM6<<5)|    \
(SELECT_CPU_EPWM7<<6)|(SELECT_CPU_EPWM8<<7)|(SELECT_CPU_EPWM9<<8)|(SELECT_CPU_EPWM10<<9)|(SELECT_CPU_EPWM11<<10)|(SELECT_CPU_EPWM12<<11))

#define SELECT_CPU_ECAP  \
((SELECT_CPU_ECAP1<<0)|(SELECT_CPU_ECAP2<<1)|(SELECT_CPU_ECAP3<<2)|(SELECT_CPU_ECAP4<<3)|(SELECT_CPU_ECAP5<<4)|(SELECT_CPU_ECAP6<<5))

#define SELECT_CPU_EQEP  \
((SELECT_CPU_EQEP1<<0)|(SELECT_CPU_EQEP2<<1)|(SELECT_CPU_EQEP3<<2))

#define SELECT_CPU_SD  \
((SELECT_CPU_SD1<<0)|(SELECT_CPU_SD2<<1))

#define SELECT_CPU_SCI  \
((SELECT_CPU_SCI_A<<0)|(SELECT_CPU_SCI_B<<1)|(SELECT_CPU_SCI_C<<2)|(SELECT_CPU_SCI_D<<3))

#define SELECT_CPU_SPI  \
((SELECT_CPU_SPI_A<<0)|(SELECT_CPU_SPI_B<<1)|(SELECT_CPU_SPI_C<<2))

#define SELECT_CPU_I2C  \
((SELECT_CPU_I2C_A<<0)|(SELECT_CPU_I2C_B<<1))

#define SELECT_CPU_CAN  \
((SELECT_CPU_CAN_A<<0)|(SELECT_CPU_CAN_B<<1))

#define SELECT_CPU_MCBSP  \
((SELECT_CPU_MCBSP_A<<0)|(SELECT_CPU_MCBSP_B<<1))

#define SELECT_CPU_ADC  \
((SELECT_CPU_ADC_A<<0)|(SELECT_CPU_ADC_B<<1)|(SELECT_CPU_ADC_C<<2)|(SELECT_CPU_ADC_D<<3))

#define SELECT_CPU_CMPSS  \
((SELECT_CPU_CMPSS1<<0)|(SELECT_CPU_CMPSS2<<1)|(SELECT_CPU_CMPSS3<<2)|(SELECT_CPU_CMPSS4<<3)|(SELECT_CPU_CMPSS5<<4)|(SELECT_CPU_CMPSS6<<5)|    \
(SELECT_CPU_CMPSS7<<6)|(SELECT_CPU_CMPSS8<<7))

#define SELECT_CPU_DAC  \
(long)(((long)SELECT_CPU_DAC_A<<16)|((long)SELECT_CPU_DAC_B<<17)|((long)SELECT_CPU_DAC_C<<18))

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
uint16_t selectCPUForPeripherals (void);



#endif /* _3_2_SYSTEM_CONTROL_SYSTEM_CONTROL_FUNCTIONAL_DESCRIPTION_H_ */
