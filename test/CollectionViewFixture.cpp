//
// Created by Paolo Mossa on 24/07/25.
//

#include "gtest/gtest.h"
#include "../Views/CollectionView.h"

#include "gtest/gtest.h"
#include <sstream> // Required for std::stringstream

// Include the actual project headers instead of mocks
#include "../Views/CollectionView.h"
#include "../Model/TodoListCollection.h"
#include "../Model/TodoList.h"
#include "../Model/Task.h"
#include "../Observer/Observer.h"


// Test fixture for setting up common objects for all tests in this suite.
class CollectionViewSuite : public ::testing::Test {
protected:
    // Pointers to the objects under test
    TodoListCollection* collection;
    CollectionView* collectionView;

    void SetUp() override {
        // 1. Setup for the main displayTest and updateTest
        collection = new TodoListCollection();
        TodoList* list1 = new TodoList();
        std::string name1 = "Groceries";
        list1->setName(name1);

        Task* task1 = new Task();
        task1->set_description("Buy milk");
        task1->set_completed(false);
        task1->set_important(false);
        list1->addTask(task1);

        Task* task2 = new Task();
        task2->set_description("Call the doctor");
        task2->set_completed(true);
        task2->set_important(true);
        list1->addTask(task2);

        collection->addList(list1);

        TodoList* list2 = new TodoList();
        std::string name2 = "Work";
        list2->setName(name2);

        Task* task3 = new Task();
        task3->set_description("Finish report");
        task3->set_completed(false);
        list2->addTask(task3);
        collection->addList(list2);

        // The CollectionView observes the collection for changes
        collectionView = new CollectionView(collection);
    }

    // TearDown() is called after each test case to clean up memory
    void TearDown() override {
        delete collectionView;
    }
};

// The public display() method tested by capturing the output sent to std::cout
TEST_F(CollectionViewSuite, displayTest) {
    // Backup the original std::cout buffer
    std::streambuf* originalCoutBuffer = std::cout.rdbuf();
    std::stringstream capturedOutput;

    // Redirect std::cout to our stringstream buffer
    std::cout.rdbuf(capturedOutput.rdbuf());

    // Call the function that prints to std::cout
    collectionView->display();

    // Restore the original std::cout buffer
    std::cout.rdbuf(originalCoutBuffer);

    // Create the expected output string based on the SetUp data
    std::string expectedOutput = "\nLISTE:\n";
    expectedOutput += "0.\tGroceries\n";
    expectedOutput += "\t0.\t\t[ ]\tBuy milk\n\n";
    expectedOutput += "\t1.\tI\t[X]\tCall the doctor\n";
    expectedOutput += "1.\tWork\n";
    expectedOutput += "\t0.\t\t[ ]\tFinish report\n";

    // Assert that the captured output matches the expected output
    ASSERT_EQ(capturedOutput.str(), expectedOutput);
}