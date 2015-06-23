// http://www.lintcode.com/en/problem/clone-graph/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;


// Definition for undirected graph.
struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
        stack<UndirectedGraphNode *> s;
        s.push(node);
        while (!s.empty()) {
            UndirectedGraphNode *q = s.top();
            s.pop();
            UndirectedGraphNode *p;
            if (mp[q] == NULL) {
                p = new UndirectedGraphNode(q->label);
                mp[q] = p;
            } else
                p = mp[q];
            for (int i = 0; i < q->neighbors.size(); ++i) {
                UndirectedGraphNode *qn = q->neighbors[i];
                UndirectedGraphNode *pn;
                if (mp[qn] == NULL) {
                    pn = new UndirectedGraphNode(qn->label);
                    mp[qn] = pn;
                    s.push(qn);
                } else
                    pn = mp[qn];
                p->neighbors.push_back(pn);
            }
        }
        return mp[node];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
