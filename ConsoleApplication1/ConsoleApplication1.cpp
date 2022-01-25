// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


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
	//相同元素，map记录出现次数
	//map遍历
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res = {};
		map<int, int> m1, m2;
		for (int i = 0; i < nums1.size(); i++) {
			if (m1.find(nums1[i]) == m1.end()) {
				m1[nums1[i]] = 1;
			} else {
				m1[nums1[i]]++;
			}
		}
		for (int i = 0; i < nums2.size(); i++) {
			if (m1.find(nums2[i]) != m1.end()) {
				if (m2.find(nums2[i]) == m2.end()) {
					m2[nums2[i]] = 1;
				} else {
					m2[nums2[i]]++;
				}
			}
		}

		for (map<int,int>::iterator it = m2.begin(); it != m2.end(); it++) {
			int j = m1[it->first] >= m2[it->first] ? m2[it->first] : m1[it->first];
			while (j != 0) {
				res.push_back(it->first);
				j--;
			}
		}
		return res;
	}

	//367. Valid Perfect Square
	bool isPerfectSquare(int num) {
		int low = 0, high = num;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int n = pow(mid, 2);
			if (n == num) {
				return 1;
			} else if (n > num) {
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		return 0;
	}

	//374. Guess Number Higher or Lower
	//二分
	int guessNumber(int n) {
		int l = 1, h = n;
		while (l <= n) {
			int mid = l + (h - l) / 2;
			int r = guess(mid);
			if (r == 0) {
				return mid;
			} else if (r==-1) {
				l = mid + 1;
			} else {
				h = mid - 1;
			}
		}
		return -1;
	}

	//383. Ransom Note
	//小写字母：数组计数
	bool canConstruct(string ransomNote, string magazine) {
		int arr[26] = {};
		for (int i = 0; i < 26; i++) {
			arr[i] = 0;
		}
		for (int i = 0; i < magazine.size(); i++) {
			arr[magazine[i] - 'a']++;
		}
		for (int i = 0; i < ransomNote.size(); i++) {
			arr[ransomNote[i] - 'a']--;
			if (arr[ransomNote[i] - 'a'] < 0) {
				return 0;
			}
		}
		return 1;
	}

	//387. First Unique Character in a String
	//小写字母：数组计数
	int firstUniqChar(string s) {
		int arr[26] = {};
		for (int i = 0; i < 26; i++) {
			arr[i] = 0;
		}
		for (int i = 0; i < s.size(); i++) {
			arr[s[i] - 'a']++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (arr[s[i] - 'a'] == 1) {
				return i;
			}
		}
		return -1;
	}

	//389. Find the Difference
	//小写字母：数组计数,
	char findTheDifference(string s, string t) {
		int arr[26] = {};
		int arr2[26] = {};
		for (int i = 0; i < 26; i++) {
			arr[i] = 0;
		}
		for (int i = 0; i < 26; i++) {
			arr2[i] = 0;
		}
		for (int i = 0; i < s.size(); i++) {
			arr[s[i] - 'a']++;
		}
		for (int i = 0; i < t.size(); i++) {
			arr2[t[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++) {
			if (arr[i] != arr2[i]) {
				char c = 'a' + i;
				return c;
			}
		}
		return '#';
	}

	//位运算
	char findTheDifference2(string s, string t) {
			string ss = s + t;
			int  res = 0;
			for (int i = 0; i < ss.size(); i++) {
				res ^= ss[i];
			}
			return res;
	}

	//392. Is Subsequence
	bool isSubsequence(string s, string t) {
		int i = 0, j = 0;
		while (i < s.size() && j < t.size()) {
			if (s[i] == t[j]) {
				i++;
				j++;
			} else {
				j++;
			}
		}
		if (i == s.size()) {
			return 1;
		} else {
			return 0;
		}
	}

	//401. Binary Watch
	//所有时间结果，找turnedOn
	//number of 1 in binary: ____builtin_popcount()
	vector<string> readBinaryWatch(int turnedOn) {
		vector<string> res = {};
		for (int h = 0; h < 12; ++h) {
			for (int m = 0; m < 60; ++m) {
				if (__popcnt(h) + __popcnt(m) == turnedOn) {
					res.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
				}
			}
		}
		return res;
	}

	//404. Sum of Left Leaves
	int sum_404 = 0;
	void func_404(TreeNode* root, int isLeft) {
		if (root == NULL) {
			return;
		}
		if (root->left == NULL && root->right == NULL && isLeft) {
			sum_404 += root->val;
		}
		func_404(root->left, 1);
		func_404(root->right, 0);
	}
	int sumOfLeftLeaves(TreeNode* root) {
		func_404(root, 0);
		return sum_404;
	}

	//405. Convert a Number to Hexadecimal
	//负数：先转unsigned
	string toHex(int num) {
		if (num == 0) {
			return "0";
		}
		string res = "";
		unsigned n = num;
		while (n!=0) {
			int t = n % 16;
			if (t <= 9) {
				res.insert(res.begin(), to_string(t)[0]);
			} else {
				res.insert(res.begin(), 'a' + t - 10);
			}
			n /= 16;
		}
		return res;
	}

	//409. Longest Palindrome
	int longestPalindrome(string s) {
		int res = 0;
		map<int, int> m;
		for (int i = 0; i < s.size(); i++) {
			if (m.find(s[i]) == m.end()) {
				m[s[i]] = 1;
			} else {
				m[s[i]]++;
			}
		}
		int numOfOdd = 0;
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
			if (it->second % 2 == 0) {
				res += it->second;
			} else {
				res += it->second / 2;
				numOfOdd++;
			}
		}
		if (numOfOdd != 0) {
			res++;
		}
		return res;
	}

	//412. Fizz Buzz
	vector<string> fizzBuzz(int n) {
		vector<string> vs = { "FizzBuzz","Fizz","Buzz" }, res = {};
		for (int i = 1; i <= n; i++) {
			if (i % 3 != 0 && i % 5 != 0) {
				res.push_back(to_string(i));
			}
			if (i % 3 == 0 && i % 5 != 0) {
				res.push_back(vs[1]);
			}
			if (i % 3 != 0 && i % 5 == 0) {
				res.push_back(vs[2]);
			}
			if (i % 3 == 0 && i % 5 == 0) {
				res.push_back(vs[0]);
			}
		}
		return res;
	}

	//414. Third Maximum Number
	//map反向遍历: reverse_iterator, rbdgin(), rend()
	int thirdMax(vector<int>& nums) {
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			m[nums[i]] = -1;
		}
		int sum = 1;
		for (map<int, int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++) {
			if (sum == 3) {
				return it->first;
			}
			sum++;
		}
		return (--m.end())->first;
	}

	//415. Add Strings
	string addStrings(string num1, string num2) {
		int c = 0;
		string res = "";
		int l1 = num1.size(), l2 = num2.size();
		if (l1 > l2) {
			for (int i = 0; i < l1 - l2; i++) {
				num2.insert(num2.begin(), '0');
			}
		} else {
			for (int i = 0; i < l2 - l1; i++) {
				num1.insert(num1.begin(), '0');
			}
		}
		for (int i = num1.size() - 1; i >= 0; i--) {
			int t = num1[i] - '0' + num2[i] - '0' + c;
			string s = to_string(t);
			c = t >= 10 ? 1 : 0;
			res.insert(res.begin(), s[s.size() - 1]);
		}
		if (c == 1) {
			res.insert(res.begin(), '1');
		}
		return res;
	}

	//434. Number of Segments in a String
	//考虑单词/考虑空格
	int countSegments(string s) {
		if (s.size() == 0) {
			return 0;
		}
		int res = 0;
		int len = 0;
		for (int i = 0; i < s.size(); i++) {
			if (len != 0 && s[i] == ' ') {
				res++;
				len = 0;
			}
			if (s[i] != ' ') {
				len = 1;
			}
		}
		if (len == 1) {
			res++;
		}
		return res;
	}

	//441. Arranging Coins
	int arrangeCoins(int n) {
		for (int i = 1; i <= n; i++) {
			int t = (pow(i, 2) + i) / 2;
			if (t > n) {
				return i - t + n;
			}
			if (t == n) {
				return i;
			}
		}
		return -1;
	}

	//448. Find All Numbers Disappeared in an Array
	//nums[i - 1] + n;找未大于n的数
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> res = {};
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			nums[(nums[i] - 1) % n] += n;  //+n，取余数，则不会越界，且能保持原数组元素下标作用。
		}
		for (int i = 0; i < n; i++) {
			if (nums[i] <= n) {
				res.push_back(i + 1);
			}
		}
		return res;
	}

	//453. Minimum Moves to Equal Array Elements
	//n-1个数+1 = 1个数-1
	int minMoves(vector<int>& nums) {
		int res = 0;
		int min = getMin(nums);
		for (int i = 0; i < nums.size(); i++) {
			res += nums[i] - min;
		}
		return res;
	}

	//455. Assign Cookies
	//贪心算法
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int res = 0;
		int i = 0, j = 0;
		while (i < g.size() && j < s.size()) {
			if (s[j] >= g[i]) {
				res++;
				i++;
			}
			j++;
		}
		return res;
	}

	//459. Repeated Substring Pattern
	//枚举，类似希尔排序，固定长度（长度=substring.size()）
	//kmp
	bool repeatedSubstringPattern(string s) {
		int n = s.size();
		for (int i = 1; i * 2 <= n; ++i) {
			if (n % i == 0) {
				bool match = true;
				for (int j = i; j < n; ++j) {
					if (s[j] != s[j - i]) {
						match = false;
						break;
					}
				}
				if (match) {
					return true;
				}
			}
		}
		return false;
	}

	//461. Hamming Distance
	int hammingDistance(int x, int y) {
		string s = UIntToBin(x ^ y);
		int res = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') {
				res++;
			}
		}
		return res;
	}

	//463. Island Perimeter
	int islandPerimeter(vector<vector<int>>& grid) {
		int nx = grid.size(), ny = grid[0].size(), res = 0;
		for (int i = 0; i < nx; i++) {
			for (int j = 0; j < ny; j++) {
				if (grid[i][j] == 1) {
					int sum = 4;
					if (i != 0) {
						if (grid[i - 1][j] == 1) {
							sum--;
						}
					}
					if (i != nx - 1) {
						if (grid[i + 1][j] == 1) {
							sum--;
						}
					}
					if (j != 0) {
						if (grid[i][j - 1] == 1) {
							sum--;
						}
					}
					if (j != ny - 1) {
						if (grid[i][j + 1] == 1) {
							sum--;
						}
					}
					res += sum;
				}
			}
		}
		return res;
	}

	//476. Number Complement
	//异或，再移位
	int findComplement(int num) {
		string s = UIntToBin(num);
		int n = s.size();
		int res = pow(2, n) - 1;
		res ^= num;
		return res;
	}

	//482. License Key Formatting
	//从末尾开始
	string licenseKeyFormatting(string s, int k) {
		string ans;
		int cnt = 0;

		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] != '-') {
				ans.push_back(toupper(s[i]));   //toupper()转大写
				cnt++;
				if (cnt % k == 0) {
					ans.push_back('-');
				}
			}
		}
		if (ans.size() > 0 && ans.back() == '-') {
			ans.pop_back();
		}
		reverse(ans.begin(), ans.end());

		return ans;
	}

	//485. Max Consecutive Ones
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int max = 0;
		int l = 0, r = 0;
		nums.insert(nums.begin(), 0);
		nums.push_back(0);
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				l = r;
				r = i;
				if (r - l > max) {
					max = r - l;
				}
			}
		}
		return max - 1;
	}

	//492. Construct the Rectangle
	vector<int> constructRectangle(int area) {
		int l = sqrt(area), h = area;
		vector<int> res = {};
		for (int i = l; i <= h; i++) {
			if (area % i == 0) {
				if (area / i > i) {
					res.push_back(area / i);
					res.push_back(i);
				} else {
					res.push_back(i);
					res.push_back(area / i);
				}
				return res;
			}
		}
		return res;
	}

	//495. Teemo Attacking
	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		int res = 0, n = timeSeries.size();
		for (int i = 0; i < n; i++) {
			if (i != n - 1) {
				if (timeSeries[i] + duration - 1 < timeSeries[i + 1]) {
					res += duration;
				} else {
					res += timeSeries[i + 1] - timeSeries[i];
				}
			} else {
				res += duration;
			}
		}
		return res;
	}

	//496. Next Greater Element I
	/*
	* 单调栈
	* 1.栈空：元素入栈，并m[num2[i]]=-1
	* 2.栈非空：栈顶元素大于当前元素，则入栈，且m[num2[i]]=栈顶元素。否则，弹栈直至栈空
	*/
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(), n2 = nums2.size();
		vector<int> res = {}, s = {};
		unordered_map<int, int> m;   //unordered_map（哈希表）：偏向查找，不按key有序。map（红黑树）：偏向排序。
		for (int i = n2 - 1; i >= 0; i--) {
			if (s.empty()) {
				m[nums2[i]] = -1;
				s.push_back(nums2[i]);
			} else {
				while (!s.empty() && nums2[i] >= s[s.size() - 1]) {
					s.erase(s.end() - 1);
				}
				if (!s.empty()) {
					m[nums2[i]] = s[s.size() - 1];
				} else {
					m[nums2[i]] = -1;
				}
				s.push_back(nums2[i]);
			}
		}
		for (int i = 0; i < n1; i++) {
			res.push_back(m[nums1[i]]); //偏向查找
		}
		return res;
	}

	//500. Keyboard Row
	vector<string> findWords(vector<string>& words) {
		unordered_map<char, int> um;
		string s1 = "qwertyuiop", s2 = "asdfghjkl", s3 = "zxcvbnm";
		vector<string> res = {};
		for (int i = 0; i < s1.size(); i++) {
			um[s1[i]] = 0;
		}
		for (int i = 0; i < s2.size(); i++) {
			um[s2[i]] = 1;
		}
		for (int i = 0; i < s3.size(); i++) {
			um[s3[i]] = 2;
		}
		for (int i = 0; i < words.size(); i++) {
			int sign = um[tolower(words[i][0])], flag = 1;
			for (int j = 0; j < words[i].size(); j++) {
				if (um[tolower(words[i][j])] != sign) {
					flag = 0;
					break;
				}
			}
			if (flag) {
				res.push_back(words[i]);
			}
		}
		return res;
	}

	//501. Find Mode in Binary Search Tree
	int max_501 = INT32_MIN;
	int num_501 = 0;
	int sum_501 = 0;
	vector<int> res_501 = {};
	
	void update_501(int x) {
		if (x == num_501) {
			++sum_501;
		} else {
			sum_501 = 1;
			num_501 = x;
		}

		//可以动态一次性使res_501始终只包含最大元素
		if (sum_501 == max_501) {
			res_501.push_back(num_501);
		}
		if (sum_501 > max_501) {
			max_501 = sum_501;
			res_501 = vector<int>{ num_501 }; //vector初始化的一种方式
		}
	}

	void midSearch(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		midSearch(root->left);
		update_501(root->val);
		midSearch(root->right);
	}
	
	vector<int> findMode(TreeNode* root) {
		midSearch(root);
		return res_501;
	}

	//504. Base 7
	string convertToBase7(int num) {
		string s = "";
		if (num == 0) {
			return "0";
		}
		int negative = num < 0 ? 1 : 0;
		num = abs(num);
		while (num != 0) {
			s.insert(s.begin(), to_string(num % 7)[0]);
			num /= 7;
		}
		if (negative) {
			s.insert(s.begin(), '-');
		}
		return s;
	}

	//506. Relative Ranks
	vector<string> findRelativeRanks(vector<int>& score) {
		vector<string> medals = { "Gold Medal","Silver Medal", "Bronze Medal" };
		vector<string> res = {};
		res.resize(score.size());
		map<int, int> m;
		for (int i = 0; i < score.size(); i++) {
			m[score[i]] = i;
		}
		int i = 0;
		for (map<int, int>::reverse_iterator it = m.rbegin(); it != m.rend(); it++) {
			if (i < 3) {
				res[it->second] = medals[i];
			} else {
				res[it->second] = to_string(i + 1);
			}
			i++;
		}
		return res;
	}

	//507. Perfect Number
	//累加穷举就完事了
	bool checkPerfectNumber(int num) {
		if (num == 1) {
			return 0;
		}
		vector<int> res = { 1 };
		int i = 2;
		for (int i = 2; i < sqrt(num); i++) {
			if (num % i == 0) {
				res.push_back(i);
				res.push_back(num / i);
			}
		}
		int sum = 0;
		for (int i = 0; i < res.size(); i++) {
			sum += res[i];
		}
		return sum == num ? 1 : 0;
	}

	//509. Fibonacci Number
	int fib(int n) {
		if (n == 0) {
			return 0;
		}
		if (n == 1) {
			return 1;
		}
		return fib(n - 1) + fib(n - 2);
	}

	int fib_nr(int n) {
		vector<int> v = { 0,1 };
		for (int i = 2; i <= n; i++) {
			v.push_back(v[i - 1] + v[i - 2]);
		}
		return v[n];
	}

	//520. Detect Capital
	bool isCapital(char c) {
		return c <= 'Z' && c >= 'A' ? 1 : 0;
	}

	bool detectCapitalUse(string word) {
		int numOfCapital = 0;
		for (int i = 0; i < word.size(); i++) {
			if (isCapital(word[i])) {
				numOfCapital++;
			}
		}
		if (!(numOfCapital == word.size() || numOfCapital == 1 || numOfCapital == 0)) {
			return 0;
		}
		if (numOfCapital == 1) {
			if (!isCapital(word[0])) {
				return 0;
			}
		}
		return 1;
	}

	//521. Longest Uncommon Subsequence I
	int findLUSlength(string a, string b) {
		if (a == b) {
			return -1;
		}
		return a.size() >= b.size() ? a.size() : b.size();
	}

	//530. Minimum Absolute Difference in BST
	int preNum_530 = -1;
	int min_530 = INT32_MAX;
	void func_530(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		func_530(root->left);
		if (preNum_530 == -1) {
			preNum_530 = root->val;
		} else {
			if (abs(preNum_530 - root->val) < min_530) {
				min_530 = abs(preNum_530 - root->val);
			}
			preNum_530 = root->val;
		}
		func_530(root->right);
	}

	int getMinimumDifference(TreeNode* root) {
		func_530(root);
		return min_530;
	}

	//541. Reverse String II
	string reverseStr(string s, int k) {
		int i = 0;
		if (k > s.size()) {
			mReverse(s, i, s.size() - 1);
		} else {
			while (i < s.size()) {
				if (i + k - 1 < s.size()) {
					mReverse(s, i, i + k - 1);
				} else {
					mReverse(s, i, s.size() - 1);
				}
				i += 2 * k;
			}
		}
		return s;
	}

	//543. Diameter of Binary Tree
	int max_534 = 0;

	//直接return，为树高
	int depth_543(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int l = depth_543(root->left);
		int r = depth_543(root->right);
		if (l + r > max_534) {
			max_534 = l + r;
		}
		return (l > r ? l : r) + 1;
	}

	int diameterOfBinaryTree(TreeNode* root) {
		int depth = depth_543(root);
		return max_534;
	}

	//551. Student Attendance Record I
	bool checkRecord(string s) {
		int numOfA = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'A') {
				numOfA++;
				if (numOfA == 2) {
					return 0;
				}
			} else {
				if (s[i] == 'L') {
					int sum = 0;
					while (s[i] == 'L') {
						sum++;
						if (sum == 3) {
							return 0;
						}
						i++;
					}
					i--;
				}
			}
		}
		return 1;
	}

	//557. Reverse Words in a String III
	string reverseWords(string s) {
		int preIndex = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				mReverse(s, preIndex, i - 1);
				preIndex = i + 1;
			}
		}
		mReverse(s, preIndex, s.size() - 1);
		return s;
	}

	//559. Maximum Depth of N-ary Tree
	//由树高扩展
	int maxDepth(Node* root) {
		if (root == NULL) {
			return 0;
		}
		int maxDep = 0;
		for (int i = 0; i < root->children.size(); i++) {
			int childDepth = maxDepth(root->children[i]);
			maxDep = childDepth > maxDep ? childDepth : maxDep;
		}
		return maxDep + 1;
	}

	//561. Array Partition I
	int arrayPairSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i] < nums[i + 1] ? nums[i] : nums[i + 1];
			i++;
		}
		return sum;
	}

	//563. Binary Tree Tilt
	//递归理解:后根
	int sum_563 = 0;

	int dfs_563(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int l = dfs_563(root->left);
		int r = dfs_563(root->right);
		sum_563 += abs(l - r);
		return l + r + root->val;
	}

	int findTilt(TreeNode* root) {
		dfs_563(root);
		return sum_563;
	}

	//566. Reshape the Matrix
	//vector分配好空间，直接push，可自动换行
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		int x = mat[0].size(), y = mat.size();
		if (x * y != r * c) {
			return mat;
		}
		vector<vector<int>> res = { };
		int index = 0;
		for (int i = 0; i < r; i++) {
			vector<int> t = {};
			for (int j = 0; j < c; j++) {
				t.push_back(mat[index / x][index % x]);
				index++;
			}
			res.push_back(t);
		}
		return res;
	}

	//572. Subtree of Another Tree
	bool isSame_572 = 0;

	bool isSameTree_572(TreeNode* t1, TreeNode* t2) {
		/*
		* if (t1->val == t2->val || (t1==NULL&&t2==NULL)) {
			return 1;
		} else {
			return 0;
		}
		将导致，直接return
		*/

		if (!t1 && !t2) {
			return 1;
		}
		if ((t1 && !t2) || (!t1 && t2) || (t1->val != t2->val)) {
			return 0;
		}
		return isSameTree_572(t1->left, t2->left) && isSameTree_572(t1->right, t2->right);
	}

	void dfs_572(TreeNode* root, TreeNode* subRoot) {
		if (root == NULL) {
			return;
		}
		if (root->val == subRoot->val) {
			if (isSame_572 != 1) {
				isSame_572 = isSameTree_572(root, subRoot);
			}
		}
		dfs_572(root->left, subRoot);
		dfs_572(root->right, subRoot);
	}

	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		dfs_572(root, subRoot);
		return isSame_572;
	}

	//575. Distribute Candies
	int distributeCandies(vector<int>& candyType) {

	}
};

int main() {
	vector<int> v1 = { 4,1,2 };
	vector<int> v2 = { 1,3,4,2 };
	vector<int> v = { };
	vector<string> vs = { "Hello","Alaska","Dad","Peace" };
	Solution s;
	int n = 0b1011;
	TreeNode* root1 = createTree("3,4,5,1,2,null,null,null,null,0");
	TreeNode* root2 = createTree("4,1,2");
	vector<vector<int>> vv = { {1,2},{3,4} };
	s.isSubtree(root1, root2);
	return 0;
}