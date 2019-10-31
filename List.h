#ifndef __EE231_List_h__
#define __EE231_List_h__
#include <iostream>
#include <string>
#include <initializer_list>
#include <cstddef>

template<typename T>
class List
{
	private:

	typedef struct llist {
		T value;
		struct llist *next;
		struct llist *prev;
	} llist;

	llist *_beg;
	llist *_end;
	size_t count;

	public:
	
	// default constructor
	List()
	{
		_beg = 0;
		_end = 0;
		count = 0;
	}

	// copy constructor
List(const List<T>&);
	List(const std::initializer_list<T>& l)	
	{	
		_beg = 0;
		_end = 0;
		count = 0;
			
		for (auto value : l)
			push_back(value);
	}	
	// destructor
~List()
	{
		while(!empty())
			pop_front();
	}

	// copy operator
	List& operator=(const List& a)
	{
		for (const llist *b = a._beg; b!= 0; b = b -> next)
		{
			push_back(b->value);
		}
		return *this;
	}

	void clear()
	{
		while(!empty())
			pop_back();
	}

	T& front()
	{
		return _beg->value;
	}

	const T& back() const
	{
		return _end->value;
	}

	void push_front(T value)
	{
		llist *newItem = new llist;
		newItem->value = value;
		newItem->next = _beg;
		if(_beg != NULL)
		_beg->prev = newItem;
		if(_end == NULL)
			_end = newItem;
		_beg = newItem;
		count++;
	}

	void pop_front()
	{
		llist *front = _beg;
		_beg = _beg->next;
		if (_beg)
		
			_beg->prev =_beg->prev->prev;
			else
				_end = NULL;

			delete front;
			
		
	}
	void push_back(T value)
{
	llist *newItem = new llist;
	newItem->value = value;
	newItem->next = 0;
	newItem->prev = _end;
	if (_end != 0)
		_end->next = newItem;
	if (_beg == 0)
		_beg = newItem;
	_end = newItem;
	count++;

}

void pop_back()
{
	llist *back = _end;
	_end = _end->prev;
	if(_end)
		_end->next = _end->next->next;
	else
		_beg = NULL;
	delete back;
}


	bool empty() const
	{
		return _beg == 0;
	}

size_t size() const
	{
		size_t count = 0;
		if( _beg == NULL ) 
			return count;
		if( _beg == _end)
		{
			count++;
			return count;
		}

		for( llist *temp = _beg; temp != NULL; temp = temp->next, count++ ){}
		
		return count;
	}

void reverse ()
	{
		if( size() <= 1 )
			return;
		llist *cur = _beg;
		llist *temp;
		while( cur != NULL )
		{
			temp = cur->prev;
			cur->prev = cur->next;
			cur->next = temp;
			cur = cur->prev;
		}	
		if(temp)
			temp = temp->prev;
		_end = _beg; _beg = temp;
	}
void unique() 
{
	for (llist *ptr = _beg; ptr != 0; ptr = ptr->next)
	{
		while (ptr -> next != 0 && ptr->value == ptr->next->value)
		{
			llist *savePtr = ptr->next;
			ptr->next = savePtr->next;
			if(savePtr->next != 0)
			{
			savePtr->next->prev = ptr;
			delete savePtr;
			}
			else
			{
				_end = ptr;
			delete savePtr;
			}
			

		}
	}
}

template <typename V> friend bool operator ==(const List<V>& a, const List<V> b);
template <typename V> friend bool operator !=(const List<V>& a, const List<V> b);


};

template <typename T>
bool operator == (const List<T> & a, const List<T> b)
{
	if (a.size() != b.size())
		return false;

	auto *aset = a._beg;
	auto *bset = b._beg;

	for(; aset != nullptr && bset != nullptr;  aset = aset->next, bset = bset->next)
	{
		if (aset->value != bset->value)
			return false;
	}
	return true;
}

template <typename T>
bool operator != (const List<T>& a, const List<T>& b)
{
	if (a.size() != b.size())
		return true;
	auto *aset = a._beg;
	auto *bset = b._beg;
	for(; aset != nullptr && bset != nullptr;  aset = aset->next, bset = bset->next)
	{
		if (aset->value != bset->value)
			return true;
	}
	return false;
}






#endif // __EE231_List_h__
