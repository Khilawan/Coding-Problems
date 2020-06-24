/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Example :

Input : [1, 10, 5]
Output : 5 

time complexity of this program is O(nlogn) however if we use radix/count sort it can be solved in linear time.
*/

int Solution::maximumGap(const vector<int> &A) {
    if(A.size()<2){
        return 0;
    }
    vector<int>b;
    for(int i=0;i<A.size();i++){
        b.push_back(A[i]);
    }
    sort(b.begin(),b.end());
    int gap=0;
    for(int i=0;i<b.size()-1;i++){
        int g=b[i+1]-b[i];
        if(g>gap){
            gap=g;
        }
    }
    return gap;
}
