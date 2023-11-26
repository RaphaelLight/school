#ifndef H_linkedListIterator
#define H_linkedListIterator

using namespace std;

//Definition of the node
template <class Type>
struct node
{
    Type info;
    node<Type> *link;
};
template <class Type>
class linkedListIterator
{
public:
    linkedListIterator();
    //Default constructor
    //Postcondition: current = nullptr;
    linkedListIterator(node<Type> *ptr);
    //Constructor with a parameter.
    //Postcondition: current = ptr;
    Type operator*();
    //Function to overload the dereferencing operator *.
    //Postcondition: Returns the info contained in the node.
    linkedListIterator<Type> operator++();
    //Overload the pre-increment operator.
    //Postcondition: The iterator is advanced to the next node.
    bool operator==(const linkedListIterator<Type>& right) const;
    //Overload the equality operator.
    //Postcondition: Returns true if this iterator is equal to the iterator specified by right, otherwise it returns false.
    bool operator!=(const linkedListIterator<Type>& right) const;
    //Overload the not equal to operator.
    //Postcondition: Returns true if this iterator is not equal to the iterator specified by right, otherwise it returns false.
private:
    node<Type> *current; //pointer to point to the current node in the linked list
};
#endif

//Including implementation temporarily

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
    current = nullptr;
}
template <class Type>
linkedListIterator<Type>::linkedListIterator(node<Type> *ptr)
{
    current = ptr;
}
template <class Type>
Type linkedListIterator<Type>::operator*()
{
    return current->info;
}
template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
    current = current->link;
    return *this;
}
template <class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
    return (current == right.current);
}
template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
    return (current != right.current);
}