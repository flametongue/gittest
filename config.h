/*************************************************************
 *
 * Copyright (C) 2016-2017 by Beijing Starblaze Technology Co., Ltd.
 *
 * NOTICE:  All information contained herein is, and remains the
 * property of Beijing Starblaze Technology Co., Ltd and its
 * suppliers, if any.  The intellectual and technical concepts
 * contained herein are proprietary to Beijing Starblaze
 * Technology Co., Ltd and are protected by patent or trade
 * secret or copyright law.
 *
 * Dissemination of this information or reproduction of this
 * material is strictly forbidden unless prior written permission
 * is obtained from Beijing Starblaze Technology Co., Ltd. Source
 * code from this file can only be used on Starblaze ASIC products.
 *
 * Distribution of source code or binaries derived from this file
 * is not permitted except as specifically allowed By Non_Disclosure
 * Agreement between your company and Beijing Starblaze Technology
 * Co., Ltd. All copies of this source code modified or unmodified
 * must retain this entire copyright notice and comment as is.
 *
 * You should have received a copy of the Non-Disclosure Agreement
 * along with this program; if not, Please contact your manager
 * immediately.
 *
 *************************************************************/


#pragma once

// Give all options default value
#ifndef COMPILE_MODE
#define COMPILE_MODE            9
#endif
// Toshiba
#ifndef NAND_TYPE
#define NAND_TYPE               T
#endif
// BICS3
#ifndef SUBTYPE
#define SUBTYPE                 bics3
#endif
// TLC
#ifndef FLASH_TYPE
#define FLASH_TYPE              T
#endif
// Serial number
#ifndef SERI_NUM
#define SERI_NUM                0
#endif
// Capacity
#ifndef CAPACITY
#define CAPACITY                512
#endif
//release or debug
#ifndef RELEASE_VERSION
#define RELEASE_VERSION         'd'
#endif

#include <types.h>
#include "version.h"

//run environment
#define FPGA_440                (1)
#define ASIC_STAR1000P          (2)
#define FPGA_STAR1000P          (3)
#define DE_ENV                  (ASIC_STAR1000P)

//RAID config
#define ENABLE_RAID             (FALSE)
#define ENABLE_RAID_DEBUG       (FALSE)
#define ENABLE_RAID_GEN_TEST    (FALSE)
#define ENABLE_RAID_RCV_TEST    (FALSE)
#define RAID_FPGA_CD01          (0)
#define RAID_FPGA_CD02          (1)
#define RAID_FPGA_SH01          (2)
#define RAID_FPGA_SH02          (3)
#define RAID_ASIC               (4)
#define RAID_ENV                (RAID_FPGA_SH01)

//EMU OPT for reduce boot time of emulation
#define EMU_PERF_OPT            (FALSE)

//function enable
#define SELF_TEST               (TRUE)
#define PERFORMANCE_COUNTER_EN  (FALSE)
#define SCU_MONITOR_SUPPORT     (FALSE)
#define DISK_DRAM               (FALSE)
#define ENABLE_PI               (FALSE)  // Now PI is controlled by define need change by using NVMe CMD
#define NFI_LDPC_PUNC           (FALSE)  // ENABLE_PI =TRUE NFI_LDPC_CRI must be 2/3; otherwise NFI_LDPC_CRI must be 0/1; 1/3-> no punc
#define ENABLE_EEEC             (FALSE)
#define ENABLE_PAGE_READ        (FALSE)
#define ENABLE_FLASH_CACHE      (FALSE)
#define LP_FW_AUTO_EN           (FALSE)  // LP_CODE
#define LP_PS_AUTO_XFR_EN       (FALSE)  // LP_CODE
#define SYS_OPEN_STRATEGY_EN    (TRUE)
#define ENABLE_SOFT             (TRUE)
#define ENABLE_SM2_TEST         (FALSE)  // always false as no longer use SM2 fw code
#define PI_INSERT_ONCE          (FALSE)
#define NFI_ACG_ON              (TRUE)
#define ENABLE_NFI_ALLOCATOR    (TRUE)
#define ENABLE_PROG_CPL         (TRUE)
#define EN_MESSAGE_QUEUE_NFI    (FALSE)
#define MULTI_PLANE_PROG        (TRUE)
#define ENABLE_DDR_IECC         (FALSE)
#define EMU_FORCE_SEL_MSIX      (TRUE)  // force sel msix type
#define AGING_EN                (FALSE)
#define INLINE_ECC_EN           (TRUE)

