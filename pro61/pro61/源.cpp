#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/*//ERROR answer
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if(head == NULL || k == 0) 
			return head;
		
		int n = 1;
		ListNode *cur = head, *newhead = NULL, *end = NULL, *p = NULL;
		// calculate the length of list
		while(cur->next != NULL){
			n++;
			cur = cur->next;
		}
		end = cur;
		if(k > n){
			newhead = ListReverse(head);
			return newhead;
		}
		else if(n == k)
			return head;
		else{
			int step = n - k - 1;
			cur = head;
			while(step--){
				cur = cur->next;
			}
			p = cur;
			newhead = cur->next;
			//rotate the list
			end->next = head;
			p->next = NULL;
			return newhead;
		}
    }

	ListNode *ListReverse(ListNode *head){
		ListNode *p = head, *q, *r = NULL;
		ListNode *newhead = NULL;
		while(p != NULL){
			q = p->next;
			if(q == NULL)
				newhead = p;
			p->next = r;
			r = p;
			p = q;
		}
		return newhead;
	}
};*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;

        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};

int main(){
	ListNode *head = new ListNode(1);
	ListNode *node = head;
	for(int i = 2;i <= 6;i++){
		ListNode *newNode = new ListNode(i);
		node->next = newNode;
		node = node->next;
	}
	Solution sul;
 	ListNode *newhead = sul.rotateRight(head, 10);
	//free the memery of ListNode
	ListNode *delnode;
	while(newhead != NULL){
		delnode = newhead;
		newhead = newhead->next;
		delete delnode;
	}
	getchar();
	return 0;
}