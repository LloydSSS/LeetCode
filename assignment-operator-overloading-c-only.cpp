// http://www.lintcode.com/en/problem/assignment-operator-overloading-c-only
// copy and swap，深拷贝

#include "lintcode.h"

class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = nullptr;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution& operator=(const Solution &object) {
        if (this != &object) {
            char *tmp = nullptr;
            if (object.m_pData != nullptr) {
                tmp = new char[strlen(object.m_pData)+1];
                strcpy(tmp, object.m_pData);
            }

            delete m_pData;
            m_pData = tmp;
        }
        return *this;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
