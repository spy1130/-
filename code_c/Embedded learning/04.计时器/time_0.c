#include "reg52.h"

sbit LED=P2^7;

int main(){
	unsigned int cnt=0;
	
	TMOD=0X01;//�������⹦�ܼĴ���TMOD�����úù���ģʽ
	
	TH0=0xFC;
	TL0=0x6E;
	TR0=1;//����(��)��ʱ��
    while(1){
			if(TF0==1){
				TF0=0;//��ʱ����
				TH0=0xFC;
				TL0=0x6E;//���¼�ʱ
				cnt++;
				if(cnt>=500){
				LED=~LED;}}
    }
}