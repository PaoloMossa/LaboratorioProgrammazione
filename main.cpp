#include <iostream>

#include "InputHandlers/CollectionInputHandler.h"
#include "Model/TodoListCollection.h"
#include "Persistence/FileHandler.h"
#include "Views/CollectionView.h"

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    FileHandler* file_handler = new FileHandler("lists.txt");

    // Task* task = new Task();
    // task->set_description("Hello World!");
    // TodoList* list1 = new TodoList();
    // std::string name = "LISTA_1";
    // list1->setName(name);
    // list1->addTask(task);
    //
    // TodoListCollection* collection = new TodoListCollection();
    // CollectionView* view = new CollectionView(collection);
    // collection->addList(list1);

    TodoListCollection* collection = file_handler->load();
    CollectionView* view = new CollectionView(collection);
    view->display();

    CollectionInputHandler* inputHandler;
    inputHandler = new CollectionInputHandler(collection);
    inputHandler->displayActions();

    file_handler->save(collection);

    // delete task;
    // delete list1;
    delete file_handler;
    delete collection;
    delete view;
    delete inputHandler;

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.