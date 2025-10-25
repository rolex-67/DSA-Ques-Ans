/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL){
            return false;
        }
        ListNode* curr=head;
        map<ListNode*,bool> visited;
        while(curr!=NULL){
            if(visited[curr]==true){
                return true;
            }
            visited[curr]=true;
            curr=curr->next;
        }
        return false;

    }
};
