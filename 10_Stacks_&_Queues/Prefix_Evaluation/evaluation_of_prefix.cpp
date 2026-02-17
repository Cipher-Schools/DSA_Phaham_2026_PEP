class Solution {
  public:
    bool operators(char c){
        return (c=='+' || c=='-'|| c=='*'|| c=='/'|| c=='^');
    }
    int evaluatePrefix(vector<string>& arr) {
        // code here
        int n = arr.size();
        stack<double>st;
        for(int i=n-1;i>=0;i--){
            // if(isdigit(arr[i][0])){
            if(arr[i].length() > 1 || isdigit(arr[i][0])){
                st.push(stoi(arr[i]));
            }
            else{
                double op1 = st.top(); st.pop();
                double op2 = st.top(); st.pop();
                    
                switch(arr[i][0]){
                    case '+': st.push(op1 + op2);break;
                    case '-': st.push(op1 - op2);break;
                    case '*': st.push(op1 * op2);break;
                    case '/': st.push(floor(op1 / op2));break;
                    case '^': st.push(pow(op1, op2));break;
                }
            }
        }
        return st.top();
    }
};
/*
#include <iostream>
#include <stack>
using namespace std;

int apply(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

int evaluatePrefix(string exp) {
    stack<int> st;

    for (int i = exp.length() - 1; i >= 0; i--) {
        char c = exp[i];

        if (isdigit(c)) {
            st.push(c - '0');
        } else {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            st.push(apply(a, b, c));
        }
    }
    return st.top();
}

int main() {
    string exp = "-+7*45+20";
    cout << evaluatePrefix(exp);
}
*/