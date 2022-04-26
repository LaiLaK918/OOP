#include <iostream>
#include <string>
#include <queue>
#include <fstream>
using namespace std;

#define FILEPATH "G:\\Code\\Text\\BinaryTree.txt"

fstream f;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* getNewNode(int);

Node* Insert(Node*, int);

bool search(Node*, int);

void printTree(Node*);

void print(Node*, string);

int findMinVal(Node*);

int findHeigh(Node*);

int countLeaf(Node*);

int level(Node*);

bool is_AVL_BST(Node*);

Node* to_AVL_BST(Node*);

Node* updateTree(Node*);

bool isSubtreeLesser(Node*, int);

bool isSubtreeGreater(Node*, int);

bool isBinarySearchTree(Node*);

Node* findMin(Node*);

Node* Delete(Node*, int);

Node* Delete_Include_Child(Node*, int);

Node* turnLeft(Node*);

Node* turnRight(Node*);

int count(Node*, int);

int main() {
	Node* root = NULL;
	int numOfNode, data;
	f.open(FILEPATH, ios::in);
	f >> numOfNode;
	for (int i = 0; i < numOfNode; i++) {
		f >> data;
		root = Insert(root, data);
	}
	int x = 3;
	root = Delete_Include_Child(root, x);
	print(root, "In");
}

Node* getNewNode(int data) {
	Node* node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

Node* Insert(Node* root, int data) {
	if (root == NULL) {
		root = getNewNode(data);
		return root;
	}
	else if (data < root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}
	return root;
}

bool search(Node* root, int data) {
	if (root == NULL) return false;
	else if (root->data == data) return true;
	else if (data < root->data) return search(root->left, data);
	else return search(root->right, data);
}

void printTree(Node* root) {
	if (root != NULL) {
		printTree(root->left);
		cout << root->data << " ";
		printTree(root->right);
	}
}

void print(Node* root, string type) {
	if (root != NULL) {
		if (type == "In") {
			print(root->left, type);
			cout << root->data << " ";
			print(root->right, type);
		}
		else if (type == "Pre") {
			cout << root->data << " ";
			print(root->left, type);
			print(root->right, type);
		}
		else if (type == "Pos") {
			print(root->left, type);
			print(root->right, type);
			cout << root->data << " ";
		}
		else if (type == "level") {
			queue<Node*> q;
			q.push(root);
			while (!q.empty()) {
				cout << q.front()->data << " ";
				if (q.front()->left != NULL)  q.push(q.front()->left);
				if (q.front()->right != NULL) q.push(q.front()->right);
				q.pop();
			}
		}
	}
}

int findMinVal(Node* root) {
	if (root == NULL) return INT16_MIN;
	Node* tmp = root;
	while (tmp->left != NULL) {
		tmp = tmp->left;
	}
	return tmp->data;
}

int findHeigh(Node* root) {
	if (root == NULL) return -1;
	return max(findHeigh(root->left), findHeigh(root->right)) + 1;
}

bool isSubtreeLesser(Node* root, int value) {
	if (root == NULL) return true;
	if (root->data < value && isSubtreeLesser(root->left, value) && isSubtreeLesser(root->right, value)) return true;
	return false;
}

bool isSubtreeGreater(Node* root, int value) {
	if (root == NULL) return true;
	if (root->data >= value && isSubtreeGreater(root->left, value) && isSubtreeGreater(root->right, value)) return true;
	return false;
}

bool isBinarySearchTree(Node* root) {
	if (root == NULL) return true;
	if (isSubtreeGreater(root->right, root->data) && isSubtreeLesser(root->left, root->data) && isBinarySearchTree(root->left)
		&& isBinarySearchTree(root->right)) return true;
	return false;
}

Node* findMin(Node* root) {
	if (root->left == NULL) return root;
	return findMin(root->left);
}

Node* Delete(Node* root, int data) {
	if (root == NULL) return root;
	if (data < root->data) root->left = Delete(root->left, data);
	else if (data > root->data) root->right = Delete(root->right, data);
	else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
			return root;
		}
		else if (root->left == NULL) {
			Node* temp = root;
			root = root->right;
			delete temp;
			return root;
		}
		else if (root->right == NULL) {
			Node* temp = root;
			root = root->left;
			delete temp;
			return root;
		}
		else {
			Node* temp = findMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right, temp->data);
		}
	}
	return root;
}

int countLeaf(Node* root) {
	if (root->left == NULL && root->right == NULL) return 1;
	else if (root->right == NULL) return countLeaf(root->left);
	else if (root->left == NULL) return countLeaf(root->right);
	return countLeaf(root->left) + countLeaf(root->right);
}

int level(Node* root) {
	return findHeigh(root);
}

bool is_AVL_BST(Node* root) {
	if (root == NULL) return true;
	if (abs(level(root->left) - level(root->right)) > 1) return false;
	return is_AVL_BST(root->left) && is_AVL_BST(root->right);
}

Node* turnLeft(Node* root) {
	Node* B = root->right;
	Node* C = B->left;
	root->right = C;
	B->left = root;
	return B;
}

Node* turnRight(Node* root) {
	Node* B = root->left;
	Node* C = B->right;
	root->left = C;
	B->right = root;
	return B;
}

Node* updateTree(Node* root) {
	if (!is_AVL_BST(root)) {
		if (level(root->left) > level(root->right)) {
			if (level(root->left->left) >= level(root->left->right)) {
				root = turnRight(root);
			}
			else {
				root->left = turnLeft(root->left);
				root = turnRight(root);
			}
		}
		else {
			if (level(root->right->right) >= level(root->right->left)) {
				root = turnLeft(root);
			}
			else {
				root->right = turnRight(root->right);
				root = turnLeft(root);
			}
		}
	}

	if (root->left != NULL) root->left = to_AVL_BST(root->left);
	if (root->right != NULL) root->right = to_AVL_BST(root->right);
	return root;
}

Node* to_AVL_BST(Node* root) {
	while (!is_AVL_BST(root)) {
		root = updateTree(root);
	}
	return root;
}

int count(Node* root, int data) {
	if (root == NULL) return 0;
	if (root->data == data) return 1 + count(root->left, data) + count(root->right, data);
	else if (data < root->data) return count(root->left, data);
	else return count(root->right, data);
}

Node* Delete_Include_Child(Node* root, int data) {
	if (root == NULL) return root;
	if (data < root->data) root->left = Delete_Include_Child(root->left, data);
	else if (data > root->data) root->right = Delete_Include_Child(root->right, data);
	else {
		delete root;
		root = NULL;
		return root;
	}
	return root;
}
