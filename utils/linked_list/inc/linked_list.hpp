#ifndef _HOMEBREW_LINKED_LIST
#define _HOMEBREW_LINKED_LIST

#include <cstdint>

/**
  * Node to create the list from.
  *
  * @tparam T the type of data stored in the node.
  */
template <class T>
class Node
{
public:

	/**
	 * Default constructor.
	 *
	 * @param  none.
	 * @return none.
	 */
	Node() = default;

	/**
	 * Constructor to create Node with given data.
	 *
	 * @param  aData data to initialize mData with.
	 * @return none.
	 */
	Node(const T& aData) : mData(aData), mNext(nullptr) {}

	T mData;
	Node* mNext;
};

/**
  * Linked list container for objects of different types in ascending order.
  *
  * @tparam T the type of data stored in the list.
  */
template <class T>
class LinkedList
{
public:

	/**
	 * Constructor, constructs empty list.
	 *
	 * @param  none.
	 * @return none.
	 */
	LinkedList();

	/**
	 * Constructor, constructs list with mHead in given node.
	 *
	 * @param  aNewNode node to place mHead pointer on.
	 * @return none.
	 */
	LinkedList(Node<T> aNewNode) : mHead(aNewNode)
	{
		mSize++;
	}

	/**
	 * Constructor, constructs list with mHead in node with given value.
	 *
	 * @param  aValue value to initialize mHead.
	 * @return none.
	 */
	LinkedList(T aValue)
	{
		mHead = new Node<T>(aValue);
		mSize++;
	}

	/**
	 * Copy constructor.
	 *
	 * @param  aLinkedList list to be copied.
	 * @return none.
	 */
	LinkedList(const LinkedList<T>& aLinkedList);

	/**
	 * Destructor.
	 *
	 * @param  none.
	 * @return none.
	 */
	~LinkedList();

	/**
	 * Assignment operator.
	 *
	 * @param  aLinkedList list which we assign.
	 * @return pointer to list to which we assigned aLinkedList.
	 * @overload
	 */
	LinkedList<T>& operator=(const LinkedList<T>& aLinkedList);

	/**
	 * Inserts node with given value to the list,
	 * keeping ascending order.
	 *
	 * @param  aValue value to insert to list.
	 * @return none.
	 */
	void insert(T aValue);

	/**
	 * Removes first element of the list.
	 *
	 * @param  none.
	 * @return none.
	 */
	void deleteFirst();

	/**
	 * Removes element of given value from the list.
	 *
	 * @param  aValue value of element to delete.
	 * @return none.
	 */
	void deleteOfValue(T aValue);

	/**
	 * Removes last element of the list.
	 *
	 * @param  none.
	 * @return none.
	 */
	void deleteLast();

	/**
	 * Returns current size of the list.
	 *
	 * @param  none.
	 * @return mSize.
	 */
	uint32_t size() const;

	/**
	 * Returns if the list is empty.
	 *
	 * @param  none.
	 * @return true - if empty;
	 *         false - if not.
	 */
	bool empty() const;

private:
	Node<T>* mHead;
	uint32_t mSize;
};

#endif