#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
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


// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    string itoa(int i) {
        string a;
        stringstream ss;
        ss << i;
        ss >> a;
        return a;
    }
    
    int atoi(string a) {
        stringstream ss;
        int i;
        ss << a;
        ss >> i;
        return i;
    }
    
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        string str;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while (p != NULL || !st.empty()) {
            while (p != NULL) {
                str += itoa(p->val) + " ";
                st.push(p);
                p = p->left;
            }
            str += "# ";
            if (!st.empty()) {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }
        return str;
    }
    
    string serialize2(TreeNode *root) {
        string str;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *p = st.top();
            st.pop();
            if (p == NULL)
                str += "# ";
            else {
                str += itoa(p->val) + " ";
                st.push(p->left);
                st.push(p->right);
            }
        }
        return str;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) {
        stringstream ss;
        string str;
        
        stack<TreeNode *> st;
        ss << data;
        ss >> str;
        if (str == "#")
            return NULL;
        TreeNode *root, *p;
        p = root = new TreeNode(atoi(str));
        st.push(root);
        while (p != NULL || !st.empty()) {
            ss >> str;
            if (p != NULL && str != "#") {
                int i = atoi(str);
                p->left = new TreeNode(i);
                st.push(p->left);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                ss >> str;
                if (str == "#")
                    continue;
                int i = atoi(str);
                p->right = new TreeNode(i);
                st.push(p->right);
                p = p->right;
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(1);
    string str = sol.serialize(root);
    cout << str << endl;
    TreeNode *root2 = sol.deserialize(str);
    return 0;
}
