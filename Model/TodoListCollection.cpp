//
// Created by Paolo Mossa on 09/03/25.
//

#include "TodoListCollection.h"

void TodoListCollection::attach(Observer *o) {
    observers.push_back(o);
    for (auto list : lists)
        list->attach(o);
}

void TodoListCollection::detach(Observer *o) {
    observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}

void TodoListCollection::notify() {
    for (auto observer : observers)
        observer->update();
}

void TodoListCollection::forwardObservers(TodoList *list) const {
    for (auto observer : observers)
        list->attach(observer);
}

std::vector<TodoList *> TodoListCollection::get_lists() const {
    return lists;
}

int TodoListCollection::size() {
    return lists.size();
}

void TodoListCollection::addList(TodoList *newList) {
    lists.push_back(newList);
    forwardObservers(newList);
    notify();
}

void TodoListCollection::addAllList(const std::vector<TodoList *>& lists) {
    for (auto list : lists)
        addList(list);
    notify();
}

void TodoListCollection::removeList(int index) {
    if (index >= 0 && index < lists.size())
        lists.erase(lists.begin() + index);
    notify();
}
