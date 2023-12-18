#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int key;
    Node *left;
    Node *right;
    int height;
};
int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;  //65
}
Node* newNode(int key)
{
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1; //  initially height is fixed to 1...height is diff than height/depth
    return(node);     // re6turn 20
}

Node *rightRotate(Node *y)// datatype Node ptr.....for ll
{
    Node *x = y->left;//x,y?
    y->left = x->right;
    x->right = y;
    y->height = max(height(y->left),height(y->right)) + 1;
    x->height = max(height(x->left),height(x->right)) + 1;
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = max(height(x->left),height(x->right)) + 1;
    y->height = max(height(y->left),height(y->right)) + 1;
    return y;
}

int Balancefac(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;
    node->height = 1 + max(height(node->left),//node?     head initially
                        height(node->right));

    int balance = Balancefac(node);

    // Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
void preorder(Node *root)
{
    if(root != NULL)
    {


        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(Node *root)
{
    if(root != NULL)
    {

        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}
int main()
{
	//    root = insert(root, 10);
	//    root = insert(root, 20);
	//    root = insert(root, 30);
	//    root = insert(root, 40);
	//    root = insert(root, 50);
	//    root = insert(root, 25);
	Node *root = NULL;
	while(true)
	{
		cout<<"<-------------------------------------->"<<endl;
		cout<<"Enter 1 to insert node"<<endl;
		cout<<"Enter 2 to display inorder and preorder"<<endl;
		cout<<"Enter 3 to exit"<<endl;
		cout<<"<-------------------------------------->"<<endl;
		int code;cin>>code;
		if(code==1){
			cout<<"Enter the value to be inserted: ";int x;cin>>x;
			root=insert(root,x);
		}
		else if(code==2){
			 cout<<endl;
			cout<<"Preorder Dsiplay: ";
				  preorder(root);
				  cout<<endl;
				  cout<<"Inorder Display: ";inorder(root);
				  cout<<endl;
			}
			else{
				cout<<"EXITING "<<endl;
				break;
			}
	}
    return 0;
}


//
//    preorder(root);
