//Build BST from Inorder and Preorder

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
int search(int inorder[], int start, int end, int curr)  
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
Node *buildtree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);
    node->left = buildtree(preorder, inorder, start, pos - 1);
    node->right = buildtree(preorder, inorder, pos + 1, end);

    return node;
}
void inorderprint(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}
int main()
{
    int n;
    cout << "Enter the Number of elements of the Tree " << endl;
    cin >> n;
    int preorder[n];
    cout << "Enter preorder elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }
    int inorder[n];
    cout << "Enter inorder elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    
    Node *root = buildtree(preorder, inorder, 0, n - 1);
    cout << "The inorder tree is :" << endl;
    inorderprint(root);
    return 0;
}