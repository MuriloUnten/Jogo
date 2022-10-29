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
		Element<TE>* getNext()
		{
			return next;
		}

		void setPrev(Element<TE>* newPrev)
		{
			prev = newPrev;
		}
		Element<TE>* getPrev()
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
	TL* pop(int index);
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


/* Adds element to list*/
template <class TL>
void List<TL>::pushElement(TL* newData)
{
	Element<TL>* element = new Element<TL>();
	element->setData(newData);

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


/* Removes element from list at given index */
template <class TL>
TL* List<TL>::pop(int index)
{
	// Checks if index is inside of list boundaries
	if(index >= size || index < 0)
	{
		std::cout << "Index out of range on template list." << std::endl;
		exit(1);
	}

	Element<TL>* pAux = head;
	for(int i = 0; i < index; i++)
		pAux = pAux->getNext();
	
	if(pAux == head)
		head = pAux->getNext();
	else if(pAux == tail)
		pAux->getPrev()->setNext(NULL);
	else
		pAux->getPrev()->setNext(pAux->getNext());
		pAux->getNext()->setPrev(pAux->getPrev());
	
	TL* pAux2 = pAux->getData();
	delete pAux;
	return pAux2;
}


/* Removes all elements from list */
template <class TL>
void List<TL>::clear()
{
	if (head != NULL)
	{
		Element<TL>* pAux = head->getNext();
		while (pAux != NULL)
		{
			head->setNext(pAux->getNext());
			delete pAux;
			pAux = head->getNext();
		}

		delete head;
		head = NULL;
		tail = NULL;
		size = 0;
	}
}