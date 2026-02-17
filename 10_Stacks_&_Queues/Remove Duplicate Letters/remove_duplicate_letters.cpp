class Solution {
public:
        // TC - O(n)
        // SC - O(n)
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string res; // as monotonic stack
        vector<int>lastIndex(26, 0);
        vector<bool>seen(26, false);

        // push all last indexes of chars
        for(int i=0;i<n;i++){
            lastIndex[s[i]-'a'] = i;
        }

        // now store in lexicographical order, pop greater ones if they appear in later time also and mark them as not seen
        for(int i=0;i<n;i++){
            // char currCh = s[i] - 'a';
            int lastIdx = lastIndex[s[i]-'a'];

            if(seen[s[i]-'a']) continue; //if already pushed do not push again
            // pop those which are pushed already and greater than current one and will appear later
            while(res.size()>0 && res.back()>s[i] && lastIndex[res.back()-'a']>i){
                seen[res.back()-'a'] = false;
                res.pop_back();
            }
            res.push_back(s[i]);
            seen[s[i]-'a'] = true;
        }
        return res;
    }
};

// example - bcab