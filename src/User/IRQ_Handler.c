/*---------------------------------------------------------------
��ƽ    ̨������K60���İ�-���ܳ���
����    д��LQ-005
��E-mail  ��chiusir@163.com
������汾��V1.0������Դ���룬�����ο�������Ը�
�������¡�2019��04��02��
����    վ��http://www.lqist.cn
���Ա����̡�http://shop36265907.taobao.com
������ƽ̨��IAR 8.2
����    �ܡ��жϷ�����
��ע������жϷ�������������startup_MK60D10.s ��
----------------------------------------------------------------*/
#include "include.h"


/////////////////////////////////////////////////////////////////
///////////////GPIO�жϷ�����//////////////////////////////////
/////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------    
//ȫ�ֱ���  ���ڲ��԰����ⲿ�ж�
//------------------------------------------------------------------------------------------------ 
extern volatile uint8_t key_exti_flag;
/*---------------------------------------------------------------
����    ����PORTB_Interrupt
����    �ܡ�PORTB�˿ڵ��жϷ�����
����    ������
���� �� ֵ����
��ע�����ע������Ҫ����жϱ�־λ
----------------------------------------------------------------*/
void PORTB_IRQHandler()
{
    int16 delay_time = 200;
    int n;  
    n=1;
    if((PORTB_ISFR & (1<<n)))
    {
        key_exti_flag = 1;
        aim_duty += 1;
        if(aim_duty>10)       aim_duty = 10;
        else if(aim_duty<-8)  aim_duty = -8;
        temp_buff[2]=aim_duty;
        UART_PutBuff(UART4, temp_buff, LINE_LEN);
        delayms(delay_time);
    } 
    n=3;
    if((PORTB_ISFR & (1<<n)))
    {
        key_exti_flag = 2;
        aim_speed=0;
        aim_duty=0;
        aim_angle=0;
        temp_buff[1]=0;
        temp_buff[2]=0;
        temp_buff[3]=0;
        UART_PutBuff(UART4, temp_buff, LINE_LEN);
        delayms(delay_time);
    } 
    n=5;
    if((PORTB_ISFR & (1<<n)))
    {
        key_exti_flag = 3;
        aim_duty -= 1;
        if(aim_duty>10)       aim_duty=10;
        else if(aim_duty<-8)  aim_duty=-8;
        temp_buff[2]=aim_duty;
        UART_PutBuff(UART4, temp_buff, LINE_LEN);
        delayms(delay_time);
    }
    n=7;
    if((PORTB_ISFR & (1<<n)))
    {
        key_exti_flag = 4;
        aim_angle -= 300;
        if(aim_angle>900)       aim_angle=900;
        else if(aim_angle<-900)  aim_angle=-900;
        temp_buff[3]=aim_angle/100;
        UART_PutBuff(UART4, temp_buff, LINE_LEN);
        delayms(delay_time);
    }
    n=9;
    if((PORTB_ISFR & (1<<n)))
    {
        /* �û���������ж��ڳ��� */
        key_exti_flag = 5;
        aim_speed += 5+aim_duty * 5;
        if(aim_speed>200)       aim_speed=200;
        else if(aim_speed<-200)  aim_speed=-200;
        temp_buff[1]=aim_speed/5;
        UART_PutBuff(UART4, temp_buff, LINE_LEN);
        delayms(delay_time);
    }
    n=11;
    if((PORTB_ISFR & (1<<n)))
    {
        key_exti_flag = 6;
        bb_time=20;
        temp_buff[4]=bb_time;
        UART_PutBuff(UART4, temp_buff, LINE_LEN);
        temp_buff[4]=0;
        delayms(delay_time);
    }
    n=17;
    if((PORTB_ISFR & (1<<n)))
    {
        key_exti_flag = 7;
        aim_speed -= 5+aim_duty * 5;
        if(aim_speed>200)       aim_speed=200;
        else if(aim_speed<-200)  aim_speed=-200;
        temp_buff[1]=aim_speed/5;
        UART_PutBuff(UART4, temp_buff, LINE_LEN);  
        delayms(delay_time);
    }
    n=19;
    if((PORTB_ISFR & (1<<n)))
    {
        key_exti_flag = 8;
        aim_angle += 300;
        if(aim_angle>900)       aim_angle=900;
        else if(aim_angle<-900)  aim_angle=-900;
        temp_buff[3]=aim_angle/100;
        UART_PutBuff(UART4, temp_buff, LINE_LEN);
        delayms(delay_time);
        
    }    
    //����жϱ�־
    PORTB_ISFR = 0xffffffff;
}


/////////////////////////////////////////////////////////////////
///////////////PIT�жϷ�����///////////////////////////////////
/////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------    
//ȫ�ֱ���  ���ڲ���PIT��ʱ��
//------------------------------------------------------------------------------------------------ 
extern volatile uint8_t pit0_test_flag;
extern volatile uint8_t pit1_test_flag;
extern volatile uint8_t pit2_test_flag;
extern volatile uint8_t pit3_test_flag;

/*---------------------------------------------------------------
����    ����PIT0_Interrupt
����    �ܡ�PIT0���жϷ�����
����    ������
���� �� ֵ����
��ע�����ע������Ҫ����жϱ�־λ
----------------------------------------------------------------*/
void PIT0_IRQHandler()
{
    PIT_Flag_Clear(PIT0);       //���жϱ�־λ
    /*�û�����������*/  
    pit0_test_flag = 1;
}
/*---------------------------------------------------------------
����    ����PIT1_Interrupt
����    �ܡ�PIT1���жϷ�����
����    ������
���� �� ֵ����
��ע�����ע������Ҫ����жϱ�־λ
----------------------------------------------------------------*/
void PIT1_IRQHandler()
{
    PIT_Flag_Clear(PIT1);       //���жϱ�־λ
    /*�û�����������*/
    pit1_test_flag = 1;
}
/*---------------------------------------------------------------
����    ����PIT2_Interrupt
����    �ܡ�PIT2���жϷ�����
����    ������
���� �� ֵ����
��ע�����ע������Ҫ����жϱ�־λ
----------------------------------------------------------------*/
void PIT2_IRQHandler()
{
    PIT_Flag_Clear(PIT2);       //���жϱ�־λ
    /*�û�����������*/
    pit2_test_flag = 1;
}
/*---------------------------------------------------------------
����    ����PIT3_Interrupt
����    �ܡ�PIT3���жϷ�����
����    ������
���� �� ֵ����
��ע�����ע������Ҫ����жϱ�־λ
----------------------------------------------------------------*/
void PIT3_IRQHandler()
{
    PIT_Flag_Clear(PIT3);       //���жϱ�־λ
    /*�û�����������*/
    pit3_test_flag = 1;
}



/////////////////////////////////////////////////////////////////
///////////////�����жϷ�����/////////////////////////////////
/////////////////////////////////////////////////////////////////

/*---------------------------------------------------------------
����    ����DMA_CH4_Handler
����    �ܡ�DMAͨ��4���жϷ�����
����    ������
���� �� ֵ����
��ע�����ע������Ҫ����жϱ�־λ
----------------------------------------------------------------*/
void UART4_RX_TX_IRQHandler(void)
{

    
}

