/*
2018��6��1��14:47:12

*/
#include <iostream>
using namespace std;



struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};


/*
����˼·��
1������������еĽ����
   ������������ָ�룬ͬʱָ�������ͷ�ڵ� ��ָ��һ��ѭ���ƶ�һ�Σ���ָ��һ��ѭ���ƶ����Σ���ͳ��ѭ������ 
   ������ָ��ָ��ͬһ���ڵ�ʱ������ָ��ֵ��ͬ����ʱ��ѭ���������أ���Ϊ�����еĽ������
2���õ����н����֮�������0 ����������û�л�
   ���>0�������л��ṹ ����һ��ָ�룬��ͷ��������count�� Ȼ�����һ��ָ�루��ͷ��ʼ��һ���ߣ�������ָ����ͬʱ ��ʱ��Ϊ������ڵ�ַ
*/
class Solution_demo45 {
public:
    ListNode *detectCycle(ListNode *head) {
		if(!head)
			return NULL;
		ListNode *res = NULL;
		int LoopNode = CountLoopNode(head);
		ListNode *tmp1 = head,*tmp2 = head;
		if(LoopNode==0)     //���ֱ�ӾͿ��Կ�����û�л��� ��ô��ֱ�ӷ���NULL
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
		cout<<"��������ڵ�ַΪ:"<<res<<"->"<<"val:"<<res->val<<endl;
	else
		cout<<"������û�л�"<<endl;
	system("pause");
	return 0;
}