/////*******************************GPIO������**************************************/

///**
//	*������������GPIO_Baud_Rate��ʼֵ��
//	*������;����ʼֵ��ʼ������
//	*˵��������SMOD��ֵѡȡ��
//	*��ע��SMOD == 0ʱ
//*/
//uchar code BR0_Init[]={0xa0,0xd0,0xe8,0xf0,0xf4,
//											0xf8,0xfa,0xfc,0xfd,0xfe};






//											
///**
//	*������������GPIO_Baud_Rate��ʼֵ��
//	*������;����ʼֵ��ʼ������
//	*˵��������SMOD��ֵѡȡ��
//	*��ע��SMOD == 1ʱ
//*/
//uchar code BR1_Init[]={0x40,0xa0,0xd0,0xe0,0xe8,
//											0xf0,0xf4,0xf8,0xfa,0xfc};





///**
//	*������������GPIO���ճ�ʼ��
//	*������;��GPIO��ʼ�������ò�����
//	*˵�������룺baud_rate_������;SMOD�ӱ�����λ���Դ���1 2 3ģʽ��Ч REN:����ʹ�� EA_ES�����жϺʹ����ж�ʹ�ܣ����أ���
//	*��ע��ʹ��Tim1��ʱ����ģʽ2������ģʽ1 ;�������������ֵ14400
//*/
//void GPIO_Init(uint baud_rate_ , bit SMOD_, bit REN_,bit EA_ES){
//	uint baud_rate = baud_rate_;
//	uchar SMOD = SMOD_;
//	switch(SMOD){  //�����ж�
//		case 0 : PCON = 0x00;break;
//		case 1 : PCON = 0x80;break;
//	}
//	SM0 = 0;  //����ģʽѡ��
//	SM1 = 1;
//	REN = REN_;  //����ʹ��
//	EA = EA_ES;		//�ж�ʹ��
//	ES = EA_ES;		//�����ж�
////	ET1 = 1;	//��ʱ��1�ж�ʹ��,����������Զ�װ��
//	TR1 = 1;	//��ʱ��1ʹ��
//	TMOD = 0x20; //��ʱ��1ģʽѡ��
//
//	TI = 0;
//	RI = 0;
//
//	if(!SMOD){
//			switch(baud_rate){
//				case 300   : TH1 = BR0_Init[0];TL1 = BR0_Init[0];break;
//				case 600   : TH1 = BR0_Init[1];TL1 = BR0_Init[1];break;
//				case 1200  : TH1 = BR0_Init[2];TL1 = BR0_Init[2];break;
//				case 1800  : TH1 = BR0_Init[3];TL1 = BR0_Init[3];break;
//				case 2400  : TH1 = BR0_Init[4];TL1 = BR0_Init[4];break;
//				case 3600  : TH1 = BR0_Init[5];TL1 = BR0_Init[5];break;
//				case 4800  : TH1 = BR0_Init[6];TL1 = BR0_Init[6];break;
//				case 7200  : TH1 = BR0_Init[7];TL1 = BR0_Init[7];break;
//				case 9600  : TH1 = BR0_Init[8];TL1 = BR0_Init[8];break;
//				case 14400 : TH1 = BR0_Init[9];TL1 = BR0_Init[9];break;
//		}
//	}
//		else if(SMOD){
//			switch(baud_rate){
//				case 300   : TH1 = BR1_Init[0];TL1 = BR1_Init[0];break;
//				case 600   : TH1 = BR1_Init[1];TL1 = BR1_Init[1];break;
//				case 1200  : TH1 = BR1_Init[2];TL1 = BR1_Init[2];break;
//				case 1800  : TH1 = BR1_Init[3];TL1 = BR1_Init[3];break;
//				case 2400  : TH1 = BR1_Init[4];TL1 = BR1_Init[4];break;
//				case 3600  : TH1 = BR1_Init[5];TL1 = BR1_Init[5];break;
//				case 4800  : TH1 = BR1_Init[6];TL1 = BR1_Init[6];break;
//				case 7200  : TH1 = BR1_Init[7];TL1 = BR1_Init[7];break;
//				case 9600  : TH1 = BR1_Init[8];TL1 = BR1_Init[8];break;
//				case 14400 : TH1 = BR1_Init[9];TL1 = BR1_Init[9];break;
//		}
//	}
//}





///**
//	*���������������ڷ����ַ���
//	*������;��
//	*˵�������룺string ����ֵ����
//	*��ע��TI���㲻Ҫ̫�죬Ӧ��while����һ�������㣬Ҳ����д�����ж������������
//*/
//void GPIOT_Char(uchar char_){
//	GPIOT_String_Flag = 1;
//	SBUF = char_;
//	while(GPIOT_String_Flag);
////	TI = 0;
//}
//void GPIOT_String(uchar* string){
//	do
//	GPIOT_Char(*string++);
//	while(*string);
//}
///**
//	*���������������ڷ����ַ���TI����
//	*������;��TI����
//	*˵����GPIOT_String_Flag������regSTC89C52_JC_A51.h��
//	*��ע��TI��ȫ����
//*/
//void Scr_TI_Init() interrupt 4{
//	TI = 0;
//	GPIOT_String_Flag = 0;
//}
