#include <iostream>
using namespace std;


 
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		if(head == NULL)   return NULL;
		if(head->next == NULL)   return head;
        ListNode* p1 = head;
		ListNode* p2 = head->next;
		head = p2;
		ListNode* front = head;
		while(p1!=NULL && p2!=NULL){
			p1->next = p2->next;
			p2->next = p1;
			if(front != head)
				front->next = p2;
			if(p1->next == NULL)  return head;
			front = p1;
			p1 = p1->next;			
			if(p1->next == NULL)  return head;
			p2 = p1->next;
		}
		return head;
    }
};