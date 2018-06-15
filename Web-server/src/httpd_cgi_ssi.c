/**
  ******************************************************************************
  * @file    httpd_cg_ssi.c
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    31-October-2011
  * @brief   Webserver SSI and CGI handlers
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/

#include "main.h"
#include "httpd.h"

#include <string.h>
#include <stdlib.h>

uint32_t ADC_started=0;

// LED status and adc1 handle variables from main.c
extern char LEDs[4];
extern ADC_HandleTypeDef hadc1;

/* We will use single character "t" or "1" as tag for CGI.
  The tag "t" is "<!--t-->" in the html file.
  The length of the tag can be up to 8 characters.
*/
char const *TAGS[]= {"t","u","1","2","3","4"};

/* CGI handler for LED control */ 
const char * CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[]);

/* Html request for "/index.cgi" will start CGI_Handler */
const tCGI LEDS_CGI={"/index.cgi", CGI_Handler};

/* Cgi call table, only one CGI hanlder used */
tCGI CGI_TAB[1];

/**
  * @brief  SSI_Handler : SSI handler for the battery voltage page
  */
u16_t SSI_Handler(int iIndex, char *pcInsert, int iInsertLen)
{
  /* We have only one SSI handler iIndex = 0 */
  if (iIndex ==0)
  {  
    char Digit1=0, Digit2=0, Digit3=0, Digit4=0; 
    uint32_t ADCVal = 0;        

     /* configure ADC if not yet configured */
     if (!ADC_started)       
     {
				HAL_ADC_Start(&hadc1);
			  HAL_ADC_PollForConversion(&hadc1, 2);
        ADC_started = 1;
     }
     
     /* get ADC conversion value */
     //ADCVal = ADC_GetConversionValue(ADC3);
		 ADCVal = HAL_ADC_GetValue(&hadc1);
		 
     /* convert to Voltage,  step = 0.806 mV = 3300mV/4095 steps */
     ADCVal = (uint32_t)(ADCVal * 0.806 * 2.0);// the voltage is also scaled to a half
     
     /* get digits to display */
     Digit1= ADCVal/1000;
     Digit2= (ADCVal-(Digit1*1000))/100 ;
     Digit3= (ADCVal-((Digit1*1000)+(Digit2*100)))/10;
     Digit4= ADCVal -((Digit1*1000)+(Digit2*100)+ (Digit3*10));
        
     /* prepare data to be inserted in html */
     /**pcInsert       = (char)(Digit1+0x30);
     *(pcInsert + 1) = (char)('.');
     *(pcInsert + 2) = (char)(Digit2+0x30);
     *(pcInsert + 3) = (char)(Digit3+0x30);
     *(pcInsert + 4) = (char)(Digit4+0x30);*/
     //ftoa(pcInsert,ADCVal/1000.0,10);
     sprintf(pcInsert,"%5.3f",((float)ADCVal)/1000.0f);
    
    /* 5 characters need to be inserted in html*/
    return 5;
  } else if (iIndex == 1) { // Test tag "u" value
	    /* prepare data to be inserted in html */
	     *pcInsert       = (char)('1');
	     *(pcInsert + 1) = (char)('2');
	     *(pcInsert + 2) = (char)('3');
	     *(pcInsert + 3) = (char)('4');

	    /* 4 characters need to be inserted in html*/
	    return 4;
  } else if (iIndex >= 2 && iIndex <=5) { // Test tag "l1-l4" value
	    /* prepare data to be inserted in html */
	     if(LEDs[iIndex-2]) {
	       memcpy(pcInsert,"checked",7);
	    /* 7 characters need to be inserted in html*/
	      return 7;
	     }
  }
  return 0;
}

/**
  * @brief  CGI handler for LEDs control 
  */
const char * CGI_Handler(int iIndex, int iNumParams, char *pcParam[], char *pcValue[])
{
  uint32_t i=0;
  
  /* We have only one SSI handler iIndex = 0 */
  if (iIndex==0)
  {
    /* All leds off */
		//HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
		//HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);
    for(i=0;i<4;i++)
      LEDs[i]=0;
    
    /* Check cgi parameter : example GET /leds.cgi?led=2&led=4 */
    for (i=0; i<iNumParams; i++)
    {
      /* check parameter "led" */
      if (strcmp(pcParam[i] , "led")==0)   
      {
        /* switch led1 ON if 1 */
        if(strcmp(pcValue[i], "1") ==0){
          HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
          LEDs[0]=1;
        }
          
        /* switch led2 ON if 2 */
        else if(strcmp(pcValue[i], "2") ==0) {
          //HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
          LEDs[1]=1;
        }
        
        /* switch led3 ON if 3 */
        else if(strcmp(pcValue[i], "3") ==0) {
          //HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
          LEDs[2]=1;
        }
        
        /* switch led4 ON if 4 */
        else if(strcmp(pcValue[i], "4") ==0) {
          //HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
          LEDs[3]=1;
        }
      }
    }
  }
  /* uri to send after cgi call*/
  return "/index.shtml";
}

/**
 * Initialize SSI handlers
 */
void httpd_ssi_init(void)
{  
  /* configure SSI handlers (ADC page SSI) */
  http_set_ssi_handler(SSI_Handler, (char const **)TAGS, 6);
}

/**
 * Initialize CGI handlers
 */
void httpd_cgi_init(void)
{ 
  /* configure CGI handlers (LEDs control CGI) */
  CGI_TAB[0] = LEDS_CGI;
  http_set_cgi_handlers(CGI_TAB, 1);
}

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
