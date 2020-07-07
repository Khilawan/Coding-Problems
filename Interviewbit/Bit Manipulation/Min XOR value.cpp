/*
Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. 
Report the minimum XOR value.

For Examples :

Example Input 1:
    A = [0, 2, 5, 7]
Example Output 1:
    2
Explanation:
    0 xor 2 = 2
Example Input 2:
    A = [0, 4, 7, 9]
Example Output 2:
    3
*/

int Solution::findMinXor(vector<int> &A) {
    int min=INT_MAX;
    int x=0;
    sort(A.begin(),A.end());
    for(int i=0;i<A.size()-1;i++){
        x=A[i]^A[i+1];
        if(x<min){
            min=x;
        }
    }
    return min;
}
