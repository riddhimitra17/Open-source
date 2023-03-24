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
    ListNode* removeElements(ListNode* head, int v) {
        
        
        while(head!=NULL)
        {
            if (head->val==v) 
            {
                head = head->next;
                    
            }
            else 
            {
                ListNode* temp = NULL;
                ListNode* prevptr = head;
                ListNode* currentptr = head->next;
                while (currentptr!=NULL)
                {
                    if (currentptr->val == v)
                    {
                        temp=currentptr;
                        currentptr=NULL;          
                                        
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr=currentptr->next;
                    }
                }
                if (temp!=NULL) 
                {
                    prevptr->next=temp->next;
                    //return head;
                }
                else 
                return head;
        
                
            
            }
        }
        return head;
    }
};
