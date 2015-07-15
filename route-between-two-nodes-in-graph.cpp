// http://www.lintcode.com/en/problem/route-between-two-nodes-in-graph
// bfs

#include "lc.h"

class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @param s: the starting Directed graph node
     * @param t: the terminal Directed graph node
     * @return: a boolean value
     */
    bool hasRoute(vector<DirectedGraphNode*> graph,
                  DirectedGraphNode* s, DirectedGraphNode* t) {
        if (s == t) return true;
        queue<DirectedGraphNode *> qu;
        unordered_set<DirectedGraphNode *> used;
        qu.push(s);
        used.insert(s);
        while (!qu.empty()) {
            DirectedGraphNode *gn = qu.front();
            qu.pop();
            for (int i = 0; i < gn->neighbors.size(); ++i) {
                if (gn->neighbors[i] == t)
                    return true;
                if (used.find(gn->neighbors[i]) != used.end())
                    continue;
                used.insert(gn->neighbors[i]);
                qu.push(gn->neighbors[i]);
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
