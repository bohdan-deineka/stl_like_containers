#include <linked_list.hpp>
#include <algorithm>

/**
 * Refer to method declaration for details.
 */
template <class T>
LinkedList<T>::LinkedList()
{
    mHead = nullptr;
    mSize = 0;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& aLinkedList)
{
    Node<T>* currElem = nullptr;
    Node<T>* nextElem = nullptr;

    if (aLinkedList.mHead == nullptr)
    {
        mHead = nullptr;
    }

    else
    {
        mHead = new Node<T>;
        mHead->mData = aLinkedList.mHead->mData;

        currElem = mHead;
        nextElem = aLinkedList.mHead->mNext;

        mSize++;

        while (nextElem)
        {
            currElem->mNext = new Node<T>;
            currElem = currElem->mNext;

            currElem->mData = nextElem->mData;
            nextElem = nextElem->mNext;

            mSize++;
        }

        currElem->mNext = nullptr;
    }
}

/**
 * Refer to method declaration for details.
 */
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T>* killer = mHead;
    Node<T>* temp = nullptr;

    while (killer != nullptr)
    {
        temp = killer->mNext;
        delete killer;
        killer = killer->mNext;

        mSize--;
    }
}

/**
 * Refer to method declaration for details.
 */
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& aLinkedList)
{
    LinkedList<T> temp(aLinkedList);
    std::swap(temp.mHead, mHead);
    return *this;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
uint32_t LinkedList<T>::size() const
{
    return mSize;
}

/**
 * Refer to method declaration for details.
 */
template <class T>
bool LinkedList<T>::empty() const
{
    return mSize == 0;
}