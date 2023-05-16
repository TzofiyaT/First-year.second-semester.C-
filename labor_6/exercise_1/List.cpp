#include "List.h"
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {}
List::Link::Link(const Link& source) : value(source.value), next(source.next) {}
List::List() : head(NULL)
{
	//cout << "CTOR\n";
}
List::List(const List &l)
{
	cout << "Copy CTOR\n";
	Link *src, *trg;
	if (l.head == NULL)
		head = NULL;
	else
	{ 
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}

void List::operator=(const List& l)
{
	if (&l != this)                          
	{
		this->clear();
		Link *src, *trg;
		if (l.head == NULL)
			head = NULL;
		else
		{ 
			head = new Link((l.head)->value, NULL);
			src = l.head;
			trg = head;
			while (src->next != NULL)
			{
				trg->next = new Link((src->next)->value, NULL);
				src = src->next;
				trg = trg->next;
			}
		}
	}
}

List::~List()
{
	clear();
}

void List::clear()
{
	Link* next;
	for (Link *p = head; p != NULL; p = next)
	{
		next = p->next;
		p->next = NULL;
		delete p;
	}
	head = NULL;
}

bool List::isEmpty() const
{
	return head == NULL;
}

void List::add(int val)
{
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

void List::print() const
{

	for (Link* p = head; p != NULL; p = p->next)
		cout << p->value << " ";
}

void List::removeFirst()
{
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	Link* p = head;
	head = p->next;
	p->next = NULL;
	delete p;
}

List merge(List& list1, List& list2)
{
	List list3, list4;
	int num;
	while (!list1.isEmpty() && !list2.isEmpty())
	{
		if (list1.firstElement() < list2.firstElement())
		{
			num = list1.firstElement();
			list1.removeFirst();
		}
		else
		{
			num = list2.firstElement();
			list2.removeFirst();
		}
		list3.add(num);
	}
	while (!list1.isEmpty())
	{
		num = list1.firstElement();
		list3.add(num);
		list1.removeFirst();
	}
	while (!list2.isEmpty())
	{
		num = list2.firstElement();
		list3.add(num);
		list2.removeFirst();
	}
	while (!list3.isEmpty())
	{
		num = list3.firstElement();
		list4.add(num);
		list3.removeFirst();
	}
	return list4;
}

List makeSet(List list1)
{
	List list2, list3;
	int num;
	num = list1.firstElement();   
	list2.add(num);                
	list1.removeFirst();          
	while (!list1.isEmpty())
	{
		num = list1.firstElement();
		if (num != list2.firstElement()) 
		{
			list2.add(num);
			list1.removeFirst();
		}
		else  
		{
			list1.removeFirst();
		}
	}
	while (!list2.isEmpty())
	{
		num = list2.firstElement();
		list3.add(num);
		list2.removeFirst();
	}
	return list3;
}

void List::makeSet(List list1)
{
	Link*p = head;
	int m = 0;
	while (p->next != NULL)
	{
		if (p->value == (p->next)->value)
		{
			p->next = (p->next)->next;
		}
		p = p->next;
	}
}

List reverse1(List src)
{
	List dest;
	while (!src.isEmpty())
	{
		int num = src.firstElement();
		dest.add(num);
		src.removeFirst();
	}
	return dest;
}

void List::setCin(int val)
{
	if (head == NULL)
	{
		head = new Link(val, head);
	}
	else
	{
		Link*p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = new Link(val, p->next);
	}
}


void List::insert(int key)
{
	Link*p = head;     
	if (key<p->value)     
	{
		head = new Link(key, head);
		return;
	}
	while (p->next != NULL)
	{
		if (key>p->value&&key<(p->next)->value)
		{
			p->next = new Link(key, p->next);
			return;
		}
		p = p->next;
	}
	while (p->next != NULL)
	{
		p = p->next;
	}
	if (key>p->value)
	{
		p->next = new Link(key, p->next);
		return;
	}
}

void List::remove(int key)
{
	bool flag = false;       
	Link*p = head;
	if (key == p->value)       
	{
		head = head->next;      
		flag = true;          
		return;               
	}
	while (p->next != NULL)
	{
		if (key == (p->next)->value)     
		{                              
			p->next = (p->next)->next;
			flag = true;     
			return;
		}
		p = p->next;
	}
	while (p->next != NULL)
	{
		p = p->next;          
	}
	if (key == p->value)
	{
		p->next = NULL;        
		flag = true;   
		return;
	}
	if (!flag)     
	{
		throw "value not found";
	}
}

istream& operator >> (istream& in, List& list)
{
	int val1, val2;    
	in >> val1;      
	list.setCin(val1);
	in >> val2;
	while (val2>val1)    
	{
		list.setCin(val2);
		val1 = val2;
		in >> val2;
	}
	return in;
}

ostream& operator<<(ostream& out, const List& list)
{
	list.print();            
	return out;
}

int List::ListLong()
{
	Link*p = head;
	int count = 0;
	if (this->isEmpty())
	{
		return 0;
	}
	while (p->next != NULL)
	{
		count++;
		p = p->next;
	}
	return count + 1;
}

void List::addToEnd(int key)
{
	Link*p = head;
	if (this->isEmpty())
	{
		this->add(key);
	}
	else
	{
		while (p->next != NULL) 
		{
			p = p->next;
		}
		p->next = new Link(key, p->next);   
	}
}

int List::search(int index)
{
	int key;
	int i = 0;
	if (this->isEmpty())
	{
		return -1;
	}
	if (index >= this->ListLong())
	{
		for (Link* p = head; p != NULL; p = p->next)
		{
			if (i == index%this->ListLong())
			{
				key = p->value;
			}
			i++;
		}
		return key;
	}
	else
	{
		for (Link* p = head; p != NULL; p = p->next)
		{
			if (i == index)
			{
				key = p->value;				
				return key;
			}
			i++;
		}
		return key;
	}
}

List List::reverse1(List src)
{
	List dest;
	while (!src.isEmpty())
	{
		int num = src.firstElement();
		dest.add(num);
		src.removeFirst();
	}
	return dest;
}