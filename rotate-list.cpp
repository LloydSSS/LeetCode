// http://www.lintcode.com/en/problem/rotate-list/
// https://leetcode.com/problems/rotate-list/
// 首尾相连，然后再走len-k步, 断开

#include "lc.h"

class Solution {
public:
    /**
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head;
        int len = 1;
        while (p->next) {
            len++;
            p = p->next;
        }
        p->next = head;
        k %= len;
        for (int i = 0; i < len-k; ++i) {
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
