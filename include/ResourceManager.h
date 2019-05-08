#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H
#include <unordered_map>
#include <iostream>
template <typename T>
class ResourceManager
{
    public:
        /** Default constructor */
        ResourceManager() = delete;
        static T const& GetResource(std::string imgPath)
        {
            auto result = resources.find(imgPath);
            if(result == std::end(resources))
            {
                if(!resources[imgPath].loadFromFile(imgPath.data()))
                {
                    std::cout<<"failed to load : " << imgPath << std::endl;
                }
                else
                {
                    std::cout<<"success to load " << imgPath << std::endl;
                }

            }
            return resources[imgPath];
        }

    protected:
       static std::unordered_map<std::string, T> resources;
    private:
};

#endif // RESOURCEMANAGER_H
