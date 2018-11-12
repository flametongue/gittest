#include<stdio.h>
int main ()
{
	int i = 1;
	printf("====%d===\n",i);
	printf("====%d===\n",&i);
	printf("====%x===\n",&i);
	int* j = 2;
	printf("====%d===\n",j);
	printf("====%d===\n",&j);
	printf("====%x===\n",&j);
	
	printf("=======\n");
	return 0;
}