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
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* fastpointer = head;
        ListNode* slowpointer = head;

        // Move fastpointer by 2 steps and slowpointer by 1 step
        while (fastpointer != nullptr && fastpointer->next != nullptr) {
            slowpointer = slowpointer->next;
            fastpointer = fastpointer->next->next;
        }

        // slowpointer is now at the middle node
        return slowpointer;
    }
};
