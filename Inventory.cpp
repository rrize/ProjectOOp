#include "Inventory.h"
#include "Ketchup.h"
#include "Mustard.h"
#include "Relish.h"
#include <iostream>
#include <algorithm>
#include <map>

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
    std::map<std::string, int> condimentCounts;
    for (const Condiment* condiment : condiments) {
        condimentCounts[condiment->getName()]++;
    }
    for (const auto& pair : condimentCounts) {
        std::cout << pair.first << " x" << pair.second << std::endl;
    }
}

void Inventory::orderCondiment(const std::string &name) {
    if (name == "Ketchup") {
        addCondiment(new Ketchup());
    } else if (name == "Mustard") {
        addCondiment(new Mustard());
    } else if (name == "Relish") {
        addCondiment(new Relish());
    } else {
        std::cout << "Condiment not recognized. Order failed." << std::endl;
    }
}
