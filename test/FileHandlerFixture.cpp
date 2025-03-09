//
// Created by Paolo Mossa on 09/03/25.
//
#include "gtest/gtest.h"
#include "../Persistence/FileHandler.h"
#include <fstream>


class FileHandlerSuite : public ::testing::Test {
protected:
    std::string fileName = "test_attivita.txt";
    FileHandler gestoreFile;

    FileHandlerSuite() : gestoreFile(fileName) {}

    void SetUp() override {
        // Create a sample file for testing
        std::ofstream file(fileName);
        if (file.is_open()) {
            file << "LISTA_1\n";
            file << "Hello World!\n";
            file << "0\n";
            file << "0\n";
            file << "Chiamare la nonna\n";
            file << "1\n";
            file << "1\n";
        }

        file.close();
    }
    void TearDown() override {
        // Remove the test file
        remove(fileName.c_str());
    }
};

TEST_F(FileHandlerSuite, loadTest_SingleList) {
    TodoListCollection* collection = gestoreFile.load();
    ASSERT_NE(collection, nullptr);
    ASSERT_EQ(collection->size(), 1);
    ASSERT_EQ(collection->get_lists()[0]->get_tasks().size(), 2);
    ASSERT_EQ(collection->get_lists()[0]->get_tasks()[0]->get_description(), "Hello World!");
    ASSERT_EQ(collection->get_lists()[0]->get_tasks()[1]->get_description(), "Chiamare la nonna");
    ASSERT_FALSE(collection->get_lists()[0]->get_tasks()[0]->is_important());
    ASSERT_FALSE(collection->get_lists()[0]->get_tasks()[0]->is_completed());
    ASSERT_TRUE(collection->get_lists()[0]->get_tasks()[1]->is_important());
    ASSERT_TRUE(collection->get_lists()[0]->get_tasks()[1]->is_completed());
}

TEST_F(FileHandlerSuite, loadTest_MultipleLists) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        file << "LISTA_1\n";
        file << "Task 1\n";
        file << "0\n";
        file << "0\n";
        file << "----\n";
        file << "LISTA_2\n";
        file << "Task 2\n";
        file << "1\n";
        file << "1\n";
        file << "Task 3\n";
        file << "0\n";
        file << "0\n";
    }
    file.close();

    TodoListCollection* collection = gestoreFile.load();
    ASSERT_NE(collection, nullptr);
    ASSERT_EQ(collection->size(), 2);
    ASSERT_EQ(collection->get_lists()[0]->get_tasks().size(), 1);
    ASSERT_EQ(collection->get_lists()[1]->get_tasks().size(), 2);
    ASSERT_EQ(collection->get_lists()[0]->get_tasks()[0]->get_description(), "Task 1");
    ASSERT_EQ(collection->get_lists()[1]->get_tasks()[0]->get_description(), "Task 2");
    ASSERT_EQ(collection->get_lists()[1]->get_tasks()[1]->get_description(), "Task 3");

    delete collection;
}

TEST_F(FileHandlerSuite, loadTest_CorruptedData) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        file << "LISTA_1\n";
        file << "Task 1\n";
        file << "0\n";
        file << "1\n";
        file << "Task 2\n";
        file << "corrupted_data\n"; // Corrupted data.
    }
    file.close();

    TodoListCollection* collection = gestoreFile.load();
    ASSERT_NE(collection, nullptr);
    //Should only load the not-corrupted tasks
    ASSERT_EQ(collection->size(), 1);
    ASSERT_EQ(collection->get_lists()[0]->get_tasks().size(), 1);
    ASSERT_EQ(collection->get_lists()[0]->get_tasks()[0]->get_description(), "Task 1");

    delete collection;
}

TEST_F(FileHandlerSuite, saveTest) {
    TodoListCollection* collection = new TodoListCollection();
    TodoList* list1 = new TodoList();
    std::string name = "LISTA_1";
    list1->setName(name);
    Task* task1 = new Task();
    task1->set_description("Task 1");
    task1->set_completed(false);
    task1->set_important(false);
    list1->addTask(task1);
    collection->addList(list1);
    gestoreFile.save(collection);

    TodoListCollection* loadedCollection = gestoreFile.load();
    ASSERT_NE(loadedCollection, nullptr);
    ASSERT_EQ(loadedCollection->size(), 1);
    ASSERT_EQ(loadedCollection->get_lists()[0]->get_tasks().size(), 1);
    ASSERT_EQ(loadedCollection->get_lists()[0]->get_tasks()[0]->get_description(), "Task 1");
    ASSERT_FALSE(loadedCollection->get_lists()[0]->get_tasks()[0]->is_completed());
    ASSERT_FALSE(loadedCollection->get_lists()[0]->get_tasks()[0]->is_important());
    delete collection;
    delete loadedCollection;

}