/*
Find the contiguous subarray within an array, A of length N which has the largest sum.

Input Format:

The first and the only argument contains an integer array, A.
Output Format:

Return an integer representing the maximum possible sum of the contiguous subarray.

For example:

Input 1:
    A = [1, 2, 3, 4, -10]

Output 1:
    10

Explanation 1:
    The subarray [1, 2, 3, 4] has the maximum possible sum of 10.

Input 2:
    A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

Output 2:
    6

Explanation 2:
    The subarray [4,-1,2,1] has the maximum possible sum of 6.
*/

int Solution::maxSubArray(const vector<int> &A) {
    int maxsum=INT_MIN,sum=0,maxelement=INT_MIN;
    if(A.size()==1){
        return A[0];
    }
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum<=0){
            sum=0;
        }
        if(sum>maxsum&&sum!=0){
            maxsum=sum;
        }
        if(maxelement<A[i]){
            maxelement=A[i];
        }
    }
    return max(maxsum,maxelement);
}
