#ifndef SWEETDECORATOR_H
#define SWEETDECORATOR_H

#include "Feature.h"

class SweetDecorator : public Feature {
private:
    Feature* feature;

public:
    SweetDecorator(Feature* feature) : feature(feature) {}

    std::string applyFeature() const override {
        return feature->applyFeature() + " with extra sweetness";
    }

    ~SweetDecorator() {
        delete feature;
    }
};

#endif