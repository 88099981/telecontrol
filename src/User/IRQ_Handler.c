/*---------------------------------------------------------------
【平    台】龙邱K60核心板-智能车板
【编    写】LQ-005
【E-mail  】chiusir@163.com
【软件版本】V1.0，龙邱开源代码，仅供参考，后果自负
【最后更新】2019年04月02日
【网    站】http://www.lqist.cn
【淘宝店铺】http://shop36265907.taobao.com
【编译平台】IAR 8.2
【功    能】中断服务函数
【注意事项】中断服务函数的名称在startup_MK60D10.s 中
----------------------------------------------------------------*/
#include "include.h"


/////////////////////////////////////////////////////////////////
///////////////GPIO中断服务函数//////////////////////////////////
/////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------    
//全局变量  用于测试按键外部中断
//------------------------------------------------------------------------------------------------ 
extern volatile uint8_t key_exti_flag;
/*---------------------------------------------------------------
【函    数】PORTB_Interrupt
【功    能】PORTB端口的中断服务函数
【参    数】无
【返 回 值】无
【注意事项】注意进入后要清除中断标志位
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
        /* 用户自行添加中断内程序 */
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
    //清除中断标志
    PORTB_ISFR = 0xffffffff;
}


/////////////////////////////////////////////////////////////////
///////////////PIT中断服务函数///////////////////////////////////
/////////////////////////////////////////////////////////////////
//------------------------------------------------------------------------------------------------    
//全局变量  用于测试PIT定时器
//------------------------------------------------------------------------------------------------ 
extern volatile uint8_t pit0_test_flag;
extern volatile uint8_t pit1_test_flag;
extern volatile uint8_t pit2_test_flag;
extern volatile uint8_t pit3_test_flag;

/*---------------------------------------------------------------
【函    数】PIT0_Interrupt
【功    能】PIT0的中断服务函数
【参    数】无
【返 回 值】无
【注意事项】注意进入后要清除中断标志位
----------------------------------------------------------------*/
void PIT0_IRQHandler()
{
    PIT_Flag_Clear(PIT0);       //清中断标志位
    /*用户添加所需代码*/  
    pit0_test_flag = 1;
}
/*---------------------------------------------------------------
【函    数】PIT1_Interrupt
【功    能】PIT1的中断服务函数
【参    数】无
【返 回 值】无
【注意事项】注意进入后要清除中断标志位
----------------------------------------------------------------*/
void PIT1_IRQHandler()
{
    PIT_Flag_Clear(PIT1);       //清中断标志位
    /*用户添加所需代码*/
    pit1_test_flag = 1;
}
/*---------------------------------------------------------------
【函    数】PIT2_Interrupt
【功    能】PIT2的中断服务函数
【参    数】无
【返 回 值】无
【注意事项】注意进入后要清除中断标志位
----------------------------------------------------------------*/
void PIT2_IRQHandler()
{
    PIT_Flag_Clear(PIT2);       //清中断标志位
    /*用户添加所需代码*/
    pit2_test_flag = 1;
}
/*---------------------------------------------------------------
【函    数】PIT3_Interrupt
【功    能】PIT3的中断服务函数
【参    数】无
【返 回 值】无
【注意事项】注意进入后要清除中断标志位
----------------------------------------------------------------*/
void PIT3_IRQHandler()
{
    PIT_Flag_Clear(PIT3);       //清中断标志位
    /*用户添加所需代码*/
    pit3_test_flag = 1;
}



/////////////////////////////////////////////////////////////////
///////////////串口中断服务函数/////////////////////////////////
/////////////////////////////////////////////////////////////////

/*---------------------------------------------------------------
【函    数】DMA_CH4_Handler
【功    能】DMA通道4的中断服务函数
【参    数】无
【返 回 值】无
【注意事项】注意进入后要清除中断标志位
----------------------------------------------------------------*/
void UART4_RX_TX_IRQHandler(void)
{

    
}

