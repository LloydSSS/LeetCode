// http://www.lintcode.com/en/problem/binary-tree-serialization/
// 当m!=n，那么最末位必定等0，因为[m,n]必定包含奇偶数，相与最末位等0。当m=n的时候，后面都是0，前面的就是这个范围内的数按位相与的相同部分。
#include "lc.h"

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        string str;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while (p != nullptr || !st.empty()) {
            while (p != nullptr) {
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
        if (str == "")
            return "#";
        return str;
    }

    string serialize2(TreeNode *root) {
        string str;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *p = st.top();
            st.pop();
            if (p == nullptr)
                str += "# ";
            else {
                str += itoa(p->val) + " ";
                st.push(p->right);
                st.push(p->left);
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
            return nullptr;
        TreeNode *root, *p;
        p = root = new TreeNode(atoi(str));
        st.push(root);
        while ((p != nullptr && ss >> str && str != "#") || !st.empty()) {
            if (p != nullptr && str != "#") {
                int i = atoi(str);
                p->left = new TreeNode(i);
                st.push(p->left);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                ss >> str;
                if (str == "#") {
                    p = nullptr;
                    continue;
                }
                int i = atoi(str);
                p->right = new TreeNode(i);
                st.push(p->right);
                p = p->right;
            }
        }
        return root;
    }

private:
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
};

int main(int argc, char const *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->right = new TreeNode(1);
    string str = sol.serialize2(root);
    cout << str << endl;
    TreeNode *root2 = sol.deserialize(str);
    return 0;
}
