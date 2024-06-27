#ifndef CONDIMENT_H
#define CONDIMENT_H

#include <string>

class Condiment {
public:
    virtual std::string getName() const = 0;
    virtual ~Condiment() {}
};

#endif
