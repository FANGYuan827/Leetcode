/*
2018Äê6ÔÂ1ÈÕ21:09:37
*/

#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution_demo48 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
			return NULL;
		if(head->next==NULL)
			return head;
		ListNode *res = head;
		ListNode *tmp1 = head,*tmp2 = tmp1->next;
		while(tmp1&&tmp2)
		{
			if(tmp1->val==tmp2->val)
			{
				if(tmp2->next==NULL)
					tmp1->next = NULL;
				tmp2 = tmp2->next;
			}
			else
			{
				tmp1->next = tmp2;
				tmp1 = tmp2;
				tmp2 = tmp1?tmp1->next:NULL;
			}
			
		}
		return res;
    }
};

template<typename T>
void Print_list(T *head)
{
	if(!head)
		return;
	while(head)
	{
		cout<<head->val<<"->"<<ends;
		head = head->next;
	}
	cout<<endl;
}
int main_demo48(int argc,char **argv)
{
	Solution_demo48 s1;
	ListNode l1(1),l2(1),l3(1),l4(6),l5(6),l6(7),l7(8),l8(8);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	Print_list(&l1);
	ListNode *res = s1.deleteDuplicates(&l1);
	Print_list(&l1);
	system("pause");
	return 0;
}