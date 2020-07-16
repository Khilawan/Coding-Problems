/*
Given a string A denoting an expression. It contains the following operators ’+’, ‘-‘, ‘*’, ‘/’.

Chech whether A has redundant braces or not.

Return 1 if A has redundant braces, else return 0.

Note: A will be always a valid expression.



Input Format

The only argument given is string A.

Output Format

Return 1 if string has redundant braces, else return 0.


For Example

Input 1:
    A = "((a + b))"

Output 1:
    1

    Explanation 1:
        ((a + b)) has redundant braces so answer will be 1.

Input 2:
    A = "(a + (a + b))"

Output 2:
    0
    
    Explanation 2:
        (a + (a + b)) doesn't have have any redundant braces so answer will be 0.

*/


int Solution::braces(string A) {
    stack<char>ch;
    int n=A.size();
    int flag=0;
    
    for(int i=0;i<n;i++){
        if(A[i]=='('){
            ch.push(A[i]);
            flag=0;
        }else if(A[i]==')'){
            if(ch.top()=='('){
                return 1;
            }
            while(!ch.empty()&&ch.top()!='('){
                if(ch.top()=='+'||ch.top()=='-'||ch.top()=='*'||ch.top()=='/'){
                    flag=1;
                }
                ch.pop();
            }
            if(ch.empty()||flag==0){
                return 1;
            }
            ch.pop();
        }else{
            ch.push(A[i]);
        }
    }
    
    return 0;
}
