#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
main()
{
char ip1c[40],*ip3c[40],subnet1c[40],*ip4c[40];
unsigned int uip3,ip2u,subnet2u;
int i,s;
struct in_addr ip_struct,ip_struct1,subnet_struct,subnet1_struct;
printf("enter the ip Address\n");
scanf("%s",&ip1c);
i=inet_aton(ip1c,&ip_struct);
printf("%d",i);
ip2u=ntohl(ip_struct.s_addr);
printf("\nEnter the subnet mask Address\n");
scanf("%s",subnet1c);
s=inet_aton(subnet1c,&subnet_struct);
printf("%d",s);
subnet2u=ntohl(subnet_struct.s_addr);
if(i==1 && s==1)
{
printf("ip address is %x\n subnet mask address is %x\n revers ip address %x\nreverse subnet mask address %x\n",ip_struct.s_addr,subnet_struct.s_addr,ip2u,subnet2u);
uip3=ip2u;
ip2u=ip2u&subnet2u;
ip_struct1.s_addr=htonl(ip2u);
uip3=uip3&(~subnet2u);
ip3c[0]=inet_ntoa(ip_struct1);
printf("\nThe network address is %s\n",*ip3c);
printf("host ip address is:%x\n",uip3);
}
else
{
printf("not a valid address");
}
}

