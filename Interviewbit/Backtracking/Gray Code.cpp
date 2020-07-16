/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2

There might be multiple gray code sequences possible for a given n.
Return any such sequence.

*/


void sol(vector<string>&s,int A,vector<int>&res){
    for(int i=0;i<s.size();i++){
        int num=0;
        for(int j=0;j<s[i].size();j++){
            int nn=s[i][j]-'0';
            num+=pow(2,j)*nn;
        }
        res.push_back(num);
    }
}

void find(vector<string>&s,int b){
    s.push_back("0");
    s.push_back("1");
    
    for(int i=2;i<(1<<b);i<<=1){
        for(int j=i-1;j>=0;j--){
            s.push_back(s[j]);
        }
        for(int j=0;j<i;j++){
            s[j]='0'+s[j];
        }
        for(int j=i;j<2*i;j++){
            s[j]='1'+s[j];
        }
    }
    
}

vector<int> Solution::grayCode(int A) {
   
   vector<int>res;
   vector<string>s;
   find(s,A);
   
   sol(s,A,res);
   
   return res;
}
