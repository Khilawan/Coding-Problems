/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.

*/


void find(string str,int lcount,int rcount,int A,vector<string> &res){
    if(rcount>lcount){
        return;
    }else if(rcount==lcount&&rcount==A){
        res.push_back(str);
    }
    if(lcount==A){
        int nm=lcount-rcount;
        for(int i=0;i<nm;i++){
            str+=')';
        }
        res.push_back(str);
        return;
    }
    
    str+='(';
    find(str,lcount+1,rcount,A,res);
    str.pop_back();
    str+=')';
    find(str,lcount,rcount+1,A,res);
    str.pop_back();
}


vector<string> Solution::generateParenthesis(int A) {
    vector<string>res;
    if(A==0){
        return res;
    }else if(A==1){
        res.push_back("()");
        return res;
    }
    
    int lcount=1;
    int rcount=0;
    string str="";
    str+='(';
    find(str,lcount,rcount,A,res);
    return res;
}
