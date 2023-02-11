#pragma once

#include <vector>

using std::cout;
using std::endl;

template<typename T>
class SList
{

	//Aliases
	using value_type = T;
	using size_type = std::size_t;

private:

	struct Node
	{
		value_type value;
		Node* next;

		//Node constructors and destructor
		Node() : next(nullptr) {}
		Node(value_type in_value, Node* in_next) : value(in_value), next(in_next) {}
		virtual ~Node() { if (next) delete next; }
	};

	Node* head;

public:

	template<typename T>
	struct SListIterator
	{
	private:
		Node* node;

	public:
		friend class SList;

		//Iterator constructors and destructor
		SListIterator() : node(nullptr) {}
		SListIterator(Node* inNode) : node(inNode) {}
		SListIterator(const SListIterator& other) : node(other.head) {}
		virtual ~SListIterator() {};

		//Operators
		SListIterator& operator++()
		{
			if (node)
				node = node->next;
			return *this;
		}

		bool operator==(const SListIterator& other)
		{
			return node == other.node;
		}

		bool operator!=(const SListIterator& other)
		{
			return node != other.node;
		}

		value_type& operator*()
		{
			return (*node).value;
		}

		value_type* operator->()
		{
			return &(head->value);
		}
	};

	//List constructors and destructor
	explicit SList() : head(nullptr) { }
	explicit SList(size_type size) : head(nullptr) { }
	explicit SList(size_type size, const value_type& val)
	{

	}
	virtual ~SList() {};
	//TODO: etc...

	inline value_type front() const
	{	
		if (empty())
		{
			cout << "ERROR: called front(), but list is empty." << endl;
			return NULL;
		}
		return head->value;
	}

	inline void push_front(value_type in_value)
	{
		Node* newNode = new Node;
		newNode->value = in_value;
		newNode->next = head;
		head = newNode;
	}
	
	inline bool empty() const
	{
		return head == nullptr;
	}

	/*void empty();
	void clear();*/
};