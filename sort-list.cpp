// http://www.lintcode.com/en/problem/sort-list/
// https://leetcode.com/problems/sort-list/
// 归并排序

#include "lc.h"

class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *l3 = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        l3->next = l1 == nullptr ? l2 : l1;
        return dummy.next;
    }
    /**
     * @param head: The first node of linked list.
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = fast;
        while (fast->next != nullptr &&
            fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;

        head = sortList(head);
        head2 = sortList(head2);
        return mergeTwoLists(head, head2);
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
