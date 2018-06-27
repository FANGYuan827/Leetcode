/*
2018年6月2日14:35:14
*/
#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

//网友的解题思路，递归。。。简直不要太6啊
class Solution_demo49 {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(!head)
			return NULL;
		if(!head||head->next==NULL)
			return head;
		if(head->val!=head->next->val)
		{
			head->next = deleteDuplicates(head->next);
			return head;
		}
		else
		{
			int tmp = head->val;
			while(head->val==tmp)
			{
				head = head->next;
				if(!head)
					return NULL;
			}
			return deleteDuplicates(head);
		}
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

int main_demo49(int argc,char **argv)
{
	Solution_demo49 s1;
	ListNode l1(1),l2(1),l3(1),l4(6),l5(6),l6(7),l7(8),l8(8),l9(9);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	Print_list(&l1);
	ListNode *res = s1.deleteDuplicates(&l1);
	Print_list(res);
	system("pause");
	return 0;
}

/*

void func(int *a)
{
	*a = 20;
	cout<<"a adress:"<<a<<":"<<*a<<endl;
}

int main(void)
{
	int a = 10;
	cout<<"a adress:"<<&a<<":"<<a<<endl;
	func(&a);
	cout<<"a adress:"<<&a<<":"<<a<<endl;
	system("pause");
	return 0; 
}

*/