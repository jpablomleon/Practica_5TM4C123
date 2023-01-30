#include "lib/include.h"

int main(void)
{

   uint8_t dc = 25;
   char data_str[32];
   uint16_t adc_data[3] = {0};
   uint32_t i = 0;
   uint32_t Ser1 = 0;
   uint32_t Ser2 = 0;
   uint32_t Ser3 = 0;

   uint16_t Result[2];
   uint16_t duty[2];
   Conf_PLL(_50MHZ);            
   //Conf_PLL(_20MHZ);              
   Conf_Reg_ADC0();
   Conf_UART3();
   Conf_GPIO(); 
   Conf_Reg_ADC0();
   Conf_Reg_PWM1(10000);
   delay_ms(1);
   PWM_DC(PWM0, 0);
   PWM_DC(PWM2, 0);
   PWM_DC(PWM4, 0); 

    while(1)
    {
        Lector_ADC(adc_data);
        Ser1 = 2 + adc_data[0] * (12/4095.0);
        Ser2 = 4 + adc_data[1] * (7/4095.0);
        Ser3 = 4 + adc_data[1] * (7/4095.0);
        PWM_DC(PWM0, Ser1);
        PWM_DC(PWM2, Ser2);
        PWM_DC(PWM4, Ser3);
        delay_ms(50);
        GPIO_output_toggle(PORTF, P1);
        //*/
    }

}
