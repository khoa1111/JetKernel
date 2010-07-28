#define S5K4EA_COMPLETE
#undef S5K4EA_COMPLETE
/*
 * Driver for S5K4EA (SXGA camera) from Samsung Electronics
 * 
 * 1/6" 1.3Mp CMOS Image Sensor SoC with an Embedded Image Processor
 * supporting MIPI CSI-2
 *
 * Copyright (C) 2009, Dongsoo Nathaniel Kim<dongsoo45.kim@samsung.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#ifndef __S5K4EA_H__
#define __S5K4EA_H__

struct s5k4ea_reg {
	unsigned short addr;
	unsigned short val;
};

struct s5k4ea_regset_type {
	unsigned char *regset;
	int len;
};

/*
 * Macro
 */
#define REGSET_LENGTH(x)	(sizeof(x)/sizeof(s5k4ea_reg))

/*
 * Host S/W Register interface (0x70000000-0x70002000)
 */
/* Initialization section */
#define S5K4EA_Speed_368Mbps		0
#define S5K4EA_Speed_464Mbps		1
#define S5K4EA_Speed_552Mbps		2
#define S5K4EA_Speed_648Mbps		3
#define S5K4EA_Speed_736Mbps		4
#define S5K4EA_Speed_832Mbps		5
#define S5K4EA_Speed_920Mbps		6

#define S5K4EA4Khz_0Mhz		0x0000
#define S5K4EA4Khz_46Mhz		0x2CEC
#define S5K4EA4Khz_58Mhz		0x38A4
#define S5K4EA4Khz_69Mhz		0x4362
#define S5K4EA4Khz_81Mhz		0x4F1A
#define S5K4EA4Khz_91Mhz		0x58DE
#define S5K4EA4Khz_92Mhz		0x59D8
#define S5K4EA4Khz_93Mhz		0x5AD2
#define S5K4EA4Khz_104Mhz		0x6590
#define S5K4EA4Khz_115Mhz		0x704E

#define S5K4EAFrTime_30fps		0x014D	// 33.3ms -> 30 fps
#define S5K4EAFrTime_15fps		0x029A	// 66.6ms -> 15 fps
#define S5K4EAFrTime_7P5fps		0x0535	// 133.3ms -> 7.5 fps
#define S5K4EAFrTime_1P5fps		0x1964	// 650.0ms -> 1.5 fps
/*=====================================*/
/*========Register map for S5K4EA EVT1(Don't modify)===========*/
#define S5K4EA_REG_TC_IPRM_InClockLSBs				0x0238
#define S5K4EA_REG_TC_IPRM_InClockMSBs				0x023A
#define S5K4EA_REG_TC_IPRM_UseNPviClocks				0x0252
#define S5K4EA_REG_TC_IPRM_UseNMipiClocks				0x0254
#define S5K4EA_REG_TC_IPRM_NumberOfMipiLanes			0x0256
#define S5K4EA_REG_TC_IPRM_OpClk4KHz_0				0x025A
#define S5K4EA_REG_TC_IPRM_MinOutRate4KHz_0			0x025C
#define S5K4EA_REG_TC_IPRM_MaxOutRate4KHz_0			0x025E
#define S5K4EA_REG_TC_IPRM_InitParamsUpdated			0x026E
#define S5K4EA_REG_TC_GP_EnablePreview				0x0280
#define S5K4EA_REG_TC_GP_EnablePreviewChanged		0x0282
#define S5K4EA_REG_TC_GP_NewConfigSync				0x0290
#define S5K4EA_REG_TC_GP_ActivePrevConfig				0x02A4
#define S5K4EA_REG_TC_GP_PrevConfigChanged			0x02A6
#define S5K4EA_REG_TC_GP_PrevOpenAfterChange			0x02A8
#define S5K4EA_REG_0TC_PCFG_usWidth					0x02E2
#define S5K4EA_REG_0TC_PCFG_usHeight					0x02E4
#define S5K4EA_REG_0TC_PCFG_Format					0x02E6
#define S5K4EA_REG_0TC_PCFG_usMaxOut4KHzRate			0x02E8
#define S5K4EA_REG_0TC_PCFG_usMinOut4KHzRate			0x02EA
#define S5K4EA_REG_0TC_PCFG_PVIMask					0x02F0
#define S5K4EA_REG_0TC_PCFG_uClockInd					0x02F8
#define S5K4EA_REG_0TC_PCFG_FrRateQualityType			0x02FC
#define S5K4EA_REG_0TC_PCFG_usFrTimeType				0x02FA
#define S5K4EA_REG_0TC_PCFG_usMaxFrTimeMsecMult10	0x02FE
#define S5K4EA_REG_0TC_PCFG_usMinFrTimeMsecMult10	0x0300

#define S5K4EA_PCLK_MIN	S5K4EA4Khz_115Mhz
#define S5K4EA_PCLK_MAX	S5K4EA4Khz_115Mhz

#define S5K4EA_FrTime_MAX	S5K4EAFrTime_30fps
/*
 * User defined commands
 */
/* S/W defined features for tune */
#define REG_DELAY	0xFF	/* in ms */
#define REG_CMD		0xFFFF	/* Followed by command */

/* Following order should not be changed */
enum image_size_s5k4ea {
	/* This SoC supports upto SXGA (1280*1024) */
#if 0
	QQVGA,	/* 160*120*/
	QCIF,	/* 176*144 */
	QVGA,	/* 320*240 */
	CIF,	/* 352*288 */
#endif
	VGA,	/* 640*480 */
#if 0
	SVGA,	/* 800*600 */
	HD720P,	/* 1280*720 */
	SXGA,	/* 1280*1024 */
#endif
};

/*
 * Following values describe controls of camera
 * in user aspect and must be match with index of s5k4ea_regset[]
 * These values indicates each controls and should be used
 * to control each control
 */
enum s5k4ea_control {
	S5K4EA_INIT,
	S5K4EA_EV,
	S5K4EA_AWB,
	S5K4EA_MWB,
	S5K4EA_EFFECT,
	S5K4EA_CONTRAST,
	S5K4EA_SATURATION,
	S5K4EA_SHARPNESS,
};

#define S5K4EA_REGSET(x)	{	\
	.regset = x,			\
	.len = sizeof(x)/sizeof(s5k4ea_reg),}

/*
 * User tuned register setting values
 */
