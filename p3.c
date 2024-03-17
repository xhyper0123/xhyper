#include<stdio.h>
#include<string.h>
#include<conio.h>
#define N strlen(g)
char t[100]="0",cs[100]="0",g[]="10001000000100001";
int a=0,e=0,c=0;
void xor()
{
for(c=0;c<N;c++)
cs[c]=((cs[c]==g[c])?'0':'1');
}
void crc()
{
for(e=0;e<N;e++)
cs[e]=t[e];
do
{
if(cs[0]=='1')
xor();
for(c=0;c<N-1;c++)
cs[c]=cs[c+1];
cs[c]=t[e++];
}
while(e<=(a+N-1));
}
int main()
{
clrscr();
printf("enter the data\n");
scanf("%s",&t);
printf("\n generator polynomial:%s",g);
a=strlen(t);
for(e=a;e<a+N-1;e++)
t[e]='0';
printf("\n modified data is %s",t);
crc();
printf("\n check sum is %s",cs);
for(e=a;e<a+N-1;e++)
t[e]=cs[e-a];
printf("\n final code word is %s",t);
printf("\n test error detection 0(yes) 1(no)?");
scanf("%d",&e);
if (e==0)
{
do
{
printf("\n enter the position where error is to be inserted");
scanf("%d",&e);
}
while(e==0||e>a+N-1);
t[e-1]=((t[e-1]=='0')?'1':'0');
printf("\n errourns data:%s\n",t);
}
crc();
for(e=0;(e<N-1)&&(cs[e]!='1');e++);
if(e<N-1)
printf("\n error detected \n");
else
printf("\n no error detected \n");
getch();
return 0;
}
