#include<iostream>
using namespace std;
int main(){
    int r;
    cout<<"Enter rows:";
    cin>>r;
    int c;
    cout<<"Enter column:";
    cin>>c;
    int **arr=new int*[r];
    for(int i=0;i<r;i++){
        arr[i]=new int[c];
    //Dynamic memory allocation
    }
    //taking input
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
               cin>>arr[r][c];
        }
    }
    cout<<endl;
    //giving back elements
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr[r][c]<<" ";
        }
        cout<<endl;
    } 
    for(int i=0;i<r;i++){
        delete [] arr[i];
    }
    delete []arr; 
}