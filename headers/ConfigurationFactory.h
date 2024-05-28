#ifndef OOP_CONFIGURATIONFACTORY_H
#define OOP_CONFIGURATIONFACTORY_H

#include <iostream>
#include "Configuration.h"


template<typename T>
class ConfigurationFactory {
public:
    ConfigurationFactory() = default;

    ~ConfigurationFactory() { std::cout << "Destructor ConfigurationFactory\n"; }

    [[nodiscard]] inline T *createConfig() const { return new T(); }
};


#endif //OOP_CONFIGURATIONFACTORY_H
