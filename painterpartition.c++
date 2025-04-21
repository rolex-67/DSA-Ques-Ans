#include<iostream>
using namespace std;
bool Partition(int arr[],int size,int key,int mid){
    int paintercount=1;
    int simultaneus_sum=0;
    for(int i=0;i<size;i++){
        if(simultaneus_sum+arr[i]<=mid){
            simultaneus_sum=simultaneus_sum+arr[i];
        }
        else{
            paintercount++;
            if(paintercount>=key || arr[i]>mid){
                return false;
            }
            simultaneus_sum=arr[i];
        }
    }
    return true;
}
int Painter(){
    int arr[4]={5,5,5,5};
    int key=2;
    int size=4;
    int start=0;
    int sum=0;
    for(int i=0;i<size;i++){
        cout<<"Enter elements:";
        cin>>arr[i];
        sum=sum+arr[i];
    }
    int end=sum;
    int mid=start+end/2;
    int ans=-1;
    while(start<=end){
        if(Partition(int arr[4]={5,5,5,5};int key=2;int size=4;)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+end/2;
}
}