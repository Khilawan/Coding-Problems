/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]

 Ordering the results in the answer : Entry i will come before Entry j if :

len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))

In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")

*/


bool ispalin(string s,int l,int r){
    while(l<r){
        if(s[l]!=s[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void find(vector<vector<string> >&ans,vector<string>&st,string A,int i){
    if(i>=A.size()){
        ans.push_back(st);
        return;
    }
    
    for(int j=i;j<A.size();j++){
        if(ispalin(A,i,j)){
            string s=A.substr(i,j-i+1);
            st.push_back(s);
            find(ans,st,A,j+1);
            st.pop_back();
        }
    }
    
}

vector<vector<string> > Solution::partition(string A) {
    vector<vector<string> >ans;
    vector<string>st;
    find(ans,st,A,0);
    return ans;
}
