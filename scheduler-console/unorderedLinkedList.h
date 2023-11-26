#ifndef H_unorderedLinkedList
#define H_unorderedLinkedList

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedList<Type>
{
public:
    bool search(const Type& searchItem) const;
    //Function to determine whether searchItem is in the list.
    //Postcondition: Returns true if searchItem is in the list, otherwise the value false is returned.
    void insertFirst(const Type& newItem);
    //Function to insert newItem at the beginning of the list.
    //Postcondition: first points to the new list, newItem is inserted at the beginning of the list,
    //last points to the last node in the list, and count is incremented by 1.
    void insertLast(const Type& newItem);
    //Function to insert newItem at the end of the list.
    //Postcondition: first points to the new list, newItem is inserted at the end of the list, 
    //last points to the last node in the list, and count is incremented by 1.
    void deleteNode(int n);
    //Function to delete deleteItem from the list.
    //Postcondition: If found, the node containing deleteItem is deleted from the list. 
    //first points to the first node, last points to the last node of the updated list, and count is decremented by 1.
};
#endif

//Including implementation temporarily

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    node<Type> *current; //pointer to traverse the list
    bool found = false;
    current = linkedList<Type>::first; //set current to point to the first node in the list
    while (current != nullptr && !found) //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to the next node
    return found;
}//end search
template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    node<Type> *newNode; //pointer to create the new node
    newNode = new node<Type>; //create the new node
    newNode->info = newItem; //store the new item in the node
    newNode->link = linkedList<Type>::first; //insert newNode before first
    linkedList<Type>::first = newNode; //make first point to the actual first node
    linkedList<Type>::count++; //increment count
    if (linkedList<Type>::last == nullptr) //if the list was empty, newNode is also the last node in the list
        linkedList<Type>::last = newNode;
}//end insertFirst
template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    node<Type> *newNode; //pointer to create the new node
    newNode = new node<Type>; //create the new node
    newNode->info = newItem; //store the new item in the node
    newNode->link = nullptr; //set the link field of newNode to nullptr
    if (linkedList<Type>::first == nullptr) //if the list is empty, newNode is both the first and last node
    {
        linkedList<Type>::first = newNode;
        linkedList<Type>::last = newNode;
        linkedList<Type>::count++; //increment count
    }
    else //the list is not empty, insert newNode after last
    {
        linkedList<Type>::last->link = newNode; //insert newNode after last
        linkedList<Type>::last = newNode; //make last point to the actual last node in the list
        linkedList<Type>::count++; //increment count
    }
}//end insertLast
template <class Type>
void unorderedLinkedList<Type>::deleteNode(int n)
{
    node<Type> *current; //pointer to traverse the list
    node<Type> *trailCurrent; //pointer just before current
    if (linkedList<Type>::first == nullptr) //Case 1; the list is empty.
        cout << "Cannot remove from an empty list." << endl;
    else
    {
        if (n == 1) //Case 2
        {
            current = linkedList<Type>::first;
            linkedList<Type>::first = linkedList<Type>::first->link;
            linkedList<Type>::count--;
            if (linkedList<Type>::first == nullptr) //the list has only one node
                linkedList<Type>::last = nullptr;
            delete current;
        }
        else //search the list for the node with the given info
        {
            current = linkedList<Type>::first; //set current to point to the second node
            for(int i = 1; i < n; i++)
            {
                trailCurrent = current;
                current = current->link;
            }
            trailCurrent->link = current->link;
            linkedList<Type>::count--;
            if (linkedList<Type>::last == current) //node to be deleted was the last node
                linkedList<Type>::last = trailCurrent; //update the value of last
            delete current; //delete the node from the list
        }//end else
    }//end else
}//end deleteNode

