#include "stm32f4xx.h"
#include "sys.h"
#include "tim.h"
#include "oled.h"
#include "main.h"


int hours, minutes, seconds = 0;


int main(void)
{
    TIM3_Init(ARR_VALUE, PSC_VALUE);
    OLED_Init();

    while (1)
    {
        if (seconds >= MAX_Min_Second)
        {
            seconds = 0;
            minutes++;
            if (minutes >= MAX_Min_Second)
            {
                minutes = 0;
                hours++;
                if (hours >= MAX_Hours)
                {
                    hours = 0;
                }
            }
        }
        displayTime();
    }
}

void displayTime(void)
{
    OLED_ShowChar(1, 7, ':');
    OLED_ShowChar(1, 10, ':');

		
	if(seconds<10)
	{
		OLED_ShowNum(1,12,seconds);
		OLED_ShowNum(1,11,0);
	}
	else OLED_ShowNum(1,11,seconds);
	
	if(minutes<10)
	{
		OLED_ShowNum(1,9,minutes);
		OLED_ShowNum(1,8,0);
	}
	else OLED_ShowNum(1,8,minutes);

	if(hours<10)
	{
		OLED_ShowNum(1,6,hours);
		OLED_ShowNum(1,5,0);
	}
	else OLED_ShowNum(1,5,hours);
}



