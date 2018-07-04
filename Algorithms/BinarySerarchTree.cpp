#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define _WINDOWS
#ifdef _WINDOWS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

typedef struct tree_node{
    int val;
    struct tree_node* left;
    struct tree_node* right;
} bst_node;

bst_node* insert(bst_node* root, int val);
bst_node* search(bst_node* root, int val);
bst_node* remove(bst_node* root, int val);
bst_node* construct(int *vals, int count);
void free_tree(bst_node* root);
void preorder_travel(bst_node* root);
void inorder_travel(bst_node* root);
void postorder_travel(bst_node* root);

int main(int argc, char* argv[]) {
    /* memory leak detect */
#ifdef _WINDOWS
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    const int count = 10;
    int num[count] = { 3,7,9,4,2,7,0,1,5,9 };
    /**
     *            3
     *          /   \
     *         2     7
     *        /    /   \
     *       0    4     9
     *        \    \   /
     *         1    7 9
     *             /
     *            5
     */
    printf("----Construct test-----\n");
    bst_node *root = construct(num, count);
    preorder_travel(root); putchar('\n');
    inorder_travel(root); putchar('\n');
    postorder_travel(root); putchar('\n');

    printf("------Search test------\n");
    bst_node *result;
    if (result = search(root, 10))
        printf("find %d\n", result->val);
    else
        printf("not find\n");
    if (result = search(root, 9))
        printf("find %d\n", result->val);
    else
        printf("not find\n");

    /**
    *            3
    *          /   \
    *         2     7
    *        /    /   \
    *       0    4     9
    *        \    \   / \
    *         1    7 9  11
    *             /
    *            5
    */
    printf("------Insert test------\n");
    root = insert(root, 11);
    if (result = search(root, 11))
        printf("find %d\n", result->val);
    else
        printf("not find\n");
    preorder_travel(root); putchar('\n');
    inorder_travel(root); putchar('\n');
    postorder_travel(root); putchar('\n');

    /**
    *            3
    *          /   \
    *         2     7
    *        /     / \
    *       0     5   9
    *        \   /   / \
    *         1 4   9  11
    *            
    */
    printf("------Remove test------\n");
    root = remove(root, 7);
    preorder_travel(root); putchar('\n');
    inorder_travel(root); putchar('\n');
    postorder_travel(root); putchar('\n');
    free_tree(root);
}

bst_node* insert(bst_node* root, int val) {
    if (root == NULL) {
        bst_node *node = (bst_node*)malloc(sizeof(bst_node));
        node->val = val;
        node->left = node->right = NULL;
        return node;
    }
    if (root->val < val) root->right = insert(root->right, val);
    if (root->val >= val) root->left = insert(root->left, val);
    return root;
}

bst_node* search(bst_node* root, int val) {
    if (root == NULL) return NULL;
    if (root->val < val) return search(root->right, val);
    if (root->val > val) return search(root->left, val);
    return root;
}

bst_node* remove(bst_node* root, int val) {
    if (root == NULL) return NULL;
    if (root->val < val) root->right = remove(root->right, val);
    if (root->val > val ) root->left = remove(root->left, val);
    if (root->val != val) return root;
    bst_node *new_root, *rightmost, *leftmost, *new_root_parent;
    if (root->left == NULL) return root->right;
    for (new_root = root->left; new_root->right != NULL; new_root = new_root->right)
        new_root_parent = new_root;
    new_root_parent->right = NULL;
    for (rightmost = new_root; rightmost->right != NULL; rightmost = rightmost->right);
    for (leftmost = new_root; leftmost->left != NULL; leftmost = leftmost->left);
    leftmost->left = root->left;
    rightmost->right = root->right;
    printf("remove: %d\n", root->val);
    free(root);
    return new_root;
}

bst_node* construct(int* vals, int count) {
    bst_node *root = NULL;
    for (int i = 0; i < count; i++)
        root = insert(root, vals[i]);
    return root;
}

void free_tree(bst_node* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

void preorder_travel(bst_node* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder_travel(root->left);
    preorder_travel(root->right);
}

void inorder_travel(bst_node* root) {
    if (root == NULL) return;
    inorder_travel(root->left);
    printf("%d ", root->val);
    inorder_travel(root->right);
}

void postorder_travel(bst_node* root) {
    if (root == NULL) return;
    postorder_travel(root->left);
    postorder_travel(root->right);
    printf("%d ", root->val);
}
