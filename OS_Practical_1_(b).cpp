#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
using namespace std; 
int main()
{
int x; x=fork();
if(x==0){
execlp("/home/kali/Desktop/practical5","practical5",NULL);
}
else{
wait(NULL);
cout<<"Child completed\n";
}
return(0);
}