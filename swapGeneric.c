#include<stdio.h>

void swap(void *a,void *b,int size)
{
char buffer[size];
memcpy(buffer,a,size);
memcpy(a,b,size);
memcpy(b,buffer,size);
}

int main(int argc,int **argv)
{
int n1=5,n2=7;
float f1=5.5,f2=7.7;
char c1='1',c2='2';

printf("Before Swapping\n");
printf("N1=%d N2=%d \n",n1,n2);
printf("F1=%.3f F2=%.3f \n",f1,f2);
printf("C1=%c C2=%c \n",c1,c2);

swap(&n1,&n2,sizeof(n1));
swap(&f1,&f2,sizeof(f1));
swap(&c1,&c2,sizeof(c1));

printf("After Swapping\n");
printf("N1=%d N2=%d \n",n1,n2);
printf("F1=%.3f F2=%.3f \n",f1,f2);
printf("C1=%c C2=%c \n",c1,c2);
getchar();
}

