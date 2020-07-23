#ifndef _HOMEBREW_VECTOR
#define _HOMEBREW_VECTOR

#include <cstdint>

/**
  * Vector container for objects of different types.
  *
  * @tparam T the type of data stored in the vector.
  */
template <class T>
class Vector
{
public:
	
	typedef T* iterator;

	/**
	 * Constructor, constructs empty vector.
	 *
	 * @param  none.
	 * @return none.
	 */
	Vector();

	/**
	 * Constructor, constructs vector of given size.
	 *
	 * @param  aSize size of vector to be created.
	 * @return none.
	 */
	Vector(uint32_t aSize);

	/**
	 * Constructor, constructs vector of given size.
	 * After that initializes all of the elements to given value. 
	 *
	 * @param  aSize size of vector to be created.
	 * @param  aInitial value to initialize elements of vector.
	 * @return none.
	 */
	Vector(uint32_t aSize, const T& aInitial);

	/**
	 * Copy constructor.
	 *
	 * @param  aVector vector to be copied.
	 * @return none.
	 */
	Vector(const Vector<T>& aVector);

	/**
	 * Destructor.
	 *
	 * @param  none.
	 * @return none.
	 */
	~Vector();

	/**
	 * Returns capacity of the vector.
	 *
	 * @param  none.
	 * @return mCapacity.
	 */
	uint32_t capacity() const;

	/**
	 * Returns size of the vector.
	 *
	 * @param  none.
	 * @return mSize.
	 */
	uint32_t size() const;

	/**
	 * Returns if the vector is empty.
	 *
	 * @param  none.
	 * @return true - if empty;
	 *         false - if not.
	 */
	bool empty() const;

	/**
	 * Reserves more capacity for vector.
	 *
	 * @param  aCapacity new capacity of vector.
	 * @return mSize.
	 */
	void reserve(uint32_t aCapacity);

	/**
	 * Resizes the vector.
	 *
	 * @param  aSize new size of vector.
	 * @return mSize.
	 */
	void resize(uint32_t aSize);

	/**
	 * Returns pointer to the first element.
	 *
	 * @param  none.
	 * @return pointer to first element of vector.
	 */
	iterator begin();

	/**
	 * Returns pointer to the last element.
	 *
	 * @param  none.
	 * @return pointer to last element of vector.
	 */
	iterator end();

	/**
	 * Returns first element.
	 *
	 * @param  none.
	 * @return first element of vector.
	 */
	T& front();

	/**
	 * Returns last element.
	 *
	 * @param  none.
	 * @return last element of vector.
	 */
	T& back();

	/**
	 * Adds element to the back of the vector.
	 *
	 * @param  aElement element to be added.
	 * @return none.
	 */
	void push_back(const T& aElement);

	/**
	 * Removes element from the back of the vector.
	 *
	 * @param  none.
	 * @return none.
	 */
	void pop_back();

	/**
	 * Square brackets operator to return element of given index.
	 *
	 * @param  aIndex index of the element to be returned.
	 * @return element under aIndex.
	 * @overload
	 */
	T& operator[](uint32_t aIndex);

	/**
	 * Assignment operator.
	 *
	 * @param  aVector vector which we assign.
	 * @return pointer do vector to which we assigned aVector.
	 * @overload
	 */
	Vector<T>& operator=(const Vector<T>& aVector);

	/**
	 * Clears vector.
	 *
	 * @param  none.
	 * @return none.
	 */
	void clear();

private:
	uint32_t mSize;
	uint32_t mCapacity;
	T* mBuffer;
};

#endif