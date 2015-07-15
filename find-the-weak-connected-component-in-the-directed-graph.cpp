// http://www.lintcode.com/en/problem/ffind-the-weak-connected-component-in-the-directed-graph
// 并查集

#include "lc.h"

class Solution {
public:
    /**
     * @param nodes a array of directed graph node
     * @return a connected set of a directed graph
     */
    vector<vector<int>> connectedSet2(vector<DirectedGraphNode*>& nodes) {
        for (int i = 0; i < nodes.size(); ++i) {
            DirectedGraphNode *u = nodes[i];
            for (int j = 0; j < u->neighbors.size(); ++j) {
                DirectedGraphNode *v = u->neighbors[j];
                union1(u->label, v->label);
            }
        }

        unordered_map<int, vector<int> > component;
        for (int i = 0; i < nodes.size(); ++i) {
            DirectedGraphNode *u = nodes[i];
            int pu = find_p(u->label);
            component[pu].push_back(u->label);
        }

        vector<vector<int> > ans;
        for (auto &comp : component) {
            sort(comp.second.begin(), comp.second.end());
            ans.push_back(comp.second);
        }
        return ans;
    }

    unordered_map<int, int> p;
    int find_p(int x) {
        if (p.find(x) == p.end()) {
            p[x] = x;
        }
        if (p[x] != x)
            p[x] = find_p(p[x]);
        return p[x];
    }

    void union1(int x, int y) {
        p[find_p(x)] = find_p(find_p(y));
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