unsigned char s5k4ea_init_reg1[][4] = {
	{0xFC, 0xFC, 0xD0, 0x00},

	//======================================= Analog/APS setting ===============================================================                                                             
	//WRITE	D000F262	0000	// tgr_auto_exp (shutter off=0b shutter on=1b)
	{0x00, 0x28, 0xD0, 0x00},

	//002A	F468
	//0F12	0006	// For avg mode
	    	
	{0x00, 0x2A, 0xF4, 0x04},
	{0x0F, 0x12, 0x00, 0x2A},	// ADC SAT(450mV): revised by Ana 090609
	{0x00, 0x2A, 0xF4, 0x6E},
	{0x0F, 0x12, 0x00, 0x02},	// CDS TEST [0]SR/SS EN: revised by Ana 090126
	// [1]S1 H, [2]LDB H, [3]clp H
	// [4]S34 P X, [5]S24 N X
	{0x00, 0x2A, 0xF4, 0x5A},
	{0x0F, 0x12, 0x00, 0x02},	// LD LDB EN : revised by Ana 090126
	{0x00, 0x2A, 0xF4, 0x0E},
	{0x0F, 0x12, 0x00, 0x04},	// RMP REG 1.8V: revised by Ana 090126
	{0x00, 0x2A, 0xF4, 0x0C},
	{0x0F, 0x12, 0x00, 0x20},	// rmp_option(RMP_INIT_DAC): revised by Ana 090126
	    	
	{0x00, 0x2A, 0xF4, 0x20},
	{0x0F, 0x12, 0x00, 0x76},  //For SHBN 76	//0075	// COMP(CDS) bias [7:4] comp2, [3:0] comp1: revised by Ana 090126
	    	
	{0x0F, 0x12, 0x00, 0x05},	// pix current bias
	    	
	{0x00, 0x2A, 0xF4, 0x26},
	{0x0F, 0x12, 0x00, 0xD4},	// CLP level
	{0x00, 0x2A, 0xF4, 0x60},
	{0x0F, 0x12, 0x00, 0x01},	// CLP on: revised by Ana 090126
	    	
	{0x00, 0x2A, 0xE3, 0x04},
	{0x0F, 0x12, 0x00, 0x81},	// ADC OFFSET 128: revised by Ana 090126
	{0x00, 0x2A, 0xE3, 0x08},
	{0x0F, 0x12, 0x00, 0x81},	// ADC DEFAULT 128: revised by Ana 090209

	// ADLC
	{0x00, 0x2A, 0xE5, 0x06},
	{0x0F, 0x12, 0x00, 0x93},	// ADLC [7]FL,[6:5]FM,: revised by Ana 090126
	// [4]F,[3:2]LM,[1]L,[0]CH
	{0x00, 0x2A, 0xE4, 0x02},
	{0x0F, 0x12, 0x04, 0x0C},	// ADLC BPR EN[10], th 12: revised by Ana 090126
	//WRITE	D000E510	3804	// adlc_frame_filter_co_reg[B][A]

	{0x00, 0x2A, 0xF4, 0x2A},
	{0x0F, 0x12, 0x00, 0x80},	// ALL TX mode enable(ref_option[7]): revised by Ana 090130
	    	
	{0x00, 0x2A, 0xF4, 0x08},
	{0x0F, 0x12, 0x00, 0x0E},	// aig_sig_mx: revised by Ana 090209
	{0x0F, 0x12, 0x00, 0x07},	/// aig_rst_mx: revised by Ana 090209
	{0x00, 0x2A, 0xF4, 0x00},
	{0x0F, 0x12, 0x00, 0x07},	// 0007	//aig_off_rst1: for 92MHZ HS (full)
				// 0006	//aig_off_rst1: for 92MHz LS(full & avg)/ 46MHz LS(full)
				// 0005	//aig_off_rst1: for 46MHz LS(avg)
				// 0004 //aig_off_rst1: for 46MHz HS (full)

	// Doubler	
	{0x00, 0x2A, 0xF4, 0x3C},
	{0x0F, 0x12, 0x00, 0x01},	// aig_pd_inrush_ctrl: revised by Ana 090126
	{0x00, 0x2A, 0xF4, 0x40},
	{0x0F, 0x12, 0x00, 0x44},	// aig_rosc_tune_ncp[7:4], aig_rosc_tune_cp[3:0]: revised by Ana 090126
	{0x00, 0x2A, 0xF4, 0x44},
	{0x0F, 0x12, 0x00, 0x08},	// aig_reg_tune_pix
	{0x00, 0x2A, 0xF4, 0x48},
	{0x0F, 0x12, 0x00, 0x08},	// aig_reg_tune_ntg
	    	
	{0x00, 0x2A, 0xF4, 0x5C},
	{0x0F, 0x12, 0x00, 0x01},	// aig_dshut_en

	//Multiple Sampling
	{0x00, 0x2A, 0xF4, 0x06},
	{0x0F, 0x12, 0x00, 0x01},	// MS[2:0], No Multiple Sampling @92MHz,: revised by Ana 090130
	         	// 1b' 2 times multiple sampling(0001h) for 46MHz or LS@92MHz
	{0x00, 0x2A, 0xF4, 0x10},
	{0x0F, 0x12, 0x00, 0x00},    // MSOFF_EN=0 : no Multiple sampling if gain < 2 : revised by Ana 090609    
	//== APS Timing ============================================================================================================             
	{0x00, 0x28, 0xD0, 0x00},
	{0x00, 0x2A, 0xF4, 0x72},
	{0x0F, 0x12, 0x00, 0x5C},	//For 92MHz LS & HS aig_dstx_width(1us@92MHz)	: revised by Ana 090216 
				//002E	//aig_dstx_width(1us@46MHz)	: revised by Ana 090216

	//For 46MHz 7.5fps
	//002A	F476
	//0F12	0045	//aig_stx_width(1.5us@46MHz): revised by Ana 090216	 		
	    	
	{0x00, 0x28, 0xD0, 0x00},
	{0x00, 0x2A, 0xF4, 0x70},
	{0x0F, 0x12, 0x00, 0x04},

	//== CDS Timing ============================================================================================================
	// Rom retreive address was changed from 0x70003880 to 0x7000 3C00. 
	//2009.03.16

	{0x00, 0x28, 0x70, 0x00},  

	//value       register                                     decription.  
	//700017CC    senHal_ContPtrs_senModesDataArr[0]           nomal speed, normal
	//700017D0    senHal_ContPtrs_senModesDataArr[1]           nomal speed, avg mode
	//700017D4    senHal_ContPtrs_senModesDataArr[2]           nomal speed, weighted mode
	//700017D8    senHal_ContPtrs_senHighSpeedModesDataArr[0]  high speed, normal       
	//700017DC    senHal_ContPtrs_senHighSpeedModesDataArr[1]  high speed, avg mode   
	//700017E0    senHal_ContPtrs_senHighSpeedModesDataArr[2]  high speed, weighted mode  

	//HS_Normal        
	{0x00, 0x2A, 0x17, 0xD8},	// High speed Normal/Dig-subsampling         
	{0x0F, 0x12, 0x3C, 0x00},	// senHal_ContPtrs_senModesDataArr         
	{0x0F, 0x12, 0x70, 0x00},	// senHal_ContPtrs_senModesDataArr   

	//1.15fps@92MHz,HS,Normal //2.15fps@92MHz,LS,Normal 
	//3.15fps@92MHz,HS,avg    //4.15fps@92MHz,LS,avg   

	//1.                                                                     
	{0x00, 0x2A, 0x3C, 0x00},    //1.    //2.    //3.    //4.  
	{0x0F, 0x12, 0x00, 0x03},    //0003  //0003  //0003  //0003
	{0x0F, 0x12, 0x05, 0xBA},	  //05BA  //098A  //081E  //0B92
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x05, 0xBC},	  //05BC  //098C  //0414  //05CE
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //040F  //05C9
	{0x0F, 0x12, 0x05, 0xBC},	  //05BC  //098C  //0820  //0B94
	{0x0F, 0x12, 0x00, 0x14},	  //0014  //0014  //0014  //0014
	{0x0F, 0x12, 0x05, 0xBC},	  //05BC  //098C  //040F  //05C9
	{0x0F, 0x12, 0x00, 0x14},	  //0014  //0014  //0422  //05DC
	{0x0F, 0x12, 0x05, 0xBC},	  //05BC  //098C  //0820  //0B94
	{0x0F, 0x12, 0x01, 0xAE},	  //01AE  //0286  //0146  //01B6
	{0x0F, 0x12, 0x02, 0x38},	  //0238  //0310  //01D0  //0240
	{0x0F, 0x12, 0x01, 0xAE},	  //01AE  //0286  //0554  //077E
	{0x0F, 0x12, 0x02, 0x38},	  //0238  //0310  //05DE  //0808
	{0x0F, 0x12, 0x02, 0x38},	  //0238  //0310  //01D0  //0240
	{0x0F, 0x12, 0x05, 0xBA},	  //05BA  //098A  //0410  //05CA
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //05DE  //0808
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //081E  //0B92
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x01, 0xAC},	  //01AC  //0284  //0144  //01B4
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0414  //05CE
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0552  //077C
	{0x0F, 0x12, 0x01, 0xAC},	  //01AC  //0284  //0144  //01B4
	{0x0F, 0x12, 0x02, 0x40},	  //0240  //0318  //01D8  //0248
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0552  //077C
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //05E6  //0810
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x00, 0x8C},	  //008C  //008C  //008C  //008C
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //040F  //05C9
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //049A  //0654
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x00, 0x9E},	  //009E  //009E  //009E  //009E
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //040F  //05C9
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //04AC  //0666
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x01, 0xAC},	  //01AC  //0284  //0144  //01B4
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //040F  //05C9
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0552  //077C
	{0x0F, 0x12, 0x00, 0xA6},	  //00A6  //00A6  //00A6  //00A6
	{0x0F, 0x12, 0x05, 0xBA},	  //05BA  //098A  //0410  //05CA
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //04B4  //066E
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //081E  //0B92
	{0x0F, 0x12, 0x02, 0x92},	  //0292  //036A  //022A  //029A
	{0x0F, 0x12, 0x05, 0xBA},	  //05BA  //098A  //0410  //05CA
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0638  //0862
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //081E  //0B92
	{0x0F, 0x12, 0x00, 0xD8},	  //00D8  //00D8  //00D8  //00D8
	{0x0F, 0x12, 0x01, 0xA8},	  //01A8  //0278  //0140  //01A8
	{0x0F, 0x12, 0x02, 0xC4},	  //02C4  //039C  //0292  //02CC
	{0x0F, 0x12, 0x05, 0xB4},	  //05B4  //097C  //040A  //05BC
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //04E6  //06A0
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //054E  //0770
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //06A0  //0894
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0818  //0B84
	{0x0F, 0x12, 0x01, 0xAA},	  //01AA  //0282  //0142  //01B2
	{0x0F, 0x12, 0x01, 0xD6},	  //01D6  //02AE  //016E  //01DE
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //040C  //05C6
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0438  //05F2
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0550  //077A
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //057C  //07A6
	{0x0F, 0x12, 0x01, 0xBB},	  //01BB  //0293  //014D  //01BD
	{0x0F, 0x12, 0x01, 0xEF},	  //01EF  //02C7  //0182  //01F2
	{0x0F, 0x12, 0x01, 0xF9},	  //01F9  //02D1  //018C  //01FC
	{0x0F, 0x12, 0x02, 0x03},	  //0203  //02DB  //0196  //0206
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0417  //05D1
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //044C  //0606
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0456  //0610
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0460  //061A
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //055B  //0785
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0590  //07BA
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //059A  //07C4
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //05A4  //07CE
	{0x0F, 0x12, 0x01, 0xCC},	  //01CC  //02A4  //0158  //01C8
	{0x0F, 0x12, 0x01, 0xEF},	  //01EF  //02C7  //0182  //01F2
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0422  //05DC
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //044C  //0606
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0566  //0790
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0590  //07BA
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x00, 0x0D},	  //000D  //000D  //000D  //000D
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x00, 0x0D},	  //000D  //000D  //000D  //000D
	{0x0F, 0x12, 0x01, 0xAE},	  //01AE  //0286  //0146  //01B6
	{0x0F, 0x12, 0x01, 0xB6},	  //01B6  //028E  //014E  //01BE
	{0x0F, 0x12, 0x05, 0xBA},	  //05BA  //098A  //0410  //05CA
	{0x0F, 0x12, 0x05, 0xC6},	  //05C6  //0996  //0418  //05D2
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0554  //077E
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //055C  //0786
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //081E  //0B92
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //082A  //0B9E
	{0x0F, 0x12, 0x00, 0xD4},	  //00D4  //00D4  //00D4  //00D4
	{0x0F, 0x12, 0x01, 0xAC},	  //01AC  //0284  //0144  //01B4
	{0x0F, 0x12, 0x02, 0xC0},	  //02C0  //0398  //028E  //02C8
	{0x0F, 0x12, 0x05, 0xB8},	  //05B8  //0988  //040E  //05C8
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //04E2  //069C
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0552  //077C
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //069C  //0890
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //081C  //0B90
	{0x0F, 0x12, 0x01, 0xAE},	  //01AE  //0286  //0146  //01B6
	{0x0F, 0x12, 0x05, 0xC9},	  //05C9  //0A7C  //0410  //05CA
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0554  //077E
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0830  //0BA4
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000

	//HS_avg
	{0x00, 0x2A, 0x17, 0xDC},	// High speed Normal/Dig-subsampling         
	{0x0F, 0x12, 0x3C, 0xE0},	// senHal_ContPtrs_senModesDataArr         
	{0x0F, 0x12, 0x70, 0x00},	// senHal_ContPtrs_senModesDataArr   

	//1.15fps@92MHz,HS,Normal //2.15fps@92MHz,LS,Normal 
	//3.15fps@92MHz,HS,avg    //4.15fps@92MHz,LS,avg   

	//1.                                                                     
	{0x00, 0x2A, 0x3C, 0xE0},    //1.    //2.    //3.    //4.  
	{0x0F, 0x12, 0x00, 0x03},    //0003  //0003  //0003  //0003
	{0x0F, 0x12, 0x08, 0x1E},	  //05BA  //098A  //081E  //0B92
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x04, 0x14},	  //05BC  //098C  //0414  //05CE
	{0x0F, 0x12, 0x04, 0x0F},	  //0001  //0001  //040F  //05C9
	{0x0F, 0x12, 0x08, 0x20},	  //05BC  //098C  //0820  //0B94
	{0x0F, 0x12, 0x00, 0x14},	  //0014  //0014  //0014  //0014
	{0x0F, 0x12, 0x04, 0x0F},	  //05BC  //098C  //040F  //05C9
	{0x0F, 0x12, 0x04, 0x22},	  //0014  //0014  //0422  //05DC
	{0x0F, 0x12, 0x08, 0x20},	  //05BC  //098C  //0820  //0B94
	{0x0F, 0x12, 0x01, 0x46},	  //01AE  //0286  //0146  //01B6
	{0x0F, 0x12, 0x01, 0xD0},	  //0238  //0310  //01D0  //0240
	{0x0F, 0x12, 0x05, 0x54},	  //01AE  //0286  //0554  //077E
	{0x0F, 0x12, 0x05, 0xDE},	  //0238  //0310  //05DE  //0808
	{0x0F, 0x12, 0x01, 0xD0},	  //0238  //0310  //01D0  //0240
	{0x0F, 0x12, 0x04, 0x10},	  //05BA  //098A  //0410  //05CA
	{0x0F, 0x12, 0x05, 0xDE},	  //0000  //0000  //05DE  //0808
	{0x0F, 0x12, 0x08, 0x1E},	  //0000  //0000  //081E  //0B92
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x01, 0x44},	  //01AC  //0284  //0144  //01B4
	{0x0F, 0x12, 0x04, 0x14},	  //0000  //0000  //0414  //05CE
	{0x0F, 0x12, 0x05, 0x52},	  //0000  //0000  //0552  //077C
	{0x0F, 0x12, 0x01, 0x44},	  //01AC  //0284  //0144  //01B4
	{0x0F, 0x12, 0x01, 0xD8},	  //0240  //0318  //01D8  //0248
	{0x0F, 0x12, 0x05, 0x52},	  //0000  //0000  //0552  //077C
	{0x0F, 0x12, 0x05, 0xE6},	  //0000  //0000  //05E6  //0810
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x00, 0x8C},	  //008C  //008C  //008C  //008C
	{0x0F, 0x12, 0x04, 0x0F},	  //0000  //0000  //040F  //05C9
	{0x0F, 0x12, 0x04, 0x9A},	  //0000  //0000  //049A  //0654
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x00, 0x9E},	  //009E  //009E  //009E  //009E
	{0x0F, 0x12, 0x04, 0x0F},	  //0000  //0000  //040F  //05C9
	{0x0F, 0x12, 0x04, 0xAC},	  //0000  //0000  //04AC  //0666
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x01, 0x44},	  //01AC  //0284  //0144  //01B4
	{0x0F, 0x12, 0x04, 0x0F},	  //0000  //0000  //040F  //05C9
	{0x0F, 0x12, 0x05, 0x52},	  //0000  //0000  //0552  //077C
	{0x0F, 0x12, 0x00, 0xA6},	  //00A6  //00A6  //00A6  //00A6
	{0x0F, 0x12, 0x04, 0x10},	  //05BA  //098A  //0410  //05CA
	{0x0F, 0x12, 0x04, 0xB4},	  //0000  //0000  //04B4  //066E
	{0x0F, 0x12, 0x08, 0x1E},	  //0000  //0000  //081E  //0B92
	{0x0F, 0x12, 0x02, 0x2A},	  //0292  //036A  //022A  //029A
	{0x0F, 0x12, 0x04, 0x10},	  //05BA  //098A  //0410  //05CA
	{0x0F, 0x12, 0x06, 0x38},	  //0000  //0000  //0638  //0862
	{0x0F, 0x12, 0x08, 0x1E},	  //0000  //0000  //081E  //0B92
	{0x0F, 0x12, 0x00, 0xD8},	  //00D8  //00D8  //00D8  //00D8
	{0x0F, 0x12, 0x01, 0x40},	  //01A8  //0278  //0140  //01A8
	{0x0F, 0x12, 0x02, 0x92},	  //02C4  //039C  //0292  //02CC
	{0x0F, 0x12, 0x04, 0x0A},	  //05B4  //097C  //040A  //05BC
	{0x0F, 0x12, 0x04, 0xE6},	  //0000  //0000  //04E6  //06A0
	{0x0F, 0x12, 0x05, 0x4E},	  //0000  //0000  //054E  //0770
	{0x0F, 0x12, 0x06, 0xA0},	  //0000  //0000  //06A0  //0894
	{0x0F, 0x12, 0x08, 0x18},	  //0000  //0000  //0818  //0B84
	{0x0F, 0x12, 0x01, 0x42},	  //01AA  //0282  //0142  //01B2
	{0x0F, 0x12, 0x01, 0x6E},	  //01D6  //02AE  //016E  //01DE
	{0x0F, 0x12, 0x04, 0x0C},	  //0000  //0000  //040C  //05C6
	{0x0F, 0x12, 0x04, 0x38},	  //0000  //0000  //0438  //05F2
	{0x0F, 0x12, 0x05, 0x50},	  //0000  //0000  //0550  //077A
	{0x0F, 0x12, 0x05, 0x7C},	  //0000  //0000  //057C  //07A6
	{0x0F, 0x12, 0x01, 0x4D},	  //01BB  //0293  //014D  //01BD
	{0x0F, 0x12, 0x01, 0x82},	  //01EF  //02C7  //0182  //01F2
	{0x0F, 0x12, 0x01, 0x8C},	  //01F9  //02D1  //018C  //01FC
	{0x0F, 0x12, 0x01, 0x96},	  //0203  //02DB  //0196  //0206
	{0x0F, 0x12, 0x04, 0x17},	  //0000  //0000  //0417  //05D1
	{0x0F, 0x12, 0x04, 0x4C},	  //0000  //0000  //044C  //0606
	{0x0F, 0x12, 0x04, 0x56},	  //0000  //0000  //0456  //0610
	{0x0F, 0x12, 0x04, 0x60},	  //0000  //0000  //0460  //061A
	{0x0F, 0x12, 0x05, 0x5B},	  //0000  //0000  //055B  //0785
	{0x0F, 0x12, 0x05, 0x90},	  //0000  //0000  //0590  //07BA
	{0x0F, 0x12, 0x05, 0x9A},	  //0000  //0000  //059A  //07C4
	{0x0F, 0x12, 0x05, 0xA4},	  //0000  //0000  //05A4  //07CE
	{0x0F, 0x12, 0x01, 0x58},	  //01CC  //02A4  //0158  //01C8
	{0x0F, 0x12, 0x01, 0x82},	  //01EF  //02C7  //0182  //01F2
	{0x0F, 0x12, 0x04, 0x22},	  //0000  //0000  //0422  //05DC
	{0x0F, 0x12, 0x04, 0x4C},	  //0000  //0000  //044C  //0606
	{0x0F, 0x12, 0x05, 0x66},	  //0000  //0000  //0566  //0790
	{0x0F, 0x12, 0x05, 0x90},	  //0000  //0000  //0590  //07BA
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x00, 0x0D},	  //000D  //000D  //000D  //000D
	{0x0F, 0x12, 0x00, 0x01},	  //0001  //0001  //0001  //0001
	{0x0F, 0x12, 0x00, 0x0D},	  //000D  //000D  //000D  //000D
	{0x0F, 0x12, 0x01, 0x46},	  //01AE  //0286  //0146  //01B6
	{0x0F, 0x12, 0x01, 0x4E},	  //01B6  //028E  //014E  //01BE
	{0x0F, 0x12, 0x04, 0x10},	  //05BA  //098A  //0410  //05CA
	{0x0F, 0x12, 0x04, 0x18},	  //05C6  //0996  //0418  //05D2
	{0x0F, 0x12, 0x05, 0x54},	  //0000  //0000  //0554  //077E
	{0x0F, 0x12, 0x05, 0x5C},	  //0000  //0000  //055C  //0786
	{0x0F, 0x12, 0x08, 0x1E},	  //0000  //0000  //081E  //0B92
	{0x0F, 0x12, 0x08, 0x2A},	  //0000  //0000  //082A  //0B9E
	{0x0F, 0x12, 0x00, 0xD4},	  //00D4  //00D4  //00D4  //00D4
	{0x0F, 0x12, 0x01, 0x44},	  //01AC  //0284  //0144  //01B4
	{0x0F, 0x12, 0x02, 0x8E},	  //02C0  //0398  //028E  //02C8
	{0x0F, 0x12, 0x04, 0x0E},	  //05B8  //0988  //040E  //05C8
	{0x0F, 0x12, 0x04, 0xE2},	  //0000  //0000  //04E2  //069C
	{0x0F, 0x12, 0x05, 0x52},	  //0000  //0000  //0552  //077C
	{0x0F, 0x12, 0x06, 0x9C},	  //0000  //0000  //069C  //0890
	{0x0F, 0x12, 0x08, 0x1C},	  //0000  //0000  //081C  //0B90
	{0x0F, 0x12, 0x01, 0x46},	  //01AE  //0286  //0146  //01B6
	{0x0F, 0x12, 0x04, 0x10},	  //05C9  //0A7C  //0410  //05CA
	{0x0F, 0x12, 0x05, 0x54},	  //0000  //0000  //0554  //077E
	{0x0F, 0x12, 0x08, 0x30},	  //0000  //0000  //0830  //0BA4
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000
	{0x0F, 0x12, 0x00, 0x00},	  //0000  //0000  //0000  //0000

	{REG_DELAY, 100, 0, 0},	// p100

	//Current(00:2mA,01:4mA,10:6mA,11:8mA)
	{0x00, 0x28, 0xD0, 0x00},
	{0x00, 0x2A, 0x10, 0x82},	
	{0x0F, 0x12, 0x01, 0x55},	//FFFF	//D0_D4_cs12 [11:0]
	{0x0F, 0x12, 0x01, 0x55},	//FFFF	//D0_D4_cs12 [11:0]
	{0x00, 0x2A, 0x10, 0x88},	
	{0x0F, 0x12, 0x05, 0x55},	//05CF	//0555 //Sda_cd10	Scl_cd10	PCLK_cd10	Reserved	Vsync_cd10	Hsync_cd10

	{REG_DELAY, 100, 0, 0},	// p100

	// End Analog script

	//////////////////////////////////////////////////////////////////
	// Start Tuning param for EVT1
	//////////////////////////////////////////////////////////////////

	/////////////////////// AF Setting Start
	// AF Interface Settings
	{0x00, 0x28, 0x70, 0x00},
	{0x00, 0x2A, 0x02, 0x3E},	
	{0x0F, 0x12, 0x00, 0x03},	// AFModeType - 0:NONE, 2:VCM_PWM, 3:VCM_I2C
	{0x00, 0x2A, 0x02, 0x3C},	
	{0x0F, 0x12, 0x00, 0x00},	// No Led Gpio
	{0x00, 0x2A, 0x02, 0x40},	
	{0x0F, 0x12, 0x00, 0x00},	// No PWM
	{0x00, 0x2A, 0x02, 0x42},	
	{0x0F, 0x12, 0x00, 0x00},
	{0x00, 0x2A, 0x02, 0x44},	
	{0x0F, 0x12, 0x00, 0x31},	// No GPIO Port,	31	// Use GPIO3 for Enable Port
	{0x00, 0x2A, 0x02, 0x46},	
	{0x0F, 0x12, 0x00, 0x00},
	{0x00, 0x2A, 0x02, 0x4C},	
	{0x0F, 0x12, 0x20, 0x0C},	// Use GPIO1 for SCL, GPIO2 for SDA
	{0x00, 0x2A, 0x02, 0x4E},	
	{0x0F, 0x12, 0x03, 0x20},	//0C0 //0190	//0320	// MI2C Speed : 400KHz

	// AF Window Settings
	{0x00, 0x2A, 0x02, 0xC6},
	{0x0F, 0x12, 0x01, 0x00},
	{0x00, 0x2A, 0x02, 0xC8},	
	{0x0F, 0x12, 0x00, 0xE3},
	{0x00, 0x2A, 0x02, 0xCA},	
	{0x0F, 0x12, 0x02, 0x00},
	{0x00, 0x2A, 0x02, 0xCC},	
	{0x0F, 0x12, 0x02, 0x38},
	{0x00, 0x2A, 0x02, 0xCE},	
	{0x0F, 0x12, 0x01, 0x8C},
	{0x00, 0x2A, 0x02, 0xD0},	
	{0x0F, 0x12, 0x01, 0x66},
	{0x00, 0x2A, 0x02, 0xD2},	
	{0x0F, 0x12, 0x00, 0xE6},
	{0x00, 0x2A, 0x02, 0xD4},	
	{0x0F, 0x12, 0x01, 0x32},
	{0x00, 0x2A, 0x02, 0xD6},	
	{0x0F, 0x12, 0x00, 0x01},

	// AF Setot Settings
	{0x00, 0x2A, 0x06, 0xBE},	
	{0x0F, 0x12, 0x00, 0xFF},

	// AF Scene Settings
	{0x00, 0x2A, 0x15, 0xDA},	
	{0x0F, 0x12, 0x00, 0x03},

	// AF Fine Search Settings
	{0x00, 0x2A, 0x15, 0x50},	
	{0x0F, 0x12, 0x10, 0x02},
	{0x00, 0x2A, 0x15, 0x5A},	
	{0x0F, 0x12, 0x00, 0x04},
	{0x00, 0x2A, 0x14, 0xE8},	
	{0x0F, 0x12, 0x03, 0x02},


	// AF Lens Position Table Settings
	{0x00, 0x2A, 0x14, 0xF0},	
	{0x0F, 0x12, 0x00, 0x11},	// 18 Steps	
	{0x0f, 0x12, 0x00, 0x36},	// af_pos_usTable
	{0x0F, 0x12, 0x00, 0x3D},	
	{0x0F, 0x12, 0x00, 0x44},	
	{0x0F, 0x12, 0x00, 0x4B},
	{0x0F, 0x12, 0x00, 0x52},	
	{0x0F, 0x12, 0x00, 0x59},
	{0x0F, 0x12, 0x00, 0x60},
	{0x0F, 0x12, 0x00, 0x67},	
	{0x0F, 0x12, 0x00, 0x6E},
	{0x0F, 0x12, 0x00, 0x75},
	{0x0F, 0x12, 0x00, 0x7C},
	{0x0F, 0x12, 0x00, 0x83},
	{0x0F, 0x12, 0x00, 0x8A},
	{0x0F, 0x12, 0x00, 0x91},
	{0x0F, 0x12, 0x00, 0x98},
	{0x0F, 0x12, 0x00, 0x9F},
	{0x0F, 0x12, 0x00, 0xA6},
	{0x0F, 0x12, 0x00, 0xAD},

	// AF Macro Position Setting
	{0x00, 0x2A, 0x14, 0xE2},	
	{0x0F, 0x12, 0x11, 0x04},

	/////////////////////// AF Setting End

	/////////////////////////////////////////Jpeg/////////////
	{0x00, 0x2A, 0x16, 0x90},
	{0x0F, 0x12, 0x01, 0x8E},	//jpeg_BrcMaxQuality
	{0x00, 0x2A, 0x16, 0xD6},
	{0x0F, 0x12, 0x00, 0x01},	//jpeg_MinQtblValue
	{0x00, 0x2A, 0x04, 0xC0},
	{0x0F, 0x12, 0x00, 0x5D},	//005F //005D //4EA_REG_TC_BRC_usCaptureQuality(4~99_dec)

	///////////////////////////////////////////
};

