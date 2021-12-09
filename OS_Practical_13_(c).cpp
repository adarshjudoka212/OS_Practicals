#include<iostream>
using namespace std;
void show(int block[],int burst[],int n,int c,int allocation[]){
cout<<"processes size "<<"Allocated at "<<"Block size\n";
for(int i=0;i<c;i++){
if(allocation[i]==-1){
cout<<burst[i]<<"\t\t"<<"Not Allocated\n";
}
else{
cout<<burst[i]<<"\t\t"<<allocation[i]+1<<"\t"<<block[allocation[i]]<<"\n";
}
}
}
void worst_fit(int block[],int burst[],int n,int c){
int allocation[c];
for(int i=0;i<c;i++)allocation[i] = -1;
int memoryused[n];
for(int i=0;i<n;i++)
memoryused[i]= 0;
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-1;j++)
{
if(block[j]<block[j+1])
{
int t=0;
t=block[j];
block[j]=block[j+1];
block[j+1]=t;
}
}
}
for(int i=0;i<c-1;i++)
{
for(int j=0;j<c-1;j++)
{
if(burst[j]>burst[j+1])
{
int t=0;
t=burst[j];
burst[j]=burst[j+1];
burst[j+1]=t;
}
}
}
for(int i=0;i<c;i++){//c=No of Processes
for(int j=0;j<n;j++){//j=No of blocks
if((block[j]-memoryused[j])>=burst[i]){
memoryused[j]+=burst[i];
allocation[i]=j;
j=n;
}}
}
show(block,burst,n,c,allocation);
}
int main(){
int n,c;
cout<<"No of Memory blocks you want to enter:-";
cin>>n;
int Block[n];
cout<<"Enter no of process u want";
cin>>c;
int Burst[c];
cout<<"Enter Size of memory blocks resp:-";
for(int i=0;i<n;i++)
cin>>Block[i];
cout<<"Enter Size of Processess resp:-";
for(int i=0;i<n;i++)
cin>>Burst[i];
worst_fit(Block,Burst,n,c);
}