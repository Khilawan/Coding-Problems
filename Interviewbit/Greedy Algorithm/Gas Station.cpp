/*

Given two integer arrays A and B of size N.
There are N gas stations along a circular route, where the amount of gas at station i is A[i].

You have a car with an unlimited gas tank and it costs B[i] of gas to travel from station i
to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the minimum starting gas station’s index if you can travel around the circuit once, otherwise return -1.

You can only travel in one direction. i to i+1, i+2, … n-1, 0, 1, 2.. Completing the circuit means starting at i and
ending up at i again.



Input Format:
    The first argument given is the integer array A.
    The second argument given is the integer array B.

Output Format:
    Return the minimum starting gas station's index if you can travel around the circuit once, otherwise return -1.

For Example

Input 1:
    A =  [1, 2]
    B =  [2, 1]

Output 1:
    1



*/


int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n=A.size();
    vector<int>c(n,0);
    
    if(n==1){
        return A[0]>=B[0]?0:-1;
    }
    
    int asum=0;
    int bsum=0;
    int sum=0;
    int ind=0;
    
    for(int i=0;i<n;i++){
        asum+=A[i];
        bsum+=B[i];
        sum+=A[i]-B[i];
        
        if(sum<0){
            sum=0;
            ind=i+1;
        }
    }
    
    return asum>=bsum?ind:-1;
}
