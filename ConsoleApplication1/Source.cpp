#include"Header.h"
void trimLeftTrailingSpaces(string& input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string& input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

//eg:"-21,234,1", "6,2,8,0,4,7,9,null,null,3,5"
vector<int> stringToVector_int(string s) {
	vector<string> s_split = {};
	vector<int> res = {};
	int i = 0;
	string s_t = "";
	while (i < s.size()) {
		if (s[i] == ',') {
			s_split.push_back(s_t);
			s_t = "";
		} else {
			s_t.push_back(s[i]);
		}
		i++;
	}
	s_split.push_back(s_t);
	for (int i = 0; i < s_split.size(); i++) {
		string s = s_split[i];
		int sum = 0;
		if (s != "null") {
			for (int i = s.size() - 1; i >= 0; i--) {
				if (s[i] != '-') {
					sum += pow(10, s.size() - i - 1) * (s[i] - '0');
				} else {
					sum = -sum;
				}
			}
			res.push_back(sum);
		} else {
			res.push_back(-1);
		}
		
	}
	return res;
}

ListNode* createListNode_rear(string s) {
	vector<int> v = stringToVector_int(s);
	ListNode* head = new ListNode();
	head->val = v[0];
	head->next = NULL;
	ListNode* rear = head;
	for (int i = 1; i < v.size(); i++) {
		ListNode* temp = new ListNode();
		temp->val = v[i];
		rear->next = temp;
		rear = temp;
	}
	return head;
}

ListNode* createLoopListNode_rear(string s, int pos) {
	vector<int> v = stringToVector_int(s);
	ListNode* head = new ListNode();
	head->val = v[0];
	head->next = NULL;
	ListNode* rear = head;
	for (int i = 1; i < v.size(); i++) {
		ListNode* temp = new ListNode();
		temp->val = v[i];
		rear->next = temp;
		rear = temp;
	}
	ListNode* p = head;
	if (pos == -1) {
		return head;
	}
	for (int i = 0; i < pos; i++) {
		p = p->next;
	}
	rear->next = p;
	return head;
}

void mergeLinkList(ListNode* h1, ListNode* h2) {
	ListNode* p1 = h1, * p2 = h2;
	h1 = h1->next;
	h2->next->next = h1;
}

int getNumOfDigits(int nums) {
	int res = 0;
	while (nums != 0) {
		res++;
		nums /= 10;
	}
	return res;
}

TreeNode* createTree(string s) {
	vector<int> v = stringToVector_int(s);
	vector<TreeNode*> tv = {};
	for (int i = 0; i < v.size(); i++) {
		TreeNode* t = new TreeNode();
		if (v[i] != -1) {
			t->val = v[i];
			tv.push_back(t);
		} else {
			tv.push_back(NULL);
		}
		
	}
	for (int i = 0; i < v.size(); i++) {
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		if (tv[i] == NULL) {
			continue;
		}
		if (l > v.size() - 1) {
			tv[i]->left = NULL;
		}
		if (r > v.size() - 1) {
			tv[i]->right = NULL;
		}
		if (l <= v.size() - 1) {
			tv[i]->left = tv[l];
		}
		if (r <= v.size() - 1) {
			tv[i]->right = tv[r];
		}
	}
	return tv[0];
}