//void LCD_RC(){

//}

//void LCD_RD(){

//}





void LCD_Busy(){
		uchar test = 0xff;
	//STA7 == 1禁止读写
	do{
		test = 0xff;
		lcd_en = 0;
		lcd_rw = 1;
		lcd_rs = 0;
		lcd_en = 1;
		test = P0;
	}while(0x80 & test);//0x80 = 1000_0000
	lcd_en = 0;
}




/**
	*函数中文名：矩阵键盘表
	*函数用途：参考
	*说明:
	*备注：
*/
void LCD_WC(uchar com){    //1602
	LCD_Busy();
	lcd_en = 0;
	lcd_rs = 0;
	lcd_rw = 0;
	lcd_com = com;  //准备好数据和rs、rw读写位
	Delay(50);      //稳定		
	lcd_en = 1;     
	Delay(80);      //给E足够时间的高电平以读取数据
	lcd_en = 0;
}





/**
	*函数中文名：矩阵键盘表
	*函数用途：参考
	*说明:
	*备注：
*/
void LCD_WD(uchar dat){    //1602
	LCD_Busy();
	lcd_en = 0;
	lcd_rs = 1;
	lcd_rw = 0;
	lcd_dat = dat; //准备好数据和rs、rw读写位
	Delay(50);      //稳定		
	lcd_en = 1;
	Delay(80);     //给E足够时间的高电平以读取数据
	lcd_en = 0;
}





/**
	*函数中文名：矩阵键盘表
	*函数用途：参考
	*说明:
	*备注：
*/
void LCD_Init(){   //1602
//	LCD_WC(0x01);  //数据清零，指针清零，必须放在Init此处，否则第二行设置被暴力清除(待验证)
	lcd_en = 0;
	LCD_WC(0x38);  //16*2显示，5*7点阵，8位数据接口
	LCD_WC(0x0f);  //开显示，显示光标，光标闪烁
	LCD_WC(0x06);  //地址自动加一
	LCD_WC(0x80);  //指针初位	
}






/**
	*函数中文名：矩阵键盘表
	*函数用途：参考
	*说明:
	*备注：
*/
void LCD_String(uchar* string_ , bit row){  //1602
	if(!row){
		LCD_WC(0x80);
		do{
			LCD_WD(*string_++);
			}while(*string_);
	}
	if(row){
		LCD_WC(0xc0);
		do{
			LCD_WD(*string_++);
			}while(*string_);
	}
}
