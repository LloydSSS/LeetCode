// http://www.lintcode.com/en/problem/linked-list-cycle/
// https://leetcode.com/problems/linked-list-cycle/
// 第一次面试。。。。
#include "lc.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
