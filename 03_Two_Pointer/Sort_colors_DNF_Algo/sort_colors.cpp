// LeetCode Problem 75 - https://leetcode.com/problems/sort-colors/description/

/* DNF Algo - 

The Dutch National Flag algorithm, also known as 3-way partitioning, is an algorithm for sorting an array containing three 
distinct values. The algorithm was designed to solve the problem of sorting an array containing only 0s, 1s, and 2s, 
which is similar to the problem in the given question.

The algorithm works by maintaining three pointers: low, mid, and high. The low pointer points to the beginning of the array, 
the high pointer points to the end of the array, and the mid pointer starts at the beginning of the array and moves through it.

The idea behind the algorithm is to keep all the 0s before the low pointer, all the 2s after the high pointer, 
and all the 1s between the low and high pointers. The algorithm moves the mid pointer through the array, 
comparing the value at each position with 1. If the value is 0, the element is swapped with the element at the low pointer, 
and the low and mid pointers are incremented. If the value is 2, the element is swapped with the element at the high pointer, 
and the high pointer is decremented. If the value is 1, the mid pointer is simply incremented.

The algorithm terminates when the mid pointer crosses the high pointer, indicating that all the elements have been processed 
and the array is sorted.

The Dutch National Flag algorithm is called one-pass because it sorts the array in a single pass through the elements. 
The time complexity of the algorithm is O(n), where n is the size of the array.

*/
// Approach - 1 | 3-Pointer | DNF (Dutch National Flag Algo) | TC - O(n) , SC - O(1)
void sortColors(vector<int> &nums)
{
  int n = nums.size();
  int start = 0, mid = 0, end = n - 1;
  while (mid <= end)
  {
    if (nums[mid] == 0)
    {
      swap(nums[start], nums[mid]);
      start++;
      mid++;
    }
    else if (nums[mid] == 2)
    {
      swap(nums[mid], nums[end]);
      end--;
    }
    else
    {
      mid++;
    }
  }
}

// Approach - 2 | Counting Sort | Counting 0s, 1s and 2s | TC - O(n), SC - O(1)
void sortColors(vector<int> &nums)
{
  int n = nums.size();
  int count0 = 0, count1 = 0, count2 = 0;

  vector<int> result;
  for (int i = 0; i < n; i++)
  {
    if (nums[i] == 0)
    {
      count0++;
    }
    if (nums[i] == 1)
    {
      count1++;
    }
    if (nums[i] == 2)
    {
      count2++;
    }
  }
  for (int i = 0; i < count0; i++)
  {
    result.push_back(0);
  }
  for (int i = count0; i < count0 + count1; i++)
  {
    if (count1 != 0)
    {
      result.push_back(1);
    }
  }
  for (int i = count1; i < count1 + count2; i++)
  {
    if (count2 != 0)
    {
      result.push_back(2);
    }
  }
  for (int i = 0; i < n; i++)
  {
    nums[i] = result[i];
  }
}

// OR
void sortColors(int A[], int n) {
    int num0 = 0, num1 = 0, num2 = 0;
    
    for(int i = 0; i < n; i++) {
        if (A[i] == 0) ++num0;
        else if (A[i] == 1) ++num1;
        else if (A[i] == 2) ++num2;
    }
    
    for(int i = 0; i < num0; ++i) A[i] = 0;
    for(int i = 0; i < num1; ++i) A[num0+i] = 1;
    for(int i = 0; i < num2; ++i) A[num0+num1+i] = 2;
}
