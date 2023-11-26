#ifndef H_Calendar
#define H_Calendar

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include "Task.h"
#include "taskList.h"

using namespace std;

class Calendar
{
public:
    //Function to add task to a task list of a specified date.
    void addTaskOnDate(const Task&);
    //Function to remove task on a task list of a specified date.
    void removeTaskOnDate(int,int,int);
    //Function to display the task list of a specified date.
    void displayTasksOnDate(int,int);
    //Function to clear the task list of a specified date.
    void clearTasksOnDate(int,int);
    //Function to copy the tasks listed on a task list of a specified date to another specified date.
    void copyTasksOnDate(int,int,int,int);
    //Function to move a task on the task list to the top of the list.
    void moveTaskToTop(int,int,int);
    //Function to move a task on the task list to the bottom of the list.
    void moveTaskToBottom(int,int,int);
    //Function to move task up one step in the list.
    void moveTaskUp(int,int,int);
    //Function to move task down one step in the list.
    void moveTaskDown(int,int,int);
    //Function to save all tasks of a specified date in a text(save) file.
    void saveTask(const Task&); 
    //Function to load all saved tasks from their respective text(save) file.
    void loadSavedTasks(); 
    //Function to return the year of the calendar.
    int getYear();
    //Constructor to initialize the year of the calendar.
    Calendar(int _year = 0000);
private:
    int year; //Variable to hold the year of the calendar.
    //int maxNumOfFiles = 365; //Variable to hold the max number of files in the array-list of text(save) file names.
    int length = 0; //Variable to keep track of the length of the array-list of text(save) file names.
    string fileNames[365]; //Array-list of text(save) file names. 
    taskList calendar[13][32]; //2D Array of type taskList to store the task list of each month and day in the calendar.
    void saveChanges(int,int,taskList); //Function to save changes to the task list.
};

//Including implementation temporarily

