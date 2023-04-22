#include <iostream>
#include <vector>
#include "include/list.h"
using namespace std;

void List::printMenu() {
    int choice;
    cout << "\nMenu\n**********" 
        << "\n1 - Print list..\n" 
        << "2 - Add to list..\n" 
        << "3 - Delete from list..\n" 
        << "4 - Save your list\n"
        << "5 - Exit program\n\n" 
        << "Enter your choice and press enter: ";
    cin >> choice;
    if (choice == 1) {
        system("clear");
        printList();
    }
    else if (choice == 2) {
        system("clear");
        addItem();
    }
    else if (choice == 3) {
        system("clear");
        deleteItem();
    }
    else if (choice == 4) {
        system("clear");
        saveList();
    }
    else if (choice == 5) {
        system("clear");
        return;
    }
    else {
        cout << "Sorry choice not valid\n";
        system("clear");
        printMenu();
    }
}

void List::addItem() {
    cout << "\n" << "Add a new item: ";
    string item;
    cin >> item;
    list.push_back(item);
    cout << "Succesfully added " << item << " to your list \n";
    cin.clear();
    printMenu();
}

void List::deleteItem() {
    cout << "Delete an item by picking a number...\n";
    if (list.size()) {
        for (int i = 0; i < (int)list.size(); i++) {
            if (i != 0) {
                cout << i << ": " << list[i] << "\n";
            }
        }
        int choiceNum;
        cout << "item to delete: ";
        cin >> choiceNum;
        if (choiceNum != 0 && choiceNum <= list.size()) {
            system("clear");
            cout << "Succesfully deleted item " << choiceNum;
            list.erase(list.begin() + choiceNum);
        }
        else {
            system("clear");
            cout << "Invalid selection, try again\n";
            printMenu();
        }
    }
    else {
        cout << "No items in your list\n";
    }
    printMenu();
}

void List::printList() {
    cout << "\n";
    for (int i = 0; i < (int)list.size(); i++) {
        if (i != 0) {
            cout << i << " - " << list[i] << "\n";
        }
        else {
            cout << list[0] << "\n" << "**********\n";
        }
    }
    cout << "\nM - Menu \n";
    string choice;
    cin >> choice;
    if (choice == "M" || choice == "m") {
        system("clear");
        printMenu();
    }
    else {
        cout << "Invalid choice please try again...";
        printList();
    }
}

bool List::findUserList() {
    system("clear");
    bool userFound = false;
    cout << "\nWelcome " << username << "\n";

    for (int userIndex = 0; userIndex < (int)mainList.size(); userIndex++) {
        if (mainList[userIndex][0] == username) {
            cout << "You are now logged in\n";
            list = mainList[userIndex];
            currentUserIndex = userIndex;
            userFound = true;
            break;
        }
    }

    if (userFound == false) {
        list.push_back(username);
        mainList.push_back(list);
        currentUserIndex = (int)mainList.size() - 1;
        cout << "New account created!!!\n";
    }

    return userFound;
}

void List::saveList() {
    cout << "Saving your list.. \n";
    mainList[currentUserIndex] = list;
    cout << "Your list has been saved!!\n";
    printMenu();
}