// https://leetcode.com/problems/reverse-nodes-in-k-group/
// 头插法或原地reverse

#include "lc.h"

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *prev = new_head;
        for (int i = 1; i < m; ++i)
            prev = prev->next;
        ListNode *p = prev->next, *cur = p->next, *ne = NULL;
        for (int i = m; i < n; ++i) {
            ne = cur->next;
            cur->next = p;
            p = cur;
            cur = ne;
        }
        prev->next->next = ne;
        prev->next = p;
        return new_head->next;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2 || head == NULL) return head;

        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *prev = new_head;
        int len = 0;
        while (head != NULL) {
            len++;
            head = head->next;
        }

        for (int i = 0; i < len/k; ++i) {
            ListNode *p = prev->next, *cur = p->next, *ne = NULL;
            for (int j = i*k+1; j < (i+1)*k; ++j) {
                ne = cur->next;
                cur->next = p;
                p = cur;
                cur = ne;
            }
            ListNode *q = prev->next;
            q->next = ne;
            prev->next = p;
            prev = q;
        }
        return new_head->next;
    }
};

class Solution2 {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        ListNode *prev = new_head;
        for (int i = 1; i < m; ++i)
            prev = prev->next;
        ListNode *tail = prev;
        for (int i = m; i <= n; ++i)
            tail = tail->next;
        while (prev->next != tail) {
            ListNode *p = prev->next;
            prev->next = p->next;
            p->next = tail->next;
            tail->next = p;
        }
        return new_head->next;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k < 2) return head;
        int len = 0;
        ListNode *p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }
        for (int i = 0; i < len/k; ++i) {
            int m = i*k+1, n = (i+1)*k;
            head = reverseBetween(head, m, n);
        }
        return head;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
