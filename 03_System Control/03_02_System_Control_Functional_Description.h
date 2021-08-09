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


/************************* DEVICE CONFIGURATION TARGET START (UNCOMMENT WHAT YOU EXPECT)********/
#define DC0_DUAL_CORE					((uint32_t)0x00000001)

#define DC1_CPU1_FPU_TMU				((uint32_t)0x00000001)
#define DC1_CPU2_FPU_TMU				((uint32_t)0x00000002)
#define DC1_CPU1_VCU					((uint32_t)0x00000004)
#define DC1_CPU2_VCU					((uint32_t)0x00000008)
#define DC1_CPU1_CLA1					((uint32_t)0x00000040)
#define DC1_CPU2_CLA1					((uint32_t)0x00000100)

#define DC2_EMIF1						((uint32_t)0x00000001)
#define DC2_EMIF2						((uint32_t)0x00000002)

#define DC3_EPWM1						((uint32_t)0x00000001)
#define DC3_EPWM2						((uint32_t)0x00000002)
#define DC3_EPWM3						((uint32_t)0x00000004)
#define DC3_EPWM4						((uint32_t)0x00000008)
#define DC3_EPWM5						((uint32_t)0x00000010)
#define DC3_EPWM6						((uint32_t)0x00000020)
#define DC3_EPWM7						((uint32_t)0x00000040)
#define DC3_EPWM8						((uint32_t)0x00000080)
#define DC3_EPWM9						((uint32_t)0x00000100)
#define DC3_EPWM10						((uint32_t)0x00000200)
#define DC3_EPWM11						((uint32_t)0x00000400)
#define DC3_EPWM12						((uint32_t)0x00000800)

#define DC4_ECAP1						((uint32_t)0x00000001)
#define DC4_ECAP2						((uint32_t)0x00000002)
#define DC4_ECAP3						((uint32_t)0x00000004)
#define DC4_ECAP4						((uint32_t)0x00000008)
#define DC4_ECAP5						((uint32_t)0x00000010)
#define DC4_ECAP6						((uint32_t)0x00000020)

#define DC5_EQEP1						((uint32_t)0x00000001)
#define DC5_EQEP2						((uint32_t)0x00000002)
#define DC5_EQEP3						((uint32_t)0x00000004)

#define DC6_CLB1						((uint32_t)0x00000001)
#define DC6_CLB2						((uint32_t)0x00000002)
#define DC6_CLB3						((uint32_t)0x00000004)
#define DC6_CLB4						((uint32_t)0x00000008)

#define DC7_SD1							((uint32_t)0x00000001)
#define DC7_SD2							((uint32_t)0x00000002)

#define DC8_SCI_A						((uint32_t)0x00000001)
#define DC8_SCI_B						((uint32_t)0x00000002)
#define DC8_SCI_C						((uint32_t)0x00000004)
#define DC8_SCI_D						((uint32_t)0x00000008)

#define DC9_SPI_A						((uint32_t)0x00000001)
#define DC9_SPI_B						((uint32_t)0x00000002)
#define DC9_SPI_C						((uint32_t)0x00000004)

#define DC10_I2C_A						((uint32_t)0x00000001)
#define DC10_I2C_B						((uint32_t)0x00000002)

#define DC11_CAN_A						((uint32_t)0x00000001)
#define DC11_CAN_B						((uint32_t)0x00000002)

#define DC12_MCBSP_A					((uint32_t)0x00000001)
#define DC12_MCBSP_B					((uint32_t)0x00000002)
#define DC12_USB_A_DEVICE_ONLY			((uint32_t)0x000010000)
#define DC12_USB_A_DEVICE_AND_HOST		((uint32_t)0x000020000)

#define DC13_UPP_A						((uint32_t)0x00000001)

#define DC14_ADC_A						((uint32_t)0x00000001)
#define DC14_ADC_B						((uint32_t)0x00000002)
#define DC14_ADC_C						((uint32_t)0x00000004)
#define DC14_ADC_D						((uint32_t)0x00000008)

#define DC15_CMPSS1						((uint32_t)0x00000001)
#define DC15_CMPSS2						((uint32_t)0x00000002)
#define DC15_CMPSS3						((uint32_t)0x00000004)
#define DC15_CMPSS4						((uint32_t)0x00000008)
#define DC15_CMPSS5						((uint32_t)0x00000010)
#define DC15_CMPSS6						((uint32_t)0x00000020)
#define DC15_CMPSS7						((uint32_t)0x00000040)
#define DC15_CMPSS8						((uint32_t)0x00000080)

#define DC17_DAC_A						((uint32_t)0x000010000)
#define DC17_DAC_B						((uint32_t)0x000020000)
#define DC17_DAC_C						((uint32_t)0x000040000)

#define DC18_LS0_1						((uint32_t)0x00000001)
#define DC18_LS1_1						((uint32_t)0x00000002)
#define DC18_LS2_1						((uint32_t)0x00000004)
#define DC18_LS3_1						((uint32_t)0x00000008)
#define DC18_LS4_1						((uint32_t)0x00000010)
#define DC18_LS5_1						((uint32_t)0x00000020)

#define DC19_LS0_2						((uint32_t)0x00000001)
#define DC19_LS1_2						((uint32_t)0x00000002)
#define DC19_LS2_2						((uint32_t)0x00000004)
#define DC19_LS3_2						((uint32_t)0x00000008)
#define DC19_LS4_2						((uint32_t)0x00000010)
#define DC19_LS5_2						((uint32_t)0x00000020)

#define DC20_GS0						((uint32_t)0x00000001)
#define DC20_GS1						((uint32_t)0x00000002)
#define DC20_GS2						((uint32_t)0x00000004)
#define DC20_GS3						((uint32_t)0x00000008)
#define DC20_GS4						((uint32_t)0x00000010)
#define DC20_GS5						((uint32_t)0x00000020)
#define DC20_GS6						((uint32_t)0x00000040)
#define DC20_GS7						((uint32_t)0x00000080)
#define DC20_GS8						((uint32_t)0x00000100)
#define DC20_GS9						((uint32_t)0x00000200)
#define DC20_GS10						((uint32_t)0x00000400)
#define DC20_GS11						((uint32_t)0x00000800)
#define DC20_GS12						((uint32_t)0x00001000)
#define DC20_GS13						((uint32_t)0x00002000)
#define DC20_GS14						((uint32_t)0x00004000)
#define DC20_GS15						((uint32_t)0x00008000)

#define PERCNF1_1_USB_A_PHY				((uint32_t)0x00010000)
#define PERCNF1_1_ADC_A_MODE_16B		((uint32_t)0x00000001)
#define PERCNF1_1_ADC_B_MODE_16B		((uint32_t)0x00000002)
#define PERCNF1_1_ADC_C_MODE_16B		((uint32_t)0x00000004)
#define PERCNF1_1_ADC_D_MODE_16B		((uint32_t)0x00000008)
/************************* DEVICE CONFIGURATION TARGET END *************************************/




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
uint16_t checkDeviceCapability (void);
uint16_t eFuseErrorStatus (void);

#endif /* _3_2_SYSTEM_CONTROL_SYSTEM_CONTROL_FUNCTIONAL_DESCRIPTION_H_ */
