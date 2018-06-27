/*
2018Äê6ÔÂ20ÈÕ19:53:12 
Sort a linked list in O(n log n) time using constant space complexity.
*/
#include <iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

class Solution_demo56 {
public:
    ListNode *sortList(ListNode *head) {
        if(!head)
            return head;
        
    }
};

int main(int argc,char **argv)
{
	ListNode l1(10),l2(22),l3(1),l4(4),l5(125),l6(16);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	Solution_demo56 *s1 = new Solution_demo56();
	ListNode *res = NULL;
	res = s1->sortList(&l1);
	while(res)
	{
		cout<<res->val<<"->";
		res = res->next;
	}
	cout<<endl;
	system("pause");
	return 0;
}