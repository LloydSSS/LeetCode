// https://leetcode.com/problems/intersection-of-two-linked-lists/
// 纪录链表的长度，以及最后一个节点是否相同

#include "lc.h"

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int lenA = 1, lenB = 1;
        ListNode *pA = headA, *pB = headB;
        while (pA->next != NULL) {
            pA = pA->next;
            ++lenA;
        }
        while (pB->next != NULL) {
            pB = pB->next;
            ++lenB;
        }
        if (pA != pB) return NULL;
        pA = headA;
        pB = headB;
        if (lenA > lenB) {
            int ab = lenA - lenB;
            while (ab--) pA = pA->next;
        } else if (lenA < lenB) {
            int ba = lenB - lenA;
            while (ba--) pB = pB->next;
        }
        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
