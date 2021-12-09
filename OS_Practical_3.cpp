#include <iostream>
#include <sys/sysinfo.h>
#include<unistd.h>
#include<string.h>
using namespace std;
void defVersion()
{
cout << "\nCPU type and model: \n";
system("grep 'model name' /proc/cpuinfo | awk '{print $4, $5, $6, $7, $8}'");
cout << "Kernel version: \n";
system("cat /proc/sys/kernel/osrelease");
cout << "Amount of time since the system was last booted: \n";
system("cat /proc/uptime | awk '{print $1\n}'");
cout<<"The configured memory is; \n";
system("cat /proc/meminfo | awk 'NR==1{print $2}'\n");
cout<<"Amount of free memory is: \n";system("cat /proc/meminfo | awk 'NR==2{print $2}'\n");
cout<<"Amount of used memory is: \n";
system("cat /proc/meminfo | awk '{if (NR==1) a=$2; if(NR==2) b=$2} END {print a-b}'\n");
}
int main(int ac, char *av[])
{
defVersion();
return 0;
}