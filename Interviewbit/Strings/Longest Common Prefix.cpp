/*
Given the array of strings A,
you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
and S2.

For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".



Input Format

The only argument given is an array of strings A.
Output Format

Return longest common prefix of all strings in A.
For Example

Input 1:
    A = ["abcdefgh", "aefghijk", "abcefgh"]
Output 1:
    "a"
    Explanation 1:
        Longest common prefix of all the strings is "a".

Input 2:
    A = ["abab", "ab", "abcd"];
Output 2:
    "ab"
    Explanation 2:
        Longest common prefix of all the strings is "ab".
*/

string Solution::longestCommonPrefix(vector<string> &A) {
    string pre="";
    if(A.size()==1){
        for(int i=0;i<A[0].size();i++){
            pre+=A[0][i];
        }
        return pre;
    }
    int ind=0;
    for(int i=0;i<A.size()-1;i++){
        if(i>0){
            int j;
            for(j=0;j<A[i+1].size()&&j<pre.size();j++){
                if(pre[j]!=A[i+1][j]){
                    break;
                }
            }
            ind=min(ind,j);
        }else{
            int j=0;
            while(A[0][j]==A[1][j]){
                pre+=A[0][j++];
            }
            ind=j;
        }
    }
    string res="";
    for(int i=0;i<ind;i++){
        res+=pre[i];
    }
    return res;
}
