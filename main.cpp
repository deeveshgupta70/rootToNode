#include<bits/stdc++.h>

using namespace std;

#define Fast1 ios_base::sync_with_stdio(0)
#define Fast2 cin.tie(0)
#define Fast3 cout.tie(0)
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)
#define mod 1e9 + 7
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define INF 1000000000000000003
typedef long long int ll;
typedef short int SI;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define POB pop_back
#define MP make_pair

class binaryTree
{
public:
	int data;
	binaryTree* left;
	binaryTree* right;
	binaryTree(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~binaryTree(){
		delete left;
		delete right;
	}
	
};

binaryTree* builtTree(){

	int rootData;
	cin>>rootData;
	binaryTree* root = new binaryTree(rootData);

	queue<binaryTree*> node;
	node.push(root);

	while(!node.empty()){

		binaryTree* ptr = node.front();
		node.pop();

		int val;
		cin>>val;

		if( val != -1){
			ptr->left = new binaryTree(val);
			node.push(ptr->left);
		}

		cin>>val;

		if(val != -1){
			ptr->right = new binaryTree(val);
			node.push(ptr->right);
		}

	}

	return root;
}

// Level Order Traversal
void levelOrderTraversal(binaryTree* root){

	if(!root) return;

	queue<binaryTree*> node;

	node.push(root);

	while(!node.empty()){

		int count = node.size();

		while(count--){
			binaryTree* ptr = node.front();
			node.pop();

			cout<<ptr->data<<" ";

			if(ptr->left) node.push(ptr->left);

			if(ptr->right) node.push(ptr->right);
		}
		cout<<"\n";

	} 
}

// Preorder - Traversal
void preorderTraversal(binaryTree* root){

	if(!root) return;

	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

int countNode(binaryTree* root){
	if(!root) return 0;

	return (1 + countNode(root->left) + countNode(root->right));
}

vector<int>* rootPath(binaryTree* root,int data){

	if(!root) {
		return NULL;
	}

	if(root->data == data){
		vector<int>* res = new vector<int>();
		res->push_back(root->data);
		return res;
	}

	vector<int> *l = rootPath(root->left,data);
	if(l){
		l->push_back(root->data);
		return l;
	}
	vector<int>* r = rootPath(root->right,data);
	if(r){
		r->push_back(root->data);
		return r;
	}else{
		return NULL;
	}
}

int main(){
	binaryTree* root  = builtTree();
    
    cout<<"\n";
	preorderTraversal(root);
	cout<<"\n";
	levelOrderTraversal(root);
	cout<<"\n";
	cout<<"total Number of Nodes :"<<countNode(root);

	cout<<"\n path to 8 :";
	vector<int>* path = rootPath(root,8);
	for( int i = 0; i < path->size(); i++){
		cout<<path->at(i)<<" ";
	}
	delete root;
	return 0;
}

/*
Input:
1 2 3 4 5 6 7 -1 -1 -1 -1  8 9 -1 -1 -1 -1 -1 -1 -1

output:
1 2 4 5 3 6 8 9 7 
1 
2 3 
4 5 6 7 
8 9 

total Number of Nodes :9
 path to 8 :8 6 3 1 

*/
