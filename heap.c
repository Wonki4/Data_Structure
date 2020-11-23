#include <iostream>
#include <vector>
using namespace std;

vector<int> heap;

//bool ascend(int a, int b) {
//
//}
//
//bool descend() {
//
//
//}


void push_heap(int value) {
	heap.push_back(value);
	int cur = heap.size() - 1;
	while (cur > 0 && heap[cur] > heap[(cur - 1) / 2]) {
		int temp = heap[cur];
		heap[cur] = heap[(cur - 1) / 2];
		heap[(cur - 1) / 2] = temp;

		cur = (cur - 1) / 2;
	}
}

int pop_heap() {
	int result = heap[0];

	heap[0] = heap.size() - 1;
	int cur = 0;
	int left, right, next;

	while (1) {
		next = cur;
		left = cur * 2 + 1;
		right = cur * 2 + 2;
		if (left >= heap.size()) break;
		if (heap[left] > heap[next]) next = left;
		if (right < heap.size() && heap[right] > heap[next]) next = right;
		if (next == cur) break;
		else {
			int temp = heap[cur];
			heap[cur] = heap[next];
			heap[next] = temp;
			cur = next;
		}
	}
	heap.pop_back();
	return result;
}

int main() {
	push_heap(16);
	push_heap(28);
	push_heap(34567);
	push_heap(3227);
	push_heap(45834563);
	push_heap(457456);
	push_heap(6834568);

	pop_heap();
	pop_heap();
	pop_heap();
	pop_heap();
	pop_heap();
	pop_heap();
	pop_heap();
	return 0;
}
