///*******************************数码管函数库**************************************/

///**
//	*函数中文名：共阴极数码管段码表0~f - .
//	*函数用途：
//	*说明：
//	*备注：
//*/
//uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
//					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,
//					0x40,0x80};





///**
//	*函数中文名：数码管按位显示函数
//	*函数用途：
//	*说明：
//	*备注：存在P0 = 0的关灯函数防止重影
//*/
//void Seg_Display(uint digit, uint num){
//	P0 = 0; //Must be here!!!
//	switch(digit){//硬件从左至右0-7 共阴极
//		case 0 : P24 = 0;P23 = 0;P22 = 0;break;
//		case 1 : P24 = 0;P23 = 0;P22 = 1;break;
//		case 2 : P24 = 0;P23 = 1;P22 = 0;break;
//		case 3 : P24 = 0;P23 = 1;P22 = 1;break;
//		case 4 : P24 = 1;P23 = 0;P22 = 0;break;
//		case 5 : P24 = 1;P23 = 0;P22 = 1;break;
//		case 6 : P24 = 1;P23 = 1;P22 = 0;break;
//		case 7 : P24 = 1;P23 = 1;P22 = 1;break;
//	}
//	switch(num){
//		case 0 : P0 = table[0];break;
//		case 1 : P0 = table[1];break;
//		case 2 : P0 = table[2];break;
//		case 3 : P0 = table[3];break;
//		case 4 : P0 = table[4];break;
//		case 5 : P0 = table[5];break;
//		case 6 : P0 = table[6];break;
//		case 7 : P0 = table[7];break;
//		case 8 : P0 = table[8];break;
//		case 9 : P0 = table[9];break;
//		case 'a' : P0 = table[10];break;
//		case 'b' : P0 = table[11];break;
//		case 'c' : P0 = table[12];break;
//		case 'd' : P0 = table[13];break;
//		case 'e' : P0 = table[14];break;
//		case 'f' : P0 = table[15];break;
//		case '-' : P0 = table[16];break;
//		case '.' : P0 = table[17];break;
//	}
//}




