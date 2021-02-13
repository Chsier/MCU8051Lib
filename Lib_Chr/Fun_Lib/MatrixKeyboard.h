///*******************************矩阵键盘函数库**************************************/


///**
//	*函数中文名：矩阵键盘表
//	*函数用途：参考
//	*说明:
//	*备注：
//*/
//uchar code mxkey[]={0x7e,0x7d,0x7b,0x77,
//										0xbe,0xbd,0xbb,0xb7,
//										0xde,0xdd,0xdb,0xd7,
//										0xee,0xed,0xeb,0xe7};





///**
//	*函数中文名：矩阵键盘扫描
//	*函数用途：扫描矩阵键盘
//	*说明：输入：无;返回：键号，无按键时返回16
//	*备注：前置函数 L_Delay();自带消抖；无法排除两键同时按下 
//*/
//char Mxkey_Get(){
//	uchar temp,num = 16;
//	bit flag_1 = 0,flag_2 = 0,done = 0;
//	while(1){
//		P3 = 0x0f;
//		if(P3 != 0x0f){
//				L_Delay(500);
//			if(P3 != 0x0f){
//				temp = P3;
//				temp = temp & 0x0f;
//				flag_1 = 1;
//				switch(temp){
//					case 0xe : num = 0;break;
//					case 0xd : num = 1;break;
//					case 0xb : num = 2;break;
//					case 0x7 : num = 3;break;
//				}
//			}
//		}
//		
//		P3 = 0xf0;
//		if(P3 != 0xf0){
//				L_Delay(500);
//			if(P3 != 0xf0){
//				temp = P3;
//				temp = temp & 0xf0;
//				flag_2 = 1;
//				switch(temp){
//					case 0x70 : num += 0;break;
//					case 0xb0 : num += 4;break;
//					case 0xd0 : num += 8;break;
//					case 0xe0 : num += 12;break;
//				}
//			}
//		}
//			if(flag_1&flag_2 == 1)
//				done = 1;
//			if(done == 1){
//				break;
//			}
//		}
//	return (num);
//}
//
