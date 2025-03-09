//
// Created by Paolo Mossa on 09/03/25.
//
#include "gtest/gtest.h"
#include "../Model/TodoList.h"


TEST(TodoListTest, addTaskTest) {
    Task* task = new Task();
    task->set_description("Hello World!");
    TodoList* list = new TodoList();
    list->addTask(task);
    EXPECT_EQ(list->get_tasks().size(), 1);
    EXPECT_EQ(list->get_tasks()[0]->get_description(), "Hello World!");
    ASSERT_FALSE(list->get_tasks()[0]->is_completed());
    ASSERT_FALSE(list->get_tasks()[0]->is_important());
}
