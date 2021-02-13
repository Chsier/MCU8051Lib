/////*******************************GPIO函数库**************************************/

///**
//	*函数中文名：GPIO_Baud_Rate初始值表
//	*函数用途：初始值初始化设置
//	*说明：按照SMOD数值选取表
//	*备注：SMOD == 0时
//*/
//uchar code BR0_Init[]={0xa0,0xd0,0xe8,0xf0,0xf4,
//											0xf8,0xfa,0xfc,0xfd,0xfe};






//											
///**
//	*函数中文名：GPIO_Baud_Rate初始值表
//	*函数用途：初始值初始化设置
//	*说明：按照SMOD数值选取表
//	*备注：SMOD == 1时
//*/
//uchar code BR1_Init[]={0x40,0xa0,0xd0,0xe0,0xe8,
//											0xf0,0xf4,0xf8,0xfa,0xfc};





///**
//	*函数中文名：GPIO接收初始化
//	*函数用途：GPIO初始化并设置波特率
//	*说明：输入：baud_rate_波特率;SMOD加倍控制位仅对串口1 2 3模式有效 REN:接收使能 EA_ES：总中断和串口中断使能；返回：无
//	*备注：使用Tim1计时器，模式2；串口模式1 ;波特率输入最大值14400
//*/
//void GPIO_Init(uint baud_rate_ , bit SMOD_, bit REN_,bit EA_ES){
//	uint baud_rate = baud_rate_;
//	uchar SMOD = SMOD_;
//	switch(SMOD){  //翻倍判断
//		case 0 : PCON = 0x00;break;
//		case 1 : PCON = 0x80;break;
//	}
//	SM0 = 0;  //串口模式选择
//	SM1 = 1;
//	REN = REN_;  //接收使能
//	EA = EA_ES;		//中断使能
//	ES = EA_ES;		//串口中断
////	ET1 = 1;	//计时器1中断使能,无需操作，自动装填
//	TR1 = 1;	//计时器1使能
//	TMOD = 0x20; //计时器1模式选择
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
//	*函数中文名：串口发送字符串
//	*函数用途：
//	*说明：输入：string 返回值：无
//	*备注：TI清零不要太快，应该while其置一后再请零，也不能写在其中断里，经测试无用
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
//	*函数中文名：串口发送字符串TI清零
//	*函数用途：TI清零
//	*说明：GPIOT_String_Flag定义在regSTC89C52_JC_A51.h中
//	*备注：TI安全清零
//*/
//void Scr_TI_Init() interrupt 4{
//	TI = 0;
//	GPIOT_String_Flag = 0;
//}
