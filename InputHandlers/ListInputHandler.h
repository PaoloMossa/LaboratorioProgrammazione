//
// Created by Paolo Mossa on 09/03/25.
//

#ifndef LISTINPUTHANDLER_H
#define LISTINPUTHANDLER_H

#include "../Controllers/ListController.h"


class ListInputHandler {
private:
    TodoList* list;
    ListController* controller;


    void listen();
public:
    explicit ListInputHandler(TodoList *list)
        : list(list) {controller = new ListController(list);}

    void displayActions();
};



#endif //LISTINPUTHANDLER_H
