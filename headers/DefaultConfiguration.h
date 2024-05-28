#ifndef OOP_DEFAULTCONFIGURATION_H
#define OOP_DEFAULTCONFIGURATION_H

#include "Configuration.h"


class DefaultConfiguration : public Configuration {
public:
    ~DefaultConfiguration() override;

    void loadSettings() override;
};


#endif //OOP_DEFAULTCONFIGURATION_H
