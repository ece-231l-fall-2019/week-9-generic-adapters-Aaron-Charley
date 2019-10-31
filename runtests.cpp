#include <iostream>

// change the value below to 1 to run tests against your StringList class.
// change the value below to 0 to run tests against the built in std::list.

#include <string>

#if 1
#include "List.h"
#include "Stack.h"
#include "queue.h"
typedef Stack<std::string> StringStack;
typedef List<std::string> StringList;
typedef Queue<double> DoubleQueue;
typedef Stack<int> IntStack;
typedef List<int> IntList;
typedef Queue<char> CharQueue;

#else
#include <list>
typedef std::list<std::string> StringList;
typedef std::list<int> IntList;
#include <stack>
typedef std::stack<std::string> StringStack;
typedef std::stack<int> IntStack;
#endif

void Assert(bool cond, std::string message)
{
	if (cond)
		std::cout << "Pass: " << message << std::endl;
	else
		std::cerr << "FAIL: " << message << std::endl;
}

int main()
{
	// TODO:
	// Write more tests to fully test your classes.

	StringList a;
	StringList b;

	a.push_front("A");
	Assert(a.front() == "A", "front == A");
	a.push_front("B");
	Assert(a.front() == "B", "front == B");
	a.pop_front();
	Assert(a.front() == "A", "front == A");
	a.push_front("Z");
	Assert(a.front() == "Z", "front == Z");

	b = a;

	Assert(b.front() == "Z", "b.front == Z");
	b.pop_front();
	Assert(b.front() == "A", "b.front == A");
	b.pop_front();
	Assert(b.empty() == true, "b is empty");
	Assert(a.empty() == false, "a is NOT empty");

	StringList i{"1", "3", "3", "7"};

	Assert(i.size() == 4, "StringList has 4 elements");
	Assert(i.front() == "I", "i.front() == 1");
	Assert(i.back() == "friend", "i.back() == 7");
	i.pop_back();
	Assert(i.empty() == false, "i is NOT empty");
	i.push_back("father");
	i.pop_front();
	Assert(i.front() == "am", "i.front() == 3");
	i.pop_front();
	Assert(i.front() == "your", "i.front() == 3");
	i.push_front("is");
	i.push_front("3");
	i.push_front("7");
	Assert(i.size() == 5, "i has 5 elements");
	// TODO: check all methods on StringList...

	StringStack c;
	c.push("A");
	c.push("B");
	Assert(c.top() == "B", "B is at top");
	c.pop();
	Assert(c.empty() == false, "B is not empty");
	c.pop();
	Assert(c.empty() == true, "B is empty");

	// TODO: check all methods on StringStack...

	IntList ia;
	ia.push_front(5);
	ia.push_front(6);
	Assert(ia.front() == 6, "front is 6");




	// TODO: check all methods on IntList...

	IntStack ic;
	ic.push(6);
	ic.push(5);
	Assert(ic.top() == 5, "top is 5");

		IntStack ib;
	ib.push(6);
	ib.push(9);
	Assert(ib.top() == 9, "top is 9");

		IntStack iz;
	iz.push(4);
	iz.push(2);
	Assert(iz.top() == 5, "top is 2");






	// TODO: check all methods on IntStack...
	
IntStack f{};
	f.push(1);
	f.push(2);
	f.push(3);
	f.push(4);
	Assert(f.top() == 4, "top is 4");
	f.pop();
	f.pop();
	Assert(f.top() == 2, "top is 2");
	
	IntStack z{};
	z.push(55);
	Assert(z.empty() == false, "e.IntStack is NOT empty");
	Assert(z.size() == 1, "e.IntStack has 1 element");
	Assert(z.top() == 42, "top is 42");
	
	IntStack l{};
	l = z;
	l.pop();
	Assert(l.empty() == true, "f.IntStack is empty");
	Assert(l.size() == 0, "f.IntStack has 1 element");

	IntStack im{};
	im.push(6);
	im.push(5);
	
	Assert(im.top() == 4, "top is 4");

	//queue
	CharQueue m{'H', 'A', 'L', 'F', ' ', 'L', 'I', 'F', 'E', '2'};
	Assert(m.front() == 'E', "m.front() = E");
	Assert(m.back() == 'E', "m.back() = E");
	Assert(m.size() == 10, "CharQueue m has 10 elements");
	m.pop();
	m.pop();
	m.pop();
	m.pop();
	m.pop();
	Assert(m.front() == 'L', "m.front() = L");
	Assert(m.back() == 'H', "m.back() = H");
	Assert(m.size() == 5, "CharQueue m has 5 elements");

	
	return 0;
}


