/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};
int count(struct node *p)
{
	if (p == NULL)
		return(0);
	else
		if (p->left == NULL && p->right == NULL)
			return(1);
		else
			return(1 + (count(p->left) + count(p->right)));
}
int arr(struct node *root,int i,int array[],int n)
{
	
	if (root == NULL)
		return i;


	array[i] = root->data;
	i++;
	if (root->left != NULL)
		arr(root->left, i,array,n);
	if (root->right != NULL)
		arr(root->right, i, array,n);


	array[i] = root->data;
	i++;
}
struct node *newNode2(int data);

struct node* sortedArrayToBST1(int arr[], int start, int end)
{
	if (start > end)
		return NULL;

	
	int mid = (start + end) / 2;
	struct node *root = newNode2(arr[mid]);

	
	root->left = sortedArrayToBST1(arr, start, mid - 1);

	
	root->right = sortedArrayToBST1(arr, mid + 1, end);

	return root;
}


struct node *newNode2(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}
struct node * convert_array_to_bst1(int *arr, int len){
	int start = 0, end = len;
	if (arr == NULL)
		return NULL;
	return sortedArrayToBST1(arr, start, end);
}

void fix_bst(struct node *root){
	int i = 0, temp,j,k;
	int n = count(root);
	int *array = (int*)malloc(sizeof(int)*n);
	arr(root,i,array,n);
	for (k = 0; k < n; k++)
	{
		for (j = k+1; j < n; j++)
		{
			if (array[k]>array[j])
			{

				temp = array[k];
				array[k] = array[j];
				array[j] = temp;
			}
		}
	}
	root =convert_array_to_bst1(array, n);
}



