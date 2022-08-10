class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
    if(!head||!head->next)return head;
        ListNode* dummynode = new ListNode(-1);
        ListNode* prev = dummynode;
        ListNode* curr = head;
        while(curr&&curr->next){
            prev->next = curr->next;
            curr->next = prev->next->next;
            prev->next->next = curr; 
            prev = curr;
            curr = curr->next;
        }
        return dummynode->next;
    }
};

/*
 ListNode* swapPairs(ListNode* head) {
    if(!head||!head->next)return head;
        ListNode* newhead = head->next->next;
        ListNode* temp = head->next;
        head->next = newhead;
        temp->next = head;
        head->next = swapPairs(newhead);
        return temp;
    }
*/
