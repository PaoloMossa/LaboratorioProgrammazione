//
// Created by Paolo Mossa on 09/03/25.
//

#include "ListInputHandler.h"

#include <iostream>

void ListInputHandler::displayActions() {
    std::cout << "INSERIRE COMANDO (aggiungi, rimuovi, modifica, completa): ";
    listen();
}

void ListInputHandler::listen() {
    std::string command;
    std::cin >> command;
    if (command == "aggiungi") {
        std::cout << "INSERIRE LA DESCRIZIONE DELLA NUOVA ATTIVITÀ: ";
        std::string description;
        std::cin.ignore();
        std::getline(std::cin, description);
        std::cout << "L'ATTIVITÀ DEVE ESSERE CONTRASSEGNATA COME IMPORTANTE? (y/n)" << std::endl;
        std::string tag;
        std::cin >> tag;
        if (tag == "y")
            controller->addTaskToList(description,true);
        else controller->addTaskToList(description,false);
    }
    else if (command == "rimuovi") {
        std::string index;
        std::cout << "Inserire indice: ";
        std::cin >> index;
        try {
            controller->removeFromList(std::stoi(index));
        } catch (...) {
            std::cout << "Indice non valido" << std::endl;
        }
    }
    else if (command == "modifica") {
        std::string index;
        std::string description;
        std::cout << "Inserire indice: ";
        std::cin >> index;
        std::cout << "Inserire nuova descrizione: ";
        std::cin.ignore();
        std::getline(std::cin, description);
        try {
            controller->modifyTask(std::stoi(index),description);
        } catch (...) {
            std::cout << "Indice non valido" << std::endl;
        }
    } else if (command == "completa") {
        std::string index;
        std::cout << "Inserire indice: ";
        std::cin >> index;
        try {
            controller->completeTask(std::stoi(index));
        } catch (...) {
            std::cout << "Indice non valido" << std::endl;
        }
    }
}
