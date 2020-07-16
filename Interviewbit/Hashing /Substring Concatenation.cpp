/*
You are given a string, S, and a list of words, L, that are all of the same length.

Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

Example :

S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].
(order does not matter).

*/

vector<int> Solution::findSubstring(string A, const vector<string> &B) {
    unordered_map<string,int>s;
    vector<int>v;
    int n=B.size();
    
    for(int i=0;i<n;i++){
        s[B[i]]++;
    }
    
    int sz=B[0].size();
    int m=A.size();
    
    for(int i=0;i<=m-(n*sz)+1;i++){
        unordered_map<string,int>mp;
        int flag=0;
        for(int j=i;j<i+n*sz;j+=sz){
            string str="";
            for(int k=j;k<j+sz;k++){
                str+=A[k];
            }
            if(s.find(str)==s.end()){
                flag=1;
                break;
            }
            mp[str]++;
        }
        if(flag){
            continue;
        }
        int f=1;
        unordered_map<string,int>::iterator it;
        
        for(it=s.begin();it!=s.end();it++){
            if(mp[it->first]!=it->second){
                f=0;
                break;
            }
        }
        if(f){
            v.push_back(i);
        }
        mp.clear();
    }
    return v;
}
