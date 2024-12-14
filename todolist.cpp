 #include <iostream>
#include <vector>
#include <string>

using namespace std;

 
struct Task {
    string description;
    bool isCompleted;
};

 
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void completeTask(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                completeTask(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << " Goodbye!" << endl;
                break;
            default:
                cout << " Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

 
void displayMenu() {
    cout << "\n--- To-Do List Menu ---" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}
 
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    cin.ignore();  
    getline(cin, newTask.description);
    newTask.isCompleted = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

 
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display!" << endl;
        return;
    }

    cout << "\n--- To-Do List ---" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].isCompleted) {
            cout << " [Completed]";
        }
        cout << endl;
    }
}

 
void completeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to complete!" << endl;
        return;
    }

    int taskIndex;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskIndex;

    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks[taskIndex - 1].isCompleted = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

 
void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove!" << endl;
        return;
    }

    int taskIndex;
    cout << "Enter the task number to remove: ";
    cin >> taskIndex;

    if (taskIndex > 0 && taskIndex <= tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}
