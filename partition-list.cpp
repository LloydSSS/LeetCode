// http://www.lintcode.com/en/problem/partition-list/
// https://leetcode.com/problems/partition-list/
// 用两个链表分别存储，反而简单了

#include "lc.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy1(-1), dummy2(-1);
        ListNode *low = &dummy1, *high = &dummy2;
        ListNode *p = head;
        while (p != nullptr) {
            if (p->val < x) {
                low->next = p;
                low = low->next;
            } else {
                high->next = p;
                high = high->next;
            }
            p = p->next;
        }
        low->next = dummy2.next;
        high->next = nullptr;
        return dummy1.next;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
