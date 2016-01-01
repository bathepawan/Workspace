int getGCD(int n1,int n2)
{
if(n2==0)
return n1;
else
return getGCD(n2,(n1%n2));
}
int main()
{
int n1,n2;
printf("Enter numbers: ");
scanf("%d %d",&n1,&n2);
printf("GCD = %d ",getGCD(n1,n2));
}
