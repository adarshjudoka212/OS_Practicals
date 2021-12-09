#include<iostream>
using namespace std;
int ct=0,i=0,wp[25]={0},comp[25];
void findTurnAroundTime(int i,int at[],int tat[],int qt)
{
// calculating turnaround time by
//complete at- start at
tat[i] = qt-at[i];
comp[i]=qt;
//cout<<"\nct"<<comp[i]<<" ------------------------------------ 3";
}
void findWaitingTime(int tat[], int n, int bt[], int wt[])
{ //calculating waiting time by
//turn around time -burst btime
for(int i=0;i<n;i++)
{
wt[i]=tat[i]-bt[i];
}
}
void waitingQueue(int dup_bt[],int n,int processes[],int at[],int tat[])
{
for(int i=0;i<n;i++)
{
if(dup_bt[i]!=0)
{
int j=0;
j=ct;
ct=ct+dup_bt[i];
dup_bt[i]=0;
findTurnAroundTime(i,at,tat,ct);
cout<<"\n ~~~~~~\n";
cout<<j<<" |"<<" P"<<processes[i]<<" | "<< ct
<<"\n";//<<"\t"<<at[j]<<"\t"<<quantum1<<"\n";
cout<<" ~~~~~~";
}
}
}
void ReadyQueue(int processes[],int bt[],int at[],int n,int pri[])
{
int dup_bt[n],tat[n],wt[n];
//arranging places according to the PRIORITY
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-1;j++)
{
if(pri[j]<pri[j+1])
{
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
t=pri[j];
pri[j]=pri[j+1];
pri[j+1]=t;
}
else if(pri[j]==pri[j+1]&&at[j]>at[j+1])
{
int t=0;
t=at[j];
at[j]=at[j+1];
at[j+1]=t;
t=processes[j];
processes[j]=processes[j+1];
processes[j+1]=t;
t=bt[j];
bt[j]=bt[j+1];
bt[j+1]=t;t=pri[j];
pri[j]=pri[j+1];
pri[j+1]=t;
}
}
}
//show
cout << "\nProcesses "<< " Arrival time "<< " Burst time "<<"Priotrity \n";
for (int i=0; i<n; i++)
{
cout << " " << processes[i] <<"\t\t"<<at[i] <<"\t\t"<< bt[i] <<"\t<< pri[i]" <<"\t "<<endl;
}
for (int i = 0 ; i < n ; i++)
dup_bt[i] = bt[i];
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
if(dup_bt[j]!=0)
{
if(ct==at[j]||ct>at[j])
{
int l=0;
l=ct;
ct=ct+dup_bt[j];
dup_bt[j]=0;
findTurnAroundTime(j,at,tat,ct);
cout<<"\n ~~~~~~\n";
cout<<l<<" |"<<" P"<<processes[j]<<" | "<< ct
<<"\n";//<<"\t"<<at[j]<<"\t"<<quantum1<<"\n";
cout<<" ~~~~~~";
j=n;
//cout<<"\n5";
}
}
}
}
waitingQueue(dup_bt,n,processes,at,tat);
findWaitingTime(tat,n,bt,wt);
cout<< "\nProcesses "<< " Burst time "<<"\tArrival time "<<"turn around Time"<<"Complition Time"
<<"waiting Time"<<"\n";
for (int i = 0 ; i < n ; i++)
cout<<processes[i]<<"\t\t "<<bt[i]<<"\t\t "<<at[i]<<"\t\t "<<tat[i]<<"\t\t "
<<comp[i]<<"\t\t "<<wt[i]<<"\n";
}
//main code
int main()
{
int n;
cout<<"enter no of process u want :-";
cin>>n;
int processes[n];
int burst_time[n];
int arrival_time[n];
int priority[n];
for(int i=0;i<n;i++){
processes[i]=i+1;
//process id's
cout<<"Enter Burst_time of process no "<<i+1<<" :"; //burst_time
cin>>burst_time[i];
cout<<"Enter Arrival_time of process no"<<i+1<<" :";
cin>>arrival_time[i];
cout<<"Enter Priority of process no"<<i+1<<" :";
cin>>priority[i];
}
cout<<"input :- \n";
cout << "Processes "<< " Arrival time "<< " Burst time "<<"Priotrity \n";
for (int i=0; i<n; i++)
{
cout << " " << processes[i] <<"\t\t"<<arrival_time[i] <<"\t\t"<< burst_time[i] <<"\t"<< priority[i] <<"\t"<<endl;
}
ReadyQueue(processes,burst_time,arrival_time,n,priority);
return(0);
}
