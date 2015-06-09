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
     * @return: The new head of reversed linked list.
     */
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
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse2(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *cur = head;
        while (cur->next != NULL) {
            ListNode *ne = cur->next;
            cur->next = ne->next;
            ne->next = dummy.next;
            dummy.next = ne;
        }
        return dummy.next;
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
