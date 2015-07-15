// https://leetcode.com/problems/remove-linked-list-elements/
// 依次删除

#include "lc.h"

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        while (p->next != NULL) {
            ListNode *q = p->next;
            if (q->val == val) {
                p->next = q->next;
                delete q;
            } else {
                p = p->next;
            }
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
