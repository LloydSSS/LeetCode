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

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The new head of reversed linked list.
     */
    ListNode *reverse(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode *ne = cur->next;
            cur->next = pre;
            pre = cur;
            cur = ne;
        }
        return pre;
    }

    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return;

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
        head2 = reverse(head2);

        ListNode *p = head, *q = head2;
        ListNode *head3 = &dummy;
        while (p != nullptr && q != nullptr) {
            head3->next = p;
            p = p->next;
            head3 = head3->next;
            head3->next = q;
            q = q->next;
            head3 = head3->next;
        }
        head3->next = p == nullptr ? q : p;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> v = {1,2,3};
    int x;
    cin >> x;
	Solution sol;
    for (int i = 0; i < 3; ++i) {
        cout << v[i] << endl;
    }
	return 0;
}
