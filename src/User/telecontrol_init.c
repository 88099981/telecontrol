/**********************************************************
**0000000000000000000000000000000000000000000000000000000**
**00                                                   00**
**00                    ң��ģ��                       00**
**00                  ���ߣ�������                     00**
**00                                                   00**
**0000000000000000000000000000000000000000000000000000000**
**00            �������ã� ��init                       00**
**0000000000000000000000000000000000000000000000000000000**
**********************************************************/
#include "include.h"
int16 aim_speed = 0;
int16 aim_duty = 0;
int16 aim_angle = 0;
uint16 bb_time = 0;

void telecontrol_init(void)
{
    /* ��ʼ�����İ��ϵ�LED */
    GPIO_PinInit(PTA17, GPO, 1);
    GPIO_PinInit(PTC0 , GPO, 1);
    GPIO_PinInit(PTD15, GPO, 1);
    GPIO_PinInit(PTE26, GPO, 1);
    /* �ڲ����� �½��ش����ж� �жϷ������� IRQ_Handler.c */
    GPIO_ExtiInit(PTB1, falling_up);
    GPIO_ExtiInit(PTB3, falling_up);
    GPIO_ExtiInit(PTB5, falling_up);
    GPIO_ExtiInit(PTB7, falling_up);
    GPIO_ExtiInit(PTB9, falling_up);
    GPIO_ExtiInit(PTB11, falling_up);
    GPIO_ExtiInit(PTB17, falling_up);
    GPIO_ExtiInit(PTB19, falling_up);
    
    UART_Init(UART4, 115200);//���ڳ�ʼ�� 
    //delay(1000);
    //OLED_CLS();   
    TFTSPI_Init(1);                 //TFT��ʼ��  0:����  1������
    TFTSPI_CLS(u16BLACK);
    
    temp_buff[0]=0xD8;
    temp_buff[LINE_LEN-1]=0xEE;
}
