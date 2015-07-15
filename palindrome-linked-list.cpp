// https://leetcode.com/problems/palindrome-linked-list/
// 将后半段翻转，然后比较

#include "lc.h"

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == slow)
            return true;
        fast = slow->next;
        slow->next = nullptr;
        fast = reverse(fast);
        slow = dummy.next;
        while (fast != nullptr && slow != nullptr) {
            if (fast->val != slow->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }
    ListNode *reverse(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *pre = NULL, *cur = head;
        while (cur != NULL) {
            ListNode *ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        return pre;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
