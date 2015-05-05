#include <iostream>
using namespace std;

class Solution {
public:
    /*
     * @param n: An integer
     * @return: True or false
     */
    bool checkPowerOf2(int n) {
        // write your code here
        if (n <= 0) return false;
        cout << (n&(n-1)) << endl;
        return (n&(n-1)) == 0;
    }
};

int main(int argc, char const *argv[])
{
	Solution sol;
	cout << sol.checkPowerOf2(4) << endl;
	/* code */
	return 0;
}