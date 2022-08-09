class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        if(!head1)return head2;
        if(!head2)return head1;
        ListNode* l1 = NULL;
        if(head1->val<=head2->val){
            l1 = head1;
            l1->next = mergeTwoLists(head1->next,head2);
        }else{
            l1 = head2;
            l1->next = mergeTwoLists(head1,head2->next);
        }
        return l1;
    }
};    
/*
if(!head1)return head2;
        if(!head2)return head1;
        ListNode* newhead = NULL;
        ListNode* newtail = NULL;
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        if(temp1->val<=temp2->val){
            newhead = temp1;
            newtail = temp1;
            temp1 = temp1->next;
        }else{
            newhead = temp2;
            newtail = temp2;
            temp2 = temp2->next;
        }
        while(temp1&&temp2){
            if(temp1->val<=temp2->val){
                newtail->next = temp1;
                newtail = temp1;
                temp1=temp1->next;
            }else{
                newtail->next = temp2;
                newtail = temp2;
                temp2=temp2->next;
            }
        }
        if(temp1)newtail->next = temp1;
        else newtail->next = temp2;
        return newhead;

*/
