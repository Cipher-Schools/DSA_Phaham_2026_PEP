// Last non-leaf node = n/2 - 1
// Call heapify from that index down to 0

void minHeapify(vector<int>& a, int n, int i){
  int smallest = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if(left<n && a[left]  <a[smallest]){
    smallest = left;
  }
  if(right<n && a[right]  <a[smallest]){
    smallest = right;
  }
  if(smallest != i){
    swap(a[smallest], a[i]);
    minHeapify(a, n, smallest);
  }
}

void buildMinHeap(vector<int>& a) {
    int n = a.size();
    for (int i = n/2 - 1; i >= 0; i--) {
        minHeapify(a, n, i);
    }
}