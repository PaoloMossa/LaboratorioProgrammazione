cmake_minimum_required(VERSION 3.30)
project(Laboratorio_Programmazione)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_Programmazione main.cpp
        Observer/Subject.h
        Observer/Observer.h
        Model/Task.cpp
        Model/Task.h
        Model/TodoList.cpp
        Model/TodoList.h
        Model/TodoListCollection.cpp
        Model/TodoListCollection.h
        Controllers/ListController.cpp
        Controllers/ListController.h
        Views/CollectionView.cpp
        Views/CollectionView.h
        InputHandlers/CollectionInputHandler.cpp
        InputHandlers/CollectionInputHandler.h
        InputHandlers/ListInputHandler.cpp
        InputHandlers/ListInputHandler.h
        Persistence/FileHandler.cpp
        Persistence/FileHandler.h
        Controllers/CollectionController.cpp
        Controllers/CollectionController.h)
