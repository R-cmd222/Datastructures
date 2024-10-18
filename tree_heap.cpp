#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        if (index && heap[(index - 1) / 2] < heap[index]) {
            swap(heap[index], heap[(index - 1) / 2]);
            heapifyUp((index - 1) / 2);
        }
    }

    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    void remove() {
        if (heap.size()) {
            heap[0] = heap.back();
            heap.pop_back();
            heapifyDown(0);
        }
    }

    int getMax() {
        return heap.size() ? heap[0] : -1;  // Return -1 if heap is empty
    }

    void printHeap() {
        for (int i : heap)
            cout << i << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(30);
    h.insert(40);
    cout << "Max-Heap array: ";
    h.printHeap();

    cout << "Max element: " << h.getMax() << endl;
    h.remove();
    cout << "Max-Heap array after removing max element: ";
    h.printHeap();

    return 0;
}
