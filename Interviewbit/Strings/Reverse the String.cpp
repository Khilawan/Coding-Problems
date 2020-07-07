/*
Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.



Input Format

The only argument given is string A.

Output Format

Return the string A after reversing the string word by word.

For Example

Input 1:
    A = "the sky is blue"

Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
    
Output 2:
    "ib is this"
*/

string Solution::solve(string A) {
    stack<string>s;
    string str="";
    int flag=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==' '&&flag){
            s.push(str);
            str.clear();
            flag=0;
        }else if(A[i]!=' '){
            flag=1;
            str+=A[i];
        }
    }
    if(str.size()!=0){
        s.push(str);
    }
    string res="";
    while(!s.empty()){
        string ss=s.top();
        res.append(ss);
        s.pop();
        if(s.empty()){
            break;
        }
        res+=' ';
    }
    return res;
}
