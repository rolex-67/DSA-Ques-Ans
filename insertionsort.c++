#include<iostream>
using namespace std;
int insertionsort(int arr[],int size){
    for(int i=1;i<size;i++){
        int temp=arr[i];
        int j=i-1;
      for( ; j>=0;j--){
        if(arr[j]>temp){
            arr[j+1]=arr[j];
        }
        else{
            break;
        }
      } 
      arr[j+1]=temp; 
    }
}
void pa(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}
int main(){
    int arr[6]={3,4,6,8,4,7};
    insertionsort(arr,6);
    cout<<"Sorted array:"<<endl;
    pa(arr,6);
}