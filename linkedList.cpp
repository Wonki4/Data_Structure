#include<malloc.h>
struct Node {
	int value;
	Node * next;
};

Node * head;
Node * last;

void addNode(int value) {
	if (head == NULL) {
		head = new Node({ value, NULL });
		last = head;
		return;
	}
	last->next = new Node({ value, NULL });
	last = last->next;
}

int main() {

	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(5);
	return 0;
}