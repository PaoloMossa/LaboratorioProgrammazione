//
// Created by Paolo Mossa on 08/03/25.
//

#ifndef TODOLIST_H
#define TODOLIST_H
#include <string>
#include <vector>

#include "Task.h"
#include "../Observer/Subject.h"



class TodoList : Subject {
private:
    std::string name;
    std::vector<Task*> tasks;

    bool checkIndex(int index);

public:
    void addTask(Task* newTask) {
        tasks.push_back(newTask);
        notify();
    }

    void removeTask(int index);
    void modifyTask(int index, Task* newTask);
    void completeTask(int index);

    std::vector<Task *> get_tasks() const;


    void attach(Observer *o) override;

    void detach(Observer *o) override;

    std::string getName() const;

    void setName(std::string& name) {this->name = name;}

protected:
    void notify() override;
};



#endif //TODOLIST_H
