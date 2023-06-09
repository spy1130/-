#include <reg52.h>


unsigned char T0RH,T0RL;



//1<=max<=71
void ConfigTimer0(unsigned char ms)
{
	unsigned long tmp;
	
	tmp=11059200/12;		//����Ƶ��
	tmp=(tmp*ms)/1000;
	tmp=65536-tmp;			//��ֵ
	T0RH=(unsigned char)(tmp>>8);
	T0RL=(unsigned char)(tmp);
	
	ET0=1;
	TMOD=0x01;	//���ù���ģʽ
	TH0=T0RH;	//���ö�ʱʱ��
	TL0=T0RL;
	TR0=1;		//������ʱ��
}

void main()
{	
	EA=1;
	P1=0X0E;
	
	ConfigTimer0(1);	//�趨1ms
	

	while(1)
	{

	}
}

//T0��ʱ���жϺ���
void InterruptTimer0() interrupt 1
{	
	static unsigned int cnt=0;

	TH0=T0RH;
	TL0=T0RL;

	cnt++;
	if(cnt>=500)
	{
		cnt=0;
	}
}
