#include <malloc.h>

struct Node {
	int value;
	Node * next;
};

Node * head;

void push(int value) {
	head = new Node({ value, head });
}

Node * top() {
	return head;
}

void pop() {
	if (head == NULL) return;
	Node * temp = head;
	head = head->next;
	free(temp);
}


int main() {
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	pop();
	return 0;
}