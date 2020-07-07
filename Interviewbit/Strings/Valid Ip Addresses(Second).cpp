/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/

bool check(string s){
    if(s.size()>1&&s[0]=='0'){
        return false;
    }
    if(stoi(s)>=0&&stoi(s)<=255){
        return true;
    }
    return false;
}

vector<string> Solution::restoreIpAddresses(string A) {
    vector<string>res;
    int n=A.size();
    if(n>12||n<4){
        return res;
    }
    
    for(int i=1;i<4;i++){
        string s1=A.substr(0,i);
        if(!check(s1)){
            continue;
        }
        for(int j=1;(i+j)<A.size()&&j<4;j++){
            string s2=A.substr(i,j);
            if(!check(s2)){
                continue;
            }
            for(int k=1;(i+j+k)<A.size()&&k<4;k++){
                string s3=A.substr(i+j,k);
                string s4=A.substr(i+j+k);
                if(check(s3)&&check(s4)){
                    string s=s1+'.'+s2+'.'+s3+'.'+s4;
                    res.push_back(s);
                }
            }
        }
        
    }
    
    return res;
}
