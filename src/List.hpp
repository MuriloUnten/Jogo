#pragma once

#include <iostream>

namespace Lists
{
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
			Element<TE>* getNext() const
			{
				return next;
			}

			void setPrev(Element<TE>* newPrev)
			{
				prev = newPrev;
			}
			Element<TE>* getPrev() const
			{
				return prev;
			}

			void setData(TE* newData)
			{
				data = newData;
			}
			TE* getData() const
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

		Element<TL>* getHead() const;
		TL* operator[](int index);
		void pushElement(TL* newData);
		TL* pop(int index);
		void clear();
		const unsigned int getSize() const;
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
	List<TL>::Element<TL>* List<TL>::getHead() const
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
		if(newData == NULL)
		{
			std::cout << "Trying to push NULL pointer to list." << std::endl;
			exit(1);
		}
			
		Element<TL>* element = new Element<TL>();
		element->setData(newData);

		if(head == NULL)
		{
			head = element;
			tail = element;
			size++;
			return;
		}

		element->setPrev(tail);
		element->setNext(NULL);
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


	template<class TL>
	const unsigned int List<TL>::getSize() const
	{
		return size;
	}

}// namespace Lists