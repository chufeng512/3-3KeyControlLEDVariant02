#include <STC89C5xRC.H>
#define SW1 P42	//按键SW1 定义
#define SW2 P43	//按键SW2 定义

//需求：独立按键控制LED灯的移动
//延时函数：作用->消除抖动
void Delay10ms()		//@11.0592MHz
{
	unsigned char i, j;

	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	unsigned char i = 0;   // 局部变量要付给初始值，否则是随机数i
	P0 = ~0x01;
	while (1)
	{
		if (SW1 == 0)      		// 检查按键SW1
		{
			Delay10ms();   			// 延时消抖
			while (SW1 == 0);  // 等待按键释放
			Delay10ms();       // 延时消抖
				
			i++;
			if(i>=8)
				i=0;
			
			P0 = ~(0x01<<i);		
			}
		
		if(SW2 == 0)
		{
			Delay10ms();
			while(SW2 == 0);
			Delay10ms();
			
			if(i==0)
				i = 7;
			else
				i--;
			P0 = ~(0x01<<i); //这里左移是左移i位，如右移1位，相当于左移7位
			//例如i=3.此时第四个LED亮，右移1位，此时i = 2，第三个灯亮
		}
		}
}

