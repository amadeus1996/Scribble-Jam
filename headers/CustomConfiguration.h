#ifndef OOP_CUSTOMCONFIGURATION_H
#define OOP_CUSTOMCONFIGURATION_H

#include "Configuration.h"


class CustomConfiguration : public Configuration {
public:
    ~CustomConfiguration() override;

    void loadSettings() override;
};


#endif //OOP_CUSTOMCONFIGURATION_H