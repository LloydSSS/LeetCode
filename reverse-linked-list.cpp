// http://www.lintcode.com/en/problem/reverse-linked-list/
// https://leetcode.com/problems/reverse-linked-list/
// 头插法或原地reverse

#include "lc.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode *ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        return pre;
    }
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse2(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = head;
        while (cur->next != nullptr) {
            ListNode *ne = cur->next;
            cur->next = ne->next;
            ne->next = dummy.next;
            dummy.next = ne;
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
