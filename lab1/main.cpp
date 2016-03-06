#include <stdio.h>
void MaxMin(int a, int b, int& max, int& min);
void MaxMin(int a, int b, int& max, int& min){
max=(a<b)?b:a;
min=(a<b)?a:b;
}
void main(){
4
int max, min, a=2, b=3;
MaxMin(a, b, max, min);
printf("\nmax(%d, %d) = %d", a, b, max);
printf("\nmin(%d, %d) = %d", a, b, min);
}
