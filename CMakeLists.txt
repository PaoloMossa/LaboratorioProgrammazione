cmake_minimum_required(VERSION 3.30)
project(Laboratorio_Programmazione)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

add_subdirectory(test)

set(SOURCE_FILES Observer/Subject.h
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
add_executable(Laboratorio_Programmazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Laboratorio_Programmazione core)

#add_executable(Laboratorio_Programmazione main.cpp
#        Observer/Subject.h
#        Observer/Observer.h
#        Model/Task.cpp
#        Model/Task.h
#        Model/TodoList.cpp
#        Model/TodoList.h
#        Model/TodoListCollection.cpp
#        Model/TodoListCollection.h
#        Controllers/ListController.cpp
#        Controllers/ListController.h
#        Views/CollectionView.cpp
#        Views/CollectionView.h
#        InputHandlers/CollectionInputHandler.cpp
#        InputHandlers/CollectionInputHandler.h
#        InputHandlers/ListInputHandler.cpp
#        InputHandlers/ListInputHandler.h
#        Persistence/FileHandler.cpp
#        Persistence/FileHandler.h
#        Controllers/CollectionController.cpp
#        Controllers/CollectionController.h)
