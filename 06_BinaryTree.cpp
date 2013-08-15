#include <iostream>
#include <queue>

using namespace std;


struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};

BinaryTreeNode *ConstructCore(int *startPreorder, int *endPreorder,
							  int *startInorder, int *endInorder)
{
	BinaryTreeNode *root = new BinaryTreeNode;
	root->value = startPreorder[0];

	// 在中序遍历中找到根节点的值
	int *rootInorder = startInorder;
	while (rootInorder <= endInorder && *rootInorder != root->value)
	{
		++rootInorder;
	}
	if (rootInorder == endInorder && *rootInorder != root->value)
	{
		throw std::exception("Invalid Input.");
	}

	int leftLength = rootInorder - startInorder;
	int *leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		root->left = ConstructCore(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
	}
	else
	{
		root->left = NULL;
	}

	if (rootInorder != endInorder)
	{
		root->right = ConstructCore(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
	}
	else 
	{
		root->right = NULL;
	}

	return root;
}


BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
	if (preorder == NULL || inorder == NULL || length <= 0)
	{
		return NULL;
	}

	return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}


void LevelOrder(BinaryTreeNode *root)
{
	queue<BinaryTreeNode *> nodeQueue;
	nodeQueue.push(root);
	BinaryTreeNode *p = NULL;
	while (!nodeQueue.empty())
	{
		p = nodeQueue.front();
		nodeQueue.pop();

		cout << p->value << "\t";
		if (p->left)
		{
			nodeQueue.push(p->left);
		}
		if (p->right)
		{
			nodeQueue.push(p->right);
		}

		
	}
}
int main()
{
	int preorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int inorder[] = {4, 7, 2, 1, 5, 3, 8, 6};

	BinaryTreeNode *root = Construct(preorder, inorder, 8);
	LevelOrder(root);

	system("pause");
	return 0;
}