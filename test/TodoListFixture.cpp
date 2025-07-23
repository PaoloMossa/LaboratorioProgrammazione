//
// Created by Paolo Mossa on 09/03/25.
//

#include <gtest/gtest.h>
#include "../Model/Task.h"
#include "../Model/TodoList.h"


class TodoListSuite : public ::testing::Test {
protected:
    TodoList* list = new TodoList();

    virtual void SetUp() {
        Task* task = new Task();
        task->set_description("Hello World!");
        std::string name = "LISTA_1";
        list->setName(name);
        list->addTask(task);
    }
};

TEST_F(TodoListSuite, removeTaskTest) {
    list->removeTask(0);
    EXPECT_EQ(list->get_tasks().size(), 0);
}

TEST_F(TodoListSuite, removeTaskTest_WrongIndex) {
    list->removeTask(99);
    EXPECT_EQ(list->get_tasks().size(), 1);
}

TEST_F(TodoListSuite,removeTaskTest_NegativeIndex) {
    list->removeTask(-1);
    EXPECT_EQ(list->get_tasks().size(), 1);
}

TEST_F(TodoListSuite, modifyTaskTest) {
    Task* newTask = new Task();
    newTask->set_description("Description Changed!");
    list->modifyTask(0, newTask);
    EXPECT_EQ(list->get_tasks()[0]->get_description(), "Description Changed!");
}

TEST_F(TodoListSuite, modifyTaskTest_WrongIndex) {
    Task* newTask = new Task();
    newTask->set_description("Description Changed!");
    list->modifyTask(99, newTask);
    EXPECT_EQ(list->get_tasks()[0]->get_description(), "Hello World!");
}

TEST_F(TodoListSuite, modifyTaskTest_NegativeIndex) {
    Task* newTask = new Task();
    newTask->set_description("Description Changed!");
    list->modifyTask(-1, newTask);
    EXPECT_EQ(list->get_tasks()[0]->get_description(), "Hello World!");
}

TEST_F(TodoListSuite, modifyTaskTest_NullPtrAsTask) {
    Task* newTask = new Task();
    newTask->set_description("Description Changed!");
    list->modifyTask(0, nullptr);
    EXPECT_EQ(list->get_tasks()[0]->get_description(), "Hello World!");
}

TEST_F(TodoListSuite, completeTaskTest) {
    list->completeTask(0);
    EXPECT_EQ(list->get_tasks()[0]->is_completed(), true);
}

TEST_F(TodoListSuite, completeTaskTest_WrongIndex) {
    list->completeTask(99);
    EXPECT_EQ(list->get_tasks()[0]->is_completed(), false);
}

TEST_F(TodoListSuite, completeTaskTest_NegativeIndex) {
    list->completeTask(-1);
    EXPECT_EQ(list->get_tasks()[0]->is_completed(), false);
}


