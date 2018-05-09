/*
2018年4月24日10:48:53
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set toNULL.
Initially, all next pointers are set toNULL.
Note:
You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,

         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
*/
#include "iostream"
#include <queue>
#include <vector>
using namespace std;


/*
广度优先遍历
*/
struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution_demo08 {
public:
//非递归解法
/*
广度优先遍历利用的queue模型,利用queue的FIFO特点 
同时统计某一层结点的数量，在一个循环当中处理该层的所有结点
*/
    void connect(TreeLinkNode *root) {
        if(root==NULL)
			return;
		queue<TreeLinkNode *>my_queue;
		vector<TreeLinkNode *>my_vector;
		my_queue.push(root);
		while(my_queue.size()>0)
		{
			int count = 0,nextcount = my_queue.size();
			while(count++<nextcount)
			{
				TreeLinkNode *top = my_queue.front();
				my_queue.pop();
				if(top->left!=NULL)
					my_queue.push(top->left);
				if(top->right!=NULL)
					my_queue.push(top->right);
				my_vector.push_back(top);
			}
			if(my_vector.size()<2)
			{
				my_vector.clear();
			}
			else
			{
				for(int i=0;i<my_vector.size()-1;++i)
					my_vector[i]->next = my_vector[i+1];
			}
			my_vector.clear();
		}
    }
//递归解法
	void connect_1(TreeLinkNode *root)
	{
		if(root == NULL)
			return;
		if(root->left!=NULL&&root->right!=NULL)
			root->left->next = root->right;             //兄弟结点
		if(root->next!=NULL&&root->right!=NULL)        //堂兄弟节点 root->next!=NULL表示该结点有堂兄弟结点
			root->right->next = root->next->left;
		connect_1(root->left);
		connect_1(root->right);
	}
};

void main_demo08()
{
	Solution_demo08 s1;
	TreeLinkNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	s1.connect_1(&t1);
	system("pause");
}