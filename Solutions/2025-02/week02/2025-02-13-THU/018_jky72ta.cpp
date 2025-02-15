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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *n  = nullptr;
            static int round = 0;
            if (l1 == nullptr && l2 == nullptr)
                return (new ListNode());
            else
            {
                round = round + 1;
                n = addTwoNumbers((l1 != nullptr ? l1->next : l1), (l2 != nullptr ? l2->next : l2));
            }
                
            int a = 0;
            int b = 0;
            if (l1 != nullptr)
                a = l1->val;
            if (l2 != nullptr)
                b = l2->val;
            int num = a + b + n->val;
            n->val = num % 10;
            if (num >= 10)
            {
                ListNode* temp = n;
                while (num >= 10)
                {
                    if (temp->next == nullptr)
                    {
                        temp->next = new ListNode();
                    }
                    temp = temp->next;
                    num = num / 10;
                    num = temp->val + (num);
                    temp->val = num % 10;
                }
            }
            round = round - 1;
            if (round > 0)
            {
                return (new ListNode(0 , n));
            }
         
            return (n);
        }
    };