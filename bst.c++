#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelordertraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* inserttobst(Node* root, int d){
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data){
        root->right = inserttobst(root->right, d);
    }
    else{
        root->left = inserttobst(root->left, d);
    }
    return root;
}

void takeinput(Node* &root){
    int data;
    cin >> data;
    while(data != -1){
        root = inserttobst(root, data);
        cin >> data;
    }
}
//Max/min value in a tree
Node* minval(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
Node* maxval(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
Node* deletefrombst(Node* root,int val){
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1child
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL ){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //2child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minval(root->right)->data;
            root->data=mini;
            root->right=deletefrombst(root->right,mini);
        }

    }
    else if (root->data >val)
    {
        root->left=deletefrombst(root->left,val);
        return root;
    }
    else{
        root->right=deletefrombst(root->right,val);
        return root;
    }
}
int main(){
    Node* root = NULL;
    cout << "Enter data to create BST:" << endl;
    takeinput(root);
    cout << "Printing BST:" << endl;
    levelordertraversal(root);
    cout<<"Min value is "<<minval(root)->data<<endl;
    cout<<"Min value is "<<maxval(root)->data<<endl;
    root=deletefrombst(root, 11);

    cout << "Printing BST:" << endl;
    levelordertraversal(root);
    cout<<"Min value is "<<minval(root)->data<<endl;
    cout<<"Min value is "<<maxval(root)->data<<endl;
    return 0;
}