unsigned short s5k4ea_init_reg2[][2] = {
	//clk Settings
	{0x002A, S5K4EA_REG_TC_IPRM_InClockLSBs},	//input=24MHz
	{0x0F12, 0x5DC0},
	{0x002A, S5K4EA_REG_TC_IPRM_InClockMSBs},
	{0x0F12, 0x0000},
	{0x002A, S5K4EA_REG_TC_IPRM_UseNPviClocks},	//0 PVI configurations
	{0x0F12, 0x0000},
	{0x002A, S5K4EA_REG_TC_IPRM_UseNMipiClocks},	// 1 MIPI configurations
	{0x0F12, 0x0001},
	{0x002A, S5K4EA_REG_TC_IPRM_NumberOfMipiLanes},	// Num of lane MIPI 
	{0x0F12, 2},
	{0x002A, S5K4EA_REG_TC_IPRM_OpClk4KHz_0},	// 1st system CLK 92MHz for parallel
	{0x0F12, S5K4EA4Khz_92Mhz},	// 2CEC
	{0x002A, S5K4EA_REG_TC_IPRM_MinOutRate4KHz_0}, 	// Pclk : 92Mhz
	{0x0F12, S5K4EA_PCLK_MIN},
	{0x002A, S5K4EA_REG_TC_IPRM_MaxOutRate4KHz_0},
	{0x0F12, S5K4EA_PCLK_MAX},
	{0x002A, S5K4EA_REG_TC_IPRM_InitParamsUpdated},
	{0x0F12, 0x0001},
	{REG_DELAY, 100},	// p100
};

