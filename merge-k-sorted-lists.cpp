// http://www.lintcode.com/en/problem/merge-k-sorted-lists/
// 两两进行合并

#include "lc.h"

class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        ListNode *head = lists[0];
        for (int i = 1; i < lists.size(); ++i)
            head = mergeTwoLists(head, lists[i]);
        return head;
    }

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
