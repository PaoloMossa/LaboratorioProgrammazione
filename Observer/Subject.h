//
// Created by Paolo Mossa on 08/03/25.
//

#ifndef SUBJECT_H
#define SUBJECT_H
#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void attach(Observer *o) = 0;
    virtual void detach(Observer *o) = 0;

protected:
    virtual void notify() = 0;

    std::vector<Observer *> observers;
};
#endif //SUBJECT_H