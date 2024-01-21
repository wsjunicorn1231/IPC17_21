#include "stm32f4xx.h"
#include "sys.h"
#include "tim.h"
#include "oled.h"

#define arr 5000		
#define psc 8400	
#define Line 1			
#define Column 5	
#define Max_min_second 60		
#define Max_hours 24		
#define Initial_value 0		
#define ten 10	
#define Display_zero 0		
	


int hours, minutes, seconds;		
void Time_calculation(void);
void OLED_display_time(void);

int main(void)
{
	TIM3_Init(arr,psc);
	OLED_Init();
	
	while(1)
	{
		Time_calculation();
		OLED_display_time();
	}
}





void Time_calculation(void)
{
	if(seconds > Max_min_second)
	{
		seconds=Initial_value;
		minutes++;
	}
	else if(minutes>Max_min_second)
	{
		minutes=Initial_value;
		hours++;
	}
	else if(hours>Max_hours) 
	{
		hours=Initial_value;
	}
}

void OLED_display_time(void)
{
	OLED_ShowChar(Line,Column+2,':');
	OLED_ShowChar(Line,Column+5,':');
	
	if(seconds<ten)
	{
		OLED_ShowNum(Line,Column+7,seconds);
		OLED_ShowNum(Line,Column+6,Display_zero);
	}
	else OLED_ShowNum(Line,Column+6,seconds);
	
	if(minutes<ten)
	{
		OLED_ShowNum(Line,Column+4,minutes);
		OLED_ShowNum(Line,Column+3,Display_zero);
	}
	else OLED_ShowNum(Line,Column+3,minutes);

	if(hours<ten)
	{
		OLED_ShowNum(Line,Column+1,hours);
		OLED_ShowNum(Line,Column,Display_zero);
	}
	else OLED_ShowNum(Line,Column,hours);
}