void Calendar::addTaskOnDate(const Task& task)
{
    calendar[task.getMonth()][task.getDay()].addTask(task);
}
void Calendar::removeTaskOnDate(int month, int day, int n)
{   
    if(calendar[month][day].length() == 0)
        cout << "Cannot remove from an empty task list." << endl << endl;
    else if(n <= 0 || n > calendar[month][day].length())
    {
        cout << "Input out of bounds." << endl;
    }
    else
    {
        calendar[month][day].removeTask(n);
        saveChanges(month, day, calendar[month][day]);
    }              
}
void Calendar::displayTasksOnDate(int month, int day)
{
    cout << "Task List on " << month << "/" << day << "/" << year << endl << endl;
    calendar[month][day].print();
}
void Calendar::clearTasksOnDate(int month, int day)
{
    calendar[month][day].clearTasks();
    saveChanges(month, day, calendar[month][day]);
}
void Calendar::copyTasksOnDate(int month, int day, int otherMonth, int otherDay)
{
    calendar[month][day].copyTasks(calendar[otherMonth][otherDay]);
    saveChanges(month, day, calendar[month][day]);
}
void Calendar::moveTaskToTop(int month, int day, int n)
{
    if(calendar[month][day].length() == 0)
        cout << "Cannot move in an empty task list." << endl << endl;
    else if(n <= 0 || n > calendar[month][day].length())
    {
        cout << "Input out of bounds." << endl;
    }
    else
    {
        calendar[month][day].moveTaskToFront(n);
        saveChanges(month, day, calendar[month][day]);
    }
}
void Calendar::moveTaskToBottom(int month, int day, int n)
{
    if(calendar[month][day].length() == 0)
        cout << "Cannot move in an empty task list." << endl << endl;
    else if(n <= 0 || n > calendar[month][day].length())
    {
        cout << "Input out of bounds." << endl;
    }
    else
    {
        calendar[month][day].moveTaskToBack(n);
        saveChanges(month, day, calendar[month][day]);
    }
}
void Calendar::moveTaskUp(int month, int day, int n)
{
    if(calendar[month][day].length() == 0)
        cout << "Cannot move in an empty task list." << endl << endl;
    else if(n <= 0 || n > calendar[month][day].length())
    {
        cout << "Input out of bounds." << endl;
    }
    else
    {
        calendar[month][day].moveTaskUp(n);
        saveChanges(month, day, calendar[month][day]);
    }
}
void Calendar::moveTaskDown(int month, int day, int n)
{
    if(calendar[month][day].length() == 0)
        cout << "Cannot move in an empty task list." << endl << endl;
    else if(n <= 0 || n > calendar[month][day].length())
    {
        cout << "Input out of bounds." << endl;
    }
    else
    {
        calendar[month][day].moveTaskDown(n);
        saveChanges(month, day, calendar[month][day]);
    }
}
void Calendar::saveTask(const Task& task)
{
    int day, month, startHr, startMin, endHr, endMin; //Task info variables declaration.
    //Text(save) file name processing stage.
    string fileName;
    bool found = false;
    day = task.getDay();
    month = task.getMonth();
    fileName = to_string(month) + "." + to_string(day) + ".txt";
    ofstream fout("save_files/" + fileName, ios::app); //ofstream variable declaration, opening and appending output to text(save) file.
    //Searching the name of the text(save) file in the array-list. 
    for(int i = 0; i < length; i++)
    {
        if(fileNames[i] == fileName)
            found = true;
    }
    //Inserts the name of the text(save) file in the array-list and the list of text(save) file names 
    //if it is not available.
    if(!found)
    {
        fileNames[length] = fileName;
        ofstream f_out("file_names.txt", ios::app);
        f_out << fileName << endl;
        f_out.close();
        length++;
        fout << month << " " << day << endl << endl;
        //This should only be written once at the top of the text(save) file 
        //when the text(save) file for a specified date is empty.
    }
    //Saving tasks info in the text file.
    task.getStartTime(startHr, startMin);
    task.getEndTime(endHr, endMin);
    fout << startHr << " " << startMin << " " << endHr << " " << endMin << endl;
    fout << task.getTitle() << endl;
    fout << task.getDesc() << endl << endl;
    fout.close();
}
void Calendar::saveChanges(int month, int day, taskList list)
{
    ofstream fout; //ofstream variable declaration
    Task task; //Task variable declaration and initialization.
    int startHr, startMin, endHr, endMin; //Task info variables declaration.
    //Text(save) file name processing stage.
    string fileName;
    bool found = false;
    fileName = to_string(month) + "." + to_string(day) + ".txt";
    fout.open("save_files/" + fileName);
    //Searching the name of the text(save) file in the array-list. 
    for(int i = 0; i < length; i++)
    {
        if(fileNames[i] == fileName)
            found = true;
    }
    if(found)
    {
        fout << month << " " << day << endl << endl;
        while(!list.isEmptyList())
        {
            task = list.front();
            //Saving changes to the task list in the text file.
            task.setTaskDate(month, day);
            task.getStartTime(startHr, startMin);
            task.getEndTime(endHr, endMin);
            fout << startHr << " " << startMin << " " << endHr << " " << endMin << endl;
            fout << task.getTitle() << endl;
            fout << task.getDesc() << endl << endl;
            list.deleteNode(1);
        }
    }
    else
    {
        while(!list.isEmptyList())
        {
            task = list.front();
            task.setTaskDate(month, day);
            saveTask(task);
            list.deleteNode(1);
        }
    }
    fout.close();
}
void Calendar::loadSavedTasks()
{
    ifstream fin, f_in; //ifstream variables declaration.
    Task task; //Task variable declaration.
    //Task info variables declaration.
    int day, month, startHr, startMin, endHr, endMin;
    string title, description; 
    //Loading saved text(save) file names from the list of text(save) file names.
    int i = 0;
    f_in.open("file_names.txt");
    f_in >> fileNames[i];
    i++;
    while(!f_in.eof())
    {
        f_in >> fileNames[i];
        i++;
        length++;
    }
    f_in.close();
    //Loading saved tasks from text(save) files.
    for(int j = 0; j < length; j++)
    {
        fin.open("save_files/" + fileNames[j]);
        fin >> month >> day;
        task.setTaskDate(month, day);
        fin >> startHr >> startMin >> endHr >> endMin;
        while(fin)
        {
            fin.ignore(1,'\n');
            getline(fin, title);
            getline(fin, description);
            task.setStartTime(startHr, startMin);
            task.setEndTime(endHr, endMin);
            task.setTaskInfo(title, description);
            addTaskOnDate(task);

            fin >> startHr >> startMin >> endHr >> endMin;
        }
        fin.close();
    }
}
int Calendar::getYear()
{
    return year; //Returns the year of the calendar.
}
Calendar::Calendar(int _year)
{
    year = _year; //Initializes the year of the calendar.
}

#endif
