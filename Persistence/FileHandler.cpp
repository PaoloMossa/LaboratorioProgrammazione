//
// Created by Paolo Mossa on 09/03/25.
//

#include "FileHandler.h"

#include <fstream>
#include <iostream>

void FileHandler::save(TodoListCollection *collection) {
    std::vector<TodoList*> lists = collection->get_lists();
    std::ofstream file(filename);
    if (file.is_open()) {
        for (auto list : lists) {
            file << list->getName() << std::endl;
            for (auto task : list->get_tasks()) {
                file << task->get_description() << std::endl;
                file << task->is_completed() << std::endl;
                file << task->is_important() << std::endl;
            }
            file << "----" << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file" << std::endl;
    }
}

TodoListCollection * FileHandler::load() {
    TodoListCollection* result = new TodoListCollection();
    std::vector<TodoList*> todo_lists;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            TodoList* list = new TodoList();
            list->setName(line);
            while (std::getline(file, line) && line != "----") {
                Task* task = new Task();
                task->set_description(line);
                if (std::getline(file, line)) {
                    try {
                        task->set_completed(std::stoi(line));
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid data for task completion status: " << line << std::endl;
                        delete task;
                        continue;
                    }
                }

                if (std::getline(file, line)) {
                    try {
                        task->set_important(std::stoi(line));
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Invalid data for task importance status: " << line << std::endl;
                        delete task;
                        continue;
                    }
                }
                list->addTask(task);
                //file >> line;
            }
            todo_lists.push_back(list);
        }
    } else {
        std::cerr << "Error opening file for loading." << std::endl;
    }
    file.close();
    result->addAllList(todo_lists);
    return result;
}
