// http://www.lintcode.com/en/problem/merge-two-sorted-lists/
// 比较，合并

#include "lintcode.h"

class Solution {
public:
    /**
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1);
        ListNode *l3 = &dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                l3->next = l1;
                l1 = l1->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
            }
            l3 = l3->next;
        }
        l3->next = l1 == nullptr ? l2 : l1;
        return dummy.next;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
