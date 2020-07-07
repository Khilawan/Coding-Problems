/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

Note2: Your answer should not have leading zeroes. For example, 00 is not a valid answer.
 
For example,
given strings "12", "10", your answer should be “120”.
*/

string Solution::multiply(string A, string B) {
    int len1=A.size();
    int len2=B.size();
    
    if(len1==0||len2==0){
        return "0";
    }
    
    vector<int>res(len1+len2,0);
    int carry=0;
    int mul=0;
    
    for(int i=len1-1;i>=0;i--){
        carry=0;
        int mlr=0;
        int n1=A[i]-'0';
        
        for(int j=len2-1;j>=0;j--){
            int n2=B[j]-'0';
            int sum=n1*n2+res[mul+mlr]+carry;
            carry=sum/10;
            res[mul+mlr]=sum%10;
            mlr++;
        }
        
        if(carry>0){
            res[mul+mlr]+=carry;
        }
        mul++;
    }
    
    string ans="";
    int ind=len1+len2-1;
    while(ind>=0&&res[ind]==0){
        ind--;
    }
    if(ind==-1){
        return "0";
    }
    
    for(int i=ind;i>=0;i--){
        ans+=res[i]+'0';
    }
    
    
    return ans;
}
