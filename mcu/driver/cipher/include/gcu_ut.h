/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    gcu_ut.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines GCU unit test interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __GCU_UT_H__
#define __GCU_UT_H__

#include "kal_public_api.h" //MSBB change #include "kal_release.h"

#include "drv_comm.h"
#include "reg_base.h"

#define   UINT8           volatile unsigned char 
#define   UINT8P          volatile unsigned char *
#define   UINT16          volatile unsigned short 
#define   UINT16Point     volatile unsigned short *
#define   UINT32          volatile unsigned int 
#define   UINT32Point     volatile unsigned int *


// APB Module confg
#define HW_VERSION	     ((UINT16Point)(CONFIG_base+0x0000))
#define FW_VERSION	     ((UINT16Point)(CONFIG_base+0x0004))
#define HW_CODE	        ((UINT16Point)(CONFIG_base+0x0008))
#define MPLL	           ((UINT16Point)(CONFIG_base+0x0100))
#define DPLL	           ((UINT16Point)(CONFIG_base+0x0104))
#define CLK_CON	        ((UINT16Point)(CONFIG_base+0x0108))
#define SLEEP_CON	        ((UINT16Point)(CONFIG_base+0x010c))
#define UPLL	           ((UINT16Point)(CONFIG_base+0x0110))
#define IDN_SEL	        ((UINT16Point)(CONFIG_base+0x0200))
#define PDN_CON0	        ((UINT16Point)(CONFIG_base+0x0300))
#define PDN_CON1	        ((UINT16Point)(CONFIG_base+0x0304))
#define PDN_CON2	        ((UINT16Point)(CONFIG_base+0x0308))
#define PDN_CON3	        ((UINT16Point)(CONFIG_base+0x030c))
#define PDN_SET0	        ((UINT16Point)(CONFIG_base+0x0310))
#define PDN_SET1	        ((UINT16Point)(CONFIG_base+0x0314))
#define PDN_SET2	        ((UINT16Point)(CONFIG_base+0x0318))
#define PDN_SET3	        ((UINT16Point)(CONFIG_base+0x031c))

#define PDN_CLR0	        ((UINT16Point)(CONFIG_base+0x0320)) //in gcu_test.c, Power on GCU ==> *PDN_CLR0 = 0x0004;
  

#define PDN_CLR1	        ((UINT16Point)(CONFIG_base+0x0324))
#define PDN_CLR2	        ((UINT16Point)(CONFIG_base+0x0328))
#define PDN_CLR3	        ((UINT16Point)(CONFIG_base+0x032c))
#define PDN_CON4	        ((UINT16Point)(CONFIG_base+0x0330))
#define PDN_SET4	        ((UINT16Point)(CONFIG_base+0x0334))
#define PDN_CLR4	        ((UINT16Point)(CONFIG_base+0x0338))
#define AHB_CON	        ((UINT16Point)(CONFIG_base+0x0400))
#define APB_CON	        ((UINT16Point)(CONFIG_base+0x0404))
#define WRP_CON	        ((UINT16Point)(CONFIG_base+0x0500))
#define WRP_STA	        ((UINT16Point)(CONFIG_base+0x0504))
#define ARM_CON	        ((UINT16Point)(CONFIG_base+0x0508))
#define SYSRAM_CON	     ((UINT16Point)(CONFIG_base+0x0600))
#define ACIF_CON0	        ((UINT16Point)(CONFIG_base+0x0700))
#define ACIF_CON1	        ((UINT16Point)(CONFIG_base+0x0704))
#define ACIF_CON2	        ((UINT16Point)(CONFIG_base+0x0708))
#define ACIF_CON3	        ((UINT16Point)(CONFIG_base+0x070c))
#define ACIF_CON4	        ((UINT16Point)(CONFIG_base+0x0710))
#define ACIF_CON5	        ((UINT16Point)(CONFIG_base+0x0714))
#define ROM_DELSEL0	     ((UINT16Point)(CONFIG_base+0x0800))
#define ROM_DELSEL1	     ((UINT16Point)(CONFIG_base+0x0804))
#define ROM_DELSEL2	     ((UINT16Point)(CONFIG_base+0x0808))
#define SPARE_REG0	     ((UINT16Point)(CONFIG_base+0xff00))
#define SPARE_REG1	     ((UINT16Point)(CONFIG_base+0xff04))



