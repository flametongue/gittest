#include<stdio.h>

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

typedef unsigned long UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
typedef union
{
    UINT32  all;

    struct
    {
        UINT32  fragment    :
                MAX_TU_PER_PAGE_SHIFT;      ///<  [1:0]
        UINT32  plane       :
                MAX_PLANE_PER_DIE_SHIFT;    ///<  [2:2]
        UINT32  pg_in_wl      :
                MAX_PAGE_PER_WL_SHIFT;      ///<  [4:3]
        UINT32  ch          :
                MAX_CH_SHIFT;               ///<  [7:5]
        UINT32  ce          :
                MAX_CE_PER_CH_SHIFT;        ///<  [10:8]
        UINT32  lun         :
                MAX_LUN_PER_CE_SHIFT;       ///<  [11:11]
        UINT32  page      :
                MAX_WL_PER_BLOCK_SHIFT;     ///<  [19:12]
        UINT32  block    :
                MAX_BLOCK_PER_PLANE_SHIFT;  ///<  [30:20]
    } fields;
} PPA;

typedef struct
{
    UINT16*  last_valid_page;
    UINT8*   scan_counter;
    UINT8    stage;
	UINT32   stage1;
} BBM_FORMAT_CTRL;



void main()
{
	PPA ppa ;
	ppa.all = 0xfffff;
	ppa.fields.fragment --;
	printf("=======%d====\n",ppa.fields.fragment);
	printf("=======%d====\n",ppa.fields.plane);
	printf("=======%d====\n",ppa.fields.pg_in_wl);
	printf("=======%d====\n",ppa.fields.ch);
	printf("=======%x====\n",ppa.all);
	
	BBM_FORMAT_CTRL ctrl;
	//ctrl.last_valid_page
	*ctrl.last_valid_page = 3;
	printf("====BBM_FORMAT_CTRL%x===\n",ctrl.last_valid_page);
	printf("====BBM_FORMAT_CTRL%p===\n",ctrl.last_valid_page);
}