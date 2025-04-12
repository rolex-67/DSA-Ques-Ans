#include<iostream>
using namespace std;
int binaryS(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=start+end/2;
    int ans=-1;
    while (start<=end){
        if(key==arr[mid]){
            ans=mid;
            end=mid-1;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return ans;
}
int binaryf(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=start+end/2;
    int ans=-1;
    while (start<=end){
        if(key==arr[mid]){
            ans=mid;
            start=mid+1;
        }
        if(key>arr[mid]){
            start=mid+1;
        }
        else if(key<arr[mid]){
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return ans;
}
int main(){
    int data[5]={1,2,3,4,5};
    cout<<"THe left ouccerence of the is:"<<binaryS(data,5,2);
    cout<<"THe right ouccerence of the is"<<binaryf(data,5,2);
    return 0;
}