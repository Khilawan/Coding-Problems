/*
Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.

*/


int Solution::lengthOfLongestSubstring(string A) {
    
    set<char>s;
    int n=A.size();
    
    int mx=0;
    int l=0;
    int i=0;
    int tmp=0;
    while(l<n&&i<n){
        if(s.find(A[l])==s.end()){
            s.insert(A[l]);
            tmp=l-i+1;
            l++;
        }else{
            while(A[i]!=A[l]){
                s.erase(A[i]);
                i++;
            }
            s.erase(A[i++]);
            tmp=l-i+1;
        }
        mx=max(mx,tmp);
    }
    
    return mx;
}
