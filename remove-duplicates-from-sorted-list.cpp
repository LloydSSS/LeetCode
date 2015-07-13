// http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-list
// 重复值保留一个

#include "lintcode.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *p = head, *q = head->next;
        while (q != nullptr) {
            if (q->val == p->val) {
                ListNode *tmp = q;
                q = q->next;
                p->next = q;
                delete tmp;
            } else {
                q = q->next;
                p = p->next;
            }
        }
        return head;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
