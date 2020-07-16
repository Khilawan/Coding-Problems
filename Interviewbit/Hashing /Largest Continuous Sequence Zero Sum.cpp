/*
Find the largest continuous sequence in a array which sums to zero.

Example:

Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 

*/

vector<int> Solution::lszero(vector<int> &A) {
    
    unordered_map<int,int>m;
    vector<int>res;
    int n=A.size();
    int pre[n]={0};
    
    int ml=0,mr=0,mx=0;
    pre[0]=A[0];
    m[pre[0]]=0;
    
    int flag=0;
    if(pre[0]==0){
        ml=mr=0;
        mx=1;
        flag=1;
    }
    for(int i=1;i<n;i++){
        pre[i]+=pre[i-1]+A[i];
        if(pre[i]==0){
            if(mx<i+1){
                ml=0;
                mr=i;
                mx=i+1;
                flag=1;
            }
        }else if(m.find(pre[i])!=m.end()){
            if(mx<i-m[pre[i]]){
                ml=m[pre[i]]+1;
                mr=i;
                mx=i-m[pre[i]];
                flag=1;
            }
        }else{
            m[pre[i]]=i;
        }
    }
    
    for(int i=ml;i<=mr&&flag;i++){
        res.push_back(A[i]);
    }
    
    return res;
    
}
