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
        if(A[i]=='1'&&B[i]=='1'&&carry==1){
            sum+='1';
            carry=1;
        }else if(A[i]=='1'&&B[i]=='1'&&carry==0){
            sum+='0';
            carry=1;
        }else if(A[i]=='0'&&B[i]=='0'){
            char ch=carry+'0';
            sum.push_back(ch);
            carry=0;
        }else{
            if(carry==1){
                sum+='0';
                carry=1;
            }else{
                sum+='1';
                carry=0;
            }
        }
        i++;
    }
    if(carry==1){
        sum+='1';
    }
    reverse(sum.begin(),sum.end());
    return sum;
}
