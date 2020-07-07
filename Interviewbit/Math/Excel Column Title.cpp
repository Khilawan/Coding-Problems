/*
Problem Description

Given a positive integer A, return its corresponding column title as appear in an Excel sheet.



Problem Constraints
1 <= A <= 1000000000



Input Format
First and only argument is integer A.



Output Format
Return a string, the answer to the problem.



Example Input
Input 1:

 A = 1
Input 2:

 A = 28


Example Output
Output 1:

 "A"
Output 2:

 "AB"

*/

string Solution::convertToTitle(int A) {
    
    stack<char>ch;
    string s="";
    int rem;
    
    while(A){
        rem=A%26;
        if(rem!=0){
            ch.push(64+rem);
            A=ceil(A/26);
        }else{
            ch.push(90);
            A-=26;
            A/=26;
        }
        
    }
    
    while(ch.size()){
        s+=ch.top();
        ch.pop();
    }
    
    return s;
}
