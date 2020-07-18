#include "vector.hpp"

/**
 * Refer to method declaration for details.
 */
template <class T>
Vector<T>::Vector()
{
	mSize = 0;
	mCapacity = 0;	
	mBuffer = 0;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
Vector<T>::Vector(uint32_t aSize)
{
	mSize = aSize;
	mCapacity = aSize;	
	mBuffer = new T[aSize];
}

/**
 * Refer to method declaration for details.
 */
template <class T>
Vector<T>::Vector(uint32_t aSize, const T& aInitial)
{
	mSize = aSize;
	mCapacity = aSize;
	mBuffer = new T[aSize];

	for (uint32_t i = 0; i < mSize; i++)
	{
		mBuffer[i] = aInitial;
	}
}

/**
 * Refer to method declaration for details.
 */
template <class T>
Vector<T>::Vector(const Vector<T>& aVector)
{
	mSize = aVector.mSize;
	mCapacity = aVector.mCapacity;
	mBuffer = new T[mSize];

	for (uint32_t i = 0; i < mSize; i++)
	{
		mBuffer[i] = aVector.mBuffer[i];
	}
}

/**
 * Refer to method declaration for details.
 */
template <class T>
Vector<T>::~Vector()
{
	delete[] mBuffer;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
void Vector<T>::push_back(const T& aElement)
{
	if (mSize >= mCapacity)
	{
		reserve(mCapacity + 5);
	}
	mBuffer[mSize++] = aElement;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
void Vector<T>::pop_back()
{
	mSize--;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
void Vector<T>::reserve(uint32_t aCapacity)
{
	if (mBuffer == 0)
	{
		mSize = 0;
		mCapacity = 0;
	}

	T* newBuffer = new T[aCapacity];
	uint32_t newBufferSize = aCapacity < mSize ? aCapacity : mSize;

	for (uint32_t i = 0; i < newBufferSize; i++)
	{
		newBuffer[i] = mBuffer[i];
	}

	mCapacity = aCapacity;
	delete[] mBuffer;
	mBuffer = newBuffer;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
void Vector<T>::resize(uint32_t aSize)
{
	reserve(aSize);
	mSize = aSize;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& aVector)
{
	delete[] mBuffer;
	mSize = aVector.mSize;
	mCapacity = aVector.mCapacity;
	mBuffer = new T[mSize];

	for (uint32_t i = 0; i < mSize; i++)
	{
		mBuffer[i] = aVector.mBuffer[i];
	}
	return *this;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
T& Vector<T>::operator[](uint32_t aIndex)
{
	return mBuffer[aIndex];
}

/**
 * Refer to method declaration for details.
 */
template <class T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return mBuffer;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
typename Vector<T>::iterator Vector<T>::end()
{
	return mBuffer + size();
}

/**
 * Refer to method declaration for details.
 */
template <class T>
T& Vector<T>::front()
{
	return mBuffer[0];
}

/**
 * Refer to method declaration for details.
 */
template <class T>
T& Vector<T>::back()
{
	return mBuffer[mSize - 1];
}

/**
 * Refer to method declaration for details.
 */
template <class T>
void Vector<T>::clear()
{
	mSize = 0;
	mCapacity = 0;
	mBuffer = 0;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
uint32_t Vector<T>::size() const
{
	return mSize;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
uint32_t Vector<T>::capacity() const
{
	return mCapacity;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
bool Vector<T>::empty() const
{
	return mSize = 0;
}