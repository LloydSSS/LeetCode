#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution  
{  
private:  
    Solution()   //构造函数是私有的  
    {  
    }  
    static Solution *m_pInstance;  
public:  
    static Solution * getInstance()  
    {  
        if(m_pInstance == NULL)  //判断是否第一次调用  
            m_pInstance = new Solution();  
        return m_pInstance;  
    }  
};
Solution *Solution::m_pInstance = NULL;

int main(int argc, char const *argv[]) {
    Solution* sol = Solution::getInstance();
    char s[100] = "hello";
    char t[100] = "world";
    swap(s, t);
    cout << t << s << endl;
    return 0;
}
