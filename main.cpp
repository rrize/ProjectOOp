#include "Ketchup.h"
#include "Mustard.h"
#include "Relish.h"
#include "Inventory.h"
#include <iostream>
#include <string>
#include <cassert>

void runTests() {
    {
        Inventory inventory;
        inventory.addCondiment(new Ketchup());
        inventory.addCondiment(new Mustard());
        inventory.addCondiment(new Relish());

        // Debug output to show contents of inventory
        std::cout << "Contents after adding condiments:" << std::endl;
        inventory.listCondiments();

        int ketchupCount = 0;
        int mustardCount = 0;
        int relishCount = 0;

        for (const auto& condiment : inventory.getCondiments()) {
            if (condiment->getName() == "Ketchup") ketchupCount++;
            if (condiment->getName() == "Mustard") mustardCount++;
            if (condiment->getName() == "Relish") relishCount++;
        }

        std::cout << "Ketchup count: " << ketchupCount << std::endl;
        std::cout << "Mustard count: " << mustardCount << std::endl;
        std::cout << "Relish count: " << relishCount << std::endl;

        assert(ketchupCount == 1);
        assert(mustardCount == 1);
        assert(relishCount == 1);

        std::cout << "testAddCondiments passed." << std::endl;
    }

    {
        Inventory inventory;
        inventory.addCondiment(new Ketchup());
        inventory.addCondiment(new Mustard());
        inventory.addCondiment(new Relish());
        inventory.addCondiment(new Ketchup());

        inventory.removeCondiment("Ketchup");

        std::cout << "Contents after removing Ketchup:" << std::endl;
        inventory.listCondiments();

        int ketchupCount = 0;
        int mustardCount = 0;
        int relishCount = 0;

        for (const auto& condiment : inventory.getCondiments()) {
            if (condiment->getName() == "Ketchup") ketchupCount++;
            if (condiment->getName() == "Mustard") mustardCount++;
            if (condiment->getName() == "Relish") relishCount++;
        }

        std::cout << "Ketchup count: " << ketchupCount << std::endl;
        std::cout << "Mustard count: " << mustardCount << std::endl;
        std::cout << "Relish count: " << relishCount << std::endl;

        assert(ketchupCount == 0);
        assert(mustardCount == 1);
        assert(relishCount == 1);

        std::cout << "testRemoveCondiments passed." << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    runTests();

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
