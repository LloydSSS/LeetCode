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

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

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
