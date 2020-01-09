#include <iostream>
#include <ctime>

#include "framework.h"
#include "prop_item.hpp"
#include "property_manager.hpp"


static fe::PropItem* createPropItem()
{
    fe::PropItem* propItem = new fe::PropItem();
    propItem->id = std::rand() % 1000 + 1;
    propItem->name.assign("weapon");
    return propItem;
}

void propitem_without_project()
{
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
}
