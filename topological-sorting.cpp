// http://www.lintcode.com/en/problem/topological-sorting/
// bfs拓扑排序，记录每个点的入度，将入度为0的加入队列

#include "lintcode.h"

class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        if (graph.size() <= 1) return graph;
        map<DirectedGraphNode*, int> deg;
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i]->neighbors.size(); ++j) {
                deg[graph[i]->neighbors[j]]++;
            }
        }
        queue<DirectedGraphNode*> qu;
        for (int i = 0; i < graph.size(); ++i) {
            if (deg[graph[i]] == 0) {
                qu.push(graph[i]);
            }
        }

        vector<DirectedGraphNode*> ans;
        while (!qu.empty()) {
            DirectedGraphNode* dgn = qu.front();
            qu.pop();
            ans.push_back(dgn);
            for (int j = 0; j < dgn->neighbors.size(); ++j) {
                deg[dgn->neighbors[j]]--;
                if (deg[dgn->neighbors[j]] == 0)
                    qu.push(dgn->neighbors[j]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
