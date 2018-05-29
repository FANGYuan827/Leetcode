/*
2018年5月24日10:08:30
Given a binary tree containing digits from0-9only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path1->2->3which represents the number123.

Find the total sum of all root-to-leaf numbers.
*/
#include <iostream>
#include <vector>
using namespace std;




 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };



class Solution_demo33 {
public:
    int sumNumbers(TreeNode *root) {
		if(!root)
			return 0;
		vector<vector<int> >res;
		vector<int>tmp;
		FindPath(root,res,tmp);
		int sum=0;
		vector<vector<int> >::iterator it;
		for(it=res.begin();it!=res.end();++it)
		{
			sum+=Sum(*it);
		}
		return sum;
    }
private:
	void FindPath(TreeNode *root,vector<vector<int> >&res,vector<int>&tmp)
	{
		if(root!=NULL&&root->left==NULL&&root->right==NULL)
		{
			tmp.push_back(root->val);
			res.push_back(tmp);
			tmp.pop_back();
			return;
		}
		if(root!=NULL)
		{
			tmp.push_back(root->val);
			FindPath(root->left,res,tmp);
			FindPath(root->right,res,tmp);
			tmp.pop_back();
		}
	}
	int Sum(vector<int>&input)
	{
		vector<int>::iterator it;
		int sum=0;
		for(it=input.begin();it!=input.end();++it)
		{
			sum=sum*10+(*it);
		}
		return sum;
	}
};
int main_demo33(int argc,char **argv)
{
	Solution_demo33 s1;
	TreeNode t1(1),t2(2),t3(3),t4(4),t5(5),t6(6),t7(7),t8(8),t9(9);
	t1.left = &t2;
	t1.right = &t3;
	t2.left = &t4;
	t2.right = &t5;
	t3.left = &t6;
	t3.right = &t7;
	t5.left = &t8;
	t8.right = &t9;
	int res = s1.sumNumbers(&t1);
	cout<<"结果为:"<<res<<endl;
	system("pause");
	return 0;
}