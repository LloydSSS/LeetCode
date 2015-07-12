// http://www.lintcode.com/en/problem/clone-graph/
// 深拷贝，使用hash_map纪录对应关系
#include "lintcode.h"

class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return nullptr;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
        stack<UndirectedGraphNode *> s;
        s.push(node);
        while (!s.empty()) {
            UndirectedGraphNode *q = s.top();
            s.pop();
            UndirectedGraphNode *p;
            if (mp[q] == nullptr) {
                p = new UndirectedGraphNode(q->label);
                mp[q] = p;
            } else
                p = mp[q];
            for (int i = 0; i < q->neighbors.size(); ++i) {
                UndirectedGraphNode *qn = q->neighbors[i];
                UndirectedGraphNode *pn;
                if (mp[qn] == nullptr) {
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
