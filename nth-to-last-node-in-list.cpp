// http://www.lintcode.com/en/problem/add-two-numbers/#
// 注意链表长度小于n的情况

#include "lintcode.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list.
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;
        for (int i = 0; i < n && fast != nullptr; ++i)
            fast = fast->next;
        if (fast == nullptr)
            return nullptr;
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;

	return 0;
}
