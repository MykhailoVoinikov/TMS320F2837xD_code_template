#include "03_02_System_Control_Functional_Description.h"

//*****************************************************************************
//! Reads all UIDs
//! \param UIDs structure target.
//! \return None
//*****************************************************************************
void deviceIdentification (DeviceID_t* device_id)
{	
    device_id->FormatRevision = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
            SYSCTL_PARTIDL_PARTID_FORMAT_REVISION_M) >> SYSCTL_PARTIDL_PARTID_FORMAT_REVISION_S);
    device_id->FlashSize = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
            SYSCTL_PARTIDL_FLASH_SIZE_M) >> SYSCTL_PARTIDL_FLASH_SIZE_S);
    device_id->Instaspin = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
            SYSCTL_PARTIDL_INSTASPIN_M) >> SYSCTL_PARTIDL_INSTASPIN_S);
    device_id->PinCount = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
            SYSCTL_PARTIDL_PIN_COUNT_M) >> SYSCTL_PARTIDL_PIN_COUNT_S);
    device_id->Qual = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDL) &
            SYSCTL_PARTIDL_QUAL_M) >> SYSCTL_PARTIDL_QUAL_S);
    device_id->ClassID = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDH) &
            SYSCTL_PARTIDH_DEVICE_CLASS_ID_M) >> SYSCTL_PARTIDH_DEVICE_CLASS_ID_S);
    device_id->PartNo = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDH) &
            SYSCTL_PARTIDH_PARTNO_M) >> SYSCTL_PARTIDH_PARTNO_S);
    device_id->Family = ((HWREG(DEVCFG_BASE + SYSCTL_O_PARTIDH) &
            SYSCTL_PARTIDH_FAMILY_M) >> SYSCTL_PARTIDH_FAMILY_S);
    device_id->RevID = HWREG(DEVCFG_BASE + SYSCTL_O_REVID);
    device_id->UID_PsRand0 = HWREG(UID_REGS_BASE + UID_PSRAND0_O_UID_REGS);
    device_id->UID_PsRand1 = HWREG(UID_REGS_BASE + UID_PSRAND1_O_UID_REGS);
    device_id->UID_PsRand2 = HWREG(UID_REGS_BASE + UID_PSRAND2_O_UID_REGS);
    device_id->UID_PsRand3 = HWREG(UID_REGS_BASE + UID_PSRAND3_O_UID_REGS);
    device_id->UID_PsRand4 = HWREG(UID_REGS_BASE + UID_PSRAND4_O_UID_REGS);
    device_id->UID_PsRand5 = HWREG(UID_REGS_BASE + UID_PSRAND5_O_UID_REGS);
    device_id->UID_Unique = HWREG(UID_REGS_BASE + UID_UNIQUE_O_UID_REGS);
    device_id->UID_CheckSum = HWREG(UID_REGS_BASE + UID_CHECKSUM_O_UID_REGS);
    device_id->CPU_ID = (uint16_t)HWREG(UID_CPUID_BASE);
}

//*****************************************************************************
//! CPU Select register for common peripherals
// This register must be configured prior to enabling the peripheral clocks.
// The clock for each peripheral is derived from the selected CPU subsystem. The clock mux controlled by
// this register is not glitch-free, therefore the CPUSELx register must be configured before the PCLKCRx
// register.
// The reset for each peripheral is also driven from the selected CPU.
//! \param None.
//! \return Error: 0xAAAA - OK; other - module error number
//*****************************************************************************
uint16_t selectCPUForPeripherals (void)
{
    EALLOW;
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL0) = SELECT_CPU_EPWM;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL0) != SELECT_CPU_EPWM) return SYSCTL_CPUSEL0_EPWM;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL0_EPWM);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL1) = SELECT_CPU_ECAP;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL1) != SELECT_CPU_ECAP) return SYSCTL_CPUSEL1_ECAP;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL1_ECAP);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL2) = SELECT_CPU_EQEP;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL2) != SELECT_CPU_EQEP) return SYSCTL_CPUSEL2_EQEP;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL2_EQEP);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL4) = SELECT_CPU_SD;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL4) != SELECT_CPU_SD) return SYSCTL_CPUSEL4_SD;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL4_SD);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL5) = SELECT_CPU_SCI;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL5) != SELECT_CPU_SCI) return SYSCTL_CPUSEL5_SCI;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL5_SCI);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL6) = SELECT_CPU_SPI;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL6) != SELECT_CPU_SPI) return SYSCTL_CPUSEL6_SPI;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL6_SPI);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL7) = SELECT_CPU_I2C;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL7) != SELECT_CPU_I2C) return SYSCTL_CPUSEL7_I2C;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL7_I2C);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL8) = SELECT_CPU_CAN;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL8) != SELECT_CPU_CAN) return SYSCTL_CPUSEL8_CAN;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL8_CAN);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL9) = SELECT_CPU_MCBSP;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL9) != SELECT_CPU_MCBSP) return SYSCTL_CPUSEL9_MCBSP;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL9_MCBSP);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL11) = SELECT_CPU_ADC;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL11) != SELECT_CPU_ADC) return SYSCTL_CPUSEL11_ADC;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL11_ADC);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL12) = SELECT_CPU_CMPSS;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL12) != SELECT_CPU_CMPSS) return SYSCTL_CPUSEL12_CMPSS;
    EALLOW;
