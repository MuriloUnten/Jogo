#pragma once

#include <iostream>

template <class TL>
class List
{
public:
	template <class TE>
	class Element
	{
	private:
		Element<TE>* next;
		Element<TE>* prev;
		TE* data;

	public:
		Element()
		{
			next = NULL;
			prev = NULL;
			data = NULL;
		}
		~Element()
		{
			next = NULL;
			prev = NULL;
			data = NULL;
		}

		void setNext(Element<TE>* newNext)
		{
			next = newNext;
		}
		Element<TE>* getnext()
		{
			return next;
		}

		void setPrev(Element<TE>* newPrev)
		{
			prev = newPrev;
		}
		Element<TE>* getprev()
		{
			return prev;
		}

		void setdata(TE* newData)
		{
			data = newData;
		}
		TE* getdata()
		{
			return data;
		}
	};

private:
	Element<TL>* head;
	Element<TL>* tail;

public:
	List();
	~List();

	Element<TL>* getHead(); // Your only possible way to get head.
	void pushElement(TL* newData);
	Element<TL>* pop(int index);
	void clear();

};


template <class TL>
List<TL>::List()
{
	head = NULL;
	tail = NULL;
}

template <class TL>
List<TL>::~List()
{
	clear();
}

template <class TL>
List<TL>::Element<TL>* List<TL>::getHead()
{
	return head;
}


template <class TL>
void List<TL>::pushElement(TL* newData)
{
	Element<TL>* element = new Element<TL>();
	element->setdata(newData);

	if (head == NULL)
	{
		head = element;
		tail = element;
		return;
	}

	element->setPrev(tail);
	tail->setNext(element);
	tail = element;
}


template <class TL>
List<TL>::Element<TL>* List<TL>::pop(int index)
{
	Element<TL>* pAux = head;
	while(pAux != NULL)
	{
		if(pAux->getdata())
	}
}


template <class TL>
void List<TL>::clear()
{
	if (head != NULL)
	{
		Element<TL>* pAux = head->getnext();
		while (pAux != NULL)
		{
			head->setNext(pAux->getnext());
			delete pAux;
			pAux = head->getnext();
		}

		delete head;
		head = NULL;
		tail = NULL;
	}
}