#include "Ketchup.h"
#include "Mustard.h"
#include "Relish.h"
#include "Inventory.h"
#include <iostream>
#include <string>

int main() {
    Inventory inventory;

    inventory.addCondiment(new Ketchup());
    inventory.addCondiment(new Mustard());
    inventory.addCondiment(new Relish());

    std::string command;

    while (true) {
        std::cout << "\nCondiments in inventory:" << std::endl;
        inventory.listCondiments();

        std::cout << "Enter a command (order, remove, exit): ";
        std::getline(std::cin, command);

        if (command == "exit") {
            break;
        } else if (command == "remove") {
            std::string condimentToRemove;
            std::cout << "Enter the name of the condiment to remove: ";
            std::getline(std::cin, condimentToRemove);
            inventory.removeCondiment(condimentToRemove);
        } else if (command == "order") {
            std::string condimentToOrder;
            std::cout << "Enter the name of the condiment to order: ";
            std::getline(std::cin, condimentToOrder);
            inventory.orderCondiment(condimentToOrder);
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}
