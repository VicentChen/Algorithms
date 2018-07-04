#include <stdio.h>
#include <stdlib.h>

#define _WINDOWS
#ifdef _WINDOWS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#define AMOUNT 11
#define init_tree(root, rightmost, stack, stack_top)\
	do {\
		root = new_node(num[0]);\
		rightmost = root;\
		stack[stack_top++] = num[0];\
	} while(0)

#define set_left_child(parent_node, child_node)\
	do {\
		parent_node->left = child_node;\
		if (child_node != NULL)\
			child_node->parent = parent_node;\
	} while(0)

#define set_right_child(parent_node, child_node)\
	do {\
		parent_node->right = child_node;\
		if (child_node != NULL)\
			child_node->parent = parent_node;\
	} while(0)

typedef struct Node{
	int val;
	struct Node *left;
	struct Node *right;
	struct Node	*parent;
}node;

typedef struct {
	node *root;
	node *leftmost;
} ctree;

node* new_node(int val) {
	node* tree_node = (node*)malloc(sizeof(node));
	tree_node->val = val;
	tree_node->parent = tree_node->left = tree_node->right = NULL;
	return tree_node;
}

node* build_cartsian_tree(const int* num) {
	int stack[AMOUNT];
	int stack_top = 0;
	node *root, *rightmost;
	init_tree(root, rightmost, stack, stack_top);
	
	for (int i = 1; i < AMOUNT; i++) {
		node* tree_node = new_node(num[i]);
		node* curr_node = rightmost;
		while (true) {
			/* no smaller value */
			if (curr_node == NULL) {
				set_left_child(tree_node, root);
				root = tree_node;
				rightmost = root;
				break;
			}

			/* has smaller value */
			if (curr_node->val < tree_node->val) {
				set_left_child(tree_node, curr_node->right);
				set_right_child(curr_node, tree_node);
				rightmost = tree_node;
				break;
			}

			/* move upward the tree */
			curr_node = curr_node->parent;
		}
	}
	return root;
}

/* not precise travel ways except inorder */

void preorder_travel(const node* root) {
	if (root == NULL) return;
	printf("%d ", root->val);
	preorder_travel(root->left);
	preorder_travel(root->right);
}

void inorder_travel(const node* root) {
	if (root == NULL) return;
	inorder_travel(root->left);
	printf("%d ", root->val);
	inorder_travel(root->right);
}

void postorder_travel(const node* root) {
	if (root == NULL) return;
	postorder_travel(root->left);
	postorder_travel(root->right);
	printf("%d ", root->val);
}

void free_tree(node* root) {
	// \TODO 
	if (root == NULL) return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

int main(int argc, char* argv[]) {
	/* memory leak detect */
#ifdef _WINDOWS
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	/**
	 *         1
	 *        / \
	 *       /   \
	 *      /     \
	 *     3       5
	 *    / \     /
	 *   9   7   8
	 *            \
	 *            10
	 *           /  \
	 *          12  15
	 *             /  \
	 *            20  18
	 */
	int num[AMOUNT] = { 9, 3, 7, 1, 8, 12, 10, 20, 15, 18, 5 };
	node* root = build_cartsian_tree(num);
	preorder_travel(root); printf("\n");
	inorder_travel(root); printf("\n");
	postorder_travel(root); printf("\n");
	free_tree(root);
}
