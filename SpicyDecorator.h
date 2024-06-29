#ifndef SPICYDECORATOR_H
#define SPICYDECORATOR_H

#include "Feature.h"

class SpicyDecorator : public Feature {
private:
    Feature* feature;

public:
    SpicyDecorator(Feature* feature) : feature(feature) {}

    std::string applyFeature() const override {
        return feature->applyFeature() + " with extra spice";
    }

    ~SpicyDecorator() {
        delete feature;
    }
};

#endif
