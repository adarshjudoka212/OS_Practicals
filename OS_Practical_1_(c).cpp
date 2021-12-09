#include <iostream> 
#include <sys/wait.h>
#include <unistd.h> 
using namespace std;
int main()
{
    pid_t id = fork();
{
    cout<<"\n Child Terminated";
}
{
    wait(NULL);
    cout<<"\n Parent Terminated";
}
return 0;
}