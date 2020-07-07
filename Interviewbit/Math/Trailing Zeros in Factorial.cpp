/*
Given an integer A, return the number of trailing zeroes in A!.

Note: Your solution should be in logarithmic time complexity.



**Problem Constraints**
1 <= A <= 10000



**Input Format**
First and only argumment is integer A.



**Output Format**
Return an integer, the answer to the problem.



**Example Input**
Input 1:

 A = 4
Input 2:

 A = 5


**Example Output**
Output 1:

 0
Output 2:

 1
*/

int Solution::trailingZeroes(int A) {
    int sum=0;
    int i=5;
    while((A/i)!=0){
        sum+=(A/i);
        i=i*5;
    }
    return sum;
}
