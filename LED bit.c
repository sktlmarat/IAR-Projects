/*
@author Marat
Microcontroller: Stellaris LM4F120 LaunchPad
The code is same for Simple LED, however for changing a bits i used bitwise operation such shift, AND and etc.
*/
#define GREEN (1U << 3)
#define GPIOF (*(unsigned int *)0x400253FCU)
int main()
{
  int temp=0;
  *((unsigned int *)0x400FE608U)=(1U << 5); // setting 5th bit of clock , this allow us to unblock gpio ports (Shift to 5 bits) 
  *((unsigned int *)0x40025400U)=((1U << 1) | (1U << 2) | (1U << 3)); // setting bits 1,2,3 as output in GPIO e port (Done using shift operators and OR operator) 
  *((unsigned int *)0x4002551CU)=((1U << 1) | (1U << 2) | (1U << 3)); // setting bits 1,2,3 as output in digital function register

  while(1){
    GPIOF = GREEN; // setting 3rd bit in order light up green LED (In this case just shifted to three in order to set 3rd bit)
    while(temp < 99999){
      temp++;
    }
    GPIOF &= ~GREEN; // setting the bits to 0 in order to turn off the LED (In this case i used AND operator with complement, because this operation preserves all bits excluding the bit which was changed when lighted up to green) 
    while(temp < 99999){
      temp++;
    }
  }
  return 0;
}
