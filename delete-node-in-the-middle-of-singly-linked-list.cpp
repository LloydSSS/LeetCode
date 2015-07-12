// http://www.lintcode.com/en/problem/delete-node-in-the-middle-of-singly-linked-list/
// 将该节点之后的所有节点val向前拷贝一个，删除最后一个节点

#include "lintcode.h"

class Solution {
public:
    /**
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        if (node == NULL) return;
        ListNode *p = node;
        while (node->next != NULL) {
            node->val = node->next->val;
            p = node;
            node = node->next;
        }
        p->next = NULL;
        delete node;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
