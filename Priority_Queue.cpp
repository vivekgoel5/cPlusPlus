#include <iostream>
#include <vector>
using namespace std;

// Templated Priority Queue using Max Heap
template <typename T>
class PriorityQueue {
private:
	vector<T> heap;

	// Helper to swap elements
	void swap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	// Heapify up to maintain max-heap property
	void heapifyUp(int index) {
		int parent = (index - 1) / 2;
		while (index > 0 && heap[index] > heap[parent]) {
			swap(heap[index], heap[parent]);
			index = parent;
			parent = (index - 1) / 2;
		}
	}

	// Heapify down to maintain max-heap property
	void heapifyDown(int index) {
		int size = heap.size();
		while (true) {
			int left = 2 * index + 1;
			int right = 2 * index + 2;
			int largest = index;

			if (left < size && heap[left] > heap[largest]) {
				largest = left;
			}
			if (right < size && heap[right] > heap[largest]) {
				largest = right;
			}
			if (largest == index) break;

			swap(heap[index], heap[largest]);
			index = largest;
		}
	}

public:
	// Insert element
	void push(const T& value) {
		heap.push_back(value);
		heapifyUp(heap.size() - 1);
	}

	// Remove the maximum element
	void pop() {
		if (heap.empty()) return;
		heap[0] = heap.back();
		heap.pop_back();
		heapifyDown(0);
	}

	// Get the maximum element
	T top() const {
		if (!heap.empty()) {
			return heap[0];
		}
		throw runtime_error("Priority queue is empty");
	}

	// Check if the priority queue is empty
	bool empty() const {
		return heap.empty();
	}

	// Get size of the priority queue
	int size() const {
		return heap.size();
	}
};

int main() {
	PriorityQueue<int> pq;
	pq.push(10);
	pq.push(20);
	pq.push(5);
	pq.push(30);

	cout << "Top element: " << pq.top() << endl;

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;

	return 0;
}
