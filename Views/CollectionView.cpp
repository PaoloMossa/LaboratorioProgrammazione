//
// Created by Paolo Mossa on 09/03/25.
//

#include "CollectionView.h"

#include <iostream>

void CollectionView::display() const {
    std::cout << std::endl << "LISTE:" << std::endl;
    for (int i=0; i < collection->size(); i++)
        std::cout << i << ".\t" << toString(collection->get_lists()[i]);
}

void CollectionView::update() {
    display();
}

std::string CollectionView::toString(Task *task) const {
    auto description = task->get_description();
    bool completed = task->is_completed();
    bool important = task->is_important();
    std::string tag = "";
    if (important)
        tag = "I";

    std::string result = tag + "\t" + (completed?"[X]":"[ ]") + "\t" + description + "\n";

    return result;
}

std::string CollectionView::toString(TodoList *list) const {
    std::string result;
    result = list->getName();

    for (int i=0; i<list->get_tasks().size(); i++) {
        result.append("\n\t")
            .append(std::to_string(i))
            .append(".\t")
            .append(toString(list->get_tasks()[i]));
    }

    return result;
}
