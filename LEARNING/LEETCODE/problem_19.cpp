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
    int count(ListNode* temp) {
        if (temp == nullptr)
            return 0;
        return 1 + count(temp->next);
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = count(head);
        n = length - n;

        if (n == 0) {  // Special case: Remove the head node
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* temp = head;
        for (int i = 1; i < n; ++i) {  // Go to the node before the one to delete
            temp = temp->next;
        }

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};
