BEGIN{
recd=0
drop=0
}
{
if($1=="r"&&$4=="4"&&$5=="tcp"&&$6=="1540")
{
recd++;
}
if($1=="d"&&$3=="
3"&&$5=="tcp"&&$6=="1540")
{
drop++;
}
}
END{
printf("\n total number of data packets received at Node 3: %d\n", recd++);
printf("\n total number of packets dropped at Node 3: %d\n", drop++);
}