// APB Module gcu
#define GCU_CON	        ((UINT32Point)(GCU_base+0x0000))
#define GCU_STA	        ((UINT32Point)(GCU_base+0x0004))
#define GCU_SKEY0	        ((UINT32Point)(GCU_base+0x0008))
#define GCU_SKEY1	        ((UINT32Point)(GCU_base+0x000c))
#define GCU_MKEY	        ((UINT32Point)(GCU_base+0x0010))
#define GCU_CKEY	        ((UINT32Point)(GCU_base+0x0014))



#define MDM_TM_base        0x10800000

#define MDM_TM_ERRMSG      ((UINT16Point)(MDM_TM_base+0x0000))  //Error Message Register
#define MDM_TM_INFOMSG     ((UINT16Point)(MDM_TM_base+0x0002))  //Information Message Register
#define MDM_TM_ERRCNT      ((UINT16Point)(MDM_TM_base+0x0004))  //Error Count Register
#define MDM_TM_ENDFAIL     ((UINT16Point)(MDM_TM_base+0x00fa))  //End Simulation With Fail Msg
#define MDM_TM_ENDSUCC     ((UINT16Point)(MDM_TM_base+0x00fc))  //End Simulation With Success Msg
#define MDM_TM_ENDSIM      ((UINT16Point)(MDM_TM_base+0x00fe))  //End Simulation Register
#define MDM_TM_ALLFMT32B   ((UINT32Point)(MDM_TM_base+0x0100))  //LSB: Display All Format 32b Value
#define MDM_TM_HEXFMT32B   ((UINT32Point)(MDM_TM_base+0x0104))  //LSB: Display Hexa Format 32b Value
#define MDM_TM_DECFMT32B   ((UINT32Point)(MDM_TM_base+0x0108))  //LSB: Display Dec Format 32b Value
#define MDM_TM_BINFMT32B   ((UINT32Point)(MDM_TM_base+0x010c))  //LSB: Display Bin Format 32b Value
#define MDM_TM_HEXFMT16B   ((UINT16Point)(MDM_TM_base+0x0110))  //Display Hexa Format 16b Value
#define MDM_TM_DECFMT16B   ((UINT16Point)(MDM_TM_base+0x0112))  //Display Dec Format 16b Value
#define MDM_TM_BINFMT16B   ((UINT16Point)(MDM_TM_base+0x0114))  //Display Bin Format 16b Value
#define MDM_TM_MEMDUMPSTR  ((UINT32Point)(MDM_TM_base+0x0200))  //Start Address of Memory Dumping
#define MDM_TM_MEMDUMPSTOP ((UINT32Point)(MDM_TM_base+0x0204))  //Stop Address of Memory Dumping


/// GCU all conformance test pattern

//GEA1
kal_uint8 gcu_ciphertext_1[18] = {0x1F, 0xA1, 0x98, 0xAB, 0x21, 0x14, 0xC3, 0x8A, 0x9E, 0xBC, 0xCB, 0x63, 0xAD, 0x48, 0x13, 0xA7, 0x40, 0xC1};
kal_uint8 gcu_ciphertext_2[18] = {0x2A, 0x26, 0xD8, 0xFB, 0x64, 0xEC, 0xF3, 0x0C, 0x14, 0x7F, 0x1F, 0x16, 0x5E, 0xBC, 0x8B, 0x31, 0x9B, 0xE6};
kal_uint8 gcu_ciphertext_3[18] = {0xB9, 0xA0, 0xF5, 0xDD, 0x05, 0x48, 0x24, 0xC5, 0xD8, 0x26, 0xA8, 0xF3, 0x3D, 0x8C, 0x61, 0x6B, 0xD1, 0x07};
kal_uint8 gcu_ciphertext_4[18] = {0xE4, 0x00, 0x13, 0xBA, 0x42, 0xF7, 0x7C, 0xD1, 0x68, 0x5E, 0xAB, 0x0F, 0xA9, 0x5B, 0x8F, 0x76, 0xDC, 0x3F};
kal_uint8 gcu_ciphertext_5[18] = {0xB9, 0xA0, 0xF5, 0xDD, 0x05, 0x48, 0x24, 0xC5, 0xD8, 0x26, 0xA8, 0xF3, 0x3D, 0x8C, 0x61, 0x6B, 0xD1, 0x07};
kal_uint8 gcu_ciphertext_6[18] = {0x48, 0xF8, 0x08, 0x7E, 0x63, 0xEE, 0x3C, 0x59, 0x6F, 0x42, 0x02, 0xA9, 0x44, 0xF8, 0xEE, 0x25, 0xDD, 0xD0};
kal_uint8 gcu_ciphertext_7[18] = {0x30, 0x73, 0x6A, 0xD5, 0x39, 0x13, 0x58, 0x56, 0x00, 0x22, 0x31, 0xEC, 0x7F, 0x18, 0x2B, 0x3D, 0x03, 0x2D};

