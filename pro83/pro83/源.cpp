#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
		ListNode *p = head, *delnode = NULL;
		while(p != NULL && p->next != NULL){
			if(p->val == p->next->val){
				delnode = p->next;
				delete delnode;
				p->next = p->next->next;
			}
			if(p->next != NULL){
				if(p->val != p->next->val)
					p = p->next;
			}
		}
		return head;
    }
};