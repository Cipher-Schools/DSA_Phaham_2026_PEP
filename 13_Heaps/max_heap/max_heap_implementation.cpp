// Last non-leaf node = n/2 - 1
// Call heapify from that index down to 0


void maxHeapify(vector<int>& a, int n, int i){
  int largest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if(left<n && a[left]  >a[largest]){
    largest = left;
  }
  if(right<n && a[right]  >a[largest]){
    largest = right;
  }
  if(largest != i){
    swap(a[largest], a[i]);
    maxHeapify(a, n, largest);
  }
}

void buildMaxHeap(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        maxHeapify(a, n, i);
    }
}