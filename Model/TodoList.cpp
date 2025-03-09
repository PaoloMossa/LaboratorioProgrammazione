//
// Created by Paolo Mossa on 08/03/25.
//

#include "TodoList.h"

bool TodoList::checkIndex(int index) {
    bool valid = false;
    if (index < 0 || index >= tasks.size())
        valid = true;
    return valid;
}

void TodoList::removeTask(int index) {
    if (index >= 0 && index < tasks.size())
        tasks.erase(tasks.begin() + index);
    notify();
}

void TodoList::modifyTask(int index, Task *newTask) {
    if (index < 0 || index >= tasks.size() || newTask == nullptr)
        return;
    tasks[index] = newTask;
    notify();
}

void TodoList::completeTask(int index) {
    if (index >= 0 && index < tasks.size())
        tasks[index]->set_completed(true);
    notify();
}

std::vector<Task *> TodoList::get_tasks() const {
    return tasks;
}

void TodoList::notify() {
    for (auto observer : observers)
        observer->update();
}

void TodoList::attach(Observer *o) {
    if (std::find(observers.begin(), observers.end(), o) == observers.end()) {
        observers.push_back(o);
    }
}

void TodoList::detach(Observer *o) {
    observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}

std::string TodoList::getName() const {
    return name;
}