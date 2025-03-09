//
// Created by Paolo Mossa on 09/03/25.
//

#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <string>
#include <vector>
#include "../Model/TodoListCollection.h"




class FileHandler {
public:
    explicit FileHandler(std::string filename) : filename(filename){}
    void save(TodoListCollection* collection);
    TodoListCollection* load();
private:
    std::string filename;
};



#endif //FILEHANDLER_H
