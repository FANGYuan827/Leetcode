/*
2018年6月27日14:48:55
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
数组可以通过index直接访问任意一个元素

解题思路：
通过快、慢指针来找到链表的中间结点 
找到中间结点之后 要以中间结点的值建立一个树的根结点 然后需要将原链表断开，分为前后两个链表 都不能包含原中间结点 
然后在分别对这两个链表递归调用原函数，分别连上左右子结点即可
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
		if(!(head->next))     //如果是叶子结点
		{
			TreeNode *leaf = new TreeNode(head->val);
			return leaf;
		}
		ListNode *slow = head,*fast = head;
		ListNode *before_s = head;
		ListNode *after_s = head;
		/*
		while(fast->next&&fast->next->next) //这个判断条件(fast->next&&fast->next->next)
		{									//与下面的(fast&&fast->next)得到的二叉树在链表结点为奇数情况下是一样的，偶数情况下跟结点会有不同
			before_s = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		*/
		while(fast&&fast->next)      //利用快慢指针找到链表的中间结点
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

	//简洁版 来自网上大神
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
	cout<<"所建树的中序遍历序列为:"<<endl;
	//MorrisInorder(res);
	Inord(res);
	cout<<endl;
	system("pause");
	return 0;
}