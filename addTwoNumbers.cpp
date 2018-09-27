/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
   ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode * head = nullptr;
      ListNode * prev = nullptr;
      int carryOut = 0;
      while (l1 != nullptr || l2 != nullptr || carryOut != 0)
      {
         int result = carryOut;
         if (l1 != nullptr)
         {
            result += l1->val;
         }
         if (l2 != nullptr)
         {
            result += l2->val;
         }
         carryOut = result / 10;
         result %= 10;
         ListNode * cur = new ListNode(result);
         if (!prev)
         {
            head = cur;
         }
         else
         {
            prev->next = cur;
         }
         prev = cur;
         if (l1 != nullptr)
         {
            l1 = l1->next;
         }
         if (l2 != nullptr)
         {
            l2 = l2->next;
         }
      }
      return head;
   }
};