#ifndef KETCHUPFEATURE_H
#define KETCHUPFEATURE_H

#include "Feature.h"

class KetchupFeature : public Feature {
public:
    std::string applyFeature() const override {
        return "Ketchup: Adding a tangy flavor.";
    }
};

#endif
