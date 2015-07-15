// https://leetcode.com/problems/dungeon-game/
/*
At first glance, this problem bears a large resemblance to the "Maximum/Minimum Path Sum" problem. However, a path with maximum overall health gain does not guarantee the minimum initial health, since it is essential in the current problem that the health never drops to zero or below. For instance, consider the following two paths: 0 -> -300 -> 310 -> 0 and 0 -> -1 -> 2 -> 0. The net health gain along these paths are -300 + 310 = 10 and -1 + 2 = 1, respectively. The first path has the greater net gain, but it requires the initial health to be at least 301 in order to balance out the -300 loss in the second room, whereas the second path only requires an initial health of 2.

Fortunately, this problem can be solved through a table-filling Dynamic Programming technique, similar to other "grid walking" problems:

To begin with, we should maintain a 2D array D of the same size as the dungeon, where D[i][j] represents the minimum health that guarantees the survival of the knight for the rest of his quest BEFORE entering room(i, j). Obviously D[0][0] is the final answer we are after. Hence, for this problem, we need to fill the table from the bottom right corner to left top.

Then, let us decide what the health should be at least when leaving room (i, j). There are only two paths to choose from at this point: (i+1, j) and (i, j+1). Of course we will choose the room that has the smaller D value, or in other words, the knight can finish the rest of his journey with a smaller initial health. Therefore we have:

  min_HP_on_exit = min(D[i+1][j], D[i][j+1])
Now D[i][j] can be computed from dungeon[i][j] and min_HP_on_exit based on one of the following situations:

If dungeon[i][j] == 0, then nothing happens in this room; the knight can leave the room with the same health he enters the room with, i.e. D[i][j] = min_HP_on_exit.
If dungeon[i][j] < 0, then the knight must have a health greater than min_HP_on_exit before entering (i, j) in order to compensate for the health lost in this room. The minimum amount of compensation is "-dungeon[i][j]", so we have D[i][j] = min_HP_on_exit - dungeon[i][j].
If dungeon[i][j] > 0, then the knight could enter (i, j) with a health as little as min_HP_on_exit - dungeon[i][j], since he could gain "dungeon[i][j]" health in this room. However, the value of min_HP_on_exit - dungeon[i][j] might drop to 0 or below in this situation. When this happens, we must clip the value to 1 in order to make sure D[i][j] stays positive: D[i][j] = max(min_HP_on_exit - dungeon[i][j], 1).
Notice that the equation for dungeon[i][j] > 0 actually covers the other two situations. We can thus describe all three situations with one common equation, i.e.:

D[i][j] = max(min_HP_on_exit - dungeon[i][j], 1)
for any value of dungeon[i][j].

Take D[0][0] and we are good to go. Also, like many other "table-filling" problems, the 2D array D can be replaced with a 1D "rolling" array here.

 */
#include "lc.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        if (dungeon.size() == 0 || dungeon[0].size() == 0) return 1;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = dungeon[m-1][n-1] > 0 ? 1 : 1-dungeon[m-1][n-1];
        for (int i = m-2; i >= 0; --i) {
            dp[i][n-1] = minHp(dp[i+1][n-1]-dungeon[i][n-1]);//dp[i+1][n-1]-dungeon[i][n-1] > 0 ? dp[i+1][n-1]-dungeon[i][n-1] : 1;
        }
        for (int j = n-2; j >= 0; --j) {
            dp[m-1][j] = minHp(dp[m-1][j+1]-dungeon[m-1][j]);
        }
        for (int i = m-2; i >= 0; --i) {
            for (int j = n-2; j >= 0; --j) {
                dp[i][j] = minHp(min(dp[i+1][j], dp[i][j+1])-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
    int minHp(int hp) {
        return hp > 0 ? hp : 1;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
