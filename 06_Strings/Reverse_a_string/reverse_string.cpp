// GFG Problem - https://www.geeksforgeeks.org/problems/reverse-a-string/1

// Approach - 1 | Iterative | TC - O(n), SC - O(1)

string reverseString(string& s) {
    string res;
  
  	// Traverse on s in backward direction
  	// and add each charecter to a new string
    for (int i = s.size() - 1; i >= 0; i--) {
        res += s[i];
    }
    return res;
}

// Approach - 2 | Two Pointer | TC - O(n), SC - O(1)

string reverseString(string &s) {
    int left = 0, right = s.length() - 1;

    // Swap characters from both ends till we reach
    // the middle of the string
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
  
    return s;
}

// Approach - 3 | In-built
string reverseString(string &s) {
    reverse(s.begin(), s.end());
  	return s;
}