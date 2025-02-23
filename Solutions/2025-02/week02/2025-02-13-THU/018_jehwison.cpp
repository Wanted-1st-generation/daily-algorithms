class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* dummyNode = new ListNode(0);
        ListNode* currentNode = dummyNode;

        bool isRoundUp = false;

        while (isRoundUp ||
            l1 != nullptr || l2 != nullptr)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + (isRoundUp ? 1 : 0);
            isRoundUp = sum >= 10;

            // First Dummy node's value is always zero
            currentNode->next = new ListNode(sum % 10);
            currentNode = currentNode->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        ListNode* result = dummyNode->next;
        delete dummyNode;
        return result;
    }
};
