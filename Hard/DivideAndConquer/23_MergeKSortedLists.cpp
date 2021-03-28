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
// Use priority queue to sort the head node
// and then find the smallest element among them
// Time complexity: O(nlogn)
// Space complexity: O(n)
struct CMP
{
    bool operator()(ListNode* a, ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, CMP> pq;
        for (int i = 0; i < n; i++)
        {
            if (lists[i]) pq.push(lists[i]);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (!pq.empty())
        {
            auto tmp = pq.top(); pq.pop();
            cur->next = tmp;
            cur = cur->next;
            if (tmp->next) pq.push(tmp->next);
        }
        return dummy->next;
    }
};