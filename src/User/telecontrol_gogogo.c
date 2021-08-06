/**********************************************************
**0000000000000000000000000000000000000000000000000000000**
**00                                                   00**
**00                    ң��ģ��                       00**
**00                  ���ߣ�������                     00**
**00                                                   00**
**0000000000000000000000000000000000000000000000000000000**
**00            �������ã�  go                          00**
**0000000000000000000000000000000000000000000000000000000**
**********************************************************/
#include "include.h"

/**************����**************/
void telecontrol_gogogo(void)
{
        
    telecontrol_init();
   
//    PIT_Init(PIT0,5);//1.718e-3����ʱ���ж�
//    NVIC_SetPriority(PIT0_IRQn,NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0,2));
    //NVIC_SetPriority(UART4_RX_TX_IRQn,NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1,2));

    NVIC_SetPriority(PORTB_IRQn,NVIC_EncodePriority(NVIC_GetPriorityGrouping(),2,2));
    NVIC_EnableIRQ(PORTB_IRQn);			         //ʹ��PORTB_IRQn���ж�  
    
    /* ���ȼ����� ��ռ���ȼ�1  �����ȼ�2   ԽС���ȼ�Խ��  ��ռ���ȼ��ɴ�ϱ���ж� */
    NVIC_SetPriority(UART4_RX_TX_IRQn,NVIC_EncodePriority(NVIC_GetPriorityGrouping(),1,2));
    
    NVIC_EnableIRQ(UART4_RX_TX_IRQn);			          //ʹ��UART4_RX_TX_IRQn���ж�
    char txt[16]={0};
    while(1)
    {
        sprintf(txt,"speed:%5d  ",aim_speed);
        TFTSPI_P8X16Str(1,0,txt,u16WHITE,u16BLACK);
        
        sprintf(txt,"duty: %5d  ",aim_duty);
        TFTSPI_P8X16Str(1,1,txt,u16WHITE,u16BLACK);
        
        sprintf(txt,"angle:%5d  ",aim_angle);
        TFTSPI_P8X16Str(1,2,txt,u16WHITE,u16BLACK);
        
        sprintf(txt,"TEMP0:%5x  ",temp_buff[0]);
        TFTSPI_P8X16Str(1,4,txt,u16WHITE,u16BLACK);
        
        sprintf(txt,"TEMP1:%5d  ",temp_buff[1]);
        TFTSPI_P8X16Str(1,5,txt,u16WHITE,u16BLACK);
        
        sprintf(txt,"TEMP2:%5d  ",temp_buff[2]);
        TFTSPI_P8X16Str(1,6,txt,u16WHITE,u16BLACK);
        
        sprintf(txt,"TEMP3:%5d  ",temp_buff[3]);
        TFTSPI_P8X16Str(1,7,txt,u16WHITE,u16BLACK);
        
        sprintf(txt,"TEMP4:%5d  ",temp_buff[4]);
        TFTSPI_P8X16Str(1,8,txt,u16WHITE,u16BLACK);
        
        sprintf(txt,"TEMP5:%5x  ",temp_buff[5]);
        TFTSPI_P8X16Str(1,9,txt,u16WHITE,u16BLACK);
    }
}