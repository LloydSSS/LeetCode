/*
1. Sweep line with max-heap:
Notice that "key points" are either the left or right edges of the buildings. Therefore, we first obtain both the edges of all the N buildings, and store the 2N edges in a sorted array. Maintain a max-heap of building heights while scanning through the edge array: If the current edge is a left edge, then add the height of its associated building to the max-heap; if the edge is a right one, remove the associated height from the heap. Then we take the top value of the heap (yi) as the maximum height at the current edge position (xi). Now (xi, yi) is a potential key point. If yi is the same as the height of the last key point in the result list, it means that this key point is not a REAL key point, but rather a horizontal continuation of the last point, so it should be discarded; otherwise, we add (xi,yi) to the result list because it is a real key point. Repeat this process until all the edges are checked.

It takes O(NlogN) time to sort the edge array. For each of the 2N edges, it takes O(1) time to query the maximum height but O(logN) time to add or remove elements. Overall, this solution takes O(NlogN) time.

For C++ programmers: As appealing as the solution may sound, it is not particularly C++ friendly. As of yet, C++ standard still does not support removal of a non-top element from a heap in a portable way. If you are to try this solution in C++, you may need to implement your own heap structure or even resort to other libraries that supports the removal operation.

2. Divide and Conquer:
Divide the list of buildings into two halves. Recursively get the skyline of both halves, and then merge the two skylines in O(n) time (see if you can figure out this part yourself). According to Master's Theorem, this solution takes O(NlogN) time as well, the same as merge sort.

Be warned, my friend, thou art about to do some serious coding should thou dare this path. Dauntlessly define thy classes and meticulously do thy math. Listen to the prophecy if thou must, but do not let thy own sword idle with rust. By the journey's end, may thy toil and sweat be duly repaid, and no more interviews shalt thou again be afraid.
*/
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

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int>>& buildings) {
        return getSkyline2(buildings);
        vector<pair<int, int> > ans;
        vector<pair<int, int> > heights;
        for (auto &v : buildings) {
            heights.push_back(make_pair(v[0], -v[2]));
            heights.push_back(make_pair(v[1], v[2]));
        }
        sort(heights.begin(), heights.end());
        priority_queue<int> heap;
        unordered_map<int, int> mp;
        heap.push(0); // most important
        // multiset<int> bst;
        // bst.insert(0)
        int pre = -1, cur = 0;
        for (auto &h : heights) {
            if (h.second < 0) {
                heap.push(-h.second);
            } else {
                mp[h.second]++;
                while (!heap.empty() && mp[heap.top()] > 0) {
                    mp[heap.top()]--;
                    heap.pop();
                }
            }
            cur = heap.top();
            if (cur != pre) {
                ans.push_back(make_pair(h.first, cur));
                pre = cur;
            }
        }
        return ans;
    }
    vector<pair<int, int> > getSkyline2(vector<vector<int>>& buildings) {
        vector<pair<int, int> > ans;
        vector<pair<int, int> > heights;
        for (auto &v : buildings) {
            heights.push_back(make_pair(v[0], -v[2]));
            heights.push_back(make_pair(v[1], v[2]));
        }
        sort(heights.begin(), heights.end());
        multiset<int> bst;
        bst.insert(0);
        int pre = -1, cur = 0;
        for (auto &h : heights) {
            if (h.second < 0) {
                bst.insert(-h.second);
            } else {
                bst.erase(bst.find(h.second));
            }
            cur = *bst.rbegin();
            if (cur != pre) {
                ans.push_back(make_pair(h.first, cur));
                pre = cur;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
