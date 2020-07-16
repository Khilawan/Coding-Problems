/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in linear time complexity.
Note that when the count of a character C in T is N, then the count of C in minimum window in S should be at least N.

Example :

S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC"

 Note:
If there is no such window in S that covers all characters in T, return the empty string ''.
If there are multiple such windows, return the first occurring minimum window ( with minimum start index ).

*/

string Solution::minWindow(string A, string B) {
    
   int l=0,r=0;
   int n=A.size();
   
   unordered_map<char,int>m;
   unordered_map<char,int>sm;
   
   for(int i=0;i<B.size();i++){
       m[B[i]]++;
   }
   
   int num=m.size();
   
   int count=0;
   int s=-1,e=n-1;
   int mn=INT_MAX;
   while(l<n){
       while(r<n&&count<num){
           sm[A[r]]++;
           if(sm[A[r]]==m[A[r]]){
               count++;
           }
           r++;
       }
       
       if(count==num){
           if(mn>r-l+1){
               mn=r-l+1;
               s=l;
               e=r-1;
           }
       }
       --sm[A[l]];
       if(sm[A[l]]<m[A[l]]){
           count--;
       }
       l++;
   }
   
   string str="";
   if(s==-1){
       return str;
   }
   
   for(int i=s;i<=e;i++){
       str+=A[i];
   }
   
   return str;
}




