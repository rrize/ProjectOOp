#include "Inventory.h"
#include <iostream>
#include <algorithm>

Inventory::~Inventory() {
    for (Condiment* condiment : condiments) {
        delete condiment;
    }
}

void Inventory::addCondiment(Condiment* condiment) {
    condiments.push_back(condiment);
}

void Inventory::removeCondiment(const std::string &name) {
    auto it = std::remove_if(condiments.begin(), condiments.end(),
                             [&name](Condiment* condiment) {
                                 if (condiment->getName() == name) {
                                     delete condiment;
                                     return true;
                                 }
                                 return false;
                             });

    condiments.erase(it, condiments.end());
}

void Inventory::listCondiments() const {
    for (const Condiment* condiment : condiments) {
        std::cout << condiment->getName() << std::endl;
    }
}
