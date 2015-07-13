// http://www.lintcode.com/en/problem/remove-nth-node-from-end-of-list/
// 快指针先走n步, 慢指针再走

#include "lintcode.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        for (int i = 0; i < n; ++i)
            fast = fast->next;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummy.next;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
