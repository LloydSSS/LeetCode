// http://www.lintcode.com/en/problem/add-two-numbers/#
// 注意链表长度小于n的情况
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
     * @param n: An integer.
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode *nthToLast(ListNode *head, int n) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;
        for (int i = 0; i < n && fast != NULL; ++i)
            fast = fast->next;
        if (fast == NULL)
            return NULL;
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;

	return 0;
}
