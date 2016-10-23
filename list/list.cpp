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
	if(pHead==NULL)
		return NULL;
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

/*
 * 快排
 * 枢轴 左边比它小右边比它大 递归 
 */

pNode GetPartion(pNode pHead,pNode pEnd)
{
	pNode prev = pHead;
	pNode cur = pHead->_next;
	pNode key = pHead;
	
	while(cur != pEnd)
	{
		if(cur->_data < key->_data)
		{
			prev = prev->_next;
			swap(cur->_data,prev->_data);
		}
			cur = cur->_next;
	}
	swap(prev->_data,key->_data);//prev->_data = key->_data;
	return prev;
}
void QuickSort(pNode pHead,pNode pEnd)
{
	if( pHead == NULL )//1 0  递归跳出条件：只剩一个节点 pHead->next==PEnd  则还有两个节点
		return;
//	show(pHead);
	if(pHead != pEnd)
	{
		pNode Partion = GetPartion(pHead,pEnd);
		QuickSort(pHead,Partion);
		QuickSort(Partion->_next,pEnd);
	}
}

void TestQuickSort()
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
	QuickSort(a,NULL);
//	cout<<a->_data<<endl;
	show(a);	
}
//升序
void BubbleSort(pNode pHead)
{
	pNode end = NULL;
	if(pHead == NULL)
		return;
	
	pNode cur = NULL;
	pNode prev = NULL;
	while(pHead != end)
	{
		 prev = pHead;
		 cur = pHead->_next;
		while(cur != end)
		{
			if(cur->_data < prev->_data)
				swap(cur->_data , prev->_data);
			prev = cur;
			cur = cur->_next;
		}
		end = prev;
	}
	
}
void TestBub()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);

	show(a);
	BubbleSort(a);
	show(a);

}
/*
 *	在一个无头链表的非头节点前插入一个节点
 *	*/ 

void NoHead_NonepHead(pNode pos,int data)

{
	if(NULL == pos)
		return;
	pNode pnode = new Node(data,NULL);

	pNode prev = pos;
	pNode cur = pos->_next;
		
	prev->_next = pnode;
	pnode->_next = cur;

	swap(pnode->_data,pos->_data);	
	
}
void TestNoHead_NonepHead()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);
	
	pNode x = new Node(100,NULL);
	show(a);
	NoHead_NonepHead(b,100);
	show(a);
	
}
/*
 *	逆置链表
 *	*/
void _Reverse(pNode& pHead)
{
	if(pHead == NULL || pHead->_next == NULL)
		return;
	pNode SubHead = pHead->_next;
	pHead->_next = NULL;
	while(SubHead != NULL)
	{
		pNode ins = SubHead;
		SubHead = SubHead->_next; 
		ins->_next = pHead;
		pHead = ins;
	}
}

void Test_Res()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);
	
	show(a);
	_Reverse(a);
	show(a);	
}
/*	
*		合并两个有序链表，之后仍然有序
*		先找到头，newhead 单链表不会回退，头指针走过去就丢了
*		然后排序
*		最后把没有排的（一个已经排完，另一个还有很长一串），拼到newhead的后面
*/
pNode Merge(pNode pHead1,pNode pHead2)
{
	if(pHead1 == NULL || pHead2 == NULL )
		return pHead1 == NULL ? pHead2:pHead1;
	
	pNode cur = pHead1;
	if(pHead1->_data < pHead2->_data)
		pHead1 = pHead1->_next;
	else
	{
		cur = pHead2;
		pHead2 = pHead2->_next;	
	}
	pNode newHead = cur;

	while(pHead1 != NULL && pHead2 != NULL)//while(cur != NULL)
	{
		if(pHead1->_data < pHead2->_data)
		{
			cur->_next = pHead1;
			pHead1 = pHead1->_next;
		}		
		else
		{
			cur->_next = pHead2;
			pHead2 = pHead2->_next;	
		}
		cur = cur->_next;
	}
	if(pHead1 != NULL)
	{
		cur->_next = pHead1;
	}
	if(pHead2 != NULL)
	{
		cur->_next = pHead2;
	}
	return newHead;
}

void TestMerge()
{
	pNode h = new Node(7, NULL);
	pNode g = new Node(5, h);
	pNode f = new Node(3, g);
	pNode e = new Node(1, f);

	pNode d = new Node(8, NULL);
	pNode c = new Node(6, d);
	pNode b = new Node(2, c);
	pNode a = new Node(2, b);
	
	//show(a);
	pNode pBegin = Merge(a,e);
//	pNode pBegin = Merge(a,NULL);
//	pNode pBegin = Merge(NULL,e);
	show(pBegin);
	
}

