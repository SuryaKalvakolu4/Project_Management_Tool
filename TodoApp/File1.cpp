#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

int main() {
    std::vector<Task> tasks;
    char choice;

    do {
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. View Tasks\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case '1':
                {
                    Task newTask;
                    std::cout << "Enter task description: ";
                    std::cin >> newTask.description;
                    newTask.completed = false;
                    tasks.push_back(newTask);
                }
                break;
            case '2':
                {
                    int index;
                    std::cout << "Enter index of task to mark as completed: ";
                    std::cin >> index;
                    if (index >= 0 && index < tasks.size())
                        tasks[index].completed = true;
                    else
                        std::cout << "Invalid index!\n";
                }
                break;
            case '3':
                {
                    int index;
                    std::cout << "Enter index of task to delete: ";
                    std::cin >> index;
                    if (index >= 0 && index < tasks.size())
                        tasks.erase(tasks.begin() + index);
                    else
                        std::cout << "Invalid index!\n";
                }
                break;
            case '4':
                {
                    std::cout << "Tasks:\n";
                    for (size_t i = 0; i < tasks.size(); ++i) {
                        std::cout << i << ". ";
                        if (tasks[i].completed)
                            std::cout << "[X] ";
                        else
                            std::cout << "[ ] ";
                        std::cout << tasks[i].description << std::endl;
                    }
                }
                break;
            case '5':
                std::cout << "Exiting program...";
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != '5');

    return 0;
}

