// http://www.lintcode.com/zh-cn/problem/insertion-sort-list/
// https://leetcode.com/problems/insertion-sort-list/
// 水

#include "lc.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The head of linked list.
     */
    ListNode *insertionSortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode dummy(INT_MIN);
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur != nullptr) {
            while (pre->next != nullptr && pre->next->val < cur->val)
                pre = pre->next;
            ListNode *tmp = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = tmp;
            pre = &dummy;
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
