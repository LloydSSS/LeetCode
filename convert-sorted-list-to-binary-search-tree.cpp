// http://www.lintcode.com/en/problem/convert-sorted-list-to-binary-search-tree/
// 找到中间位置之后递归
#include "lintcode.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        if (head ->next == nullptr)
            return new TreeNode(head->val);
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = fast;
        while (fast->next != nullptr &&
            fast->next->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = nullptr;
        TreeNode *rt = new TreeNode(head2->val);
        head2 = head2->next;
        rt->left = sortedListToBST(head);
        rt->right = sortedListToBST(head2);
        return rt;
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
