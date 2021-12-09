#include<iostream>
using namespace std;
// Function to find the waiting time for all
// processes
void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
// Make a copy of burst times bt[] to store remaining
// burst times.
int rem_bt[n];
for (int i = 0 ; i < n ; i++)
rem_bt[i] = bt[i];
int t = 0;
// Keep traversing processes in round robin manner
// until all of them are not done.
while (1)
{
bool done = true;
// Traverse all processes one by one
for (int i = 0 ; i < n; i++)
{
// If burst time of a process is greater than 0// then only need to process further
if (rem_bt[i] > 0)
{
done = false;
if (rem_bt[i] > quantum)
{
// Increase the value of t i.e. shows
// how much time a process has been processed
t += quantum;
// Decrease the burst_time of current process
// by quantum
rem_bt[i] -= quantum;
}
// If burst time is smaller than or equal to
// quantum. Last cycle for this process
else
{
// Increase the value of t i.e. shows
// how much time a process has been processed
t = t + rem_bt[i];
// Waiting time is current time minus time
// used by this process
wt[i] = t - bt[i];// As the process gets fully executed
// make its remaining burst time = 0
rem_bt[i] = 0;
}
}
}
if (done == true)
break;
}
}
void findTurnAroundTime(int processes[], int n,
int bt[], int wt[], int tat[])
{
for (int i = 0; i < n ; i++)
tat[i] = bt[i] + wt[i];
}
// Function to calculate average time
void findavgTime(int processes[], int n, int bt[],
int quantum)
{
int wt[n], tat[n], total_wt = 0, total_tat = 0;
// Function to find waiting time of all processesfindWaitingTime(processes, n, bt, wt, quantum);
// Function to find turn around time for all processes
findTurnAroundTime(processes, n, bt, wt, tat);
cout << "Processes "<< " Burst time "
<< " Waiting time " << " Turn around time\n";
// Calculate total waiting time and total turn
// around time
for (int i=0; i<n; i++)
{
total_wt = total_wt + wt[i];
total_tat = total_tat + tat[i];
cout << " " << i+1 << "\t\t" << bt[i] <<"\t "
<< wt[i] <<"\t\t " << tat[i] <<endl;
}
cout << "Average waiting time = "
<< (float)total_wt / (float)n;
cout << "\nAverage turn around time = "
<< (float)total_tat / (float)n;
}
int main()
{int n;
cout<<"enter the number of preocesses"<<endl;
cin>>n;
int processes[n];
cout<<"enter the processes"<<endl;
for(int i=0;i<n;i++)
{
cin>>processes[i];
}
cout<<"enter burst time"<<endl;
int burst_time[n];
for(int i=0;i<n;i++)
{
cin>>burst_time[i];
}
// Time quantum
int quantum ;
cout<<"enter the value of quantum time"<<endl;
cin>>quantum;
findavgTime(processes, n, burst_time, quantum);
getchar();
getchar();return 0;
}