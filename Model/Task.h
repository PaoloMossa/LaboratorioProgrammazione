//
// Created by Paolo Mossa on 08/03/25.
//

#ifndef TASK_H
#define TASK_H
#include <string>


class Task {
private:
    std::string description;
    bool important;
    bool completed;
public:
    std::string get_description() const;

    void set_description(const std::string &description);

    bool is_important() const;

    void set_important(bool important);

    bool is_completed() const;

    void set_completed(bool completed);
};



#endif //TASK_H
