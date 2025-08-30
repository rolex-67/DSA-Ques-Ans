/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node* curr=head;
        int len=0;
        while(curr!=NULL){
            curr=curr->next;
            len++;
        }
        if(k>len){
            return -1;
        }
        Node* temp=head;
        for(int i=1;i<len-k+1;i++){
            temp=temp->next;
        }
        return temp->data;
        
        
    }
};
