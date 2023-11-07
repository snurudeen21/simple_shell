#include <stdio.h>
/**
 *main-Entry point.
 *Return: return 0 after the main function run successfully
*/
int main(void)
{
	int a = 4;
  int *ptr = &a;
  *ptr = 10;
  
  printf(" Pointer has done its thing. a = %d", a);
  
	return (0);
}
