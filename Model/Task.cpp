//
// Created by Paolo Mossa on 08/03/25.
//

#include "Task.h"

std::string Task::get_description() const {
    return description;
}

void Task::set_description(const std::string &description) {
    this->description = description;
}

bool Task::is_important() const {
    return important;
}

void Task::set_important(bool important) {
    this->important = important;
}

bool Task::is_completed() const {
    return completed;
}

void Task::set_completed(bool completed) {
    this->completed = completed;
}
