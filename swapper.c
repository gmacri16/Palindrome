//Gregory Macri
#include <stdio.h>

void swapWrong(int x,int y);
void swapRight(int *px,int *py);
int main()
{
  int x,y,a,b;
  int *px,*py,*pa,*pb;
  int array[2];
  array[0] = 6;
  array[1] = 4;
  a = array[0];
  b = array[1];
  x = 7;
  y = 14;
  px = &x;
  py = &y;
  pa = &array[0];
  pb = &array[1];

  printf("The values X and Y are equal to: %d and %d\n", x, y);
 
  swapWrong(x,y);
  printf("After the wrong swap, the values X and Y are equal to: %d and %d\n", x, y);
  
  swapRight(px,py);
  printf("After the right swap, the values X and Y are equal to: %d and %d\n", x, y);
  
  printf("In an array, the values of the first and second slots are: %d and %d\n", array[0],array[1]);
  
  swapWrong(a,b);
  printf("In an array, the values of the first and second slots after the wrong swap are: %d and %d\n", array[0],array[1]);
  
  swapRight(pa,pb);
  printf("In an array, the values of the first and second slots after the right swap are: %d and %d\n",array[0],array[1]);
  
  return 0;
}

void swapWrong(int x, int y)
{
  int temp;

  temp = x;
  x = y;
  y = temp;
}

void swapRight(int *px, int *py)
{
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
