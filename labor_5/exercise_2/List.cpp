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
	//cout << "DTOR: ";
	//print();
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

void List::print() const
{
	for (Link* p = head; p != NULL; p = p->next)
		cout << p->value << " ";
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