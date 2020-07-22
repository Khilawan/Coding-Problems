/*
Given two arrays A & B of size N each.
Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)

*/


vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    priority_queue<pair<int,pair<int,int>>>q;
    vector<int>res;
    set<pair<int,int>>s;
    int n=A.size();
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    q.push(make_pair(A[n-1]+B[n-1],make_pair(n-1,n-1)));
    s.insert(make_pair(n-1,n-1));
    
    while(n--){
        int l=q.top().second.first;
        int r=q.top().second.second;
        res.push_back(q.top().first);
        q.pop();
        if(l>0&&r>=0&&s.find(make_pair(l,r-1))==s.end()){
            q.push(make_pair(A[l]+B[r-1],make_pair(l,r-1)));
            s.insert(make_pair(l,r-1));
        }
        if(l>=00&&r>0&&s.find(make_pair(l-1,r))==s.end()){
            q.push(make_pair(A[l-1]+B[r],make_pair(l-1,r)));
            s.insert(make_pair(l-1,r));
        }
    }
    
    return res;
}
