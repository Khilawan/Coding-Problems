/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.


The digit 0 maps to 0 itself.
The digit 1 maps to 1 itself.

Input: Digit string "23"

Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Make sure the returned strings are lexicographically sorted.

*/


void find(map<char,string>&m,vector<string>&s,string A,int i,int n,string str){
    
    if(i==n){
        s.push_back(str);
        return;
    }
    
    int sz=m[A[i]].size();
    //vector<char>t=m[A[i]];
    int k=0;
    while(k<sz){
        str+=m[A[i]][k];
        //cout<<str<<endl;
        find(m,s,A,i+1,n,str);
        str.pop_back();
        k++;
    }
    
}


vector<string> Solution::letterCombinations(string A) {
    map<char,string>m;

    m['0']='0';

    m['1']='1';

    m['2']="abc";

    m['3']="def";
  
    m['4']="ghi";

    m['5']="jkl";

    m['6']="mno";

    m['7']="pqrs";

    m['8']="tuv";

    m['9']="wxyz";
    
    vector<string>s;
    string str="";
    
    find(m,s,A,0,A.size(),str);
    
    return s;
}
