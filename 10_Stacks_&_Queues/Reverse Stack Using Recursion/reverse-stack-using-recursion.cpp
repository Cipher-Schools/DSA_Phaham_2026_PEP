// Iterative using Array
void reverseStack(stack<int> &stack) {
    vector<int>arr;
    while(!stack.empty()){
        arr.push_back(stack.top());
        stack.pop();
    }
    for(int num:arr){
        stack.push(num);
    }
}

// Recursive

void insertAtBottom(stack<int> &stack, int temp){
    if(stack.empty()){
        stack.push(temp);
        return;
    }
    int ele = stack.top();
    stack.pop();
    insertAtBottom(stack, temp);
    stack.push(ele);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty()) return;
    int temp = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, temp);
}