/*
 *只遍历一边，找中间节点(快慢指针)
 *
 *有头指针  快慢指针指向头指针
 *快的比慢的快一倍时（快的走两步，慢的走一步），快的到了终点，慢的到了一半
 *还有到三分之一的......起点相同，快的走三步
 *
*/
pNode FindMid(pNode pHead)
{
	if(pHead == NULL ||  pHead->_next == NULL)
		return NULL;
	
	pNode fast = pHead;
	pNode slow = pHead;
	while(fast && fast->_next)//while(slow != fast)
	{
		slow = slow->_next;

		fast = fast->_next;
		fast = fast->_next;
	}
	return slow;
}
void TestFindMid()
{

	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);
	
	show(a);
	pNode mid = FindMid(a);
	cout<<mid->_data<<endl;
}

/*
 *	查找单链表的倒数第K个节点，只能遍历一次
 *	*/

pNode Findlast_K(pNode pHead,int k)
{
	if(pHead == NULL || k == 0)
		return NULL;
	
	pNode fast = pHead;
	pNode slow = pHead;
	int num = k;
	while(--num)
	{
	//	slow = slow->_next;	
		if(fast->_next)
		{
			fast = fast->_next;
		}
		else
			exit(2);
	}
	while(fast->_next)
	{
		fast = fast->_next;
		slow = slow->_next;
	}
	return slow;
	
}
void TestFindlast_K()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);
	
	show(a);
	pNode pk = Findlast_K(a,1);
	cout<<"倒数第1:"<<pk->_data<<endl;
	pNode pk1 = Findlast_K(a,8);
	cout<<"倒数第8:"<<pk1->_data<<endl;
	pNode pk2 = Findlast_K(a,5);
	cout<<"倒数第5:"<<pk2->_data<<endl;
	pNode pk3 = Findlast_K (a,9);
	cout<<"倒数大于链表长度:"<<pk3->_data<<endl;
}



/*
 *	判断带环（快慢指针），时：O(n)	空：O(1)
 *	*/
bool Isring(pNode pHead)
{
	pNode fast = pHead;
	pNode slow = pHead;
	while(fast && fast->_next)
	{
		slow = slow->_next;
		
		fast = fast->_next;
		fast = fast->_next;
		if(fast == slow)
			break;
	}
	return !(fast == NULL || fast->_next == NULL);
}

void TestIsring()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, d);
	h->_next = d;	
	cout<<Isring(a)<<endl;

} 

/*
 *	判断链表是否带环，若带环求长度，求环的入口，  并求每个方法的时/空复杂度
 *	算法描述：
 *
 *	当fast若与slow相遇时，slow肯定没有走遍历完链表，而fast已经在环内循环了n圈(1<=n)。假设slow走了s步，则fast走了2s步（fast步数还等于s 加上在环上多转的n圈），设环长为r，则：
 *
 *	2s = s + nr
 *	s= nr
 *
 *	设整个链表长L，入口环与相遇点距离为x，起点到环入口点的距离为a。
 *	a + x = s
 *	a + x = nr
 *	a + x = (n – 1)r +r = (n-1)r + L - a
 *	a = (n-1)r + (L – a – x)
 *
 *	(L – a – x)为相遇点到环入口点的距离，由此可知，从链表头到环入口点等于(n-1)循环内环+相遇点到环入口点，于是我们从链表头、与相遇点分别设一个指针，每次各走一步，两个指针必定相遇，且相遇第一点为环入口点。
 *	*/
pNode FindPort(pNode pHead)
{
	pNode fast = pHead;
	pNode slow = pHead;
	while(fast && fast->_next)
	{
		slow = slow->_next;
		
		fast = fast->_next;
		fast = fast->_next;
		if(fast == slow)
			break;
	}
	if(fast == NULL || fast->_next == NULL)
		return NULL;

	slow = pHead;
	while(fast != slow)
	{	
		fast = fast->_next;
		slow = slow->_next;
	}
	//return slow;

	//环长
	pNode cir_len =slow;
	int count = 1;
<<<<<<< 48f6125a39d1ecd6b029c5968c7181885c64ad86
	slow = slow->_next;
	while( slow != cir_len && ++count)
	{
		slow = slow->_next;
=======
	cir_len = cir_len->_next;
	while( slow != cir_len && ++count)
	{
		cir_len = cir_len->_next;
>>>>>>> 修正了部分逆置的bug，原来是测试函数没有写对，注意返回值
	}
	cout<<"circle lenth:>"<<count<<endl;
	return slow;
	
}
void TestFindPort()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, d);
	h->_next = d;	
	cout<<FindPort(a)->_data<<endl;

}
/*
<<<<<<< 48f6125a39d1ecd6b029c5968c7181885c64ad86
 *	判断两个链表是否相交（链表不带环）
 *		将链表1 首尾相接， 转化成判断 链表2 是否带环问题
 *		*/
 
