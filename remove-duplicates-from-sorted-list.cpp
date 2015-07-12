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
        this->next = nullptr;
    }
};

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
