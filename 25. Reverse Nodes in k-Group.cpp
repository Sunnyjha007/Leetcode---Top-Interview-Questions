class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        for(int i=0;i<k;i++){
            if(temp == NULL)return head;
            temp = temp->next;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        for(int i=0;i<k;i++){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head->next = reverseKGroup(curr,k);
        return prev;
    }
};

//iterative solution->
 ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = NULL;
        ListNode* prev = NULL;
        ListNode* nxt = NULL;
        ListNode* before = dummy;
        ListNode* after = head;
       while(true){
          ListNode* temp = after;
           for(int i=0;i<k;i++){
               if(temp == NULL)return dummy->next;
               temp = temp->next;
           }
           curr = after;
           prev = before;
           for(int i=0;i<k;i++){
               nxt = curr->next;
               curr->next = prev;
               prev = curr;
               curr = nxt;
           }
           after->next = curr;
           before->next = prev;
           before = after;
           after = curr;
       }
    }
