/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
*/

stack<int>s;
stack<int>ms;

MinStack::MinStack() {
    while(!s.empty()){
        s.pop();
    }
    while(!ms.empty()){
        ms.pop();
    }
}

void MinStack::push(int x) {
    if(ms.empty()||x<=ms.top()){
        ms.push(x);
    }
    s.push(x);
}

void MinStack::pop() {
    if(s.empty()){
        return;
    }
    if(s.top()==ms.top()){
        ms.pop();
    }
    s.pop();
}

int MinStack::top() {
    if(s.empty()){
        return -1;
    }
    return s.top();
}

int MinStack::getMin() {
    if(!ms.empty()){
        return ms.top();
    }
    return -1;
}









