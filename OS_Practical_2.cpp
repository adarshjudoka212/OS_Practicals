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
cout << "Amount of time since the system was last booted: \n"; system("cat /proc/uptime | awk '{print $1\n}'");
}
void secVersion()
{
cout << "\nPRINT IN AWK\n";
cout << "Amount of time user has spent in:\nUser mode:\n";
system("grep 'cpu' /proc/stat | awk 'NR == 1 {print $2}'"); cout << "System mode: \n";
system("grep 'cpu' /proc/stat | awk ' NR == 1 {print $4}'"); cout << "Idle: \n";
system("grep 'cpu' /proc/stat | awk 'NR == 1 {print $5}'");
cout << "\nSHELL SCRIPT\n";
cout << "Amount of time user has spent in:\n"; system("Q2SecVersion");
cout << "\nNumber of disk requests:\n"; system("grep 'intr' /proc/stat | awk '{print $17}'");
cout << "Number of context switches: \n"; system("grep 'ctxt' /proc/stat | awk '{print $2}'");
cout << "Time at which system was booted:\n"; system("grep 'btime' /proc/stat | awk '{print $2}'");
cout << "Time at which system was booted:\n"; system("Q2EpochToLocal");
cout << "Number of processes created:\n";
}

void thirdVersion(int a, int b)
{
struct sysinfo sInfo;
if (sysinfo(&sInfo) < 0)
{

cout << "\nError in finding information about the system"; 
exit(1);
}
cout << "\nAmount of memory configured into system: " << sInfo.totalram/1024 <<"KB";;
cout << "\nAmount of memory currently available: " << sInfo.freeram/1024 << "KB"; cout << "\nLoad averages: \n";
for (int i = 1; i <= b/a; i++)
{
cout << i << ". " << sInfo.loads[0] << "\n"; if (i == b/a) break;
sleep(a);
if (sysinfo(&sInfo) < 0)
{

cout << "\nError in finding information about the system"; exit(1);
}
}
}
int main(int ac, char *av[])
{
switch (ac){
case 1: defVersion(); break;
case 2: if (strcmp(av[1], "-s") == 0)
{
}
else
break;
defVersion(); secVersion();
cout << "\nInvalid option\n";
case 4: if (strcmp(av[1], "-l") == 0)
{
}
else
break;
defVersion(); secVersion();
thirdVersion(atoi(av[2]), atoi(av[3]));

cout << "\nInvalid option\n";

default: cout << "\nInvalid number of arguments\n";
}
}