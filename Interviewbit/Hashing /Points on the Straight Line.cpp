/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Sample Input :

(1, 1)
(2, 2)

Sample Output :
2

You will be given 2 arrays X and Y. Each point is represented by (X[i], Y[i])
*/

int Solution::maxPoints(vector<int> &x, vector<int> &y) {
    
    if(x.size()==1){
        return 1;
    }
    
   long long mx=INT_MIN;
   vector<pair<double,double>>v;
   
    for(int i=0;i<x.size();i++){
       v.push_back(pair<double,double>(x[i],y[i]));
    }
    
    unordered_map<double,long long>m;
    
    for(int i=0;i<x.size();i++){
        m.clear();
        long long mm=INT_MIN;
        for(int j=0;j<x.size();j++){
            if(i==j){
                continue;
            }
            if(v[i].first==v[j].first){
                m[INT_MAX]++;
            }else{
                double slope=(v[j].second-v[i].second)/(v[j].first-v[i].first);
                m[slope]++;
            }
        }
        unordered_map<double,long long>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            mm=max(mm,it->second);
        }
        mx=max(mm,mx);
    }
    
    if(mx==INT_MIN){
        return 0;
    }
    return (int)mx+1;
}