kal_uint8 gcu_plaintext_1[18] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
kal_uint8 gcu_plaintext_2[18] = {0x91, 0xE1, 0xDB, 0x43, 0x0B, 0x86, 0x40, 0x18, 0xED, 0x59, 0x63, 0x9B, 0xAB, 0x9A, 0x73, 0xC3, 0xCD, 0xE6};
kal_uint8 gcu_plaintext_3[18] = {0xA8, 0xCA, 0xA6, 0x70, 0x98, 0x74, 0x82, 0x4D, 0x5B, 0x80, 0x40, 0x98, 0xB7, 0x69, 0x36, 0x4F, 0xD5, 0xAC};
kal_uint8 gcu_plaintext_4[18] = {0x36, 0x20, 0xAA, 0x33, 0x00, 0x77, 0x59, 0x16, 0x41, 0xD9, 0xD6, 0xA7, 0x3B, 0xBC, 0x8C, 0xA6, 0x53, 0xE4};
kal_uint8 gcu_plaintext_5[18] = {0xA8, 0xCA, 0xA6, 0x70, 0x98, 0x74, 0x82, 0x4D, 0x5B, 0x80, 0x40, 0x98, 0xB7, 0x69, 0x36, 0x4F, 0xD5, 0xAC};
kal_uint8 gcu_plaintext_6[18] = {0x12, 0xC1, 0x11, 0x1A, 0x6C, 0xB0, 0xF8, 0xD3, 0xF1, 0x83, 0x06, 0x77, 0x97, 0xCB, 0x2E, 0xBF, 0x5B, 0x6C};
kal_uint8 gcu_plaintext_7[18] = {0xA6, 0x41, 0x88, 0xFB, 0xB8, 0x2B, 0xAE, 0x69, 0x41, 0x19, 0xFC, 0x45, 0x01, 0xA7, 0xB2, 0xEB, 0xCB, 0xC5};


kal_uint16 gcu_key_1[7] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001c};
kal_uint16 gcu_key_2[7] = {0xC5F9, 0x7B00, 0x89D3, 0xE84E, 0xC582, 0xF740, 0x001E};
kal_uint16 gcu_key_3[7] = {0x4B65, 0xE3CA, 0xBFCF, 0x78B1, 0x4F69, 0x88D6, 0x001E};
kal_uint16 gcu_key_4[7] = {0x06CF, 0xC095, 0x2794, 0xBE2D, 0xDEE5, 0x4BE3, 0x001C};
kal_uint16 gcu_key_5[7] = {0x4B65, 0xE3CA, 0xBFCF, 0x78B1, 0x4F69, 0x88D6, 0x001E};
kal_uint16 gcu_key_6[7] = {0x8A50, 0x9DAA, 0xF1A7, 0xE0F8, 0x897C, 0x2CEB, 0x001C};
kal_uint16 gcu_key_7[7] = {0xB1D3, 0x590B, 0xDE75, 0xCA23, 0x2CCC, 0x233E, 0x001E};


