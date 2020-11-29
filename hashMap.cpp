#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define BUCSIZE 5
struct Node {
	char value[10];
	Node * next;
};

Node buf[10000];
Node * bucket[BUCSIZE];
int bufCnt;

Node* myAlloc(char value[10], Node * next) {
	strcpy(buf[bufCnt].value, value);
	buf[bufCnt].next = next;
	return &buf[bufCnt++];
}

int hashFunc(char value[10]) {
	int len = strlen(value);
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum += value[i] * 21 + 7;
	}
	return sum % BUCSIZE;
}

void addNode(char value[10]) {
	int code = hashFunc(value);
	bucket[code] = myAlloc(value, bucket[code]);
}

int main() {
	char values[5][10] = {
		"sdgsdg",
		"sdafha",
		"Sfjsfgj",
		"dfgttr",
		"tktuy"
	};
	for (int i = 0; i < 5; i++) {
		addNode(values[i]);
	}

	return 0;
}