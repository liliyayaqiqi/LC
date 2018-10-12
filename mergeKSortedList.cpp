/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * Example:
 * Input:
 * [
 *  1->4->5,
 *  1->3->4,
 *  2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// slow test new linked-list and copy value into it
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
        {
            return nullptr;
        }
        bool finish = false;
        ListNode * head = nullptr;
        ListNode * current = nullptr;
        while (!finish)
        {
            int minimum = INT_MAX;
            int minimumIndex = -1;
            for (int i = 0; i < lists.size(); ++i)
            {
                auto ptr = lists[i];
                if (ptr != nullptr)
                {
                    if (ptr->val < minimum)
                    {
                        minimum = ptr->val;
                        minimumIndex = i;
                    }
                }
            }
            if (minimumIndex == -1)
            {
                finish = true;
            }
            else
            {
                ListNode * newNode = new ListNode(minimum);
                if (current != nullptr)
                {
                    current->next = newNode;
                }
                else
                {
                    head = newNode;
                }
                current = newNode;
                lists[minimumIndex] = lists[minimumIndex]->next;
            }
        }
        return head;
    }
};

//compare one by one using priority queue
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * dummyHead = new ListNode(0);
        auto cmp = [](const ListNode * l1, const ListNode * l2){
            return l1 != nullptr && l2 != nullptr && l1->val > l2->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq;
        for (auto node : lists)
        {
            if (node)
            {
                pq.push(node);
            }
        }
        ListNode * pre = dummyHead;
        while (!pq.empty())
        {
            pre->next = pq.top();
            pq.pop();
            pre = pre->next;
            if (pre->next)
            {
                pq.push(pre->next);
            }
        }
        return dummyHead->next;
    }
};

//recursive solution based on merge 2 sorted linked list (not fast)
ListNode* merge2Lists(ListNode * l1, ListNode * l2)
{
    ListNode * dummyHead = new ListNode(0);
    ListNode * pre = dummyHead;
    while (l1 && l2)
    {
        if (l1->val < l2->val)
        {
            pre->next = l1;
            l1 = l1->next;
        }
        else
        {
            pre->next = l2;
            l2 = l2->next;
        }
        pre = pre->next;
    }
    if (l1)
    {
        pre->next = l1;
    }
    if (l2)
    {
        pre->next = l2;
    }
    return dummyHead->next;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
        {
            return nullptr;
        }
        while (lists.size() > 1)
        {
            ListNode * l1 = lists.back();
            lists.pop_back();
            ListNode * l2 = lists.back();
            lists.pop_back();
            lists.push_back(merge2Lists(l1, l2));
        }
        return lists[0];
    }
};
