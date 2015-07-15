// http://www.lintcode.com/en/problem/singleton/
// 单例模式

#include "lc.h"

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
        if(m_pInstance == nullptr)  //判断是否第一次调用
            m_pInstance = new Solution();
        return m_pInstance;
    }
};
Solution *Solution::m_pInstance = nullptr;

int main(int argc, char const *argv[]) {
    Solution* sol = Solution::getInstance();
    return 0;
}
