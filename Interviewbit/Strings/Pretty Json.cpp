/*
Given a string A representating json object. Return an array of string denoting json object with proper indentaion.

Rules for proper indentaion:

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Note:

[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.



Input Format

The only argument given is the integer array A.


Output Format

Return a list of strings, where each entry corresponds to a single line. The strings should not have "\n" character in them.

For Example

Input 1:
    A = "{A:"B",C:{D:"E",F:{G:"H",I:"J"}}}"

Output 1:
    { 
        A:"B",
        C: 
        { 
            D:"E",
            F: 
            { 
                G:"H",
                I:"J"
            } 
        } 
    }

Input 2:
    A = ["foo", {"bar":["baz",null,1.0,2]}]
Output 2:
   [
        "foo", 
        {
            "bar":
            [
                "baz", 
                null, 
                1.0, 
                2
            ]
        }
    ]
*/

string str(int ind){
    string s="";
    for(int i=0;i<ind;i++){
        s+='\t';
    }
    return s;
}

vector<string> Solution::prettyJSON(string A) {
    vector<string>s;
    int ind=0;
    string tmp="";
    int flag=0;
    for(int i=0;i<A.size();i++){
        if(A[i]=='{'||A[i]=='['){
            if(flag==1){
                s.push_back(tmp);
                flag=0;
            }
                
            tmp.clear();
            tmp+=str(ind);
            tmp+=A[i];
            s.push_back(tmp);
            tmp.clear();
            ind++;
            tmp+=str(ind);
        }else if(A[i]=='}'||A[i]==']'){
            if(flag==1){
                s.push_back(tmp);
                flag=0;
            }
                
            tmp.clear();
            --ind;
            tmp+=str(ind);
            tmp+=A[i];
            if(A[i+1]==','){
                tmp+=',';
                i++;
            }
            s.push_back(tmp);
            tmp.clear();
            tmp+=str(ind);
            flag=0;
            
        }else if(A[i]==','){
            tmp+=',';
           s.push_back(tmp);
           tmp.clear();
           tmp+=str(ind);
           flag=0;
        }else{
            tmp+=A[i];
            flag=1;
        }
    }
    return s;
}
