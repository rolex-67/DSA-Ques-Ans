#include<iostream>
using namespace std;
int main(){
    int arr[4]={10,20,30,40};
    int *ptr=&arr[0];
    cout<<ptr<<endl;
    cout<<&ptr<<endl;
    cout<<*ptr<<endl;
    cout<<arr<<endl;
    cout<<"\n*****\n"<<endl;
    char ch[6]="abcde";
    char *cr=&ch[0];
    cout<<cr<<endl;
    cout<<&cr<<endl;
    cout<<*cr<<endl;
    cout<<ch<<endl;

}
