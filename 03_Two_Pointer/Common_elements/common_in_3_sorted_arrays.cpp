// GFG Problem - https://www.geeksforgeeks.org/problems/common-elements1132/1

// Approach - 1 | 3-pointer | TC - O(max(n1,n2,n3)) = O(n), SC - O(1)
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();
        // Initializing variables i, j, k to track array indices.
        int i = 0, j = 0, k = 0;

        // Initializing vector to store common elements.
        vector<int> res;

        // Initializing variable last to track previous common element.
        int last = INT_MIN;

        // Loop until reach the end of any array.
        while (i < n1 and j < n2 and k < n3) {
            // If current elements in all arrays are equal and not the same as the
            // previous common element.
            if (arr1[i] == arr2[j] and arr1[i] == arr3[k] and arr1[i] != last) {
                // Add common element to the result vector.
                res.push_back(arr1[i]);

                // Update last variable to current common element.
                last = arr1[i];

                // Move to next elements in all arrays.
                i++;
                j++;
                k++;
            }
            // Move to the next smallest element among the three arrays.
            else if (min({arr1[i], arr2[j], arr3[k]}) == arr1[i])
                i++;
            else if (min({arr1[i], arr2[j], arr3[k]}) == arr2[j])
                j++;
            else
                k++;
        }

        // Return the result vector with common elements.
        return res;
    }


  // Approach - 2 | Using HashSet | TC - O(n), SC - O(n)

vector<int> commonElements(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3)
{
    set<int> sc1;
    set<int> sc2;
    vector<int> result;

    // Add all elements of arr1 to sc1
    for (int x : arr1) {
        sc1.insert(x);
    }

    // Check common between arr1 and arr2
    for (int x : arr2) {
        if (sc1.count(x)) {
            sc2.insert(x);
        }
    }

    sc1.clear();

    // Check common between (arr1 ∩ arr2) and arr3
    for (int x : arr3) {
        if (sc2.count(x)) {
            sc1.insert(x);
        }
    }

    // Convert set to vector
    for (int x : sc1) {
        result.push_back(x);
    }

    return result;
}
