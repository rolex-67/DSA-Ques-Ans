#include<iostream>
using namespace std;
bool search(int arr[],int size,int key){
    for(int i=1;i<=size;i++){
        if(arr[i]==key){
            return 1;
        }
    }
    return 0;
}
int main(){
    int arr[6]={1,2,3,4,5,6};
    int key;
    cout<<"Enter value of key"<<endl;
    cin>>key;
    bool found=search(arr,5,key);
    if(found){
        cout<<"The key is present"<<endl;
    }
    else{
        cout<<"THE KEY IS NOT PRESENT"<<endl;
    }
}