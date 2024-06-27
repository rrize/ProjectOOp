#include "Inventory.h"
#include <iostream>

Inventory::~Inventory() {
    for (Condiment* condiment : condiments) {
        delete condiment;
    }
}

void Inventory::addCondiment(Condiment* condiment) {
    condiments.push_back(condiment);
}

void Inventory::listCondiments() const {
    for (const Condiment* condiment : condiments) {
        std::cout << condiment->getName() << std::endl;
    }
}
