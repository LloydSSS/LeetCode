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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head;
        int len = 1;
        while (p->next) {
            len++;
            p = p->next;
        }
        p->next = head;
        k %= len;
        for (int i = 0; i < len-k; ++i) {
            p = p->next;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
