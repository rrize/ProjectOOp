#include "KetchupFeature.h"
#include "MustardFeature.h"
#include "RelishFeature.h"
#include "Condiment.h"
#include "Inventory.h"
#include "SpicyDecorator.h"
#include "SweetDecorator.h"
#include <iostream>
#include <string>
#include <cassert>

void runTests() {
    {
        Inventory inventory;
        inventory.addCondiment(new Condiment("Ketchup", new SpicyDecorator(new KetchupFeature())));
        inventory.addCondiment(new Condiment("Mustard", new MustardFeature()));
        inventory.addCondiment(new Condiment("Relish", new SweetDecorator(new RelishFeature())));

        std::cout << "Contents after adding condiments:" << std::endl;
        inventory.listCondiments();

        int ketchupCount = 0;
        int mustardCount = 0;
        int relishCount = 0;

        for (const auto& condiment : inventory.getCondiments()) {
            std::cout << "Condiment: " << condiment->getName() << ", Feature: " << condiment->applyFeature() << std::endl;
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
        inventory.addCondiment(new Condiment("Ketchup", new SpicyDecorator(new KetchupFeature())));
        inventory.addCondiment(new Condiment("Mustard", new MustardFeature()));
        inventory.addCondiment(new Condiment("Relish", new SweetDecorator(new RelishFeature())));
        inventory.addCondiment(new Condiment("Ketchup", new SpicyDecorator(new KetchupFeature())));

        inventory.removeCondiment("Ketchup");

        std::cout << "Contents after removing Ketchup:" << std::endl;
        inventory.listCondiments();

        int ketchupCount = 0;
        int mustardCount = 0;
        int relishCount = 0;

        for (const auto& condiment : inventory.getCondiments()) {
            std::cout << "Condiment: " << condiment->getName() << ", Feature: " << condiment->applyFeature() << std::endl;
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

    inventory.addCondiment(new Condiment("Ketchup", new SpicyDecorator(new KetchupFeature())));
    inventory.addCondiment(new Condiment("Mustard", new MustardFeature()));
    inventory.addCondiment(new Condiment("Relish", new SweetDecorator(new RelishFeature())));

    std::string command;

    while (true) {
        std::cout << "\nCondiments in inventory:" << std::endl;
        inventory.listCondiments();

        std::cout << "Enter a command (order, remove, decorate, setprice, exit): ";
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
        } else if (command == "setprice") {
            std::string condimentToPrice;
            double price;
            std::cout << "Enter the name of the condiment to set price: ";
            std::getline(std::cin, condimentToPrice);
            std::cout << "Enter the price: ";
            std::cin >> price;
            std::cin.ignore();
            inventory.setCondimentPrice(condimentToPrice, price);
        } else if (command == "decorate") {
            std::string condimentToDecorate;
            std::string decoration;
            std::cout << "Enter the name of the condiment to decorate: ";
            std::getline(std::cin, condimentToDecorate);
            std::cout << "Enter the decoration (spicy/sweet): ";
            std::getline(std::cin, decoration);
            Feature* newFeature = nullptr;
            for (const auto& condiment : inventory.getCondiments()) {
                if (condiment->getName() == condimentToDecorate) {
                    std::string currentFeature = condiment->applyFeature();
                    if ((decoration == "spicy" && currentFeature.find("spice") != std::string::npos) ||
                        (decoration == "sweet" && currentFeature.find("sweetness") != std::string::npos)) {
                        std::cout << condimentToDecorate << " already has the " << decoration << " feature." << std::endl;
                        newFeature = nullptr;
                        break;
                    }
                }
            }

            if (newFeature == nullptr && decoration == "spicy") {
                newFeature = new SpicyDecorator(new KetchupFeature());
            } else if (newFeature == nullptr && decoration == "sweet") {
                newFeature = new SweetDecorator(new KetchupFeature());
            } else if (newFeature == nullptr) {
                std::cout << "Unknown decoration type." << std::endl;
                continue;
            }

            inventory.setCondimentFeature(condimentToDecorate, newFeature);
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}
