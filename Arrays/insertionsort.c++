#include<iostream>
#include<vector>
using namespace std;
int sort(vector<int> &arr,int n){
    for(int i=0;i<n;i++){
        int curr=arr[i];
        int prev=i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1]=curr;
    }
}
int main(){
int n;
cout<<"Enter the size"<<endl;
cin>>n;

vector<int> arr;
for (int i=0; i<n; i++) {
    int val;
    cin>>val;
    arr.push_back(val);
}
sort(arr,n);
for(auto i:arr){
    cout<<i<<" ";
}
return 0;
}