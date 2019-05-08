/*
@author Marat
Microcontroller: Microcontroller: Stellaris LM4F120 LaunchPad
The loop while required to take some time before another light will on. the loop will take a little of time which will be enoght to see how light blinks. Otherwise without loop it will be impossible to see how light will change.
*/
int main()
{
   int temp=0;
  *((unsigned int *)0x400FE608U)=0*20U; // setting 5th bit of clock , this allow us to unblock gpio ports
  *((unsigned int *)0x40025400U)=0x0EU; // setting bits 1,2,3 as output in GPIO e port
  *((unsigned int *)0x4002551CU)=0x0EU; // setting bits 1,2,3 as output in digital function register

  while(1){
    *((unsigned int *)0x400253FCU)=0x08U; // setting 3rd bit in order light up green LED
    while(temp < 99999){
      temp++;
    }
    *((unsigned int *)0x400253FCU)=0x00U; // setting the bits to 0 in order to turn off the LED 
    while(temp < 99999){
      temp++;
    }
  }
  return 0;
}