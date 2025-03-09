//
// Created by Paolo Mossa on 09/03/25.
//

#ifndef COLLECTIONINPUTHANDLER_H
#define COLLECTIONINPUTHANDLER_H
#include <string>

#include "../Controllers/CollectionController.h"
#include "../Model/TodoListCollection.h"


class CollectionInputHandler {
private:
    CollectionController* controller;
    TodoListCollection* collection;
    bool running;

    bool checkIndex(int i);

    bool isIndex(std::string &command);

    void listen();

    void newList() const;
    void removeList() const;
public:
    explicit CollectionInputHandler(TodoListCollection *collection)
        : collection(collection) { running = true; controller = new CollectionController(collection);}

    void displayActions();
};



#endif //COLLECTIONINPUTHANDLER_H
