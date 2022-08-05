 ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        if(fast==NULL){
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;
        }
        ListNode* slow = head;
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* node = slow->next;
        slow->next = slow->next->next;
        delete node;
        return head;
    }
};


//another approach
int length(ListNode* head){
        if(!head)return 0;
        return (1+length(head->next));
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        ListNode* temp = head;
        if(len==n){
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;
        }
        for(int i=0;i<len-n-1;i++){
            temp = temp->next;
        }
        ListNode* node = temp->next;
        temp->next = temp->next->next;
        delete node;
        return head;
    }
