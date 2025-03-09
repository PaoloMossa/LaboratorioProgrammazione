//
// Created by Paolo Mossa on 08/03/25.
//

#ifndef LISTMANAGEMENTCONTROLLER_H
#define LISTMANAGEMENTCONTROLLER_H

#include "../Model/TodoList.h"



class ListController {
private:
    TodoList* list;
public:
    explicit ListController(TodoList* list) : list(list) {}
    void addTaskToList(std::string &description, bool important);
    void removeFromList(int index);
    void modifyTask(int index, const std::string &description);
    void completeTask(int index) {
        list->completeTask(index);
    }
};



#endif //LISTMANAGEMENTCONTROLLER_H
