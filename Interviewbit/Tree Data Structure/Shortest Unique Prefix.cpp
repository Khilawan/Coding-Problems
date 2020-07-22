/*
Find shortest unique prefix to represent each word in the list.

Example:

Input: [zebra, dog, duck, dove]
Output: {z, dog, du, dov}

where we can see that

zebra = z
dog = dog
duck = du
dove = dov


 NOTE : Assume that no word is prefix of another. In other words, the representation is always possible. 


*/


const int ALPHABET_SIZE = 26; 
  
struct TrieNode{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    bool isWord; 
    int count;
}; 

struct TrieNode *getNode(void){ 
    struct TrieNode *pNode =  new TrieNode; 
    pNode->isWord = false; 
    pNode->count=0;
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 

void insert(struct TrieNode *root, string key) { 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
            
        pCrawl = pCrawl->children[index];
        pCrawl->count++;
    } 
  
    pCrawl->isWord = true; 
} 

string search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
    string str="";
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        
        pCrawl = pCrawl->children[index];
        str+=key[i];
        if(pCrawl->count==1){
            break;
        }
    } 
  
    return str; 
} 

vector<string> Solution::prefix(vector<string> &A) {
    struct TrieNode *root = getNode(); 
    int n=A.size();
    
    for (int i = 0; i < n; i++){
        insert(root, A[i]);
    } 
    
    vector<string>res;
    
    for (int i = 0; i < n; i++){
        res.push_back(search(root,A[i]));
    }
    
    return res;
}