#ifdef SELECT_CPU_SELECT_LOCK
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL12_CMPSS);
#endif
    HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL14) = SELECT_CPU_DAC;
    EDIS;
    if (HWREG(DEVCFG_BASE + SYSCTL_O_CPUSEL14) != SELECT_CPU_DAC) return SYSCTL_CPUSEL14_DAC;
#ifdef SELECT_CPU_SELECT_LOCK
    EALLOW;
    HWREG(DEVCFG_BASE + SYSCTL_O_DEVCFGLOCK1) |= (1<<SYSCTL_CPUSEL14_DAC);
    EDIS;
#endif

    return 0xAAAA;
}

//*****************************************************************************
//! Check that all peripherals present on board
//! \param None.
//! \return Error: 0xaaaa - OK; other - some module not present
//*****************************************************************************
uint16_t checkDeviceCapability (void)
{

#ifdef DC0_DUAL_CORE
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC0) & DC0_DUAL_CORE)) return 1;
#endif
#ifdef DC1_CPU1_FPU_TMU
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC1) & DC1_CPU1_FPU_TMU)) return 2;
#endif
#ifdef DC1_CPU2_FPU_TMU
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC1) & DC1_CPU2_FPU_TMU)) return 3;
#endif
#ifdef DC1_CPU1_VCU
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC1) & DC1_CPU1_VCU)) return 4;
#endif
#ifdef DC1_CPU2_VCU
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC1) & DC1_CPU2_VCU)) return 5;
#endif
#ifdef DC1_CPU1_CLA1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC1) & DC1_CPU1_CLA1)) return 6;
#endif
#ifdef DC1_CPU2_CLA1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC1) & DC1_CPU2_CLA1)) return 7;
#endif
#ifdef DC2_EMIF1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC2) & DC2_EMIF1)) return 8;
#endif
#ifdef DC2_EMIF2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC2) & DC2_EMIF2)) return 9;
#endif
#ifdef DC3_EPWM1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM1)) return 10;
#endif
#ifdef DC3_EPWM2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM2)) return 11;
#endif
#ifdef DC3_EPWM3
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM3)) return 12;
#endif
#ifdef DC3_EPWM4
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM4)) return 13;
#endif
#ifdef DC3_EPWM5
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM5)) return 14;
#endif
#ifdef DC3_EPWM6
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM6)) return 15;
#endif
#ifdef DC3_EPWM7
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM7)) return 16;
#endif
#ifdef DC3_EPWM8
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM8)) return 17;
#endif
#ifdef DC3_EPWM9
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM9)) return 18;
#endif
#ifdef DC3_EPWM10
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM10)) return 19;
#endif
#ifdef DC3_EPWM11
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM11)) return 20;
#endif
#ifdef DC3_EPWM12
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC3) & DC3_EPWM12)) return 21;
#endif
#ifdef DC4_ECAP1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC4) & DC4_ECAP1)) return 22;
#endif
#ifdef DC4_ECAP2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC4) & DC4_ECAP2)) return 23;
#endif
#ifdef DC4_ECAP3
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC4) & DC4_ECAP3)) return 24;
#endif
#ifdef DC4_ECAP4
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC4) & DC4_ECAP4)) return 25;
#endif
#ifdef DC4_ECAP5
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC4) & DC4_ECAP5)) return 26;
#endif
#ifdef DC4_ECAP6
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC4) & DC4_ECAP6)) return 27;
#endif
#ifdef DC5_EQEP1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC5) & DC5_EQEP1)) return 28;
#endif
#ifdef DC5_EQEP2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC5) & DC5_EQEP2)) return 29;
#endif
#ifdef DC5_EQEP3
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC5) & DC5_EQEP3)) return 30;
#endif
#ifdef DC6_CLB1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC6) & DC6_CLB1)) return 31;
#endif
#ifdef DC6_CLB2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC6) & DC6_CLB2)) return 32;
#endif
#ifdef DC6_CLB3
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC6) & DC6_CLB3)) return 33;
#endif
#ifdef DC6_CLB4
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC6) & DC6_CLB4)) return 34;
#endif
#ifdef DC7_SD1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC7) & DC7_SD1)) return 35;
#endif
#ifdef DC7_SD2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC7) & DC7_SD2)) return 36;
#endif
#ifdef DC8_SCI_A
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC8) & DC8_SCI_A)) return 37;
#endif
#ifdef DC8_SCI_B
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC8) & DC8_SCI_B)) return 38;
#endif
#ifdef DC8_SCI_C
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC8) & DC8_SCI_C)) return 39;
#endif
#ifdef DC8_SCI_D
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC8) & DC8_SCI_D)) return 40;
#endif
#ifdef DC9_SPI_A
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC9) & DC9_SPI_A)) return 41;
#endif
#ifdef DC9_SPI_B
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC9) & DC9_SPI_B)) return 42;
#endif
#ifdef DC9_SPI_C
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC9) & DC9_SPI_C)) return 43;
#endif
#ifdef DC10_I2C_A
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC10) & DC10_I2C_A)) return 44;
#endif
#ifdef DC10_I2C_B
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC10) & DC10_I2C_B)) return 45;
#endif
#ifdef DC11_CAN_A
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC11) & DC11_CAN_A)) return 46;
#endif
#ifdef DC11_CAN_B
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC11) & DC11_CAN_B)) return 47;
#endif
#ifdef DC12_MCBSP_A
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC12) & DC12_MCBSP_A)) return 48;
#endif
#ifdef DC12_MCBSP_B
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC12) & DC12_MCBSP_B)) return 49;
#endif
#ifdef DC12_USB_A_DEVICE_ONLY
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC12) & DC12_USB_A_DEVICE_ONLY)) return 50;
#endif
#ifdef DC12_USB_A_DEVICE_AND_HOST
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC12) & DC12_USB_A_DEVICE_AND_HOST)) return 51;
#endif
#ifdef DC13_UPP_A
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC13) & DC13_UPP_A)) return 52;
#endif
#ifdef DC14_ADC_A
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC14) & DC14_ADC_A)) return 53;
#endif
#ifdef DC14_ADC_B
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC14) & DC14_ADC_B)) return 54;
#endif
#ifdef DC14_ADC_C
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC14) & DC14_ADC_C)) return 55;
#endif
#ifdef DC14_ADC_D
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC14) & DC14_ADC_D)) return 56;
#endif
#ifdef DC15_CMPSS1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC15) & DC15_CMPSS1)) return 57;
#endif
#ifdef DC15_CMPSS2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC15) & DC15_CMPSS2)) return 58;
#endif
#ifdef DC15_CMPSS3
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC15) & DC15_CMPSS3)) return 59;
#endif
#ifdef DC15_CMPSS4
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC15) & DC15_CMPSS4)) return 60;
#endif
#ifdef DC15_CMPSS5
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC15) & DC15_CMPSS5)) return 61;
#endif
#ifdef DC15_CMPSS6
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC15) & DC15_CMPSS6)) return 62;
#endif
#ifdef DC15_CMPSS7
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC15) & DC15_CMPSS7)) return 63;
#endif
#ifdef DC15_CMPSS8
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC15) & DC15_CMPSS8)) return 64;
#endif
#ifdef DC17_DAC_A
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC17) & DC17_DAC_A)) return 65;
#endif
#ifdef DC17_DAC_B
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC17) & DC17_DAC_B)) return 66;
#endif
#ifdef DC17_DAC_C
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC17) & DC17_DAC_C)) return 67;
#endif
#ifdef DC18_LS0_1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC18) & DC18_LS0_1)) return 68;
#endif
#ifdef DC18_LS1_1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC18) & DC18_LS1_1)) return 69;
#endif
#ifdef DC18_LS2_1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC18) & DC18_LS2_1)) return 70;
#endif
#ifdef DC18_LS3_1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC18) & DC18_LS3_1)) return 71;
#endif
#ifdef DC18_LS4_1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC18) & DC18_LS4_1)) return 72;
#endif
#ifdef DC18_LS5_1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC18) & DC18_LS5_1)) return 73;
#endif
#ifdef DC19_LS0_2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC19) & DC19_LS0_2)) return 74;
#endif
#ifdef DC19_LS1_2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC19) & DC19_LS1_2)) return 75;
#endif
#ifdef DC19_LS2_2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC19) & DC19_LS2_2)) return 76;
#endif
#ifdef DC19_LS3_2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC19) & DC19_LS3_2)) return 77;
#endif
#ifdef DC19_LS4_2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC19) & DC19_LS4_2)) return 78;
#endif
#ifdef DC19_LS5_2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC19) & DC19_LS5_2)) return 79;
#endif
#ifdef DC20_GS0
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS0)) return 80;
#endif
#ifdef DC20_GS1
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS1)) return 81;
#endif
#ifdef DC20_GS2
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS2)) return 82;
#endif
#ifdef DC20_GS3
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS3)) return 83;
#endif
#ifdef DC20_GS4
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS4)) return 84;
#endif
#ifdef DC20_GS5
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS5)) return 85;
#endif
#ifdef DC20_GS6
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS6)) return 86;
#endif
#ifdef DC20_GS7
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS7)) return 87;
#endif
#ifdef DC20_GS8
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS8)) return 88;
#endif
#ifdef DC20_GS9
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS9)) return 89;
#endif
#ifdef DC20_GS10
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS10)) return 90;
#endif
#ifdef DC20_GS11
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS11)) return 91;
#endif
#ifdef DC20_GS12
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS12)) return 92;
#endif
#ifdef DC20_GS13
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS13)) return 93;
#endif
#ifdef DC20_GS14
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS14)) return 94;
#endif
#ifdef DC20_GS15
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_DC20) & DC20_GS15)) return 95;
#endif
#ifdef PERCNF1_1_USB_A_PHY
	if (!(HWREG(DEVCFG_BASE + SYSCTL_O_PERCNF1) & PERCNF1_1_USB_A_PHY)) return 96;
