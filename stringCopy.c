#include<stdio.h>
#include<string.h>

void mystrcpy(char dest[],const char source[])
{
while((dest++ = source++)!='\0');
}

int main()
{
char s1[]="Hello";
char s2[]="World";

printf("Before Copy :\n");
printf("S1= %s S2= %s",s1,s2);
mystrcpy(s1,s2);
printf("After Copy :\n");
printf("S1= %s S2= %s",s1,s2);
getchar();
}
