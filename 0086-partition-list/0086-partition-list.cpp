/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* left = new ListNode();
        ListNode* orileft = left;
        ListNode* right = new ListNode();
        ListNode* oriright = right;

        ListNode* curr = head;

        while(curr != NULL){
            if(curr -> val < x){
                left -> next = curr;
                left = left -> next;
            }
            else{
                right -> next = curr;
                right = right -> next;
            }
            curr = curr -> next;
        }

        left -> next = oriright -> next;
        right -> next = NULL;
        return orileft -> next;
    }
};