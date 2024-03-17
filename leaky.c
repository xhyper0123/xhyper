#include<stdio.h>
#include<unistd.h>
int main()
{
int incoming,outgoing,bucksize, initialval,count,ans,store=0;
printf("enter bucket size, outgoing rate and counter initial size:");
scanf("%d %d %d",&bucksize, &outgoing, &initialval);
count=initialval;
while(count!=0)
{
printf("enter the incoming packet size:");
scanf("%d", &incoming);
printf("incoming packet size %d \n", incoming);
if(incoming<=(bucksize-store))
{
store+=incoming;
printf("bucket contains %d out of %d\n", store,bucksize);
}
else
{
printf("dropped %d no of packets\n", incoming -(bucksize-store));
store=bucksize;
printf("bucket now contains %d out of %d\n", store,bucksize);
}
store=store-outgoing;
sleep(5);
printf("after outgoing %d pkts left in bucket \n",store);
if (count<=incoming)
{
printf("do you want to continue? type 1 to continue");
scanf("%d", &ans);
if(ans!=1)
break;
count=initialval;
}
count=count-incoming;
printf("count=%d\n", count);
}
}
