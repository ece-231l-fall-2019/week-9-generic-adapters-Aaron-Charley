
template<typename T>
class Stack
{
	protected:
		List<T> c;
	public:
	Stack()
	{
	}

	Stack(std::initializer_list<T> l): c(l)
	{
	}

	const T& top() const
	{
		return c.back();
	}

	void push(const T& a)
	{
		c.push_back(a);
	}

	void pop()
	{
		c.pop_back();
	}

	size_t size() const
	{
		return c.size();
	}

	bool empty() const
	{
		return c.empty();
	}

	Stack<T>& operator=(const Stack<T>& other)
	{
		c = other.c;
		return *this;
	}

	void clear()
	{
		c.clear();
	}

	template<typename B>friend bool operator==(const Stack<B>&, const Stack<B>&);
	template<typename B>friend bool operator!=(const Stack<B>&, const Stack<B>&);
};

template<typename T>
bool operator==(const Stack<T>& a, const Stack<T>& b)
{
  return a.c == b.c;
}

template<typename T>
bool operator!=(const Stack<T>& a, const Stack<T>& b)
{
  return a.c != b.c;
}
