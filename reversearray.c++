#include<iostream>
using namespace std;
int main(){
    int size,rev=0,num[100];
    cout<<"Enter size of an array:";
    cin>>size;
    for(int i=size;i=1;i--){
        cin>>num[i];
        rev=rev+num[i];
    }
}