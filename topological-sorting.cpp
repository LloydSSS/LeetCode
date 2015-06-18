#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
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


// Definition for Directed graph.
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};

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
