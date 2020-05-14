/*
Given a binary encoded string and a Huffman MinHeap tree, your task is to complete the function decodeHuffmanData(), which decodes the binary encoded string and return the original string. 

Example:
Input:
2
01110100011111000101101011101000111
1011010011100101101110111
Output:
geeksforgeeks
India

*/

#include <bits/stdc++.h>
#define MAX_TREE_HT 256
using namespace std;

map<char, string> codes;
map<char, int> freq;

struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode *left, *right;
	MinHeapNode(char data, int freq)
	{
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(MinHeapNode* l, MinHeapNode* r)
	{
		return (l->freq > r->freq);
	}
};

void printCodes(struct MinHeapNode* root, string str)
{
	if (!root)
		return;
	if (root->data != '$')
		cout << root->data << ": " << str << "\n";
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

void storeCodes(struct MinHeapNode* root, string str)
{
	if (root==NULL)
		return;
	if (root->data != '$')
		codes[root->data]=str;
	storeCodes(root->left, str + "0");
	storeCodes(root->right, str + "1");
}

priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

void HuffmanCodes(int size)
{
	struct MinHeapNode *left, *right, *top;
	for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
		minHeap.push(new MinHeapNode(v->first, v->second));
	while (minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		top = new MinHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}
	storeCodes(minHeap.top(), "");
}

void calcFreq(string str, int n)
{
	for (int i=0; i<str.size(); i++)
		freq[str[i]]++;
}


string decodeHuffmanData(struct MinHeapNode* root, string binaryString);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str;
        cin>>str;
        string encodedString, decodedString;
        calcFreq(str, str.length());
        HuffmanCodes(str.length());
        for (auto i: str)encodedString+=codes[i];
        //cout<<encodedString<<endl;
        decodedString = decodeHuffmanData(minHeap.top(), encodedString);
        cout << decodedString << endl;
    }
	return 0;
}


string decodeHuffmanData(struct MinHeapNode* root, string binaryString)
{
    string str="";
    int s=0;
    while(binaryString[s]!='\0'){
        MinHeapNode* r=root;
        while(r!=NULL){
            if(binaryString[s]=='0'&&r->left!=NULL){
                r=r->left;
                s++;
            }else if(binaryString[s]=='1'&&r->right!=NULL){
                r=r->right;
                s++;
            }else{
                break;
            }
        }
        str.push_back(r->data);
    }
    return str;
}