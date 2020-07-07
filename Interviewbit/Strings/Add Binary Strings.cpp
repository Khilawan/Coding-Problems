/*
Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"
Return a + b = “111”.
*/

string Solution::addBinary(string A, string B) {
    
    int carry=0;
    string sum="";
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    
    int n=A.size();
    int m=B.size();
    int l=max(n,m);
    int i=n;
    while(i<l){
        A+='0';
        i++;
    }
    i=m;
    while(i<l){
        B+='0';
        i++;
    }

    i=0;
    while(i<l){
        carry+=A[i]-'0';
        carry+=B[i]-'0';
        sum+=carry%2+'0';
        carry/=2;
        i++;
    }
    if(carry==1){
        sum+='1';
    }
    reverse(sum.begin(),sum.end());
    return sum;
}
