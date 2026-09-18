class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     
        ListNode* dummy = new ListNode(0, head);
        ListNode* front = dummy;
        ListNode* back = dummy;

       
        for (int i = 0; i <= n; i++) {
            front = front->next;
        }

        while (front != nullptr) {
            front = front->next;
            back = back->next;
        }

        ListNode* nodeToDelete = back->next;
        back->next = back->next->next;
        
        delete nodeToDelete;

        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};