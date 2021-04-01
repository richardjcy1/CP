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
    ListNode* reverse(ListNode* head)
    {
        if (!head) return NULL;
        ListNode* cur = head;
        ListNode* prev = NULL;
        while (cur)
        {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* cur = head;
        int cnt = 0;
        while (cur)
        {
            ++cnt;
            cur = cur->next;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        while (fast && fast->next)
        {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* right = NULL;
        if (cnt & 1)
        {
            right = slow;
        }
        else
        {
            prev->next = NULL;
            right = slow;
        }
        right = reverse(right);
        ListNode* left = head;
        while (left && right)
        {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        if (left || right) return false;
        return true;
    }
};