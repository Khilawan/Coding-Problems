/*
Given a string A denoting a stream of lowercase alphabets. You have to make new string B.

B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.



Problem Constraints
1 <= length of the string <= 100000



Input Format
The only argument given is string A.



Output Format
Return a string B after processing the stream of lowercase alphabets A.



Example Input

Input 1:

 A = "abadbc"

Input 2:

 A = "abcabc"


Example Output

Output 1:

 "aabbdd"
 
Output 2:

 "aaabc#"

*/

string Solution::solve(string A) {
    queue<char>q;
    int n=A.size();
    string s="";
    map<char,int>ch;
    
    
    for(int i=0;i<n;i++){
    
        ch[A[i]]++;
        while(!q.empty()&&ch[q.front()]!=1){
            q.pop();
        }
        if(q.empty()&&ch[A[i]]==1){
            s+=A[i];
        }else if(!q.empty()&&ch[q.front()]==1){
            s+=q.front();
        }else{
            s+='#';
        }
        q.push(A[i]);
        
    }
    
    return s;
}