#if (RELEASE_VER == TRUE)
#define ENABLE_DEBUG            (FALSE)
#define ENABLE_VU               (FALSE)
#else
#define ENABLE_DEBUG            (TRUE)
#define ENABLE_VU               (FALSE)
#endif

//debug messages
#define VERBOSE_TASK        (FALSE)
#define VERBOSE_DTU         (FALSE)
#define VERBOSE_CMD         (FALSE)
#define VERBOSE_DPL         (FALSE)
#define VERBOSE_MTX         (FALSE)
#define VERBOSE_WCACHE      (FALSE)
#define VERBOSE_HOST        (FALSE)
#define VERBOSE_BM          (FALSE)
#define VERBOSE_NFI         (FALSE)
#define VERBOSE_FTL         (FALSE)
#define VERBOSE_GC          (FALSE)
#define VERBOSE_NOR         (FALSE)
#define VERBOSE_BLK         (FALSE)
#define VERBOSE_BFT         (FALSE)
#define VERBOSE_BBM         (FALSE)
#define VERBOSE_EH          (FALSE)
#define VERBOSE_DRAM_DISK   (FALSE)
#define VERBOSE_RAID        (FALSE)
#define VERBOSE_DIRTY       (FALSE)
#define VERBOSE_CPUMON      (FALSE)
#define VERBOSE_LP          (FALSE)
#define VERBOSE_HAL         (FALSE)
#define VERBOSE_LOG         (FALSE)
#define VERBOSE_BFT_VERIFY  (FALSE)
#define WUN_DEBUG           (FALSE)
#define BBM_DEBUG           (FALSE)

//COMPILE_MODE levels
#define CM_L0_METAL         0       //device test
#define CM_L9_PRODUCT       9       //production


#if (COMPILE_MODE == CM_L0_METAL)
#define ENABLE_HOST         (FALSE)
#define ENABLE_FTL          (FALSE)
#define ENABLE_MTX          (FALSE)
#define ENABLE_MCPU         (FALSE)
#define ENABLE_GC           (FALSE)
#define ENABLE_BFT          (FALSE)
#define ENABLE_BBM          (FALSE)
#define ENABLE_FULL         (FALSE)
#define TEST_MC             (FALSE)
#if TEST_MC
    #undef  ENABLE_MCPU
    #define ENABLE_MCPU     (TRUE)
#endif


#elif (COMPILE_MODE == CM_L9_PRODUCT)
#define ENABLE_HOST         (TRUE)
#define ENABLE_FTL          (FALSE)
#define ENABLE_MTX          (TRUE)
#define ENABLE_MCPU         (TRUE)
#define ENABLE_GC           (FALSE)
#define ENABLE_BFT          (FALSE)
#define ENABLE_BBM          (FALSE)
#define ENABLE_FULL         (TRUE)
#else
#error "COMPILE_MODE is not defined in build"
#endif



//version info in CFG header
#define CFG_OEM_NAME            "Starblaze"            //up to 12 characters!
#define CFG_SOC_NAME            "1000p"
#define CFG_SOC_VER             (0x1000)
#define CFG_VER_DISK_FORMAT     (2)
#define CFG_VER_FW_MAJOR        (0)
#define CFG_VER_FW_MINOR        (1)


// ================ HOST CONFIG ====================
#define MAX_READ_LATENCY        (20)
#define MAX_WRITE_LATENCY       (100)


