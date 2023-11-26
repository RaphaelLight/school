//Core Dumpers
//Scheduler Console 
//This program makes a record of your daily tasks.
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Task.h"
#include "Calendar.h"

using namespace std;

//Function to add task on a task list of a specified date.
//Precondition: Task date(Month/Day), start time(Hour/Min), end time(Hour/Min), and info(Title & Description).
//Postcondition: Adds the task to the task list and saves it in a text file. 
//If user input is invalid, the function terminates.
int setTask(Calendar&);

int main()
{
    //Displays the task list of the current day.
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    Calendar calendar((tPtr->tm_year)+1900); //Initializes the calendar to the current year.
    calendar.loadSavedTasks(); //Loads the saved tasks.
    calendar.displayTasksOnDate((tPtr->tm_mon)+1, (tPtr->tm_mday)); //Displays the task list for the current day.
    cout << endl;

    //Actions/operations menu for the task list.
    cout << "Press A to add task on the list." << endl;
    cout << "Press R to remove task on the list." << endl;
    cout << "Press D to display tasks on the list." << endl;
    cout << "Press C to copy tasks to another list." << endl;
    cout << "Press T to move task to the top of the list." << endl;
    cout << "Press B to move task to the bottom of the list." << endl;
    cout << "Press W to move task up." << endl;
    cout << "Press S to move task down." << endl;
    cout << "Press Z to clear tasks." << endl;
    cout << "Press X to close the program." << endl << endl;
    cout << "Press M to display actions menu." << endl << endl;

    int day, month, otherDay, otherMonth, n; //Variables to hold user input.
    string cat; //Catches trailing characters on key input. I can't name it catch so I named it cat ฅ^•ﻌ•^ฅ.
    char key; //Variable to get key input by the user for a specified action.
    while(true)
    {
        cout << "Press key for actions: ";
        cin >> key;
        getline(cin, cat); //Gets the trailing characters on the user key input in case the user inputs a string.
        cout << endl << endl;
        if(cat == "") //If there no trailing characters on key input, then proceed with the specified operation.
        {
            switch(toupper(key))
            {
            case 'A':
                while(true)
                {
                    if(setTask(calendar) == 1)
                        continue;
                    else
                        break;
                }
                break;
            case 'R':
                while(true)
                {
                    cout << "Date (Month/Day): " << endl;
                    cin >> month >> day;
                    cout << endl;
                    if(month <= 0 || month > 12 || day <= 0 || day > 31) //DATE EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Dates. Try Again." << endl << endl;
                        continue;
                    }
                    cout << "Position (num): ";
                    cin >> n;
                    cout << endl;
                    if(!cin) //GENERAL INPUT EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input. Try Again." << endl << endl;
                        continue;
                    }
                    calendar.removeTaskOnDate(month, day, n);
                    break;
                }
                break;
            case 'D':
                while(true)
                {
                    cout << "Date (Month/Day): " << endl;
                    cin >> month >> day;
                    cout << endl;
                    if(month <= 0 || month > 12 || day <= 0 || day > 31) //DATE EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Dates. Try Again." << endl << endl;
                        continue;
                    }
                    calendar.displayTasksOnDate(month, day);
                    break;
                }
                break;
            case 'C':
                while(true)
                {
                    cout << "Date of task list to be copied (Month/Day): " << endl;
                    cin >> otherMonth >> otherDay;
                    cout << endl;
                    if(otherMonth <= 0 || otherMonth > 12 || otherDay <= 0 || otherDay > 31) //DATE EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Dates. Try Again." << endl << endl;
                        continue;
                    }
                    cout << "Date to copy it into (Month/Day): " << endl;
                    cin >> month >> day;
                    cout << endl;
                    if(month <= 0 || month > 12 || day <= 0 || day > 31) //DATE EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Dates. Try Again." << endl << endl;
                        continue;
                    }
                    calendar.copyTasksOnDate(month, day, otherMonth, otherDay);
                    break;
                }
                break;
            case 'T':
                while(true)
                {
                    cout << "Date (Month/Day): " << endl;
                    cin >> month >> day;
                    cout << endl;
                    if(month <= 0 || month > 12 || day <= 0 || day > 31) //DATE EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Dates. Try Again." << endl << endl;
                        continue;
                    }
                    cout << "Position (num): ";
                    cin >> n;
                    cout << endl;
                    if(!cin) //GENERAL INPUT EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input. Try Again." << endl << endl;
                        continue;
                    }
                    calendar.moveTaskToTop(month, day, n);
                    break;
                }
                break;
            case 'B':
                while(true)
                {
                    cout << "Date (Month/Day): " << endl;
                    cin >> month >> day;
                    cout << endl;
                    if(month <= 0 || month > 12 || day <= 0 || day > 31)
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Dates. Try Again." << endl << endl;
                        continue;
                    }
                    cout << "Position (num): ";
                    cin >> n;
                    cout << endl;
                    if(!cin) //EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input. Try Again." << endl << endl;
                        continue;
                    }
                    calendar.moveTaskToBottom(month, day, n);
                    break;
                }
                break;
            case 'W':
                while(true)
                {
                    cout << "Date (Month/Day): " << endl;
                    cin >> month >> day;
                    cout << endl;
                    if(month <= 0 || month > 12 || day <= 0 || day > 31) //DATE EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Dates. Try Again." << endl << endl;
                        continue;
                    }
                    cout << "Position (num): ";
                    cin >> n;
                    cout << endl;
                    if(!cin) //GENERAL INPUT EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input. Try Again." << endl << endl;
                        continue;
                    }
                    calendar.moveTaskUp(month, day, n);
                    break;
                }
                break;
            case 'S':
                while(true)
                {
                    cout << "Date (Month/Day): " << endl;
                    cin >> month >> day;
                    cout << endl;
                    if(month <= 0 || month > 12 || day <= 0 || day > 31) //DATE EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Dates. Try Again." << endl << endl;
                        continue;
                    }
                    cout << "Position (num): ";
                    cin >> n;
                    cout << endl;
                    if(!cin) //GENERAL INPUT EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input. Try Again." << endl << endl;
                        continue;
                    }
                    calendar.moveTaskDown(month, day, n);
                    break;
                }
                break;
            case 'Z':
                while(true)
                {
                    cout << "Date (Month/Day): " << endl;
                    cin >> month >> day;
                    cout << endl;
                    if(month <= 0 || month > 12 || day <= 0 || day > 31) //DATE EXCEPTION HANDLER
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Dates. Try Again." << endl << endl;
                        continue;
                    }
                    calendar.clearTasksOnDate(month, day);
                    break;
                }
                break;
            case 'M':
                cout << "Press A to add task on the list." << endl;
                cout << "Press R to remove task on the list." << endl;
                cout << "Press D to display tasks on the list." << endl;
                cout << "Press C to copy tasks to another list." << endl;
                cout << "Press T to move task to the top of the list." << endl;
                cout << "Press B to move task to the bottom of the list." << endl;
                cout << "Press W to move task up." << endl;
                cout << "Press S to move task down." << endl;
                cout << "Press Z to clear tasks." << endl;
                cout << "Press X to close the program." << endl << endl;
                cout << "Press M to display actions menu." << endl;
                break;
            case 'X':
                return 1;
            default:
                cout << "Invalid Input. Try Again." << endl << endl;
                break;
            }
            cout << endl;
        }
        else
        {
            cout << "Invalid Input. Try Again." << endl << endl;
            continue;
        }
    }
    return 0;
}
int setTask(Calendar& calendar)
{
    Task task;
    int day, month, startHr, startMin, endHr, endMin;
    string title, description;
    
    cout << "Date (Month/Day): " << endl;
    cin >> month >> day;
    if(month <= 0 || month > 12 || day <= 0 || day > 31) //DATE EXCEPTION HANDLER
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Dates. Try Again." << endl << endl;
        return 1;
    }
    cout << "Start time (Hour/Min): " << endl;
    cin >> startHr >> startMin;
    cout << "End time (Hour/Min): " << endl;
    cin >> endHr >> endMin;
    if(!cin) //GENERAL INPUT EXCEPTION HANDLER
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid Input. Try Again." << endl << endl;
        return 1;
    }
    cin.ignore(1,'\n');
    cout << "Task title: ";
    getline(cin, title);
    cout << "Description: ";
    getline(cin, description);
    cout << endl;
    task.setTaskDate(month, day);
    task.setStartTime(startHr, startMin);
    task.setEndTime(endHr, endMin);
    task.setTaskInfo(title, description);
    calendar.addTaskOnDate(task);
    calendar.saveTask(task);
    return 0;
}


