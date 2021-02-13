#ifdef __STC89C5xRC_RDP_H_
/**************************************************************************
*JC_A51开发板可能无法多功能同时开发
**************************************************************************/
 
/***********************************全彩灯**********************************/
//sfr P1   = 0x90; 
sbit ledc_1 = P1^1;  //Red Color
sbit ledc_2 = P1^2;  //Blue Color
sbit ledc_3 = P1^3;  //Green Color
sbit Beep = P1^4;    //Beep

/*******************************led灯D1-D8*******************************/
//sfr P2   = 0xA0; 
sbit led_0 = P2^0;
sbit led_1 = P2^1;
sbit led_2 = P2^2;
sbit led_3 = P2^3;
sbit led_4 = P2^4;
sbit led_5 = P2^5;
sbit led_6 = P2^6;
sbit led_7 = P2^7;
/*******************************LCD1602*******************************/
sbit lcd_en = P2^7;
sbit lcd_rs = P2^6;
sbit lcd_rw = P2^5;
sbit lcd_0 = P0^0;
sbit lcd_1 = P0^1;
sbit lcd_2 = P0^2;
sbit lcd_3 = P0^3;
sbit lcd_4 = P0^4;
sbit lcd_5 = P0^5;
sbit lcd_6 = P0^6;
sbit lcd_7 = P0^7;
/*******************************LCD12864*******************************/
sbit lcd_psb = P2^0;
sbit lcd_nc = P2^1;
sfr lcd_com = 0x80;
sfr lcd_dat = 0x80;
#endif
bit GPIOT_String_Flag = 1; //输入输出清零标志
