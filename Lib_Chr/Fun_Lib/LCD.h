//void LCD_RC(){

//}

//void LCD_RD(){

//}





void LCD_Busy(){
		uchar test = 0xff;
	//STA7 == 1��ֹ��д
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
	*������������������̱�
	*������;���ο�
	*˵��:
	*��ע��
*/
void LCD_WC(uchar com){    //1602
	LCD_Busy();
	lcd_en = 0;
	lcd_rs = 0;
	lcd_rw = 0;
	lcd_com = com;  //׼�������ݺ�rs��rw��дλ
	Delay(50);      //�ȶ�		
	lcd_en = 1;     
	Delay(80);      //��E�㹻ʱ��ĸߵ�ƽ�Զ�ȡ����
	lcd_en = 0;
}





/**
	*������������������̱�
	*������;���ο�
	*˵��:
	*��ע��
*/
void LCD_WD(uchar dat){    //1602
	LCD_Busy();
	lcd_en = 0;
	lcd_rs = 1;
	lcd_rw = 0;
	lcd_dat = dat; //׼�������ݺ�rs��rw��дλ
	Delay(50);      //�ȶ�		
	lcd_en = 1;
	Delay(80);     //��E�㹻ʱ��ĸߵ�ƽ�Զ�ȡ����
	lcd_en = 0;
}





/**
	*������������������̱�
	*������;���ο�
	*˵��:
	*��ע��
*/
void LCD_Init(){   //1602
//	LCD_WC(0x01);  //�������㣬ָ�����㣬�������Init�˴�������ڶ������ñ��������(����֤)
	lcd_en = 0;
	LCD_WC(0x38);  //16*2��ʾ��5*7����8λ���ݽӿ�
	LCD_WC(0x0f);  //����ʾ����ʾ��꣬�����˸
	LCD_WC(0x06);  //��ַ�Զ���һ
	LCD_WC(0x80);  //ָ���λ	
}






/**
	*������������������̱�
	*������;���ο�
	*˵��:
	*��ע��
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
