//
// Created by Paolo Mossa on 09/03/25.
//

#ifndef TODOLISTCOLLECTION_H
#define TODOLISTCOLLECTION_H
#include <vector>

#include "TodoList.h"


class TodoListCollection : public Subject {
private:
    std::vector<TodoList*> lists;

    void forwardObservers(TodoList* list) const;

public:

    std::vector<TodoList *> get_lists() const;

    int size();

    void attach(Observer *o) override;

    void detach(Observer *o) override;

    void addList(TodoList* newList);

    void addAllList(const std::vector<TodoList*>& lists);

    void removeList(int index);
protected:
    void notify() override;
};



#endif //TODOLISTCOLLECTION_H
