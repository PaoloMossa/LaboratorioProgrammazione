//
// Created by Paolo Mossa on 23/07/25.
//

#include "gtest/gtest.h"
#include "../Controllers/CollectionController.h" // The class we are testing
#include "../Persistence/FileHandler.h"
#include <fstream>


class CollectionControllerSuite : public ::testing::Test {
protected:
    std::string fileName = "test_attivita.txt";
    FileHandler* gestoreFile = nullptr;
    TodoListCollection* collection = nullptr;
    CollectionController* controller = nullptr;


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

        gestoreFile = new FileHandler(fileName);
        collection = gestoreFile->load();
        controller = new CollectionController(collection);
    }

    // This function is called after each test is run.
    void TearDown() override {
        delete gestoreFile;
        delete collection;
        delete controller;
    }
};

TEST_F(CollectionControllerSuite, addListTest) {
    std::string name = "LISTA_2";
    controller->addList(name);
    ASSERT_EQ(collection->size(), 2);
    ASSERT_EQ(collection->get_lists()[1]->getName(), "LISTA_2");
}

TEST_F(CollectionControllerSuite, removeListTest) {
    std::string index = "0";
    controller->removeList(index);
    ASSERT_EQ(collection->size(), 0);
}

TEST_F(CollectionControllerSuite, removeListTest_WrongIndex) {
    std::string index = "99";
    controller->removeList(index);
    ASSERT_EQ(collection->size(), 1);
}

TEST_F(CollectionControllerSuite, removeListTest_NegativeIndex) {
    std::string index = "-3";
    controller->removeList(index);
    ASSERT_EQ(collection->size(), 1);
}

TEST_F(CollectionControllerSuite, removeListTest_NaN) {
    std::string index = "error";
    controller->removeList(index);
    ASSERT_EQ(collection->size(), 1);
}