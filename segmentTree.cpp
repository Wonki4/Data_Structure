#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#define MAXV 987654321
using namespace std;

struct RMQ {

	vector<int> segTree;
	int n;

	RMQ(const vector<int> &array) {
		n = array.size();
		segTree.resize(4 * n);
		init(array, 0, n - 1, 1);
	}
	int init(const vector<int> &array, int left, int right, int node) {
		if (left == right) {
			segTree[node] = array[left];
			return segTree[node];
		}
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node * 2);
		int rightMin = init(array, mid + 1, right, node * 2 + 1);
		return segTree[node] = leftMin < rightMin ? leftMin : rightMin;
	}
	int query(int left, int right, int node, int nodeLeft, int nodeRight) {
		if (right < nodeLeft || left > nodeRight) return MAXV;
		if (left <= nodeLeft && nodeRight <= right) return segTree[node];
		int mid = (nodeLeft + nodeRight) / 2;
		return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
	}
	int query(int left, int right) {
		return query(left, right, 1, 0, n - 1);
	}

	int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
		if (index < nodeLeft || index > nodeRight) return segTree[node];
		if (nodeLeft == nodeRight) return segTree[node] = newValue;
		int mid = (nodeLeft + nodeRight) / 2;
		return segTree[node] = min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
	}
	int update(int index, int newValue) {
		return update(index, newValue, 1, 0, n - 1);
	}
};


int main() {

	vector<int> myArray;
	for (int i = 0; i < 20; i++) {
		myArray.push_back(rand());
	}
	RMQ * seg = new RMQ(myArray);
	cout << seg->query(0, myArray.size() - 1) << endl;



	return 0;
}
