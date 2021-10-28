#include "ResourceType.h"

void ore::resources::ResourceType::registerInstanceCreation() {
    inUseCount++;
}

void ore::resources::ResourceType::registerInstanceDestruction() {
    if(inUseCount == 0) {
        LOG(FATAL) << "Attempted registration of the destruction of a resource for which no instances have been registered. This indicates a bug exists in the accounting for this resource!" << std::endl;
    }
}

void ore::resources::ResourceType::setName(std::string &name) {
    this->name = name;
}
