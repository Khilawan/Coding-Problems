/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.



Input Format

The only argument given is character array A.


Output Format

Return the value of arithmetic expression formed using reverse Polish Notation.

For Example

Input 1:
    A =   ["2", "1", "+", "3", "*"]
    
Output 1:
    9

*/


int Solution::evalRPN(vector<string> &A) {
    stack<int>s;
    int n=A.size();

    for(int i=0;i<n;i++){
        char ch=A[i][0];
        if(A[i].size()==1&&(ch=='+'||ch=='-'||ch=='*'||ch=='/')){
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            if(ch=='+'){
                s.push(a+b);
            }else if(ch=='-'){
                s.push(b-a);
            }else if(ch=='*'){
                s.push(a*b);
            }else if(ch=='/'){
                s.push(b/a);
            }
        }else{
            int a=stoi(A[i]);
            s.push(a);
        }
        
    }
    
    return s.top();
}
