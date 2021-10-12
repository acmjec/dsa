class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n=0;
        int m=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=NULL){
            n++;
            temp1=temp1->next;
        }
         while(temp2!=NULL){
            m++;
            temp2=temp2->next;
        }
          ListNode* tempa=headA;
        ListNode* tempb=headB;
        int x=abs(m-n);
        if(m>n){
            while(x--){
                tempb=tempb->next;
            }
        }
          else{
            while(x--){
                tempa=tempa->next;
            }
        }
        while(tempa!=tempb){
            tempa=tempa->next;
            tempb=tempb->next;
            
        }
        return tempa;
        
        
    }
};