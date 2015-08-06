// http://www.lintcode.com/en/problem/course-schedule-ii/
// 拓扑排序

#include "lc.h"

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {

        vector<int> deg(numCourses);
        vector<DirectedGraphNode *> graph;
        for (int i = 0; i < numCourses; ++i)
            graph.push_back(new DirectedGraphNode(i));
        for (auto &pii : prerequisites) {
            deg[pii.first]++;
            graph[pii.second]->neighbors.push_back(graph[pii.first]);
        }

        vector<int> ans;
        int count = numCourses;
        queue<int> qu;
        for (int i = 0; i < numCourses; ++i)
            if (deg[i] == 0) {
                qu.push(i);
                count--;
                ans.push_back(i);
            }
        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            for (auto v : graph[u]->neighbors) {
                deg[v->label]--;
                if (deg[v->label] == 0) {
                    count--;
                    ans.push_back(v->label);
                    qu.push(v->label);
                }
            }
        }
        if (count != 0)
            ans.clear();
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