unsigned char s5k4ea_init_reg3[][4] = {
	//////////////////////////////////////////////AE Setting
	{0x00, 0x2A, 0x13, 0xC8},                                                                        
	{0x0F, 0x12, 0x00, 0x30},	//3C	//002D	//003C //003A //0030	//003A	//0038	//003C 0035	TVAR_ae_BrAve	  AE target	//
	{0x00, 0x2A, 0x13, 0xCE},
	{0x0F, 0x12, 0x00, 0x0F}, //0011  ae_StatMode
	{0x00, 0x2A, 0x05, 0x90},
	{0x0F, 0x12, 0x35, 0x20},	//lt_uMaxExp1 (x4 8000/ 80ms)
	{0x0F, 0x12, 0x00, 0x00},
	{0x00, 0x2A, 0x05, 0x94},
	{0x0F, 0x12, 0xC3, 0x50},  
	{0x0F, 0x12, 0x00, 0x00},	//lt_uMaxExp2 (x4 25000/ 250ms)
	{0x00, 0x2A, 0x05, 0x98},
	{0x0F, 0x12, 0x35, 0x20},	
	{0x0F, 0x12, 0x00, 0x00},	//lt_uCapMaxExp1 (x4 8000/ 80ms)
	{0x00, 0x2A, 0x05, 0x9C},
	{0x0F, 0x12, 0xC3, 0x50}, 	//C350	//86A0	
	{0x0F, 0x12, 0x00, 0x00},	//lt_uCapMaxExp2 (x4 25000/ 250ms)
	{0x00, 0x2A, 0x05, 0xA0},
	{0x0F, 0x12, 0x04, 0x70},	//(1/12) //0350 (1/8) //0200	//lt_uMaxAnGain1
	{0x00, 0x2A, 0x05, 0xA2},
	{0x0F, 0x12, 0x10, 0x00},	//lt_uMaxAnGain2
	{0x00, 0x2A, 0x05, 0xA4},
	{0x0F, 0x12, 0x01, 0x00},	
	{0x00, 0x2A, 0x05, 0xA6},
	{0x0F, 0x12, 0x10, 0x00},	//lt_uMaxTotGain (Limit Gain)
	    	
	{0x00, 0x2A, 0x05, 0x74},
	{0x0F, 0x12, 0x01, 0x11},	//lt_uLimitHigh
	{0x00, 0x2A, 0x05, 0x76},
	{0x0F, 0x12, 0x00, 0xEF},	//lt_uLimitLow
};

