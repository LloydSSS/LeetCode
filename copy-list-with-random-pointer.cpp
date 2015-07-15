// http://www.lintcode.com/en/problem/copy-list-with-random-pointer/
// https://leetcode.com/problems/copy-list-with-random-pointer/
// 深拷贝，可以使用hash map纪录对应关系之后再拷贝random pointer，或者先把拷贝的节点放在原节点的后面，再遍历一遍进行分解

#include "lc.h"

class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode *p = head;
        while (p) {
            RandomListNode *q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }

        p = head;
        RandomListNode dummy(-1), *head2 = &dummy;
        while (p) {
            if (p->random != nullptr)
                p->next->random = p->random->next;
            head2->next = p->next;
            head2 = head2->next;
            p = p->next->next;
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
