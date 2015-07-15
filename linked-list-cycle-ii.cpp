// Linked List Cycle II
// http://www.lintcode.com/en/problem/linked-list-cycle-ii/
// https://leetcode.com/problems/linked-list-cycle-ii/
// a. 2(a+x) = a+x+ml a---非环长度，x---进入环后的长度， m快指针转的圈数，l圈的长度

#include "lc.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins.
     *           if there is no cycle, return nullptr
     */
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                break;
        }
        if (fast != slow)
            return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
