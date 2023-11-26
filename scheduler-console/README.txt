Scheduler Console
Core Dumpers™

This program makes a record of your daily tasks.

HOW IT WORKS?

--COMPONENTS--

The Scheduler has three main components:

1. Task (Object)
2. Task List
3. Calendar

All of these components has been implemented as a class along with the appropriate operations
on them. 

The task is basically treated as a data type specifically designed for storing information
related to a task.

The task list is basically an unordered linked list which stores task (objects/variables).

The calendar is made up of a 2-Dimensional array of type task list and with a size of 
12 x 31 which basically means that it stores a task list for each day and each month of
a year. 

For example. 

Let month and day be variables of type int. 

int month, day;

And let calendar be a two dimensional array of type 'taskList'.

taskList calendar[12][31];
Note: This is legal because the task list is implemented as a class. And classes are basically
      user-defined data types.

Now, when the user inputs a date of month = 10 and day = 8, the program accesses the
task list on that date by using the values of month and day as indexes to the calendar.

calendar[month][day];

And since the calendar is of type 'taskList', we can access the operations related to a task list
like adding a task on a list, removing a task, etc. via the member access operator.

calendar[month][day].addTask(task);

Since the calendar 2D array is a private member of the class Calendar, it cannot be accessed
directly outside the class. It can only be accessed through the member functions of the Calendar
class.

--USER INPUT--

Program Procedures:

When the user adds a task to a task list of a specified date, the program creates a text file
named after the specified date (if it doesn't exist yet) then writes the info of the added task 
on the text file to save it. 

The format of the text(save) file is as follows:

10.4.txt <--- text(save) file name

10 4 <--- date of the task list month and day respectively (Should only be written once).

12 30 6 45 <--- start time (hour/min) and end time (hour/min) of the task respectively.
Play Skyrim <--- task title
Defeat Alduin and kill all thalmor scums. <--- task description

11 30 3 30
Random task
Just some random task.

And so on.

When the program is closed all of the tasks added to a task list is deallocated so
when the program is opened again it loads the saved tasks to the task lists by
accessing and reading all the text(save) files and adding its contents to the
corresponding task list.

For example, the program reads the text(save) file for the task list of 10/4/2022
by reading the contents of 10.4.txt and adding them to the task list of 10/4/2022.

All text(save) files are stored in a folder called "save_files".

Note: The user need not be concerned about the year of the calendar as it is
      automatically initialized by the program to the current year. So only
      the month and day are required for the date.

When the program is opened, it displays the task list for the current day just
above the menu of operations/actions.


Although this is the console version of the scheduler program, all of the planned
features and more have all been implemented so this is actually the complete core program itself.

The only feature left to be implemented is the GUI.

REMINDER: The project files in this repository may not include the "save_files" folder for some reason so you might as well add it.