// ================ MEDIA CONFIG ====================
//MAX shift of fields
#define SECTOR_SIZE_SHIFT           (9)
#define SECTOR_PER_TU_SHIFT         (3)
#define MAX_CHUNK_PER_TU_SHIFT      (1)
#define MAX_TU_PER_PAGE_SHIFT       (2)
#define MAX_PAGE_PER_WL_SHIFT       (2)
#define MAX_PBA_COLUMN_SIZE_SHIFT   (16)
#define MAX_PBA_WL_SIZE_SHIFT       (8)
#define MAX_PBA_BLOCK_SIZE_SHIFT    (12)
#define MAX_PBA_LUN_SIZE_SHIFT      (1)
#if(NAND_TYPE == 'H')
#define MAX_WL_PER_BLOCK_SHIFT      (10) //Modified for 3DV4 by Geffory.Hu@20170729
#define SHORT_CPL_DUMMY_SHIFT       (6)
#define MAX_PLANE_PER_DIE_SHIFT     (1)
#define MAX_RESERVED_BLOCK_SHIFT    (3)
#define MAX_BLOCK_PER_PLANE_SHIFT   (10)
#else
#define MAX_WL_PER_BLOCK_SHIFT      (8)
#define MAX_PLANE_PER_DIE_SHIFT     (1)
#define MAX_BLOCK_PER_PLANE_SHIFT   (11)
#endif
#define MAX_LUN_PER_CE_SHIFT        (1)
#define MAX_CE_PER_CH_SHIFT         (3)
#define MAX_CH_SHIFT                (3)
#define WL_PLANE_FRAGMENT_MASK      ((1<<(MAX_TU_PER_PAGE_SHIFT \
                                        +MAX_PLANE_PER_DIE_SHIFT \
                                        +MAX_PAGE_PER_WL_SHIFT))-1)

#define NFI_PLANE_PER_DIE_SHIFT     (1)

#define NFI_LDPC_CRI_CONFIG         (0)
#define NFI_LDPC_FW_CRI_CONFIG      (3)
#define NFI_RANDOMISER_EANBLE       (TRUE)
#define NFI_LDPC_BYPASS_ENABLE      (FALSE)

#if (DE_ENV == FPGA_STAR1000P)
#define MAX_CH_COUNT                (4)
#else
#define MAX_CH_COUNT                (8)
#endif

#if(CAPACITY == 256)
#define MAX_CE_COUNT                (1)
#else
#define MAX_CE_COUNT                (4)
#endif
#define MAX_PAGE_PER_WL             (3)
#define MAX_WL_PER_LAYER            (4)
#define INTERLEAVE_PER_STRIPE		(4)
#define MAX_LUN_PER_CE_COUNT        (1<<MAX_LUN_PER_CE_SHIFT)

//#define RELEASE_CHECK

#ifdef RELEASE_CHECK
#undef   __LINE__
#define  __LINE__    0

#undef   __TIME__
#define  __TIME__    0

#undef   __DATE__
#define  __DATE__    0

#undef   __FILE__
#define  __FILE__    "\0"
#endif


// ================ SMART CONFIG ====================
#if ENABLE_DEBUG
#define DEVICE_EC_COUNT             (100)
#define SPACE_SHELD                 (50)
#define SECOND_PER_MINUTE           (60)
#define MINUTE_PER_HOUR             (60)
#define SECOND_PER_HOUR             (60)
#else
#define DEVICE_EC_COUNT             (3000)
#define SPACE_SHELD                 (10)
#define SECOND_PER_MINUTE           (60)
#define MINUTE_PER_HOUR             (60)
#define SECOND_PER_HOUR             (3600)
#endif


//LDPC cofnig
#define C_CFG_DECODRE_MASK_DEFAULT (1)
#define C_CFG_ENCODRE_MASK_DEFAULT (3)

//NAND config

#define NAND_T_ADL_US           (1)
#define NAND_T_PREAD_US         (120)
#define NAND_T_PROG_MS          (3)
#define NAND_T_BERASE_MS        (12)

#define NAND_ECC_CHUNK_SIZE     (4584)
#define RAID_MAX_CHUNK_SIZE     (4608)

//Read retry config
#define NAND_FW_READ_RETRY_STPE         (30)
#define NAND_HW_READ_RETRY_STPE         (0)
#define NAND_SOFTBIT_READ_RETRY_STPE    (6)

