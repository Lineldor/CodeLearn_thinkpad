#include <iostream>
#include <stdlib.h>
#include <queue>
#include <string>

struct binarytree{
	int num;
	struct binarytree *leftchild;
	struct binarytree *rightchild;
};

void creat( struct binarytree *(&root))//引用类型
{
	int i;
	std::cin>>i;
	if(i==0)
		root=NULL;
	else
	{
		root=(struct binarytree *) malloc (sizeof(struct binarytree));
		root->num=i;
		creat(root->leftchild);
		creat(root->rightchild);
	}
        
}

void visit(struct binarytree *root){
	if (root->num!=0)
		std::cout<<root->num<<' ';
}
void preorder(struct binarytree *root){
	
	if (root!=NULL)
	{
		visit (root);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}
void levelorder(struct binarytree *root){
	std::queue<struct binarytree *> q;
	struct binarytree *p=root;
	q.push(root);
	int i=0;
	while (!q.empty()){
		p=q.front();
		visit(p);
		if(p->leftchild!=NULL)
			q.push(p->leftchild);
		if(p->rightchild!=NULL)
			q.push(p->rightchild);
		q.pop();
		
	}
}
//calculate the depth of the binary tree
int treedepth(struct binarytree *root){
	int depth=0;
	if (root!=NULL){
		int lchilddepth=treedepth (root->leftchild);
		int rchilddepth=treedepth (root->rightchild);
		depth=lchilddepth>rchilddepth?lchilddepth+1:rchilddepth+1;
	}
	return depth;
}

struct binarytree *invert(struct binarytree *root){
	struct binarytree *l_child=root;
	struct binarytree *r_child=root;

	if (root!=NULL){
		l_child=invert(root->leftchild);
		r_child=invert(root->rightchild);
		root->leftchild=r_child;
		root->rightchild=l_child;

	}
	return root;//总体来说，递归就是null和返回值搞明白即可。
}

void TreePath(struct binarytree *root, std::vector<std::string> &treepath,std::string p){
	if (!root->leftchild && !root->rightchild){
		treepath.push_back(p+std::to_string(root->num));
		return ;
	}
	else{
		p=p+std::to_string(root->num);
		//treepath.push_back(root->num);
		if (root->leftchild) TreePath(root->leftchild, treepath,p);
		//treepath.push_back(root->num);
		if (root->rightchild) TreePath(root->rightchild, treepath,p);
		//treepath.push_back(root->num);
		
	}
}
void sumoftree(struct binarytree* root,std::vector<int> &sum,int now){
	if (!root->leftchild && !root->rightchild){
		sum.push_back(now+root->num);
		return ;
	}
	else{
		now+=root->num;
		if (root->leftchild) sumoftree(root->leftchild,sum,now);
		if (root->rightchild) sumoftree(root->rightchild,sum,now);
	}
}
void depthoftree(struct binarytree* root,std::vector<int> &sum,int now){
	if (!root->leftchild && !root->rightchild){
		sum.push_back(now+1);
		//now=0;
		return ;
	}
	else{
		now++;
		if (root->leftchild) depthoftree(root->leftchild,sum,now);
		if (root->rightchild) depthoftree(root->rightchild,sum,now);
	}
}
void main(){
	struct binarytree *root,*inv;
	root=(struct binarytree *) malloc (sizeof(struct binarytree));
	creat(root);
	/*std::vector<std::string> treepath;
	std::string p;*/
	std::vector<int> sum;
	depthoftree(root,sum,0);
	for (auto i:sum)
		std::cout<<i<<' ';
	/*TreePath(root,treepath,p);
	for(auto i:treepath)
		std::cout<<i<<' ';
	std::vector<int> sum;
	sumoftree(root,sum,0);
	for (auto i:sum)
		std::cout<<i<<' ';
	/*inv=invert(root);
	levelorder(inv);
	int depth=treedepth(root);
	std::cout<<std::endl<<depth<<std::endl;*/
}