unsigned short s5k4ea_init_reg4[][2] = {
	///////////////////////////////////////////
	//PREVIEW CONFIGURATION 0 (FullHD, YUV, 20fps)
	{0x002A, S5K4EA_REG_0TC_PCFG_usWidth},
	{0x0F12, 1920},	//1920    			
	{0x0F12, 1080},	//1080
	{0x002A, 0x02E6},
};

unsigned char s5k4ea_init_reg5[][4] = {
	{0x0F, 0x12, 0x00, 0x05},	//YUV	
	{0x00, 0x2A, 0x02, 0xF8}, 	//PLL config
	{0x0F, 0x12, 0x00, 0x00},
	{0x00, 0x2A, 0x02, 0xE8},	//PCLK max
};

unsigned short s5k4ea_init_reg6[][2] = {
	{0x0F12, S5K4EA_PCLK_MAX},
};

unsigned char s5k4ea_init_reg7[][4] = {
	{0x00, 0x2A, 0x02, 0xEA},	//PCLK min
};

unsigned short s5k4ea_init_reg8[][2] = {
	{0x0F12, S5K4EA_PCLK_MIN},
};

unsigned char s5k4ea_init_reg9[][4] = {
	{0x00, 0x2A, 0x02, 0xF0},	// KJ_090802 : Non-continuous clock
	{0x0F, 0x12, 0x00, 0x12},  // [4]UY0VY1	//0002
	{0x00, 0x2A, 0x02, 0xFC},	// 1b: FR (bin) 2b: Quality (no-bin)
	{0x0F, 0x12, 0x00, 0x00},
	{0x00, 0x2A, 0x02, 0xFA},
	{0x0F, 0x12, 0x00, 0x02},
	{0x00, 0x2A, 0x02, 0xFE},	//max frame time 
	{0x0F, 0x12, 0x05, 0x35},// 7.5fps	
	{0x00, 0x2A, 0x03, 0x00},
	{0x0F, 0x12, 0x00, 0x00},

	{REG_DELAY, 100, 0, 0},	// p100

	//002A	17A0
	//0F12	0000						// [0]:dig [1]:avg
	//002A 	17A2		// 1/2 sub-sampling
	//0F12 	0002
	{0x00, 0x2A, 0x05, 0x40},	// use high speed analog
	{0x0F, 0x12, 0x00, 0x01},
	{0x00, 0x2A, 0x05, 0x3A},
	{0x0F, 0x12, 0x00, 0x01},
	//002A	17B2			// 17B2 	
	//0F12	0549 			//
	//002A	17B6 			// 17B6
	//0F12	0549 			//
	//002A	17BA			// 17BA 	//
	//0F12	005B 			//

	//For C100 -  jpeg output data  type control 0028	 D000 002A	B032  0F12	 002A
	// JPEG data type (RAW8 type)

	{0x00, 0x28, 0x70, 0x00},

	///////////////////////////////////////////////
	// Capture Configuration	0	(2592x1944,  MJPEG, 15fps)
	{0x00, 0x2A, 0x03, 0xD6},
	{0x0F, 0x12, 0x0A, 0x20},        			//2592
	{0x00, 0x2A, 0x03, 0xD8},
	{0x0F, 0x12, 0x07, 0x98},        			//1944
	{0x00, 0x2A, 0x03, 0xDA},
	{0x0F, 0x12, 0x00, 0x09},			        //YUV
	{0x00, 0x2A, 0x03, 0xEC}, 	//PLL config
	{0x0F, 0x12, 0x00, 0x00},
	{0x00, 0x2A, 0x03, 0xDC},	//PCLK max
	{0x0F, 0x12, 0x5A, 0xD2},
	{0x00, 0x2A, 0x03, 0xDE},	//PCLK min
	{0x0F, 0x12, 0x58, 0xDE},
	{0x00, 0x2A, 0x03, 0xE4},
	{0x0F, 0x12, 0x00, 0x42},
	{0x00, 0x2A, 0x03, 0xF0},	// 1b: FR (bin) 2b: Quality (no-bin)
	{0x0F, 0x12, 0x00, 0x02},
	{0x00, 0x2A, 0x03, 0xEE},
	{0x0F, 0x12, 0x00, 0x02},
	{0x00, 0x2A, 0x03, 0xF2},	//max frame time : 15fps 029a
	{0x0F, 0x12, 0x05, 0x35}, // 7.5 fps
	{0x00, 0x2A, 0x03, 0xF4},
	{0x0F, 0x12, 0x00, 0x00},

	////////////////////////////////////////////////////////
	//PREVIEW
	{0x00, 0x2A, 0x02, 0xA4},
	{0x0F, 0x12, 0x00, 0x00},

	{0x00, 0x2A, 0x02, 0xA8},
	{0x0F, 0x12, 0x00, 0x01},

	{0x00, 0x2A, 0x02, 0x90},
	{0x0F, 0x12, 0x00, 0x01},

	{0x00, 0x2A, 0x02, 0xA6},
	{0x0F, 0x12, 0x00, 0x01},

	{0x00, 0x2A, 0x02, 0x80},
	{0x0F, 0x12, 0x00, 0x01},

	{0x00, 0x2A, 0x02, 0x82},
	{0x0F, 0x12, 0x00, 0x01},

	//////////////////////////////////////////////////////////////

	{0x00, 0x2A, 0x02, 0x92},
	{0x0F, 0x12, 0x07, 0x80},	//input width 
	{0x0F, 0x12, 0x04, 0x38}, 	//input height
	{0x0F, 0x12, 0x01, 0x50},	//input w-offset
	{0x0F, 0x12, 0x01, 0xB0},	//input h-offset

	{0x00, 0x2A, 0x04, 0xDA},	
	{0x0F, 0x12, 0x07, 0x80},	//crop width 
	{0x0F, 0x12, 0x04, 0x38}, 	//crop height
	//0F12	0150	//w-offset
	//0F12	01B0	//h-offset

	{0x00, 0x2A, 0x02, 0xA2},	//4EA_REG_TC_GP_InputsChangeRequest
	{0x0F, 0x12, 0x00, 0x01},
	{0x00, 0x2A, 0x02, 0x90},	//4EA_REG_TC_GP_NewConfigSync
	{0x0F, 0x12, 0x00, 0x01},	

	{REG_DELAY, 200, 0, 0},	// p200
};

