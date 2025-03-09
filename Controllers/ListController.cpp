//
// Created by Paolo Mossa on 08/03/25.
//

#include "ListController.h"

void ListController::addTaskToList(std::string &description, bool important) {
    Task* newTask = new Task();
    newTask->set_description(description);
    newTask->set_important(important);
    list->addTask(newTask);
}

void ListController::removeFromList(int index) {
    list->removeTask(index);
}

void ListController::modifyTask(int index, const std::string &description) {
    Task* modifiedTask = new Task();
    modifiedTask->set_description(description);
    list->modifyTask(index, modifiedTask);
}
