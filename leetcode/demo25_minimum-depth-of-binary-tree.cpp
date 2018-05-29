/*
2018年5月23日15:55:35
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/
#include <iostream>
#include <stack>
#include <vector>
#include <list>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution_demo25 {
public:
    int run(TreeNode *root) {
		if(root==NULL)
			return 0;
		return Deepth_Min(root);
    }
//非递归方法
	int run_(TreeNode *root);
private:
	int Deepth_Min(TreeNode *root)
	{
		if(root==NULL)
			return 0;
		return (Deepth_Min(root->left)>Deepth_Min(root->right)?Deepth_Min(root->right):Deepth_Min(root->right))+1;
	}
};
int Solution_demo25::run_(TreeNode *root)
{
	if(!root)
		return 0;
	stack<TreeNode *>tmp;
	vector<int>v;
	list<TreeNode *>l;
	l.push_back(root);
	int deepth = 0,count = 0,nextcount = 1;
	while(l.size()!=0)
	{
		TreeNode *top = l.front();
		l.pop_front();
		++count;
		if(top->left!=NULL)
		{
			l.push_back(top->left);
		}
		if(top->right!=NULL)
		{
			l.push_back(top->right);
		}
		if(count==nextcount)
		{
			nextcount = l.size();
			count=0;
			++deepth;
			list<TreeNode *>::iterator it;
			for(it=l.begin();it!=l.end();++it)
			{
				if(((*it)->left==NULL)&&((*it)->right==NULL))
					return deepth+1;     //不加+1 会报错 会漏算一个，因为将一层的结点入链表之后，判断到有叶子结点 那么就退出 这一层就会漏算了
			}
		}
	}
	return deepth;	
}


int main_demo25(int argc,char **argv)
{
	Solution_demo25 s1;
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8),t9(9);
	//t1.left = &t2;
	//t1.right = &t3;
	//t2.left = &t4;
	//t2.right = &t5;
	//t3.left = &t6;
	//t3.right = &t7;
	//t4.left = &t8;
	//t8.right = &t9;
	
	int res = 0;
	res = s1.run_(&t1);
	cout<<"树的最小深度为:"<<res<<endl;
	system("pause");
	return 0;
}