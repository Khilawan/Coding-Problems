/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example Input 1:
    A = [1, 2, 2, 3, 1]
Example Output 1:
    3
Explanation:
    3 occurs only once
Example Input 2:
    A = [1, 2, 2]
Example Output 2:
    1
*/

int Solution::singleNumber(const vector<int> &A) {
    int a=A[0];
    for(int i=1;i<A.size();i++){
        a^=A[i];
    }
    return a;
}
