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

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param x: an integer
     * @return: a ListNode
     */
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode dummy1(-1), dummy2(-1);
        ListNode *low = &dummy1, *high = &dummy2;
        ListNode *p = head;
        while (p != NULL) {
            if (p->val < x) {
                low->next = p;
                low = low->next;
            } else {
                high->next = p;
                high = high->next;
            }
            p = p->next;
        }
        low->next = dummy2.next;
        high->next = NULL;
        return dummy1.next;
    }
};


int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
