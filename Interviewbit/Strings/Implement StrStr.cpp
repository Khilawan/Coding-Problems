/*
Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

int Solution::strStr(const string A, const string B) {
    int ind=-1;
    for(int i=0;i<A.size();i++){
        if(A[i]==B[0]){
            int j=i,k=0;
            while(j<A.size()&&k<B.size()&&A[j]==B[k]){
                j++;
                k++;
            }
            if(j<=A.size()&&k==B.size()){
                ind=i;
                break;
            }
        }
        if(ind!=-1){
            break;
        }
    }
    return ind;
}
