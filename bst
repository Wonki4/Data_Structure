//Binary Search Tree
#include <vector>
using namespace std;

struct Node {
	int value;
	Node * left, *right;
};

Node * root;

void push_bst(int value) {
	Node * cur = root;
	if (root == NULL) {
		root = new Node({ value , NULL,  NULL });
		return;
	}

	while (1) {
		if (value < cur->value) {
			if (cur->left == NULL) {
				cur->left = new Node({ value, NULL, NULL });
				return;
			}
			cur = cur->left;
		}
		else {
			if (cur->right == NULL) {
				cur->right = new Node({ value, NULL, NULL });
				return;
			}
			cur = cur->right;
		}
	}
}



bool pop_bst(int value) {
	Node * cur = root;
	while (1) {
		if (cur == NULL) return false;
		else {
			if (cur->value == value) {
				//remove value;
				if (cur->left == NULL && cur->right == NULL) {
					free(cur);
					return true;
				}
				else if (cur->left == NULL) {
					Node * temp = cur->right;
					cur->value = cur->right->value;
					cur->left = cur->right->left;
					cur->right = cur->right->right;
					free(temp);
					return true;
				}
				else if (cur->right == NULL) {
					Node * temp = cur->left;
					cur->value = cur->left->value;
					cur->right = cur->left->right;
					cur->left = cur->left->left;
					free(temp);
					return true;
				}
				else {
					Node * temp = cur->left;
					Node * lr = cur->left;
					while (lr->right != NULL) {
						lr = lr->right;
					}
					lr->right = cur->right;
					cur->value = lr->value;
					cur->left = lr->left;
					cur->right = lr->right;

					free(temp);
					return true;
				}

			}
			else {
				if (value < cur->value) {
					cur = cur->left;
				}
				else {
					cur = cur->right;
				}
			}
		}
	}
}

int main() {
	push_bst(1235);
	push_bst(3463);
	push_bst(32452);
	push_bst(457);
	push_bst(458734);
	push_bst(456856);
	push_bst(3452);
	push_bst(2457);

	pop_bst(3463);

	return 0;
}

