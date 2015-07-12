// http://www.lintcode.com/en/problem/rehashing/
// 水
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        vector<ListNode *> ans(hashTable.size()*2);
        int n = ans.size();
        for (auto p : hashTable) {
            while (p != nullptr) {
                int k = (p->val%n+n)%n;
                ListNode *q;
                if (ans[k] == nullptr)
                    ans[k] = p;
                else {
                    q = ans[k];
                    while (q->next != nullptr)
                        q = q->next;
                    q->next = p;
                }
                q = p;
                p = p->next;
                q->next = nullptr;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
