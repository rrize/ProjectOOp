#include "Inventory.h"
#include "KetchupFeature.h"
#include "MustardFeature.h"
#include "RelishFeature.h"
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
        addCondiment(new Condiment("Ketchup", new KetchupFeature()));
    } else if (name == "Mustard") {
        addCondiment(new Condiment("Mustard", new MustardFeature()));
    } else if (name == "Relish") {
        addCondiment(new Condiment("Relish", new RelishFeature()));
    } else {
        std::cout << "Condiment not recognized. Order failed." << std::endl;
    }
}

void Inventory::setCondimentPrice(const std::string &name, double price) {
    for (Condiment* condiment : condiments) {
        if (condiment->getName() == name) {
            condiment->setPrice(price);
        }
    }
}

void Inventory::setCondimentFeature(const std::string &name, Feature* feature) {
    for (Condiment* condiment : condiments) {
        if (condiment->getName() == name) {
            condiment->setFeature(feature);
        }
    }
}

const std::vector<Condiment*>& Inventory::getCondiments() const {
    return condiments;
}