=======
 *	判断两个链表是否相交（链表不带环）并找出交点
 *	思路1:    如果他们相交的话，那么他们最后的一个节点一定是相同的，否则是不相交的。因此判断两个链表是否相交就很简单了，分别遍历到两个链表的尾部，然后判断他们是否相同，如果相同，则相交；否则不相交。
 *  思路2		将链表1 首尾相接， 转化成判断 链表2 是否带环问题
 *		*/
//思路1
//bool Twolist_is_point(pNode pHead1,pNode pHead2)
//{
//	if(pHead1 == NULL || pHead2 == NULL)
//		return false;
//	
//	pNode p1 = pHead1;
//	pNode p2 = pHead2;
//	while(p1->_next)
//	{
//		p1 = p1->_next;
//	}
//	while(p2->_next)
//	{
//		p2 = p2->_next;
//	}	
//	if(p1 != p2)
//		return false;
//	else
//		return true;
//}

//思路2
bool Twolist_is_point(pNode pHead1,pNode pHead2)
{
	if(pHead1 == NULL || pHead2 == NULL)
		return false;

	pNode p1 = pHead1;
	pNode p2 = pHead2;
	while(p1->_next)
	{
		p1 = p1->_next;
	}
	p1->_next = pHead1;

	return Isring(pHead2);	
//	pNode slow = pHead2;
//	pNode fast = pHead2;
//	while(fast && fast->_next)
//	{
//		slow = slow->_next;
//
//		fast = fast->_next;
//		fast = fast->_next;
//		if(slow == fast)
//			break;
//	}
//	return true;
}

//交点 思路1  判断哪个链表长，先让一个链表走过相差的路程，后让两个等长的链表一起走相遇点及为交点
int fabs(int a,int b)
{
	int c = a-b;
	return c > 0 ? c : -c; 
}
pNode Twolist_is_point_port(pNode pHead1,pNode pHead2)
{
	if(pHead1 == NULL || pHead2 == NULL)
		return NULL;
	
	pNode p1 = pHead1;
	pNode p2 = pHead2;
	int len1 = 0;
	int len2 = 0;
	while(p1->_next)
	{
		p1 = p1->_next;
		len1++;
	}
	while(p2->_next)
	{
		p2 = p2->_next;
		len2++;
	}
	//无交点	
	if(p1 != p2)
		return NULL;
	//有交点
	else
	{
		p1 = pHead1;
		p2 = pHead2;
		int far = fabs(len1,len2);
	// list1 > list2
		if(len1 > len2)
		{
			for(int i = 0;i<far;i++)
			{
				p1 = p1->_next;
			}
			while(p1 != p2)
			{
				p1 = p1->_next;
				p2 = p2->_next;
			}
			return p1;
		}
	// list1 =< list2
		else
		{
			for(int j = 0; j<far; j++)
			{
				p2 = p2->_next;
			}
			while(p1 != p2)
			{
				p1 = p1->_next;
				p2 = p2->_next;
			}
			return p1;
		}
	}
}

//交点 思路2: 运用栈 将两个链表压栈，进行出栈比较，相同及为交点
#include<stack>
pNode Twolist_is_point_stack(pNode pHead1,pNode pHead2)
{
	if(pHead1 == NULL || pHead2 == NULL)
		return NULL;
	stack<pNode> s1;
	stack<pNode> s2;
	pNode p1 = pHead1;
	pNode p2 = pHead2;
	while(p1 != NULL)
	{
		s1.push(p1);
		p1 = p1->_next;
	}
	while(p2 != NULL)
	{
		s2.push(p2);
		p2 = p2->_next;
	}
	pNode compare1 = NULL;
	pNode compare2 = NULL;
	while(!(s1.empty() && s2.empty()))
	{
		compare1 = s1.top();
		s1.pop();
		compare2 = s2.top();
		s2.pop();
		if(compare1->_data != compare2->_data)//倒着比，如果有交点肯定有许多相同的
			return compare1->_next;
	}
	return NULL;
}


