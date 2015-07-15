// https://leetcode.com/problems/swap-nodes-in-pairs/
// 依次翻转

#include "lc.h"

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *a = head, *b, *p = new ListNode(0);
        p->next = head;
        head = head->next;
        while (a != NULL && a->next != NULL) {
            b = a->next;
            p->next = b;
            a->next = b->next;
            b->next = a;
            p = a;
            a = a->next;
        }
        return head;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
