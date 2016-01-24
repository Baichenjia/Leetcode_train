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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *phead=new ListNode(0), *pnode1=l1, *pnode2=l2;
        ListNode *head = phead;
        while(pnode1!=NULL && pnode2!=NULL){
            if(pnode1->val < pnode2->val){
                phead->next = pnode1;
                phead = phead->next;
                pnode1 = pnode1->next;
            }
            else{
                phead->next = pnode2;
                phead = phead->next;
                pnode2 = pnode2->next;
            }
        }
        if(pnode1 == NULL)
            phead->next = pnode2;
        else
            phead->next = pnode1;
        return head->next;
    }
};


/*  //µÝ¹é½â·¨
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l2->next, l1);
            return l2;
        }
    }
};*/


