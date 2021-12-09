#include<iostream>
using namespace std;
// Function to find the waiting time for all
// processes
void findWaitingTime(int processes[], int n,
int bt[], int wt[],int at[])
{
// waiting time for first process is 0
wt[0] = 0;
// calculating waiting time
for (int i = 1; i < n ; i++ )
wt[i] = bt[i-1] + wt[i-1]-at[i] ;
}
// Function to calculate turn around time
void findTurnAroundTime( int processes[], int n,
int bt[], int wt[], int tat[],int at[])
{
// calculating turnaround time by
// bt[i] - at[i]
for (int i = 0; i < n ; i++)
tat[i] = bt[i]+wt[i] -at[i];
}
//Function to calculate average time
void findavgTime( int processes[], int n, int bt[],int at[])
{
int wt[n], tat[n], total_wt = 0, total_tat = 0;
//arranging places according to the arrival_time
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n+1;j++)
{
if(at[j]>at[j+1]){
int t=0;
t=at[j];
at[j]=at[j+1];
at[j+1]=t;
t=processes[j];
processes[j]=processes[j+1];
processes[j+1]=t;
t=bt[j];
bt[j]=bt[j+1];
bt[j+1]=t;
}
}
}
//Function to find waiting time of all processes
findWaitingTime(processes, n, bt, wt,at);
//Function to find turn around time for all processes
findTurnAroundTime(processes, n, bt, wt, tat,at);
//Display processes along with all details
cout << "Processes "<<"Arrival time"<< " Burst time "
<< " Waiting time " << " Turn around time\n";
// Calculate total waiting time and total turn
// around time
for (int i=0; i<n; i++)
{
total_wt = total_wt + wt[i];
total_tat = total_tat + tat[i];
cout << " " << processes[i] << "\t\t"<<at[i]<<"\t\t" << bt[i] <<"\t "
<< wt[i] <<"\t\t " << tat[i] <<endl;
}
cout << "Average waiting time = "
<< (float)total_wt / (float)n;
cout << "\nAverage turn around time = "
<< (float)total_tat / (float)n;
}
// Driver codeint main()
int main()
{
int n;
cout<<"enter no of process u want :-";
cin>>n;
int processes[n];
int burst_time[n];
int arrival_time[n];
for(int i=0;i<n;i++){
processes[i]=i+1;
//process id's
cout<<"Enter Burst_time of process no "<<i+1<<" :"; //burst_time
cin>>burst_time[i];
cout<<"Enter Arrival_time of process no"<<i+1<<" :" ; //arrival_time
cin>>arrival_time[i];
}
findavgTime(processes, n, burst_time,arrival_time);
return 0;
}