unsigned short s5k4ea_init_reg10[][2] = {
	{0x002A, S5K4EA_REG_0TC_PCFG_usMaxFrTimeMsecMult10},	//max frame time 
	{0x0F12, S5K4EA_FrTime_MAX},	//30fps	
};

unsigned char s5k4ea_init_reg11[][4] = {
	////////////////////////////////////////////////////////
	//PREVIEW
	{0x00, 0x2A, 0x02, 0xA4},
	{0x0F, 0x12, 0x00, 0x00},

	{0x00, 0x2A, 0x02, 0xA8},
	{0x0F, 0x12, 0x00, 0x01},

	{0x00, 0x2A, 0x02, 0x90},
	{0x0F, 0x12, 0x00, 0x01},

	{0x00, 0x2A, 0x02, 0xA6},
	{0x0F, 0x12, 0x00, 0x01},

	{0x00, 0x2A, 0x02, 0x80},
	{0x0F, 0x12, 0x00, 0x01},

	{0x00, 0x2A, 0x02, 0x82},
	{0x0F, 0x12, 0x00, 0x01},

	//////////////////////////////////////////////////////////////

	// AF CMD
	{0x00, 0x2A, 0x02, 0xBE},	//#4EA_REG_TC_AF	
	{0x0F, 0x12, 0x00, 0x03},	//4EA_REG_TC_AF_AfCmd

	{REG_DELAY, 200, 0, 0},	// p300

	{0x00, 0x2A, 0x02, 0xBE},	//#4EA_REG_TC_AF	
	{0x0F, 0x12, 0x00, 0x05},	//5:single AF, 6:continus AF
};

