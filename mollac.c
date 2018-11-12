#include<stdio.h>
#include<stdlib.h>

typedef unsigned long UINT32;

int main()
{
	
    // /*内存释放标志*/
	// int a = 1000;
    // int flag = 0;
    // char * p = (char *)malloc(200);
	// int b = 2000;
	// if (p == NULL)
    // {
        // /*...*/
    // }
	// printf("=====%p====\n", &a);
	// printf("=====%p====\n", &p);
	// printf("=====%p====\n", &b);
    // if (flag == 0)
    // {
        // free(p);
    // }
    // //free(p);
	
	
	UINT32 i;
    UINT32* ptr = malloc(4);
	printf("=====%x====\n",ptr);
    free(ptr);
	printf("=====%x====\n",ptr);
	
	UINT32* ptr1 = malloc(4);
	printf("=====%x====\n",ptr1);
	free(ptr);
	printf("=====end====\n");
	return 0;
}