#include <iostream>
#include <ctime>

#include "framework.h"
#include "property_manager.hpp"
#include "prop_item.hpp"

#pragma warning( disable: 4251 )

static fe::PropItem* createPropItem()
{
    fe::PropItem* propItem = new fe::PropItem();
    propItem->id = std::rand() % 1000 + 1;
    propItem->name.assign("weapon");
    return propItem;
}


int main()
{
    std::srand(std::time(nullptr));

    fe::PropertyManager managerItems;


    std::vector<unsigned __int64> listIdItems;
    for (uint64_t i = 0; i < 10; ++i)
    {
        auto p = createPropItem();
        managerItems.push(p->id, p);
        listIdItems.push_back(p->id);
    }

    for (auto id : listIdItems)
    {
        fe::PropItem* p = dynamic_cast<fe::PropItem*>(managerItems.get(id));
        if (p != nullptr)
            std::cout << "p : " << p->id << " " << p->name << std::endl;
        else
            std::cerr << "item " << id << " not found" << std::endl;

        fe::PropItem* p2 = managerItems.get<fe::PropItem*>(id);
        if (p2 != nullptr)
            std::cout << "p2 : " << p2->id << " " << p2->name << std::endl;
        else
            std::cerr << "item " << id << " not found" << std::endl;
    }

    return 0;
}