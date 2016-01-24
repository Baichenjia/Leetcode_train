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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode *pnode = head, *phead = head;
        while(pnode->next != NULL){
            length++;
            pnode = pnode->next;
        }
        if(length-n-1 == -2){
            head = head->next;
            return head;
        }
        for(int i=0;i <= length-n-1;i++)
            phead = phead->next;
        ListNode* delnode = phead->next;
        if(phead->next->next == NULL)
            phead->next = NULL;
        else
            phead->next = phead->next->next;
        delete delnode;
        return head;
    }
};