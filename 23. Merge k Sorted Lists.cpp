class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* temp = new ListNode(-1);
        ListNode* head = temp;
        while(a&&b){
            if(a->val<=b->val){
                temp->next = new ListNode(a->val);
                a = a->next;
            }else{
                temp->next = new ListNode(b->val);
                b = b->next;
            }
            temp = temp->next;
        }
        if(a)temp->next = a;
        if(b)temp->next = b;
        return head->next;
    }
    ListNode* mergeSort(vector<ListNode*>& lists,int si,int ei){
        if(si>ei)return NULL;
        if(si==ei)return lists[si];
        int mid = (si+ei)/2;
        ListNode* a = mergeSort(lists,si,mid);
        ListNode* b = mergeSort(lists,mid+1,ei);
        return merge(a,b);
        
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return mergeSort(lists,0,n-1);
    }
};
//priority queue
ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<lists.size();i++){
            ListNode* head = lists[i];
            while(head!=NULL){
                pq.push(head->val);
                head=head->next;
            }
         }
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            if(head==NULL){
                head = new ListNode(pq.top());
                tail = head;
                pq.pop();
            }else{
                tail->next = new ListNode(pq.top());
                pq.pop();
                tail=tail->next;
            }
        }
        return head;
        
        
    }
