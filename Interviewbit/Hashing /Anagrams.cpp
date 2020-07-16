/*
Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

 Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 
 Note: All inputs will be in lower-case. 

Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]

cat and tca are anagrams which correspond to index 1 and 4.
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

 Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j.

*/


vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    set<int>s;
    vector<vector<int>>res;
    int n=A.size();
    int a[n][26];
    memset(a,0,sizeof(a));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<A[i].size();j++){
            int c=A[i][j]-'a';
            a[i][c]++;
        }
    }
    
    for(int i=0;i<n;i++){
        vector<int>re;
        if(s.find(i)!=s.end()){
            continue;
        }
        re.push_back(i+1);
        for(int k=i+1;k<n;k++){
            if(s.find(k)!=s.end()){
                continue;
            }
            int flag=1;
            for(int j=0;j<26;j++){
                if(a[i][j]!=a[k][j]){
                    flag=0;
                    break;
                }
            }
            if(flag){
                s.insert(k);
                s.insert(i);
                re.push_back(k+1);
            }
        }
        res.push_back(re);
    }
    
    return res;
}