void TestTwolist_is_point()
{
	pNode h = new Node(1, NULL);
	pNode g = new Node(0, h);
	pNode f = new Node(9, g);
	pNode e = new Node(7, f);

	pNode d = new Node(5, e);
	pNode c = new Node(3, d);
	pNode b = new Node(2, c);
	pNode a = new Node(4, b);
	
//	pNode p = new Node(11, e);	//构成交点
	pNode p = new Node(11, NULL);
	pNode o = new Node(10, p);
	pNode n = new Node(6, o);
	pNode m = new Node(8, n);

	pNode ret1 = Twolist_is_point_stack(a,m); 
	pNode ret2 = Twolist_is_point_port(a,m);
	if(ret1 == NULL)
		cout<<"No point!"<<endl;
	else 
		cout<<Twolist_is_point_stack(a,m)->_data<<endl;
	if(ret2 == NULL)
		cout<<"No point!"<<endl;
	else	
		cout<<Twolist_is_point_port(a,m)->_data<<endl;

	//cout<<Twolist_is_point(a,e)<<endl;	
}
/*
 *	Josephus：n个人围成圈，依次编号为1,2,..,n，现在从1号开始依次报数，
 *		当报到m时，报m的人退出，下一个人重新从1报起，
 *			循环下去，问最后剩下那个人的编号是多少？（环链表 模拟法）
 *
 *			*/



int Joswohus(int n,int m)
{
	if(m > n  || m <= 0 || n <= 0)
		return 0;
	int i = 0;
	int s = 0;
	for(i = 2; i<n; ++i)
		s = (s+m)%i;
	return s;
//	for(i = 1; i<n; ++i)
//	{
//		if(i == m)
//		{
//			n--;
//			i = 1;
//		}
//		if(i == n)
//			break;
//	}
//	return i;
	
}

void TestJ()
{
	cout<<Joswohus(9,2)<<endl;
}

>>>>>>> 修正了部分逆置的bug，原来是测试函数没有写对，注意返回值

//单链表部分逆置
//Node* RolloverList(Node* list,int k)
//list 无头结点
//1->2->3->4->5  k=2   翻转后： 2-1->4->3->5
// 思路： 小部分翻转，各个部分拼接
<<<<<<< 48f6125a39d1ecd6b029c5968c7181885c64ad86
pNode RolloverList(pNode list,int k);
{
	int count = k;
	
=======
pNode RolloverList(pNode pHead,int k)
{
	if(pHead == NULL || pHead->_next == NULL || k <= 1)
		return NULL;
	
	int count = 0;
	pNode ins = pHead;
	pNode prevHead = NULL;
	pNode sectionTail = pHead;
	pNode sectionHead = NULL;
	pNode prevTail = NULL;
	
	int sectionNum = 0;
	while(ins)
	{
		count = k;
		prevTail = sectionTail;
		sectionTail = ins;
		while(count-- && ins)
		{
			pNode tmp = ins;
			ins = ins->_next;
			tmp->_next = sectionHead;
			sectionHead = tmp;
			
		}
		sectionNum++;
		if(1 == sectionNum)
			prevHead = sectionHead;
		else
			prevTail->_next = sectionHead;	
	}	
	sectionTail->_next = NULL;
	return prevHead;	
}

void TestRolloverList()
{
//	pNode f = new Node(6,NULL);
	pNode e = new Node(5,NULL);
	pNode d = new Node(4,e);
	pNode c = new Node(3,d);
	pNode b = new Node(2,c);
	pNode a = new Node(1,b);
	show(a);
	pNode list = RolloverList(a,2);
	show(list);
>>>>>>> 修正了部分逆置的bug，原来是测试函数没有写对，注意返回值
}
int main()
{
//	Test1();
//	Test2();
//	TestQuickSort();	
//	TestBub();
<<<<<<< 48f6125a39d1ecd6b029c5968c7181885c64ad86
//    TestNoHead_NonepHead();
=======
//  TestNoHead_NonepHead();
>>>>>>> 修正了部分逆置的bug，原来是测试函数没有写对，注意返回值
//	Test_Res();
//	TestMerge();
//	TestFindMid();
//	TestFindlast_K();
<<<<<<< 48f6125a39d1ecd6b029c5968c7181885c64ad86
//	TestIsring();
	TestFindPort();
=======
//	TestIsring()
//	TestFindPort();
//	TestTwolist_is_point();
	TestRolloverList();
//	TestJ();
>>>>>>> 修正了部分逆置的bug，原来是测试函数没有写对，注意返回值
	return 0;
}
