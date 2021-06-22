#include<iostream>

using namespace std;

template <typename T>

class maxBinaryHeap {
private:
	int N,n;
	T *arr;
public:
	maxBinaryHeap(int n) {
		N = 1;
		this->n = n+1;
		arr = new T[n + 1];
	}

	void printArr() {
		for (int i = 0;i < n;i++) {
			cout << arr[i] << ",";
		}
		cout << "\n";
	}

	void insert(T val) {
		if (N <= n) {
			arr[N] = val;
			swim(N);
			N++;
		}
	}

	bool isEmpty() {
		return N == 0;
	}

	T delMax() {
		if (isEmpty()) { return NULL; }
		T max = arr[1];
		swap(arr[1], arr[--N]);
		arr[N] = NULL;
		sink(1);
		return max;
	}

	void swim(int valindex) {
		int k = valindex;
		while (k/2>0) {
			if (arr[k / 2] < arr[k]) { swap(arr[k / 2], arr[k]);k = k / 2; }
			else { break; }
		}
	}

	void sink(int valIndex) {
		int k = valIndex;
		while (k*2<=N) {
			int j = 2 * k;
			if (j < N && arr[2 * k] < arr[2 * k + 1]) {
				j++;
			}
			if (arr[k] > arr[j]) { break; }
			swap(arr[k], arr[j]);
			k = j;
		}
	}

	~maxBinaryHeap() {
		delete[] arr;
	}
};

class test {
public:
	test() {
		cout << "cons" << "\n";
	}
};

int main() {
	maxBinaryHeap <int>mbh(7);
	mbh.insert(2);
	mbh.insert(3);
	mbh.insert(1);
	mbh.insert(5);
	mbh.insert(-1);
	mbh.insert(10);

	cout << mbh.delMax() << "\n";
	cout << mbh.delMax() << "\n";
	cout << mbh.delMax() << "\n";
	cout << mbh.delMax() << "\n";

}