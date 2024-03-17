#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int i=0,j=0,numframes,x,y,count=0;
char a[100];
printf("\n enter no of frames,: \n");
scanf("%d",&numframes);
for (i=0; i<numframes;i++)
{
printf("\n enter data %d: \n", i+1);
scanf("%c%*c",&a[i]);
x=rand()%10;
y=rand()%10;
printf("\n rondom numbers x and y are %d and %d ", x , y);
if(i==5)
{
printf("\n NAK & resending frame %d \n", i+1);
}
if((y!=x)&&(y>x)&&(count<=1))
{
count++;
sleep(1);
printf("\n Ack %d\n",i+1);
count=0;
}
}
sleep(3);
printf("\n End of sliding window protocol\n");
}
