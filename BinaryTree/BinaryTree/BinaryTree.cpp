#include <iostream>
#include <stdlib.h>
#include <queue>

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

void main(){
	struct binarytree *root;
	root=(struct binarytree *) malloc (sizeof(struct binarytree));
	creat(root);
	levelorder(root);
	int depth=treedepth(root);
	std::cout<<std::endl<<depth<<std::endl;
}