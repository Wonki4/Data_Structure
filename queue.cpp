#include <malloc.h>

struct Node {
	int value;
	Node * next;
};

Node * head;
Node * last;

void push(int value) {
	if (head == NULL) {
		head = new Node({ value, NULL });
		last = head;
		return;
	}
	last->next = new Node({ value, NULL });
	last = last->next;
}

Node * front() {
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