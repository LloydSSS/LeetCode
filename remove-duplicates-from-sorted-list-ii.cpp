// http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-list-ii/
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
// a.设置标志删除重复元素的第一个
// b.跳过所有与当前值重复的元素

#include "lc.h"

class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy, *q = head->next;
        bool flag = false;
        while (q != nullptr) {
            if (p->next->val == q->val) {
                flag = true;
                ListNode *tmp = q;
                q = q->next;
                p->next->next = q;
                delete tmp;
            } else {
                if (flag) {
                    ListNode *tmp = p->next;
                    p->next = q;
                    flag = false;
                    delete tmp;
                } else {
                    p = p->next;
                }
                q = q->next;
            }
        }
        if (flag) {
            ListNode *tmp = p->next;
            p->next = q;
            flag = false;
            delete tmp;
        }
        return dummy.next;
    }

    ListNode * deleteDuplicates2(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *cur = prev->next;
        while (cur != nullptr && cur->next != nullptr) {
            int v = cur->val;
            if (cur->next->val == v) {
                while (cur != nullptr && cur->val == v) {
                    ListNode *tmp = cur;
                    cur = cur->next;
                    delete tmp;
                }
                prev->next = cur;
            } else {
                cur = cur->next;
                prev = prev->next;
            }
        }
        return dummy->next;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
