/*
Problem Description

Given a column title A as appears in an Excel sheet, return its corresponding column number.



Problem Constraints
1 <= |A| <= 100



Input Format
First and only argument is string A.



Output Format
Return an integer



Example Input
Input 1:

 "A"
Input 2:

 "AB"


Example Output
Output 1:

 1
Output 2:

 28

*/

int Solution::titleToNumber(string A) {
    vector<int> a;
    int n=A.size();
    for(int i=n-1;i>=0;i--){
        int num=A[i];
        a.push_back(num-64);
    }
    long long sum=0;
    for(int i=0;i<a.size();i++){
        sum+=a[i]*pow(26,i);
    }
    return sum;
}
