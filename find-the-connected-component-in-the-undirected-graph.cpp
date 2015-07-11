// http://www.lintcode.com/en/problem/find-the-connected-component-in-the-undirected-graph/
// BFS，水
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

// Definition for Undirected graph.
class UndirectedGraphNode {
public:
    int label;
    vector<UndirectedGraphNode *> neighbors;

    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    /**
     * @param nodes a array of Undirected graph node
     * @return a connected set of a Undirected graph
     */
    vector<vector<int>> connectedSet(vector<UndirectedGraphNode*>& nodes) {
        vector<vector<int> > ans;
        set<UndirectedGraphNode *> used;
        int len = 0;
        for (int i = 0; i < nodes.size(); ++i) {
            if (used.find(nodes[i]) != used.end())
                continue;
            used.insert(nodes[i]);
            queue<UndirectedGraphNode *> qu;
            qu.push(nodes[i]);
            ans.push_back(vector<int>(1, nodes[i]->label));
            while (!qu.empty()) {
                UndirectedGraphNode *ugn = qu.front();
                qu.pop();
                for (int j = 0; j < ugn->neighbors.size(); ++j) {
                    UndirectedGraphNode *neigh = ugn->neighbors[j];
                    if (used.find(neigh) != used.end())
                        continue;
                    qu.push(neigh);
                    used.insert(neigh);
                    ans.back().push_back(neigh->label);
                }
            }
            sort(ans.back().begin(), ans.back().end());
        }
        return ans;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
