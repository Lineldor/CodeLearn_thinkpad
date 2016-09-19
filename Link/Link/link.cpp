#include <iostream>
#include <stdlib.h>

struct student{
	int num;
	float score;
	struct student *next;
};

struct student *creat(){
	struct student *head;//指向链表的表头
	struct student *last;//指向原链表的最后一个元素
	struct student *nxt;//指向新建元素

	int n=0;
	nxt=(struct student *)malloc (sizeof(struct student));
	last=nxt;
	
	if (nxt==NULL){
		std::cout<<"Error!"<<std::endl;
	}
	else {
		head=NULL;
		std::cin>>nxt->num>>nxt->score;
	}
	while (nxt->num>0){
		n+=1;
		if (n==1){
			head=nxt;//设置表头
			last->next=NULL;
		}
		else {
			last->next=nxt;
		}
		last=nxt;
		nxt=(struct student *) malloc (sizeof(struct student));
		std::cin>>nxt->num>>nxt->score;
	}
	last->next=NULL;
	free(nxt);
	nxt=NULL;
	return head;
}

void Print(struct student *head){
	struct student *p;
	p=head;
	if (head!=NULL){
		while (p!=NULL) {
		std::cout<<p->num<<' '<<p->score<<std::endl;
		p=p->next;
		}
		
	}
}
//删除元素 思考：把所有重复的元素都删除应该怎么办呢？
struct student *Del(struct student *head, int num){
	struct student *p1;//用于寻找
	struct student *p2;//用于存储p1
	p1=head; 
	p2=head;
	while (p1->num!=num&&p1->next!=NULL){
		p2=p1;
		p1=p1->next;
	}
	if (p1->num==num){
		if (p1==head){
			head=p1->next;
		}
		else {
			p2->next=p1->next;
		}
		free(p1);
		p1=NULL;
	}
	else{
		std::cout<<"There is no "<<num<<std::endl;
	}
	return head;
}
void main(){
	struct student *grade;
	grade=creat();
	Print(grade);
	int num;
	std::cin>>num;
	grade=Del(grade, num);
	Print (grade);
}