#include <STC89C5xRC.H>
#define SW1 P42

//������������LED��ʾ����������ÿ�ΰ���SW1��������λ+1
//��ʱ��������������
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
	unsigned char i = 0;
	while(1)
	{
		//0000 0001
		//0000 0011
		//0000 0111
		if(SW1 == 0)
		{
			Delay10ms();
			while(SW1 == 0);
			Delay10ms();
			i++;
			P0 = ~i; 
			//1������ȥ i = 1����ʱ 0000 0001
			//2��i+1 = 2����ʱ 0000 0010
			//...
		}
	}
}