/*
@author Marat
Just a simple performation of bitwise operations. If you want to check whether it is working press View>>Locals in order to see how variables change in IAR IDE.
*/
int main()
{
  unsigned int a= 0x7U;
  unsigned int b= 0x5U;
  unsigned int result;
  result = a | b; //OR
  result = a & b; //AND
  result = a^b; // XOR
  result = ~a; // NOT
  result = b >> 1; // Right shift
  result = b << 1; // Left shift
  
  return 0;
}