#endif
#ifdef PERCNF1_1_ADC_A_MODE_16B
	if ((HWREG(DEVCFG_BASE + SYSCTL_O_PERCNF1) & PERCNF1_1_ADC_A_MODE_16B)) return 97;
#endif
#ifdef PERCNF1_1_ADC_B_MODE_16B
	if ((HWREG(DEVCFG_BASE + SYSCTL_O_PERCNF1) & PERCNF1_1_ADC_B_MODE_16B)) return 98;
#endif
#ifdef PERCNF1_1_ADC_C_MODE_16B
	if ((HWREG(DEVCFG_BASE + SYSCTL_O_PERCNF1) & PERCNF1_1_ADC_C_MODE_16B)) return 99;
#endif
#ifdef PERCNF1_1_ADC_D_MODE_16B
	if ((HWREG(DEVCFG_BASE + SYSCTL_O_PERCNF1) & PERCNF1_1_ADC_D_MODE_16B)) return 100;
#endif
	
	return 0xaaaa;
}


//*****************************************************************************
//! Check Self Test
//! \param None.
//! \return Error: 0x0 - OK; 0x20U - selftest error; 0x1x - autoload error
//*****************************************************************************
uint16_t eFuseErrorStatus (void)
{
	if (HWREG(DEVCFG_BASE + SYSCTL_O_FUSEERR) & SYSCTL_FUSEERR_ERR) return SYSCTL_FUSEERR_ERR;
	return (HWREG(DEVCFG_BASE + SYSCTL_O_FUSEERR) & SYSCTL_FUSEERR_ALERR_M);
}


