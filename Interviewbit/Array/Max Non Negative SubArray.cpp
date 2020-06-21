/*
Given an array of integers, A of length N, find out the maximum sum sub-array of non negative numbers from A.

The sub-array should be contiguous i.e., a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array.

Find and return the required subarray.

NOTE:

    1. If there is a tie, then compare with segment's length and return segment which has maximum length.
    2. If there is still a tie, then return the segment with minimum starting index.

Input 1:
    A = [1, 2, 5, -7, 2, 3]

Output 1:
    [1, 2, 5]

Explanation 1:
    The two sub-arrays are [1, 2, 5] [2, 3].
    The answer is [1, 2, 5] as its sum is larger than [2, 3].

Input 2:
    A = [10, -1, 2, 3, -4, 100]
    
Output 2:
    [100]

Explanation 2:
    The three sub-arrays are [10], [2, 3], [100].
    The answer is [100] as its sum is larger than the other two.
*/

vector<int> Solution::maxset(vector<int> &A) {
    int l=0,r=0;
    int ml=0,mr=0;
    long sum=INT_MIN,cursum=0;
    vector<int> v;
    int flag=0;
    int len=0,maxlen=0;
    for(int i=0;i<A.size();i++){
        if(A[i]<0){
            l=i+1;
            r=i+1;
            cursum=0;
            len=0;
            continue;
        }
        cursum+=A[i];
        len++;
        if(cursum>sum){
            sum=cursum;
            ml=l;
            mr=r;
            flag=1;
            maxlen=len;
        }else if(cursum==sum&&len>maxlen){
            maxlen=len;
            ml=l;
            mr=r;
        }
        r++;
    }
    if(flag==0){
        return v;
    }
    for(int i=ml;i<=mr;i++){
        v.push_back(A[i]);
    }
    return v;
}
