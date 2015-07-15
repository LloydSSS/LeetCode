// http://www.lintcode.com/en/problem/add-two-numbers/#
// https://leetcode.com/problems/add-two-numbers/
// 注意是否可以使用l1 l2的节点

#include "lc.h"

class Solution {
public:
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *s = &dummy;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            s->next = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry)/10;
            s = s->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        s->next = l1 == nullptr ? l2 : l1;
        if (carry != 0) {
            if (s->next == nullptr)
                s->next = new ListNode(carry);
            else
                s->next->val += carry;
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
