/*
Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.
*/


int Solution::findCount(const vector<int> &A, int B) {
    int s=0,e=A.size()-1;
    int mid;
    while(s<=e){
        mid=(s+e)/2;
        if(A[mid]==B){
            int count=0;
            s=mid;
            e=mid+1;
            while(A[s]==B&&s>=0){
                count++;
                s--;
            }
            while(A[e]==B&&e<A.size()){
                count++;
                e++;
            }
            return count;
        }else if(A[mid]<B){
            s=mid+1;
        }else if(A[mid]>B){
            e=mid-1;
        }
    }
    return 0;
}
