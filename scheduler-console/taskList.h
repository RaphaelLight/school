#ifndef H_taskList
#define H_taskList

#include <iostream>
#include "Task.h"
#include "unorderedLinkedList.h"

using namespace std;

class taskList : public unorderedLinkedList<Task> 
{
public:
    //Function to add task to the task list.
    void addTask(const Task &);
    //Function to remove task on the task list.
    void removeTask(int);
    //Function to clear tasks on the task list.
    void clearTasks();
    //Function to copy tasks of another list to this list.
    void copyTasks(const taskList&);
    //Function to move a task to the front of the list.
    void moveTaskToFront(int);
    //Function to move a task to the back of the list.
    void moveTaskToBack(int);
    //Function to move task up one step in the list.
    void moveTaskUp(int);
    //Function to move task down one step in the list.
    void moveTaskDown(int);
};

//Including implementation temporarily

void taskList::addTask(const Task& task) 
{ 
    insertLast(task); 
    //Calls the insertLast function from the unordered linked list class
    //to insert a task at the end of the list.
}
void taskList::removeTask(int n)
{ 
    deleteNode(n);
    //Calls the deleteNode function from the unordered linked list class
    //to delete a task from the list.
}
void taskList::clearTasks() 
{ 
    destroyList();
    //Calls the function destroyList in the unordered linked list class
    //to delete all tasks from the list.
}
void taskList::copyTasks(const taskList &otherList) 
{
    linkedList::copyList(otherList);
    //Calls the protected function copyList in the linked list class
    //to copy all tasks from another list to this list.
}
void taskList::moveTaskToFront(int n)
{
    moveToFront(n);
    //Calls the moveToFront function from the linked list class
    //to move a task to the front of the list.
}
void taskList::moveTaskToBack(int n)
{
    moveToBack(n);
    //Calls the moveToBack function from the linked list class
    //to move a task to the back of the list.
}
void taskList::moveTaskUp(int n)
{
    moveForward(n);
    //Calls the moveForward function from the linked list class
    //to move a task one step up the list.
}
void taskList::moveTaskDown(int n)
{
    moveBackward(n);
    //Calls the moveBackward function from the linked list class
    //to move a task one step down the list.
}

#endif
