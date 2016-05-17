#include <iostream>
#include <vector>
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
		if(head == NULL || head->next == NULL)
			return head;
		ListNode *headpre = new ListNode(9999);
		headpre->next = head;
		ListNode *p0 = headpre, *p1 = head, *p2 = head->next;
		while(p1 != NULL && p1->next != NULL){
			if(p1->val != p2->val){
				p0 = p0->next;
				p1 = p1->next;
				p2 = p2->next;
			}
			else{
				while(p2 != NULL && p1->val == p2->val){
					p1 = p1->next;
					p2 = p2->next;
				}
				if(p2 == NULL)
					p0->next = NULL;
				else{
					p0->next = p2;
					p1 = p2;
					p2 = p2->next;
				}
			}
		}
		return headpre->next;
    }
};


int main(){
	int arr[] = {1, 1, 2, 3, 4, 4, 5, 5};
	ListNode *head = new ListNode(arr[0]);
	ListNode *p = head;
	for(int i = 1;i <= 7;++i){
		p->next = new ListNode(arr[i]);
		p = p->next;
	}

	Solution sul;
	head = sul.deleteDuplicates(head);
	while(head != NULL){
		cout<<head->val<<"--";
		head = head->next;
	}

	getchar();
	return 0;
}