//GEA2
kal_uint8 gcu2_ciphertext_1[18] = {0x04, 0x51, 0x15, 0xD5, 0xE5, 0xA2, 0xD6, 0x25, 0x41, 0xDA, 0x07, 0x8B, 0x18, 0xBA, 0xA5, 0x3F, 0xFE, 0x14};
kal_uint8 gcu2_ciphertext_2[18] = {0xE4, 0xA7, 0x4E, 0x15, 0x77, 0xBA, 0x5A, 0xEF, 0x86, 0xE0, 0xA0, 0x29, 0x57, 0xC4, 0xC3, 0x50, 0xED, 0x11};
kal_uint8 gcu2_ciphertext_3[18] = {0x19, 0x6C, 0x43, 0x25, 0xAE, 0xC8, 0xC5, 0x51, 0x49, 0xBD, 0xE1, 0xBB, 0x4A, 0x5D, 0x4E, 0x41, 0xF8, 0xF3};
kal_uint8 gcu2_ciphertext_4[18] = {0x57, 0xAC, 0x91, 0xB6, 0x9D, 0x8B, 0x36, 0x3C, 0x93, 0x93, 0xDD, 0x29, 0x89, 0xE9, 0xF5, 0x60, 0x93, 0x35};
kal_uint8 gcu2_ciphertext_5[18] = {0x19, 0x6C, 0x43, 0x25, 0xAE, 0xC8, 0xC5, 0x51, 0x49, 0xBD, 0xE1, 0xBB, 0x4A, 0x5D, 0x4E, 0x41, 0xF8, 0xF3};
kal_uint8 gcu2_ciphertext_6[18] = {0x3b, 0x76, 0x7a, 0x49, 0xd9, 0xd4, 0x8b, 0x5d, 0xff, 0x05, 0xcd, 0x01, 0xd4, 0x2c, 0x22, 0xe9, 0x9f, 0x20};
kal_uint8 gcu2_ciphertext_7[18] = {0x6c, 0x96, 0x36, 0xdd, 0x4c, 0x93, 0x56, 0x71, 0xc2, 0x0a, 0x68, 0x23, 0x24, 0x77, 0x49, 0x8a, 0x43, 0x25};

kal_uint8 gcu2_plaintext_1[18] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
kal_uint8 gcu2_plaintext_2[18] = {0x2A, 0x26, 0xD8, 0xFB, 0x64, 0xEC, 0xF3, 0x0C, 0x14, 0x7F, 0x1F, 0x16, 0x5E, 0xBC, 0x8B, 0x31, 0x9B, 0xE6};
kal_uint8 gcu2_plaintext_3[18] = {0xA8, 0xCA, 0xA6, 0x70, 0x98, 0x74, 0x82, 0x4D, 0x5B, 0x80, 0x40, 0x98, 0xB7, 0x69, 0x36, 0x4F, 0xD5, 0xAC};
kal_uint8 gcu2_plaintext_4[18] = {0x36, 0x20, 0xAA, 0x33, 0x00, 0x77, 0x59, 0x16, 0x41, 0xD9, 0xD6, 0xA7, 0x3B, 0xBC, 0x8C, 0xA6, 0x53, 0xE4};
kal_uint8 gcu2_plaintext_5[18] = {0xA8, 0xCA, 0xA6, 0x70, 0x98, 0x74, 0x82, 0x4D, 0x5B, 0x80, 0x40, 0x98, 0xB7, 0x69, 0x36, 0x4F, 0xD5, 0xAC};
kal_uint8 gcu2_plaintext_6[18] = {0x12, 0xc1, 0x11, 0x1a, 0x6c, 0xb0, 0xf8, 0xd3, 0xf1, 0x83, 0x06, 0x77, 0x97, 0xcb, 0x2e, 0xbf, 0x5b, 0x6c};
kal_uint8 gcu2_plaintext_7[18] = {0xa6, 0x41, 0x88, 0xfb, 0xb8, 0x2b, 0xae, 0x69, 0x41, 0x19, 0xfc, 0x45, 0x01, 0xa7, 0xb2, 0xeb, 0xcb, 0xc5};


kal_uint16 gcu2_key_1[7] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x001D};
kal_uint16 gcu2_key_1_bt[7] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0005};
kal_uint16 gcu2_key_1_hw[7] = {0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x000D};

kal_uint16 gcu2_key_2[7] = {0xC5F9, 0x7B00, 0x89D3, 0xE84E, 0xC582, 0xF740, 0x001F};
kal_uint16 gcu2_key_2_hw[7] = {0xC5F9, 0x7B00, 0x89D3, 0xE84E, 0xC582, 0xF740, 0x000F};