#define S5K4EA_INIT_REGS1	(sizeof(s5k4ea_init_reg1) / sizeof(s5k4ea_init_reg1[0]))
#define S5K4EA_INIT_REGS2	(sizeof(s5k4ea_init_reg2) / sizeof(s5k4ea_init_reg2[0]))
#define S5K4EA_INIT_REGS3	(sizeof(s5k4ea_init_reg3) / sizeof(s5k4ea_init_reg3[0]))
#define S5K4EA_INIT_REGS4	(sizeof(s5k4ea_init_reg4) / sizeof(s5k4ea_init_reg4[0]))
#define S5K4EA_INIT_REGS5	(sizeof(s5k4ea_init_reg5) / sizeof(s5k4ea_init_reg5[0]))
#define S5K4EA_INIT_REGS6	(sizeof(s5k4ea_init_reg6) / sizeof(s5k4ea_init_reg6[0]))
#define S5K4EA_INIT_REGS7	(sizeof(s5k4ea_init_reg7) / sizeof(s5k4ea_init_reg7[0]))
#define S5K4EA_INIT_REGS8	(sizeof(s5k4ea_init_reg8) / sizeof(s5k4ea_init_reg8[0]))
#define S5K4EA_INIT_REGS9	(sizeof(s5k4ea_init_reg9) / sizeof(s5k4ea_init_reg9[0]))
#define S5K4EA_INIT_REGS10	(sizeof(s5k4ea_init_reg10) / sizeof(s5k4ea_init_reg10[0]))
#define S5K4EA_INIT_REGS11	(sizeof(s5k4ea_init_reg11) / sizeof(s5k4ea_init_reg11[0]))

