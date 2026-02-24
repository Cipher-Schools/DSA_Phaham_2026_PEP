class MinHeap {
private:
    vector<int> heap;

    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] > heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int smallest = i;
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i) break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    int top() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

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