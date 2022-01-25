#pragma once
#include <iostream>
#include <string>
#include<vector>
#include<limits>
#include<cmath>
#include<map>
#include<algorithm>
#include<unordered_map>
using namespace std;
#ifndef leetcode

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void trimLeftTrailingSpaces(string& input);
void trimRightTrailingSpaces(string& input);
ListNode* createListNode_rear(string s);
ListNode* createLoopListNode_rear(string s, int pos);
void mergeLinkList(ListNode* h1, ListNode* h2);
int getNumOfDigits(int nums);
TreeNode* createTree(string s);
vector<int> stringToVector_int(string s);
vector<string> stringToVector_string(string s);

//278. First Bad Version
bool isBadVersion(int version);

bool findChar(string s, char c);

//374. Guess Number Higher or Lower
int guess(int num);

int getMin(vector<int> nums);

string UIntToBin(int n);

void mReverse(string& s, int l, int h);

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

#endif // !leetcode

