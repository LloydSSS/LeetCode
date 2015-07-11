//
//  lintcode.h
//
//  Created by LloydYan on 15/7/10.
//  Copyright (c) 2015年 LloydYan. All rights reserved.
//
#ifndef lintcode_h
#define lintcode_h

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

#endif
