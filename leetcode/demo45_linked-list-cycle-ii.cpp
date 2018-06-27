/*
2018年6月1日14:47:12

*/
#include <iostream>
using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};


/*
解题思路：
1、首先求出环中的结点数
   定义两个链表指针，同时指向链表的头节点 慢指针一个循环移动一次，快指针一个循环移动两次，并统计循环次数 
   当快慢指针指向同一个节点时（两个指针值相同）此时将循环次数返回（即为链表环中的结点数）
2、得到环中结点数之后，如果是0 表明链表中没有环
   如果>0，表明有环结构 定义一个指针，从头出发先走count步 然后和另一个指针（从头开始）一起走，当两者指向相同时 此时即为环的入口地址
*/
class Solution_demo45 {
public:
    ListNode *detectCycle(ListNode *head) {
		if(!head)
			return NULL;
		ListNode *res = NULL;
		int LoopNode = CountLoopNode(head);
		ListNode *tmp1 = head,*tmp2 = head;
		if(LoopNode==0)     //这个直接就可以看出来没有环了 那么就直接返回NULL
			return NULL;
		while(LoopNode>0)
		{
			--LoopNode;
			tmp1 = tmp1->next;
		}
		while(tmp1!=tmp2)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			if(tmp1==NULL||tmp2==NULL)
				return NULL;
		}
        return tmp2;
    }
private:
	int CountLoopNode(ListNode *head)
	{
		if(!head)
			return 0;
		int count = 0;
		ListNode *tmp1 = head;
		ListNode *tmp2 = head;
		while(1)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			if(tmp1==NULL||tmp2==NULL)
				return 0;
			tmp2 = tmp2->next;
			if(tmp2==NULL||tmp1==NULL)
				return 0;
			if(tmp1==tmp2)
				break;
		}
		tmp1 = tmp1->next;
		++count;
		while(tmp1!=tmp2)
		{
			tmp1 = tmp1->next;
			++count;
		}
		return count;
	}
};

int main_demo45(int argc,char **argv)
{
	Solution_demo45 s1;
	ListNode l1(10),l2(2),l3(4),l4(11),l5(3),l6(88),l7(30);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l3;
	ListNode *res = s1.detectCycle(&l1);
	if(res)
		cout<<"链表环的入口地址为:"<<res<<"->"<<"val:"<<res->val<<endl;
	else
		cout<<"链表中没有环"<<endl;
	system("pause");
	return 0;
}