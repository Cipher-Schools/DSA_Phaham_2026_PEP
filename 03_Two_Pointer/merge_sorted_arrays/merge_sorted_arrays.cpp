#include<bits\stdc++.h>
#include<typeinfo>
using namespace std;
int main(){
    int arr1[5]={2,5,7,8,10};
    int arr2[5]={1,4,6,9,11};
    int arr3[10];
    int i=0; int j=0; int k=0;
    while(i<5 and j<5){
        if(arr1[i]<=arr2[j]){
            arr3[k]=arr1[i];
            i++;
            k++;
        }
        else{
            arr3[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<5){
        arr3[k]=arr1[i];
        k++; i++;
    }
    while(j<5){
        arr3[k]=arr2[j];
        k++; j++;
    }

    // traversal
    for(int i=0;i<10;i++) cout<<arr3[i]<< " ";
    return 0;
}

// LeetCode Problem 88 - https://leetcode.com/problems/merge-sorted-array/

// Approach - 1 | Using Extra array | 2-Pointer | TC -  O(m + n), SC - O(m + n)
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	    vector<int>res;
    
        int i = 0, j = 0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        if(i==m){
            while(j<n){
                res.push_back(nums2[j]);
                j++;
            }
        }
        else if(j==n){
            while(i<m){
                res.push_back(nums1[i]);
                i++;
            }
        }
      nums1.resize(m+n,0);
      for(int i=0;i<m+n;i++){
          nums1[i]=res[i];
      }
    }


    // Approach - 2 | In-place | Without Extra Array | TC - O(m + n), SC - O(1)
       void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }

    // Approach - 3 | Using Sort | TC - O(nlog(n)), SC - O(1)
       void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = 0;
        while(i>=0 && j<n){
            if(nums1[i]>nums2[j]){
                swap(nums1[i],nums2[j]);
                i--;
                j++;
            }
            else{
                break;
            }
        }
        sort(nums1.begin(),nums1.end()-n);
        sort(nums2.begin(),nums2.end());
        for(int k = m;k<m+n;k++){
            nums1[k] = nums2[k-m];
        }
    }