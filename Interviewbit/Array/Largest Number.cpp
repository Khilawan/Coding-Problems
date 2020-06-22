/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*/

bool mycompare(string x,string y){
    string xy=x.append(y);
    string yx=y.append(x);
    return xy.compare(yx)>0;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string> str(A.size());
    int count=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            count++;
        }
        str[i]=to_string(A[i]);
    }
    if(count==A.size()){
        return "0";
    }
    sort(str.begin(),str.end(),mycompare);
    string s="";
    for(int i=0;i<str.size();i++){
        s=s.append(str[i]);
    }
    
    return s;
}
