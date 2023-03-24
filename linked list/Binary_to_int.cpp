class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int n = head->val;
        while(head->next != NULL)
        {
            n = (n << 1) | head->next->val;
            head = head->next;
        }
        return n;

    }
};
