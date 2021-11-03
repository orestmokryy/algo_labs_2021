#include <iostream>

using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node *CreateNode(int data)
{
	node *newnode = new node;
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

node *InsertIntoTree(node *root, int data)
{

	node *temp = CreateNode(data);
	node *t = new node;
	t = root;

	if (root == NULL)
		root = temp;
	else
	{

		while (t != NULL)
		{
			if (t->data < data)
			{
				if (t->right == NULL)
				{

					t->right = temp;
					break;
				}

				t = t->right;
			}

			else if (t->data > data)
			{
				if (t->left == NULL)
				{

					t->left = temp;
					break;
				}

				t = t->left;
			}
		}
	}
	return root;
}

void Search(node *root)
{
	int data;
	cout << "\nEnter the Element to be searched: ";
	cin >> data;
	int depth = 0;
	node *temp = new node;
	temp = root;

	while (temp != NULL)
	{
		depth++;
		if (temp->data == data)
		{
			cout << "\nData found at depth: " << depth;
			return;
		}

		else if (temp->data > data)
			temp = temp->left;

		else
			temp = temp->right;
	}

	cout << "\n Data not found";
	return;
}
void inorder(node *rt)
{
	if (rt != NULL)
	{
		inorder(rt->left);
		cout << rt->data << " ";
		inorder(rt->right);
	}
}
node *findMin(node *rt)
{
	node *c = rt;
	while (c && c->left != NULL)
		c = c->left;
	return c;
}
node *DeleteFun(node *rt, int val)
{
	if (rt == NULL)
		return NULL;
	else if (val < rt->data)
		rt->left = DeleteFun(rt->left, val);
	else if (val > rt->data)
		rt->right = DeleteFun(rt->right, val);
	else
	{
		if (rt->left == NULL && rt->right == NULL)
		{
			delete rt;
			rt = NULL;
		}
		else if (rt->left == NULL)
		{
			node *temp = rt->right;
			delete rt;
			rt = temp;
		}
		else if (rt->right == NULL)
		{
			node *temp = rt->left;
			delete rt;
			rt = temp;
		}
		else
		{
			node *temp = findMin(rt->right);
			rt->data = temp->data;
			rt->right = DeleteFun(rt->right, rt->data);
		}
		return rt;
	}
}

int main()
{
	char ch;
	int n, i, a[20] = {89, 53, 95, 1, 9, 67, 72, 66, 75, 77, 18, 24, 35, 90, 38, 41, 49, 81, 27, 97};
	node *root = new node;
	root = NULL;
	for (i = 0; i < 20; i++)
		root = InsertIntoTree(root, a[i]);

	inorder(root);
	Search(root);
	cout << endl
		 << "\nAfter Deletion" << endl;
	DeleteFun(root, 90);
	inorder(root);
	return 0;
}