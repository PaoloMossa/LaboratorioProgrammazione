//
// Created by Paolo Mossa on 09/03/25.
//

#ifndef COLLECTIONVIEW_H
#define COLLECTIONVIEW_H

#include "../Model/TodoListCollection.h"
#include "../Observer/Observer.h"

class CollectionView : public Observer {
private:
    TodoListCollection* collection;

    void update() override;

    std::string toString(Task *task) const;
    std::string toString(TodoList* list) const;
public:
    explicit CollectionView(TodoListCollection* collection) : collection(collection) {
        collection->attach(this);
    }
    ~CollectionView() {
        collection->detach(this);
    }
    void display() const;

};



#endif //COLLECTIONVIEW_H
