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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr)
            return head;
        
        vector<int> arr;
        ListNode* temp = head;
        
        // Store the values of the linked list in an array
        while (temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        // Perform the swap on the array (adjust indices for 0-based indexing)
        swap(arr[k - 1], arr[arr.size() - k]);
        
        // Reassign values back to the linked list
        temp = head;
        int i = 0;
        while (temp) {
            temp->val = arr[i++];
            temp = temp->next;
        }
        
        return head; // Return the head of the modified list
    }
};
