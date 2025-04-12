#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            start=mid+1;
        }
        else if (){
            end=mid-1;
        }
    mid=(start+end)/2;
    }
    return -1;
}
int main(){
    int odd[5]={3,7,88,99,101};
    int even[5]={1,4,5,8,10};
    int oddI=binarysearch(odd,5,88);
    cout<<"Index of key in array is"<<oddI<<endl;
    int evenI=binarysearch(even,5,10);
    cout<<"Index of key in array is"<<evenI<<endl;
    return 0;
}