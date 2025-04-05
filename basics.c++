#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> s;
    s.push(40);
    s.push(34);
    s.pop();
    cout<<"The top element is:"<<s.top()<<endl;
    if(s.empty()){
        cout<<"Staxk is empty"<<endl;
    }
    else{
        cout<<"Staxk is not empty"<<endl;
    }
    

return 0;}