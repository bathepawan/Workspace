#include<stdio.h>
#include<string.h>

void reverse(char *str)
{
char t;
int l,i,j;
l=strlen(str);

for(i=0,j=l-1;i<=j;i++,j--)
{
t=str[i];
str[i]=str[j];
str[j]=t;
}
//str[l]='\n';
}

int main(int argc,char *argv[])
{
char s[]="This is test string";

printf("Original String: %s \n",s);

reverse(s);

printf("Reversed String: %s \n",s);

getchar();

}
