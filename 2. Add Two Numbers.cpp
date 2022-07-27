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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h1 = l1,*h2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* curr=head;
        int sum=0,carry=0;
        while(h1||h2){
            sum = (h1?h1->val:0) + (h2?h2->val:0) + carry;
            carry = sum/10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
            if(h1)h1 = h1->next;
            if(h2)h2 = h2->next;
        }
        if(carry)curr->next = new ListNode(carry);
        return head->next;
    }
};
