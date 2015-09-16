#include<vector>
#include<cstdio>
#include<string>

using namespace std;

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		//m-1 node
		
		if (n - m == 0) {
			return head;
		}

		ListNode* firstNoChangeNode = nullptr;
		ListNode* prepNode = head;
		
		
		for (int i = 1; i < m; i++) {
			firstNoChangeNode = prepNode;
			prepNode = prepNode->next;
		}

		
		ListNode* firstNode = prepNode;
		ListNode* currNode = prepNode->next;
		for (int i = 0; i < n - m ; i++) {
			ListNode* nextNode = currNode->next;

			currNode->next = prepNode;
			prepNode = currNode;
			currNode = nextNode;
		}
		firstNode->next = currNode;
		if (m <= 1) {
			return prepNode;
		}
		else {
			
			firstNoChangeNode->next = prepNode;
			return head;
		}
	}
};



int main()
{
	
	ListNode *head = new ListNode(1);
	ListNode *prep = head;
	for (int i = 2; i < 5; i++) {
		ListNode* curr = new ListNode(i);
		prep->next = curr;
		prep = curr;
	}

	Solution solution = Solution();

	head = solution.reverseBetween(head, 1, 2);

	return 0;
}