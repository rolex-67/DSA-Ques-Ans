#include<iostream>
using namespace std;
int getSum(int *arr,int n){
    int s=0;
    for(int i=0;i<n;i++){
        s=s+arr[i];
    }
    return s;
}
int main() {
    int n;
    cout<<"EEnter n:";
    cin>>n;
    int *arr= new int[n];
    cout<<"Enter elements:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int r=getSum(arr,n);
    cout<<"Answer is:"<<r<<endl;
    return 0;
}