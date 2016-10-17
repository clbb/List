#include<iostream>
using namespace std;

typedef struct Node
{
	int _data;
	Node* _next;
	Node(int data,Node* next)
		:_data(data)
		,_next(next)
	{}
}Node,*pNode;

void show(pNode pHead)
{
	pNode cur = pHead;
	while(cur)
	{
		cout<<cur->_data<<"->";
		cur = cur->_next;
	}
	cout<<"NULL"<<endl;
}

/*
从尾到头打印
*/
void ResPrint(pNode pBegin)
{
	if(pBegin == NULL) //if(pBegin) 指针和NULL  0比较只能写清楚;  非0 向下执行； 0 else；／  pBegin==NULL true 向下；false else;
		return;
	else
	{
		ResPrint(pBegin->_next);
		cout<<pBegin->_data<<"->";
	}
}
/*
删除一个无头链表的非尾节点（偷梁换柱）
*/

void DelNopHead_NoneTail(pNode& pos)
{
	if(pos && pos->_next == NULL)
		return;

	pNode del = pos->_next;
	pos->_data = del->_data;
	pos->_next = del->_next;
	delete del;
	del->_next = NULL;
}

pNode Find(pNode pHead,int key)
{
	//if(pHead==NULL)
	//	return NULL;
	pNode cur = pHead;
	while(cur->_data != key)
	{
		cur = cur->_next;
		show(cur);
	}
		show(cur);
	return cur;
}
void Test2()
{
	Node *h = new Node(1, NULL);
	Node *g = new Node(0, h);
	Node *f = new Node(9, g);
	Node *e = new Node(7, f);

	Node *d = new Node(5, e);
	Node *c = new Node(3, d);
	Node *b = new Node(2, c);
	Node *a = new Node(4, b);
	show(a);
	//DelNopHead_NoneTail(Find(a,2));
	//Node* tmp = Find(a,2);
	//cout<<tmp->_data<<endl;
	DelNopHead_NoneTail(b);
	show(a);
}

void Test1()
{
	
	Node *h = new Node(1, NULL);
	Node *g = new Node(0, h);
	Node *f = new Node(9, g);
	Node *e = new Node(7, f);

	Node *d = new Node(5, e);
	Node *c = new Node(3, d);
	Node *b = new Node(2, c);
	Node *a = new Node(4, b);

	show(a);
	ResPrint(a);
}
int main()
{
//	Test1();
	Test2();
	return 0;
}
