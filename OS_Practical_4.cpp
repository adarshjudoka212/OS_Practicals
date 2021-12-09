#include<sys/types.h>
#include<iostream>
#include<sys/stat.h>
using namespace std;
int main(int argc , char *argv[])
{
struct stat buf;
if(argc<2)
cout<<"\nError : Parameter too low";
else
{
stat(argv[1],&buf);
cout<<"\nFile Name : "<<argv[1];
cout<<"\nUser id : "<<buf.st_uid;
if(S_ISREG(buf.st_mode))
cout<<"\n"<<argv[1]<<" is a regular file";
else
cout<<"\n"<<argv[1]<<" is a directory";
cout<<"\npermissions :-";
if(buf.st_mode & 0400)
cout<<"\nOwner has read permission";if(buf.st_mode & 0200)
cout<<"\nOwner has write permission";
if(buf.st_mode & 0100)
cout<<"\nOwner has execute permission";
if(buf.st_mode & 0040)
cout<<"\nGroup has read permission";
if(buf.st_mode & 0020)
cout<<"\nGroup has write permission";
if(buf.st_mode & 0010)
cout<<"\nGroup has execute permission";
if(buf.st_mode & 0004)
cout<<"\nOthers has read permission";
if(buf.st_mode & 0002)
cout<<"\nOthers has write permission";
if(buf.st_mode & 0001)
cout<<"\nOthers has execute permission";
}
return 0;
}