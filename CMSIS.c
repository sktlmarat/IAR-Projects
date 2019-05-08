/*
@author Marat
Here i will use predefined structs in order to perform blink. These structs can be found in the header file cmsis that i defined in the code
*/
#include <stdint.h> // header file which defined in library has integers which has specified size such as int8_t and etc, required for tm4c_cmsis file.
#include "tm4c_cmsis.h"
#define GREEN (1U << 3)
int main()
{
   int temp=0;
   SYSCTL->RCGC2 |= (1U << 5); 
   GPIOF_HS->DIR |= ((1U << 1) | (1U << 2) | (1U << 3));
   GPIOF_HS->DEN |= ((1U << 1) | (1U << 2) | (1U << 3));             
     while(1) {
       GPIOF_HS->DATA_Bits[GREEN]=GREEN; 
        while(temp < 99999){
          temp++;
        }
       GPIOF_HS->DATA_Bits[GREEN] = 0; 
        while(temp < 99999){
          temp++;
          }
     }
       return 0;
}
