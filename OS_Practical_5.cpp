#include<iostream>
#include<fstream>
using namespace std;
int main()
{
ifstream fs;
ofstream ft;
char ch;
fs.open("practical5.txt");
if(!fs){
cout<<"ERROR in opening";
exit(1);
}
ft.open("copy.txt");
if(!ft){
cout<<"ERROR in opening";
fs.close();
exit(2); }while(fs.eof()==0){
fs>>ch;
ft<<ch;
}
cout<<"Copied Successfully";
fs.close();
ft.close();
return 0;
}