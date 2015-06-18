#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

// Definition of ListNode
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL)
            return NULL;
        if (head ->next == NULL)
            return new TreeNode(head->val);
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = fast;
        while (fast->next != NULL &&
            fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *head2 = slow->next;
        slow->next = NULL;
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