#pragma once

template<typename T>
class SList
{
private:

	struct Node
	{
		T value;
		Node* next;

		//Node constructors and destructor
		Node() : next(nullptr) {}
		Node(T in_value, Node* in_next) : value(in_value), next(in_next) {}
		virtual ~Node() { if (next) delete next; }
	};

	Node* head;

public:

	//List constructors and destructor
	explicit SList() : head(nullptr) { }
	explicit SList(std::size_t size) : head(nullptr) { }
	explicit SList(std::size_t size, const T& val) { }
	//etc...

	void empty();
	void clear();
};

template<typename T>
inline void SList<T>::empty()
{ }

template<typename T>
inline void SList<T>::clear()
{ }