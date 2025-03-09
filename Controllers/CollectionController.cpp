//
// Created by Paolo Mossa on 09/03/25.
//

#include "CollectionController.h"

#include <iostream>

void CollectionController::addList(std::string &name) {
    TodoList* newList = new TodoList();
    newList->setName(name);
    collection->addList(newList);
}

void CollectionController::removeList(std::string &index) {
    try {
        int i;
        i = std::stoi(index);
        collection->removeList(i);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid index: " << index << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << "Index out of range: " << index << std::endl;
    }

}
