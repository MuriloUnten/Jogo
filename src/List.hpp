#pragma once

#include <iostream>

template <class TL>
class List
{
private:
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

		void setData(TE* newData)
		{
			data = newData;
		}
		TE* getData()
		{
			return data;
		}
	};

private:
	Element<TL>* head;
	Element<TL>* tail;

	unsigned int size;

public:
	List();
	~List();

	Element<TL>* getHead(); // The only way you're getting head.
	TL* operator[](int index);
	void pushElement(TL* newData);
	Element<TL>* pop(int index);
	void clear();
};


template <class TL>
List<TL>::List()
{
	size = 0;
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


/* Overloads the operator [] to access element in given index */
template <class TL>
TL* List<TL>::operator[](int index)
{
	if(index >= size || index < 0)
	{
		std::cout << "Index out of range on template list." << std::endl;
		exit(1);
	}

	Element<TL>* pAux = head;
	for(int i = 0; i < index; i++)
		pAux = pAux->getNext();
	
	return pAux->getData();
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
	size++;
}


template <class TL>
List<TL>::Element<TL>* List<TL>::pop(int index)
{
	if(index >= size || index < 0)
	{

	}
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