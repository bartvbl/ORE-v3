#include "ResourceContainer.h"

template<typename ContentsType>
void ore::resources::ResourceContainer<ContentsType>::registerResource(std::string itemID, ore::filesystem::path fileLocation) {

}

template<typename ContentsType>
bool ore::resources::ResourceContainer<ContentsType>::loadNext() {
    return false;
}

template<typename ContentsType>
void ore::resources::ResourceContainer<ContentsType>::evict(std::string itemID) {

}

template<typename ContentsType>
const ContentsType* ore::resources::ResourceContainer<ContentsType>::getResource_Blocking(std::string itemID) {
    return nullptr;
}