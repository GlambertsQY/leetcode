// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include<vector>
#include<limits>
#include<cmath>
#include<map>
#include"Header.h"
using namespace std;

class Solution {
public:
    //28 模式匹配，kmp最好
    int strStr(string haystack, string needle) {
        if (needle.empty() || (haystack.empty() && needle.empty()))
            return 0;
        for (int i = 0; i < (int)(haystack.size() - needle.size() + 1); i++) { //string的size()是无符号数
            int flag = 1;
            for (int j = 0, k = i; j < needle.size(); j++, k++) {
                if (haystack[k] != needle[j])
                    flag = 0;
            }
            if (flag == 1)
                return i;
        }
        return -1;
    }

    //35 使用二分法则为O(logn)
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0])
            return 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= target)
                return i;
            if (nums[i] < target)
                continue;
        }
        return nums.size();
    }

    //53. Maximum Subarray 暴力/动态规划
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum > max)
                    max = sum;
            }
        }
        return max;
    }

    //58. Length of Last Word
    int lengthOfLastWord(string s) {
        int sum = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ' && sum == 0)
                continue;
            if (s[i] != ' ')
                sum++;
            else
                break;
        }
        return sum;
    }

    //66. Plus One
    vector<int> plusOne(vector<int>& digits) {
        if (digits[digits.size() - 1] != 9) {
            digits[digits.size() - 1]++;
            return digits;
        }
        int i = 0;
        for (i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                break;
            }
        }
        if (i == -1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }

    //67. Add Binary 字符串可以直接+，不需要insert
    string addBinary(string a, string b) {
        string output = "";
        int length = a.size() >= b.size() ? a.size() : b.size();
        if (a.size() != b.size()) {
            int dif = abs((int)(a.size() - b.size()));
            if (a.size() > b.size()) {
                for (int i = 0; i < dif; i++)
                    b.insert(b.begin(), '0');
            } else {
                for (int i = 0; i < dif; i++)
                    a.insert(a.begin(), '0');
            }
        }
        int c = 0;
        for (int i = length - 1; i >= 0; i--) {
            int res = (a[i] - '0') ^ (b[i] - '0') ^ c;
            c = a[i] - '0' + b[i] - '0' + c <= 1 ? 0 : 1;
            output.insert(output.begin(), res + '0');
        }
        if (c == 1)
            output.insert(output.begin(), '1');
        return output;
    }

    //69. Sqrt(x)
    int mySqrt(int x) {
        long i;
        for (i = 0; (i * i) <= x; i++) {
            if ((i * i) == x)
                return i;
        }
        return i - 1;
    }

    //70. Climbing Stairs 动态规划，斐波那契数列
    int climbStairs(int n) {
        int* a = new int[45];
        a[0] = 1;
        a[1] = 2;
        for (int i = 2; i < n; i++)
            a[i] = a[i - 1] + a[i - 2];
        return a[n - 1];
    }


    //83. Remove Duplicates from Sorted List  无head node

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        if (!head)
            return head;
        while (p->next != nullptr) {
            if (p->val == p->next->val) {
                ListNode* del = p->next;
                p->next = p->next->next;
                delete(del);
            } else {
                p = p->next;
            }
        }
        return head;
    }

    //88. Merge Sorted Array non-decreasing=non-descending
    //不需要临时数组，可先将nums1前部的元素全部移到最后
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res = {};
        res.resize(nums1.size());
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                res[k++] = nums1[i++];
            } else {
                res[k++] = nums2[j++];
            }
        }
        if (i < m) {
            while (i < m) {
                res[k++] = nums1[i++];
            }
        }
        if (j < n) {
            while (j < n) {
                res[k++] = nums2[j++];
            }
        }
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = res[i];
        }
    }

    //94. Binary Tree Inorder Traversal 中序


    vector<int> inorderTraversal(TreeNode* root) {
        vector<TreeNode*> v = {};
        vector<int> res = {};
        TreeNode* p = root;
        while (!v.empty() || p) {
            if (p) {
                v.push_back(p);
                p = p->left;
            } else {
                p = v[v.size() - 1];
                res.push_back(p->val);
                v.pop_back();
                p = p->right;
            }
        }
        return res;
    }

    //144. Binary Tree Preorder Traversal
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> v = {};
        vector<int> res = {};
        TreeNode* p = root;
        while (!v.empty() || p) {
            if (p) {
                v.push_back(p);
                res.push_back(p->val);
                p = p->left;
            } else {
                p = v[v.size() - 1];
                v.pop_back();
                p = p->right;
            }
        }
        return res;
    }

    //100. Same Tree 前序遍历和中序遍历可唯一确定一棵树, 前提元素不相同
    //深度遍历，递归
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return 1;
        } else if (!p || !q) {
            return 0;
        } else if (p->val != q->val) {
            return 0;
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }

    //136. Single Number 位运算，0异或本身为本身
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }

    //141. Linked List Cycle 快慢指针，注意初始快指针为head->next,且因为p2快，所以p2先NULL
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return 0;
        ListNode* p1 = head, * p2 = head->next;
        while (p1 != p2) {
            if (p2 == NULL || p2->next == NULL)
                return 0;
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return 1;
    }

    //145. Binary Tree Postorder Traversal 非递归的后根遍历
    //根 -> 左 -> 右（pre）  -->  右 -> 左 -> 根  --> 左 -> 右 -> 根（post）
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> v = {};
        vector<int> res = {};
        TreeNode* p = root;
        while (!v.empty() || p) {
            if (p) {
                v.push_back(p);
                res.insert(res.begin(), p->val);
                p = p->right;
            } else {
                p = v[v.size() - 1];
                v.pop_back();
                p = p->left;
            }
        }
        return res;
    }

    //155. Min Stack
    class MinStack {
    public:
        vector<int> stack;
        int sTop;
        MinStack() {
            stack = {};
            sTop = -1;
        }

        void push(int val) {
            stack.push_back(val);
            sTop++;
        }

        void pop() {
            stack.pop_back();
            sTop--;
        }

        int top() {
            return stack[sTop];
        }

        int getMin() {
            int min = INT32_MAX;
            for (int i = 0; i < stack.size(); i++) {
                if (stack[i] < min) {
                    min = stack[i];
                }
            }
            return min;
        }
    };

    //160. Intersection of Two Linked Lists
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (headA == NULL || headB == NULL)
            return NULL;
        int sizeA = 0, sizeB = 0;
        ListNode* t1 = headA, * t2 = headB;
        while (t1 != NULL) {
            sizeA++;
            t1 = t1->next;
        }
        while (t2 != NULL) {
            sizeB++;
            t2 = t2->next;
        }
        t1 = headA;
        t2 = headB;
        if (sizeA >= sizeB) {
            for (int i = 0; i < (sizeA - sizeB); i++) {
                t1 = t1->next;
            }
        } else {
            for (int i = 0; i < (sizeB - sizeA); i++) {
                t2 = t2->next;
            }
        }
        while (!((t1 == NULL) || (t1 == t2))) { //注意条件
            t1 = t1->next;
            t2 = t2->next;
        }
        if (t1 == NULL) {
            return NULL;
        }
        return t1;
    }

    //167. Two Sum II - Input Array Is Sorted
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> res = {};
        while (i < j) {
            if (numbers[i] + numbers[j] > target) {
                j--;
            } else if (numbers[i] + numbers[j] < target) {
                i++;
            } else {
                res.push_back(i + 1);
                res.push_back(j + 1);
                break;
            }
        }
        return res;
    }

    // 168. Excel Sheet Column Title
    string convertToTitle(int columnNumber) {
        string res = "";
        int remainder = 0;
        while (columnNumber != 0) {
            columnNumber--;
            remainder = columnNumber % 26;
            res.insert(res.begin(), remainder + 'A');
            columnNumber /= 26;
        }
        return res;
    }

    //169. Majority Element
    int majorityElement(vector<int>& nums) {
        int num = -1;
        int sign = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sign == 0) {
                num = nums[i];
                sign++;
            } else {
                if (num == nums[i]) {
                    sign++;
                } else {
                    sign--;
                }
            }
        }
        return num;
    }

    //171. Excel Sheet Column Number
    int titleToNumber(string columnTitle) {
        int sum = 0;
        for (int i = 0; i < columnTitle.size(); i++) {
            sum += (columnTitle[i] - 'A' + 1) * pow(26, columnTitle.size() - i - 1);
        }
        return sum;
    }

    //190. Reverse Bits 原串不停向右移位，返回串不停向左移位
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = n & 0x1;
        n >>= 1; // 是 >>= 而不是直接 >>
        for (int i = 0; i < 31; i++) {
            res <<= 1;
            res += (n & 0x1);
            n >>= 1;
        }
        return res;
    }

    //191. Number of 1 Bits
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += (n & 0x1);
            n >>= 1;
        }
        return res;
    }

    //202. Happy Number //会循环，证明有重复，使用hashmap找到重复
    //c++的hashmap：按照key进行排序，根据key来find
    bool isHappy(int n) {
        map <int, string> m;
        while (true) {
            int numDigits = getNumOfDigits(n);
            int res = pow((n % 10), 2);
            for (int i = 0; i < numDigits; i++) {
                res += pow((n / 10 % 10), 2);
                n /= 10;
            }
            if (res == 1) {
                return 1;
            }
            if (m.find(res) != m.end()) {
                return 0;
            }
            m[res] = "result";
            n = res;
        }
    }
    //203. Remove Linked List Elements
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* p = head, * t = head;
        while (head->val == val) {
            t = head;
            head = head->next;
            if (head == NULL) {
                return NULL;
            }
            delete(t);
        }
        p = head;
        while (p->next != NULL) {
            if (p->next->val == val) {
                t = p->next;
                p->next = p->next->next;
                delete(t);
            } else {
                p = p->next;
            }
        }
        return head;
    }
    //205. Isomorphic Strings 数组排序即可，大小为128
    string getStructure(string s) {
        string res = "";
        map<char, int> m;
        int offset = 0;
        for (int i = 0; i < s.size(); i++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = offset++;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            res.push_back(m[s[i]] + 'A');
        }
        return res;
    }

    bool isIsomorphic(string s, string t) {
        string res1 = getStructure(s);
        string res2 = getStructure(t);
        for (int i = 0; i < res1.size(); i++) {
            if (res1[i] != res2[i]) {
                return 0;
            }
        }
        return 1;
    }

    //206. Reverse Linked List
    ListNode* reverseList(ListNode* head) {
        ListNode* res = new ListNode();
        while (head != NULL) {
            ListNode* t = new ListNode();
            t->val = head->val;
            t->next = res->next;
            res->next = t;
            head = head->next;
        }
        return res->next;
    }

    //递归，递归式，找中间状态
    ListNode* reverseList2(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList(head->next);
        //回溯部分
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }

    //217. Contains Duplicate 异或O(n)级
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 0;
            } else {
                return 1;
            }
        }
        return 0;
    }

    //219. Contains Duplicate II map 存<nums[i], i>
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) != m.end()) {
                if (abs(i - m[nums[i]]) <= k) {
                    return 1;
                } else {
                    m[nums[i]] = i;
                }
            } else {
                m[nums[i]] = i;
            }
        }
        return 0;
    }

    //225. Implement Stack using Queues
    //vector使用erase，可删除头元素
    //单队列：反复出头元素再入队列
    class MyStack {
    public:
        vector<int> q1;
        vector<int> q2;
        int mTop;

        MyStack() {
            q1 = {}, q2 = {};
            mTop = -1;
        }

        void push(int x) {
            q2.push_back(x);
            while (!q1.empty()) {
                q2.push_back(q1[0]);
                q1.erase(q1.begin());
            }
            while (!q2.empty()) {
                q1.push_back(q2[0]);
                q2.erase(q2.begin());
            }
            mTop++;
        }

        int pop() {
            int res = q1[0];
            q1.erase(q1.begin());
            mTop--;
            return res;
        }

        int top() {
            return q1[0];
        }

        bool empty() {
            return q1.empty();
        }
    };

    //226. Invert Binary Tree
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) { //终止递归条件 
            return NULL;
        }
        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        invertTree(root->left);
        invertTree(root->right);
        return root;  //最后执行时，即为实际根节点。最先执行时，为最底层元素的根。
    }

    //231. Power of Two
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return 0;
        }
        while (true) {
            if (n == 1) {
                return 1;
            }
            if (n % 2 != 0) {
                return 0;
            }
            n /= 2;
        }
        return 0;
    }

    //232. Implement Queue using Stacks
    class MyQueue {
    public:
        vector<int> s1;
        vector<int> s2;
        MyQueue() {
            s1 = {};
            s2 = {};
        }

        void push(int x) {
            s1.push_back(x);
        }

        int pop() {
            while (!s1.empty()) {
                s2.push_back(s1[s1.size() - 1]);
                s1.pop_back();
            }
            int res = s2[s2.size() - 1];
            s2.pop_back();
            while (!s2.empty()) {
                s1.push_back(s2[s2.size() - 1]);
                s2.pop_back();
            }
            return res;
        }

        int peek() {
            while (!s1.empty()) {
                s2.push_back(s1[s1.size() - 1]);
                s1.pop_back();
            }
            int res = s2[s2.size() - 1];
            while (!s2.empty()) {
                s1.push_back(s2[s2.size() - 1]);
                s2.pop_back();
            }
            return res;
        }

        bool empty() {
            return s1.empty();
        }
    };

    //234. Palindrome Linked List
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return 0;
        }
        int length = 0;
        ListNode* t = head;
        while (t != NULL) {
            length++;
            t = t->next;
        }
        int offset = length % 2 == 0 ? (length / 2) - 1 : length / 2;
        t = head;
        for (int i = 0; i < offset; i++) {
            t = t->next;
        }
        ListNode* p = t->next;
        t->next = NULL;
        while (p != NULL) {
            ListNode* t1 = p->next;
            p->next = t->next;
            t->next = p;
            p = t1;
        }
        t = head;
        for (int i = 0; i < offset; i++) {
            t = t->next;
        }
        t = t->next;
        p = head;
        while (t != NULL) {
            if (t->val != p->val) {
                return 0;
            }
            t = t->next;
            p = p->next;
        }
        return 1;
    }

    //235. Lowest Common Ancestor of a Binary Search Tree
    //普通非递归preordersearch无法获得route，用p表示最近访问节点
    //DFSRoute，用postorder非递归
    vector<TreeNode*> getDFSRoute(TreeNode* head, TreeNode* p) {
        vector<TreeNode*> s = {};
        TreeNode* r = NULL;
        TreeNode* h = head;
        while (!s.empty() || h != NULL) {
            if (h != NULL) {
                s.push_back(h);
                h = h->left;
            } else {
                h = s[s.size() - 1];
                if (h->right && h->right != r) { //r为最近访问过的节点，解决反复向右遍历。h右为空，则可直接return
                    h = h->right;
                } else {
                    if (h->val == p->val) {
                        return s;
                    }
                    s.pop_back();
                    r = h;  //h可能为NULL或最近访问过节点
                    h = NULL; //关键
                }
            }
        }
        return s;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1 = {}, v2 = {};
        v1 = getDFSRoute(root, p);
        v2 = getDFSRoute(root, q);
        int offset = abs((int)v2.size() - (int)v1.size());
        if (v1.size() >= v2.size()) {
            for (int i = 0; i < offset; i++) {
                v1.pop_back();
            }
        } else {
            for (int i = 0; i < offset; i++) {
                v2.pop_back();
            }
        }
        while (!v1.empty()) {
            if (v1[v1.size() - 1] == v2[v2.size() - 1]) {
                return v1[v1.size() - 1];
            }
            v1.pop_back();
            v2.pop_back();
        }
        return NULL;
    }

    //237. Delete Node in a Linked List
    //不删应该删的节点，值为最终的序列即可
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        ListNode* t = node->next;
        node->next = node->next->next;
        delete(t);
    }

    //242. Valid Anagram
    bool isAnagram(string s, string t) {
        map<char, int> m1, m2;
        if (s.size() != t.size()) {
            return 0;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m1.find(s[i]) == m1.end()) {
                m1[s[i]] = 0;
            } else {
                m1[s[i]]++;
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (m1.find(t[i]) == m1.end()) {
                return 0;
            } else {
                if (m2.find(t[i]) == m2.end()) {
                    m2[t[i]] = 0;
                } else {
                    m2[t[i]]++;
                }
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (m1[s[i]] != m2[s[i]]) {
                return 0;
            }
        }
        return 1;
    }

    //257. Binary Tree Paths
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<TreeNode*> s = {};
        vector<vector<TreeNode*>> tv = {};
        TreeNode* r = NULL;
        TreeNode* h = root;
        while (!s.empty() || h != NULL) {
            if (h != NULL) {
                s.push_back(h);
                h = h->left;
            } else {
                h = s[s.size() - 1];
                if (h->right && h->right != r) { //r为最近访问过的节点，解决反复向右遍历。h右为空，则可直接return
                    h = h->right;
                } else {
                    if (h->left == NULL && h->right == NULL) {
                        tv.push_back(s);
                    }
                    s.pop_back();
                    r = h;  //h可能为NULL或最近访问过节点
                    h = NULL; //关键
                }
            }
        }
        vector<string> res = {};
        for (int i = 0; i < tv.size(); i++) {
            string s = "";
            for (int j = 0; j < tv[i].size(); j++) {
                if (j != tv[i].size() - 1) {
                    s += to_string(tv[i][j]->val) + "->";
                } else {
                    s += to_string(tv[i][j]->val);
                }
            }
            res.push_back(s);
        }
        return res;
    }

    //全局变量，或引用参数
    
    void BTreePaths(TreeNode* root,string s, vector<string> &res) { //s不能用引用类型
        if (root == NULL) {                                         //使用则导致，每层递归s的完全相同，无视return
            return;
        }
        s += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(s);                                      //则在结尾处不加"->"
        } else {
            s += "->";
            BTreePaths(root->left, s, res);
            BTreePaths(root->right, s, res);
        }
    }

    vector<string> binaryTreePaths2(TreeNode* root) {
        vector<string> res_257 = {};
        string str_257 = "";
        BTreePaths(root, str_257, res_257);
        return res_257;
    }

    //258. Add Digits
    int addDigits(int num) {
        string s = to_string(num);
        while (s.size() > 1) {
            int t = 0;
            for (int i = 0; i < s.size(); i++) {
                t += (s[i] - '0');
            }
            s = to_string(t);
        }
        return s[0] - '0';
    }

    //263. Ugly Number
    //prime factors只有2，3，5
    bool isUgly(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        while (n%2==0) {
            n /= 2;
        }
        while (n%3==0) {
            n /= 3;
        }
        while (n%5==0) {
            n /= 5;
        }
        return n == 1 ? 1 : 0;
    }

    //268. Missing Number
    //交换：swap进行n次，实际为O(n)
    //异或：增加n个数，结果有2n+1个数。连续异或之后，剩下一个不存在的数。
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        int numOfSwap = 0;
        for (int j = 0; j < nums.size(); j++) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == -1) {
                    continue;
                }
                if (nums[i] != i) {
                    int t = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = t;
                    numOfSwap++;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) {
                return i;
            }
        }
        return 0;
    }

    //278. First Bad Version
    int firstBadVersion(int n) {
        int l = 1, h = n;
        while (l <= h) {
            long long mid = (l + h) / 2; //l+ (h-l)/2 防止l+h溢出
            int r1 = isBadVersion(mid);
            if (mid == 1 && r1 == 1) {
                return 1;
            }
            int r2 = isBadVersion(mid - 1);
            if (r1 == 1 && r2 == 0) {
                return mid;
            } else if(r1==1){
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }

    //283. Move Zeroes
    void moveZeroes(vector<int>& nums) {
        int numOfZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                numOfZero++;
            } else {
                nums[i - numOfZero] = nums[i];
            }
        }
        for (int i = nums.size() - numOfZero; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }

    //290. Word Pattern
    //bijection：双向映射
    bool wordPattern(string pattern, string s) {
        vector<string> vs = stringToVector_string(s);
        if (pattern.size() != vs.size()) {
            return 0;
        }
        map<char, string> m;
        map<string, char> m2;
        for (int i = 0; i < pattern.size(); i++) {
            if (m.find(pattern[i]) == m.end()) {
                if (m2.find(vs[i]) != m2.end()) {
                    return 0;
                }
                m2[vs[i]] = pattern[i];
                m[pattern[i]] = vs[i];
            } else {
                if (m[pattern[i]] != vs[i]) {
                    return 0;
                }
            }
        }
        return 1;
    }

    //292. Nim Game 博弈论
    //动态规划 1-3 4 5-7 8 9-11
    bool canWinNim(int n) {
        return !(n % 4 == 0);
    }

    //303. Range Sum Query - Immutable
    // sumRange(i,j)=sums[j+1]−sums[i] 简化求和
    class NumArray {
    public:
        vector<int> v;
        NumArray(vector<int>& nums) {
            int sum = 0;
            v.push_back(0);
            for (int i = 0; i < nums.size(); i++) {
                sum += nums[i];
                v.push_back(sum);
            }
        }

        int sumRange(int left, int right) {
            return v[right + 1] - v[left];
        }
    };

    //326. Power of Three
    bool isPowerOfThree(int n) {
        while (true) {
            if (n <= 0) {
                return 0;
            }
            if (n == 1) {
                return 1;
            }
            if (n % 3 != 0) {
                return 0;
            }
            n /= 3;
        }
        return 0;
    }

    //338. Counting Bits
    vector<int> countBits(int n) {
        vector<int> res = {};
        for (int i = 0; i <= n; i++) {
            int j = i;
            int sum = 0;
            while (j != 0) {
                if (j % 2 != 0) {
                    sum++;
                }
                j /= 2;
            }
            res.push_back(sum);
        }
        return res;
    }

    //342. Power of Four
    bool isPowerOfFour(int n) {
        while (true) {
            if (n <= 0) {
                return 0;
            }
            if (n == 1) {
                return 1;
            }
            if (n % 4 != 0) {
                return 0;
            }
            n /= 4;
        }
        return 0;
    }

    //344. Reverse String
    void reverseString(vector<char>& s) {
        int l = 0, h = s.size() - 1;
        while (l < h) {
            char t = s[l];
            s[l] = s[h];
            s[h] = t;
            l++;
            h--;
        }
    }

    //345. Reverse Vowels of a String
    string reverseVowels(string s) {
        string pattern = "aeiouAEIOU";
        int l = 0, h = s.size() - 1;
        vector<int> v;
        while (l < h) {
            int b1 = findChar(pattern, s[l]);
            int b2 = findChar(pattern, s[h]);
            if (b1 && b2) {
                char t = s[l];
                s[l] = s[h];
                s[h] = t;
                l++;
                h--;
            } else {
                if (b1) {
                    h--;
                } else if (b2) {
                    l++;
                } else {
                    l++;
                    h--;
                }
            }
            
        }
        return s;
    }

    //349. Intersection of Two Arrays
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res = {};
        map<int, int> m;
        map<int, int> m2;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]] = -1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (m.find(nums2[i]) != m.end()) {
                if (m2.find(nums2[i]) == m2.end()) {
                    res.push_back(nums2[i]);
                }
                m2[nums2[i]] = -1;
            }
        }
        return res;
    }

    //350. Intersection of Two Arrays II
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res = {};
        map<int, int> m;
        for (int i = 0; i < nums1.size(); i++) {
            m[nums1[i]] = -1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (m.find(nums2[i]) != m.end()) {
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};







int main() {
    vector<int> v1 = { 2,2,1 };
    vector<int> v2 = { 2,5,6 };
    vector<int> v = { -2, 0, 3, -5, 2, -1 };
    ListNode* h1 = createListNode_rear("1,1");
    ListNode* h2 = createListNode_rear("5,6");
    mergeLinkList(h1, h2);

    Solution s;
    int n = 0b1011;
    TreeNode* head = createTree("37,-34,-48,null,-100,-100,48,null,null,null,null,-54,null,-71,-22,null,null,null,8");
    TreeNode* p1 = new TreeNode(4);
    TreeNode* p2 = new TreeNode(7);
    v = s.countBits(2);
    return 0;
}