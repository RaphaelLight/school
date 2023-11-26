#ifndef H_Task
#define H_Task

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Task 
{   //Function to overload the ostream operator.
    friend ostream& operator<<(ostream&, const Task&); 
public:
    //Function to initialize the task date.
    void setTaskDate(int,int);
    //Function to initialize the task info.
    void setTaskInfo(string, string);
    //Function to initialize the starting time of a task.
    void setStartTime(int,int);
    //Function to initialize the ending time of a task.
    void setEndTime(int,int);
    //Function to return the start time of a task.
    void getStartTime(int&,int&) const;
    //Function to return the end time of a task.
    void getEndTime(int&,int&) const;
    //Function to return the day of the task.
    int getDay() const;
    //Function to return the month of the task.
    int getMonth() const;
    //Function to return the title of the task.
    string getTitle() const;
    //Function to return the description of the task.
    string getDesc() const; 
    //Function to overload the equality operator.
    bool operator==(const Task&) const;
    //Function to overload the unequality operator.
    bool operator!=(const Task&) const;
private:
    int day, month; //Variables to hold the date of the task.
    int sHour, sMinute, eHour, eMinute; //Variables to hold the start time and end time of a task.
    string taskTitle, description; //Variables to hold the task title and description.
};

//Including implementation temporarily

void Task::setTaskDate(int _month, int _day) 
{
    month = _month;
    day = _day;
}
void Task::setTaskInfo(string task_title, string _description)
{
    taskTitle = task_title;
    description = _description;
}
void Task::setStartTime(int hr, int min)
{
    if(0 <= hr && hr < 24)
        sHour = hr;
    else
        sHour = abs(hr) % 24;
    
    if(0 <= min && min < 60)
        sMinute = min;
    else
        sMinute = abs(min) % 60;
}
void Task::setEndTime(int hr, int min)
{
    if(0 <= hr && hr < 24)
        eHour = hr;
    else
        eHour = abs(hr) % 24;

    if(0 <= min && min < 60)
        eMinute = min;
    else
        eMinute = abs(min) % 60;
}
void Task::getStartTime(int& hr, int& min) const
{
    hr = sHour;
    min = sMinute;
}
void Task::getEndTime(int& hr, int& min) const
{
    hr = eHour;
    min = eMinute;
}
int Task::getDay() const
{ 
    return day;
}
int Task::getMonth() const
{ 
    return month; 
}
string Task::getTitle() const
{ 
    return taskTitle; 
}
string Task::getDesc() const
{ 
    return description; 
}
bool Task::operator==(const Task& task) const
{
    return (sHour == task.sHour && eHour == task.eHour && taskTitle == task.taskTitle && description == task.description);
}
bool Task::operator!=(const Task& task) const
{
    return (sHour != task.sHour || eHour != task.eHour || taskTitle != task.taskTitle || description != task.description);
}
ostream& operator<<(ostream& osObject, const Task& task)
{
    osObject << "Start-End: ";
    if (task.sHour < 10)
        osObject << '0';
    osObject << task.sHour << ':';
    if (task.sMinute < 10)
        osObject << '0';
    osObject << task.sMinute;
    osObject << "-";
    if (task.eHour < 10)
        osObject << '0';
    osObject << task.eHour << ':';
    if (task.eMinute < 10)
        osObject << '0';
    osObject << task.eMinute;
    osObject << endl;
    osObject << "Task: " << task.taskTitle << endl;
    osObject << "Description: " << task.description << endl;
    return osObject;
}

#endif