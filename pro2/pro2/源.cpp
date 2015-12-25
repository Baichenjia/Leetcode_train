#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		/*
		int size1 = 0, size2 = 0;
		ListNode *n1 = l1, *n2 = l2;
		while(n1 != NULL)
		{n1 = n1->next; size1++;}
		while(n2 != NULL)
		{n2 = n2->next; size2++;}
		ListNode *h1, *h2, *head1, *head2;
		h1 = new ListNode(0);
		h2 = new ListNode(0);
		head1 = h1; 
		head2 = h2;
		if(size1 < size2)
		{
			for(int i = 0;i < size2 - size1;i++)
			{
				ListNode *node = new ListNode(0);
				h1->next = node;
				h1 = h1->next;
			}
			h1->next = l1;
			head1 = head1->next;
			head2 = l2;
		}
		else if(size1 > size2)
		{
			for(int i = 0;i < size1 - size2;i++)
			{
				ListNode *node = new ListNode(0);
				h2->next = node;
				h2 = h2->next;
			}
			h2->next = l2;
			head2 = head2->next;
			head1 = l1;
		}
		else
		{
			head1 = l1;
			head2 = l2;
		}
		ListNode *l3 = new ListNode(0);
		ListNode *head = l3;
		ListNode *p1 = head1;
		ListNode *p2 = head2;
		int val1,val2,val3;
		while(p1 != NULL)
		{
			val1 = p1->val;
			val2 = p2->val;
			val3 = val1 + val2;
			p1 = p1->next;
			p2 = p2->next;
			ListNode *node = new ListNode(val3);
			l3->next = node;
			l3 = l3->next;
		}
		head = head -> next;
		ListNode *head_temp = head;
		vector<int> res;
		while(head_temp!=NULL)
		{
			int temp = head_temp->val;
			head_temp = head_temp->next;
			res.push_back(temp);
		}
		for(int i = res.size()-1;i >= 1;i--)
		{
			if(res[i] >= 10)
			{
				res[i] -= 10;
				res[i-1] += 1;
			}
		}
		
		ListNode *newhead;
		ListNode *newhead_temp = new ListNode(0);
		newhead = newhead_temp;
		bool flag = false;
		if(res[0] >= 10)
		{
			res[0] -= 10;
			flag = true;
		}
		for(int i = 0;i < res.size();i++)
		{
			ListNode* node = new ListNode(res[i]);
			newhead_temp->next = node;
			newhead_temp = newhead_temp -> next;
		}
		if(flag)
		{
			ListNode* node = new ListNode(1);
			newhead_temp->next = node;
			newhead_temp = newhead_temp->next;
			newhead_temp->next = NULL;
		}
		return newhead->next;
		*/
	    int carry = 0;
		ListNode *dummy = new ListNode(0), *cur;
		cur = dummy;
		while (l1 || l2 || carry) {
			if (l1) {
				carry += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				carry += l2->val;
				l2 = l2->next;
			}
			cur->next = new ListNode(carry%10);
			cur = cur->next;
			carry /= 10;
		}
		return dummy->next;
	}
};

ListNode* build_list(int arr[], int n)
{
	ListNode* head;
	ListNode* a = new ListNode(arr[0]);
	head = a;
	for(int i = 1;i < n;i++)
	{
		ListNode* node = new ListNode(arr[i]);
		a->next = node;
		a = a->next;
	}
	return head;
}

int main()
{
	int n = 2;
	int arr1[2] = {9,8};
	int arr2[1] = {1};
	ListNode *arr1_list = build_list(arr1, 2);
	ListNode *arr2_list = build_list(arr2, 1);
	
	Solution sul;
	ListNode *res = sul.addTwoNumbers(arr1_list, arr2_list);	
	for(int i = 0;i < n;i++)
	{
		cout<<res->val<<endl;
		res = res -> next;
	}

	getchar();getchar();
	return 0;
}