unsigned short s5k4ea_sleep_reg[][2] = {
	{0x002A, S5K4EA_REG_TC_GP_EnablePreview},
	{0x0F12, 0x0000},
	{0x002A, S5K4EA_REG_TC_GP_EnablePreviewChanged},
	{0x0F12, 0x0001},
	{REG_DELAY, 100},
};

#define S5K4EA_SLEEP_REGS	(sizeof(s5k4ea_sleep_reg) / sizeof(s5k4ea_sleep_reg[0]))

unsigned short s5k4ea_wakeup_reg[][2] = {
	{0x002A, 0x02F0},
	{0x0F12, 0x0052},
	{0x002A, S5K4EA_REG_TC_GP_PrevConfigChanged},
	{0x0F12, 0x0001},
};

#define S5K4EA_WAKEUP_REGS	(sizeof(s5k4ea_wakeup_reg) / sizeof(s5k4ea_wakeup_reg[0]))

/* Preview configuration preset #1 */
/* Preview configuration preset #2 */
/* Preview configuration preset #3 */
/* Preview configuration preset #4 */

/* Capture configuration preset #0 */
/* Capture configuration preset #1 */
/* Capture configuration preset #2 */
/* Capture configuration preset #3 */
/* Capture configuration preset #4 */

/*
 * EV bias
 */

static const struct s5k4ea_reg s5k4ea_ev_m6[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_m5[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_m4[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_m3[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_m2[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_m1[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_default[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_p1[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_p2[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_p3[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_p4[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_p5[] = {
};

static const struct s5k4ea_reg s5k4ea_ev_p6[] = {
};

#ifdef S5K4EA_COMPLETE
/* Order of this array should be following the querymenu data */
static const unsigned char *s5k4ea_regs_ev_bias[] = {
	(unsigned char *)s5k4ea_ev_m6, (unsigned char *)s5k4ea_ev_m5,
	(unsigned char *)s5k4ea_ev_m4, (unsigned char *)s5k4ea_ev_m3,
	(unsigned char *)s5k4ea_ev_m2, (unsigned char *)s5k4ea_ev_m1,
	(unsigned char *)s5k4ea_ev_default, (unsigned char *)s5k4ea_ev_p1,
	(unsigned char *)s5k4ea_ev_p2, (unsigned char *)s5k4ea_ev_p3,
	(unsigned char *)s5k4ea_ev_p4, (unsigned char *)s5k4ea_ev_p5,
	(unsigned char *)s5k4ea_ev_p6,
};

/*
 * Auto White Balance configure
 */
static const struct s5k4ea_reg s5k4ea_awb_off[] = {
};

static const struct s5k4ea_reg s5k4ea_awb_on[] = {
};

static const unsigned char *s5k4ea_regs_awb_enable[] = {
	(unsigned char *)s5k4ea_awb_off,
	(unsigned char *)s5k4ea_awb_on,
};

/*
 * Manual White Balance (presets)
 */
static const struct s5k4ea_reg s5k4ea_wb_tungsten[] = {

};

static const struct s5k4ea_reg s5k4ea_wb_fluorescent[] = {

};

static const struct s5k4ea_reg s5k4ea_wb_sunny[] = {

};

static const struct s5k4ea_reg s5k4ea_wb_cloudy[] = {

};

/* Order of this array should be following the querymenu data */
static const unsigned char *s5k4ea_regs_wb_preset[] = {
	(unsigned char *)s5k4ea_wb_tungsten,
	(unsigned char *)s5k4ea_wb_fluorescent,
	(unsigned char *)s5k4ea_wb_sunny,
	(unsigned char *)s5k4ea_wb_cloudy,
};

/*
 * Color Effect (COLORFX)
 */
static const struct s5k4ea_reg s5k4ea_color_sepia[] = {
};

static const struct s5k4ea_reg s5k4ea_color_aqua[] = {
};

static const struct s5k4ea_reg s5k4ea_color_monochrome[] = {
};

static const struct s5k4ea_reg s5k4ea_color_negative[] = {
};

static const struct s5k4ea_reg s5k4ea_color_sketch[] = {
};

/* Order of this array should be following the querymenu data */
static const unsigned char *s5k4ea_regs_color_effect[] = {
	(unsigned char *)s5k4ea_color_sepia,
	(unsigned char *)s5k4ea_color_aqua,
	(unsigned char *)s5k4ea_color_monochrome,
	(unsigned char *)s5k4ea_color_negative,
	(unsigned char *)s5k4ea_color_sketch,
};

/*
 * Contrast bias
 */
static const struct s5k4ea_reg s5k4ea_contrast_m2[] = {
};

static const struct s5k4ea_reg s5k4ea_contrast_m1[] = {
};

static const struct s5k4ea_reg s5k4ea_contrast_default[] = {
};

static const struct s5k4ea_reg s5k4ea_contrast_p1[] = {
};

static const struct s5k4ea_reg s5k4ea_contrast_p2[] = {
};

static const unsigned char *s5k4ea_regs_contrast_bias[] = {
	(unsigned char *)s5k4ea_contrast_m2,
	(unsigned char *)s5k4ea_contrast_m1,
	(unsigned char *)s5k4ea_contrast_default,
	(unsigned char *)s5k4ea_contrast_p1,
	(unsigned char *)s5k4ea_contrast_p2,
};

/*
 * Saturation bias
 */
static const struct s5k4ea_reg s5k4ea_saturation_m2[] = {
};

static const struct s5k4ea_reg s5k4ea_saturation_m1[] = {
};

static const struct s5k4ea_reg s5k4ea_saturation_default[] = {
};

static const struct s5k4ea_reg s5k4ea_saturation_p1[] = {
};

static const struct s5k4ea_reg s5k4ea_saturation_p2[] = {
};

static const unsigned char *s5k4ea_regs_saturation_bias[] = {
	(unsigned char *)s5k4ea_saturation_m2,
	(unsigned char *)s5k4ea_saturation_m1,
	(unsigned char *)s5k4ea_saturation_default,
	(unsigned char *)s5k4ea_saturation_p1,
	(unsigned char *)s5k4ea_saturation_p2,
};

/*
 * Sharpness bias
 */
static const struct s5k4ea_reg s5k4ea_sharpness_m2[] = {
};

static const struct s5k4ea_reg s5k4ea_sharpness_m1[] = {
};

static const struct s5k4ea_reg s5k4ea_sharpness_default[] = {
};

static const struct s5k4ea_reg s5k4ea_sharpness_p1[] = {
};

static const struct s5k4ea_reg s5k4ea_sharpness_p2[] = {
};

static const unsigned char *s5k4ea_regs_sharpness_bias[] = {
	(unsigned char *)s5k4ea_sharpness_m2,
	(unsigned char *)s5k4ea_sharpness_m1,
	(unsigned char *)s5k4ea_sharpness_default,
	(unsigned char *)s5k4ea_sharpness_p1,
	(unsigned char *)s5k4ea_sharpness_p2,
};
#endif /* S5K4EA_COMPLETE */

#endif