kal_uint16 gcu2_key_3[7] = {0x4B65, 0xE3CA, 0xBFCF, 0x78B1, 0x4F69, 0x88D6, 0x001F};
kal_uint16 gcu2_key_4[7] = {0x06cf, 0xc095, 0x2794, 0xbe2d, 0xdee5, 0x4be3, 0x001D};
kal_uint16 gcu2_key_5[7] = {0x4B65, 0xE3CA, 0xBFCF, 0x78B1, 0x4F69, 0x88D6, 0x001F};
kal_uint16 gcu2_key_6[7] = {0x8a50, 0x9daa, 0xf1a7, 0xe0f8, 0x897c, 0x2ceb, 0x001D};
kal_uint16 gcu2_key_7[7] = {0xb1d3, 0x590b, 0xde75, 0xca23, 0x2ccc, 0x233e, 0x001F};


//GEA3
kal_uint16 gcu3_key_1[7] = {0xBC00, 0x82C5, 0x459F, 0x2BD6, 0x21A3, 0x8E94, 0x003A};
kal_uint16 gcu3_key_2[7] = {0xFF48, 0x4881, 0x4910, 0x952C, 0xDB71, 0x5064, 0x003A};
kal_uint16 gcu3_key_3[7] = {0x0C2A, 0x9E72, 0xB222, 0xEFA8, 0xD5E5, 0x4BDB, 0x003E};
kal_uint16 gcu3_key_4[7] = {0x2C87, 0x43BD, 0xF23A, 0x3451, 0xE14F, 0x893F, 0x003A};
kal_uint16 gcu3_key_5[7] = {0x35CF, 0xE824, 0x639B, 0xCAA2, 0x7885, 0x8FE1, 0x003E};
kal_uint16 gcu3_key_6[7] = {0x7B39, 0x8B76, 0x8B44, 0x1ACA, 0xC3B5, 0x4F7B, 0x003A};

kal_uint32 GEA3output1[15] = {0x5F359709, 0xDE950D01, 0x05B17B6C, 0x90194280, 0xF880B48D, 0xCCDC2AFE, 0xED415DBE, 0xF4354EEB, 0xB21D073C, 0xCBBFB2D7, 0x06BD7AFF, 0xD371FC96, 0xE3970D14, 0x3DCB2624, 0x05482600};
kal_uint32 GEA3output2[15] = {0xFDC03D73, 0x8C8E14FF, 0x0320E59A, 0xAF757607, 0x99E9DA78, 0xDD8F8884, 0x71C4AEAA, 0xC1849633, 0xA26CD84F, 0x459D265B, 0x83D7D9B9, 0xA0B1E54F, 0x4D75E331, 0x640DF19E, 0x0DB0E000};
kal_uint32 GEA3output3[15] = {0x4718A2AD, 0xFC905909, 0x49DDADAB, 0x406EC3B9, 0x25F1AF12, 0x14673909, 0xDAAB96BB, 0x4C18B137, 0x4BB1E994, 0x45A81CC8, 0x56E47C6E, 0x49E9DBB9, 0x873D0831, 0xB2175CA1, 0xE109BA00};
kal_uint32 GEA3output4[15] = {0xB46B1E28, 0x4E3F8B63, 0xB86D9DF0, 0x915CFCED, 0xDF2F0618, 0x95BF9F82, 0xBF2593AE, 0x4847E94A, 0x4626C393, 0xCF8941CE, 0x15EA7812, 0x690D8415, 0xB88C5730, 0xFE1F5D41, 0x0E16A200};
kal_uint32 GEA3output5[15] = {0x9FEFAF15, 0x5A26CF35, 0x603E727C, 0xDAA87BA0, 0x67FD84FF, 0x98A50B7F, 0xF0EC8E95, 0xA0FB70E7, 0x9CB93DEE, 0x2B7E9AB5, 0x9D050E12, 0x62401571, 0xF349C682, 0x29DDF0DE, 0xCC4E8500};
kal_uint32 GEA3output6[15] = {0x514F6C3A, 0x3B5A55CA, 0x190092F7, 0xBB6E80EF, 0x3EDB738F, 0xCDCE2FF9, 0x0BB387DD, 0xE75BBC32, 0xA04A67B8, 0x98A3DFB8, 0x198FFFC3, 0x7D437CF6, 0x9E7F9C13, 0xB51A8687, 0x20E75000};


#endif