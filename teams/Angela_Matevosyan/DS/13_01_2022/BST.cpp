#include <iostream>
#include <queue>

class BST {
private:
	int data;
	BST* left;
	BST* right;
public:
	BST() {
		data = 0;
		left = NULL;
		right = NULL;
	}
	
	BST(int value) {
		data = value;
		left = NULL;
		right = NULL;
	}

	BST* insert(BST* root, int value) {
		if (!root) {
			return new BST(value);
		}

		if (value > root->data) {
			root->right = insert(root->right, value);
		}
		else {
			root->left = insert(root->left, value);
		}
		return root;
	}

	BST* deleteNode(BST* root, int data) {
		if (root == NULL) {
			return root;
		}
		if (data < root->data) {
			root->left = deleteNode(root->left, data);
		}
		else if (data > root->data) {
			root->right = deleteNode(root->right, data);
		}
		else {
			if (root->left == NULL && root->right == NULL) {
				return NULL;
			}
			else if (root->left == NULL) {
				BST* temp = root->right;
				free(root);
				return temp;
			}
			else if (root->right == NULL) {
				BST* temp = root->left;
				free(root);
				return temp;
			}
		}
		return root;
	}
	

	void print(BST* root) {
		if (root == NULL) {
			return;
		}
		std::queue<BST*> q;
		q.push(root);
		
		while(q.empty() == false) {
			BST* node = q.front();
			std::cout << node->data << " ";
			q.pop();

			if (node->left != NULL) {
				q.push(node->left);
			}
			if (node->right != NULL) {
				q.push(node->right);
			}
		}
	}
};

int main() {
	BST t;
	BST* root = NULL;
	root = t.insert(root, 10);
	t.insert(root, 20);
	t.insert(root, 30);
	t.deleteNode(root, 30);
	std::cout << "Level order traversal of binary tree is: ";
	t.print(root);
	std::cout << std::endl;
	return 0;
}
