//
// Created by Paolo Mossa on 09/03/25.
//

#include "CollectionInputHandler.h"

#include <iostream>

bool CollectionInputHandler::checkIndex(int i) {
    return !(i < 0 || i >= collection->size());

}

bool CollectionInputHandler::isIndex(std::string &string) {
    try {
        int i = std::stoi(string);
        return checkIndex(i);
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }

}

void CollectionInputHandler::listen() {
    std::string command;
    std::cin >> command;
    if (command == "esci")
        running = false;
    else if (command == "aggiungi") {
        newList();
    }
    else if (command == "rimuovi") {
        removeList();
    }
    else if (isIndex(command)) {
        //TODO aggiungi crazione di ListInputHandler
    }
}

void CollectionInputHandler::displayActions() {
    while (running) {
        std::cout << std::endl << "INSERIRE COMANDO ('esci', 'aggiungi', 'rimuovi' o indice della lista da modificare): ";
        listen();
    }
}

void CollectionInputHandler::newList() const {
    std::cout << std::endl;
    std::cout << "INSERIRE IL NOME DELLA NUOVA LISTA: ";
    std::string name;
    std::cin >> name;
    controller->AddList(name);
}

void CollectionInputHandler::removeList() const {
    std::string index;
    std::cout << "Inserire indice: ";
    std::cin >> index;
    controller->RemoveList(index);
}
