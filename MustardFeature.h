#ifndef MUSTARDFEATURE_H
#define MUSTARDFEATURE_H

#include "Feature.h"

class MustardFeature : public Feature {
public:
    std::string applyFeature() const override {
        return "Mustard: Adding a sharp, spicy flavor.";
    }
};

#endif
