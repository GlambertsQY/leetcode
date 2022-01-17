#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<cmath>
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

#endif // !leetcode

