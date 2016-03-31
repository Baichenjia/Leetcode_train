#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.size() == 0)
			return NULL;
		while(lists.size() > 1){
			ListNode* p1 = lists[lists.size()-1]; lists.pop_back();
			ListNode* p2 = lists[lists.size()-1]; lists.pop_back();
			ListNode* res = new ListNode(0);
			ListNode* q = res;
			while(p1 != NULL && p2 != NULL){
				if(p1->val < p2->val){
					q->next = p1;
					q = q->next;
					p1 = p1->next;
				}
				else{
					q->next = p2;
					q = q->next;
					p2 = p2->next;
				}
			}
			if(p1 == NULL){
				q->next = p2;
			}
			else
				q->next = p1;
			lists.insert(lists.begin(), res->next);
		}
		return lists[0];
    }
};


int main(){
	Solution sul;
	ListNode* p1 = new ListNode(0);  ListNode* q1 = p1;
	ListNode* p2 = new ListNode(0);  ListNode* q2 = p2;
	ListNode* p3 = new ListNode(0);  ListNode* q3 = p3;
	ListNode* p4 = new ListNode(0);  ListNode* q4 = p4;
	for(int i = 1;i < 98;i += 1){
		ListNode *temp1 = new ListNode(i);     q1->next = temp1;  q1 = q1->next;
		ListNode *temp2 = new ListNode(i+1);   q2->next = temp2;  q2 = q2->next;
		ListNode *temp3 = new ListNode(i+2);   q3->next = temp3;  q3 = q3->next;
		ListNode *temp4 = new ListNode(i+3);   q4->next = temp4;  q4 = q4->next;
	}
	ListNode* arr[4] = {p1->next, p2->next, p3->next, p4->next};
	vector<ListNode*> lists(arr, arr+4);
	
	/*
	vector<ListNode*>::iterator iter;
	for(iter = lists.begin();iter != lists.end(); iter++){
		ListNode *k = *iter;
		while(k != NULL){
			cout<<k->val<<"  ";
			k = k->next;
		}
		cout<<endl;
	}*/

	ListNode* node = sul.mergeKLists(lists);
	while(node != NULL){
		cout<<node->val<<endl;
		node = node->next;
	}
	getchar();getchar();
	return 0;
}