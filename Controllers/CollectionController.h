//
// Created by Paolo Mossa on 09/03/25.
//

#ifndef COLLECTIONCONTROLLER_H
#define COLLECTIONCONTROLLER_H
#include "../Model/TodoListCollection.h"


class CollectionController {
private:
    TodoListCollection* collection;
public:
    explicit CollectionController(TodoListCollection* collection) : collection(collection){}

    void addList(std::string &name);
    void removeList(std::string &index);
};



#endif //COLLECTIONCONTROLLER_H
