#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(-1);
        preheader->next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while(cur = cur->next) 
            num++;
        while(num>=k) {
            cur = pre->next;
            nex = cur->next;
            for(int i=1;i<k;++i) {
                cur->next=nex->next;
                nex->next=pre->next;
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        return preheader->next;
	}
};


int main(){
	ListNode *node = new ListNode(0);
	ListNode *p = node;
	for(int i = 1;i <= 10;i++){
		ListNode *q = new ListNode(i);
		p->next = q;
		p = p->next;
	}
	Solution sul;
	int k = 3;
	ListNode *res = sul.reverseKGroup(node->next, k);
	while(res != NULL){
		cout<<res->val<<endl;
		res = res->next;
	}
	getchar();getchar();
	return 0;
}