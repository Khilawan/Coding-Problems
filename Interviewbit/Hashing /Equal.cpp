/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2

Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)

If no solution is possible, return an empty list.



*/

vector<int> Solution::equal(vector<int> &A) {
    
    unordered_map<int,pair<int,int>>m;
    vector<int>v;
    int n=A.size();
    
    if(n<4){
        return v;
    }
    
    for(int i=0;i<n-1;i++){
        
        for(int j=i+1;j<n;j++){
            
            int sum=A[i]+A[j];
            if(m.find(sum)==m.end()){
                m[sum].first=i;
                m[sum].second=j;
                continue;
            }
            
            if(m.find(sum)!=m.end()){
                
                int ii=m[sum].first;
                int jj=m[sum].second;
                
                if(ii!=i&&j!=jj&&j!=ii&&jj!=i){
                    
                    if(v.size()==0){
                        v.push_back(ii);
                        v.push_back(jj);
                        v.push_back(i);
                        v.push_back(j);    
                        
                    }else{
                        if(v[0]>ii||v[0]==ii&&v[1]>jj||v[0]==ii&&v[1]==jj&&v[2]>i||v[0]==ii&&v[1]==jj&&v[2]==i&&v[3]>j){
                            v[0]=ii;
                            v[1]=jj;
                            v[2]=i;
                            v[3]=j;
                        }
                    }
                }
            }
        }
    }
    
    return v;
}
