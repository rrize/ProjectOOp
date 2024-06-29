#ifndef FEATURE_H
#define FEATURE_H

#include <string>

class Feature {
public:
    virtual std::string applyFeature() const = 0;
    virtual ~Feature() {}
};

#endif
