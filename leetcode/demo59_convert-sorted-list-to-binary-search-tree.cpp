/*
2018��6��27��14:48:55
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
#include <iostream>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
�������ͨ��indexֱ�ӷ�������һ��Ԫ��

����˼·��
ͨ���졢��ָ�����ҵ�������м��� 
�ҵ��м���֮�� Ҫ���м����ֵ����һ�����ĸ���� Ȼ����Ҫ��ԭ����Ͽ�����Ϊǰ���������� �����ܰ���ԭ�м��� 
Ȼ���ڷֱ������������ݹ����ԭ�������ֱ����������ӽ�㼴��
*/
class Solution_demo59 {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if(!head)
			return NULL;
		//TreeNode *res = BuildBST(head);
	    //return BuildBST(head);
		return BuildBST(head,NULL);
    }
private:
	TreeNode *BuildBST(ListNode *head)
	{
		if(!head)
			return NULL;
		if(!(head->next))     //�����Ҷ�ӽ��
		{
			TreeNode *leaf = new TreeNode(head->val);
			return leaf;
		}
		ListNode *slow = head,*fast = head;
		ListNode *before_s = head;
		ListNode *after_s = head;
		/*
		while(fast->next&&fast->next->next) //����ж�����(fast->next&&fast->next->next)
		{									//�������(fast&&fast->next)�õ��Ķ�������������Ϊ�����������һ���ģ�ż������¸������в�ͬ
			before_s = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		*/
		while(fast&&fast->next)      //���ÿ���ָ���ҵ�������м���
		{
			before_s = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		after_s = slow->next;
		before_s->next = NULL;
		
		TreeNode *root = new TreeNode(slow->val);
		if(slow!=head)
			root->left = BuildBST(head);    //
		if(after_s)
			root->right = BuildBST(after_s);
		return root;
	}

	//���� �������ϴ���
	TreeNode *BuildBST(ListNode *head,ListNode *tail)
	{
		if(head==tail)
			return NULL;
		ListNode *fast = head;
		ListNode *slow = head;
		while(fast!=tail&&fast->next!=tail)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		TreeNode *root = new TreeNode(slow->val);
		root->left = BuildBST(head,slow);
		root->right = BuildBST(slow->next,tail);
		return root;
	}
};

void MorrisInorder(TreeNode *root)
{
	if(!root)
		return;

}

void Inord(TreeNode *root)
{
	if(!root)
		return;
	if(root)
	{
		Inord(root->left);
		cout<<root->val<<ends;
		Inord(root->right);
	}
}

int main(int argc,char **argv)
{
	ListNode l1(1),l2(2),l3(3),l4(4),l5(5),l6(6),l7(7),l8(88),l9(999);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	l4.next = &l5;
	l5.next = &l6;
	l6.next = &l7;
	l7.next = &l8;
	l8.next = &l9;
	Solution_demo59 s1;
	TreeNode *res = s1.sortedListToBST(&l1);
	cout<<"�������������������Ϊ:"<<endl;
	//MorrisInorder(res);
	Inord(res);
	cout<<endl;
	system("pause");
	return 0;
}