#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int largest = i;
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    // Insert
    void push(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    // Get max
    int top() {
        if (heap.empty()) throw runtime_error("Heap is empty"); // return -1; 
        return heap[0];
    }

    // Delete max
    void pop() {
        if (heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            siftDown(0);
    }

    int size() {
        return heap.size();
    }

    bool empty() {
        return heap.empty();
    }

    // Build heap from array
    void buildHeap(vector<int>& arr) {
        heap = arr;
        for (int i = heap.size()/2 - 1; i >= 0; i--) {
            siftDown(i);
        }
    }

    void print() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};