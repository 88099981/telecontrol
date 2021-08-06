#ifndef INCLUDE_H_
#define INCLUDE_H_

/*
 * ����Cortex-M�ں˵�ͨ��ͷ�ļ�
 */
#include    <stdio.h>                       //printf
#include    <string.h>                      //memcpy
#include    <stdlib.h>                      //malloc

#include "common.h" 
#include "MK60N512VMD100.h"   /* �Ĵ���ӳ��ͷ�ļ� */
#include "core_cm4.h"         /* �ں��ļ����������ж����ȼ� */

/*----------------------------------------------------------------
                   �ײ������ļ�
------------------------------------------------------------------*/
#include "MK60_ADC.h"              /* ����ADCģ�� */
#include "MK60_GPIO.h"             /* ����GPIOģ�� */
#include "MK60_GPIO_Cfg.h"         /* ����GPIOģ�� ��51��IO���� */
#include "MK60_PLL.h"              /* ����ʱ��Ƶ������ */
#include "MK60_UART.h"             /* ���ڴ���ģ�� */
#include "MK60_PIT.h"              /* ����PIT��ʱ��ģ�� */
#include "MK60_FTM.h"              /* ����FTM��ʱ��ģ�� */
#include "MK60_CMT.h"              /* ����CMT��ʱ��ĳ�� */
#include "MK60_IIC.h"              /* ����IICģ�� */
#include "MK60_DMA.h"              /* ����DMAģ�� */
#include "MK60_LPTMR.h"            /* ����LPTMR��ʱ��ģ�� */
#include "MK60_WDOG.h"             /* ���ڿ��Ź� */
#include "MK60_SYSTICK.h"          /* systick �ں˶�ʱ�� */

/*----------------------------------------------------------------
                    ����ģ������
------------------------------------------------------------------*/
#include "LQ_LED.h"                /* LED         ���� */
#include "LQ_KEY.h"                /* KEY         ���� */
#include "LQ_PIT.h"                /* PIT         ���� */
#include "LQ_UART.h"               /* UART        ���� */
#include "LQ_LPTMR.h"              /* LPTMR       ���� */
#include "LQ_SYSTICK.h"            /* systick     ���� */
#include "LQ_12864.h"              /* OLED        ���� */
#include "LQ_SGP18T.h"             /* TFT1.8      ���� */

//������д��
#include "telecontrol_gogogo.h"
#include "telecontrol_init.h"
#include "telecontrol_uart.h"  
     
   

#endif