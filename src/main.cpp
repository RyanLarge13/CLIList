#include "include/list.h"
#include "include/database.h"

int main(int argsCount, char *args[]) {
    List simpleList;
    Database data;

    if (argsCount > 1) {
        simpleList.username = string(args[1]);
        simpleList.mainList = data.read();
        bool userFound = simpleList.findUserList();
        simpleList.printMenu();   
        data.write(simpleList.mainList);
    }
    else {
        cout << "Please type in a username to log in\n";
    }
    return 0;
}