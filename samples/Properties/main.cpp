#include <iostream>
#include <ctime>

#include "framework.h"
#include "prop_item.hpp"
#include "property_manager.hpp"
#include "property_project.hpp"

#pragma warning( disable: 4251 )

static fe::PropItem* createPropItem()
{
    fe::PropItem* propItem = new fe::PropItem();
    propItem->id = std::rand() % 1000 + 1;
    propItem->name.assign("weapon");
    return propItem;
}

static void without_project()
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


static void with_project()
{
    fe::PropertyProject project;
    fe::PropertyManager managerItems;

    std::vector<unsigned __int64> listIdItems;
    for (uint64_t i = 0; i < 10; ++i)
    {
        fe::PropItem* p = createPropItem();
        managerItems.push(p->id, p);
        listIdItems.push_back(p->id);
    }

    project.push(fe::PROPERTY_TYPE::PropItem, &managerItems);

    fe::PropertyManager* itemMgd = project.get(fe::PROPERTY_TYPE::PropItem);
    for (auto id : listIdItems)
    {
        fe::PropItem* itemMgd2 = project.get<fe::PropItem*>(fe::PROPERTY_TYPE::PropItem, id);
        fe::PropItem* itemMgd3 = dynamic_cast<fe::PropItem*>(project.get(fe::PROPERTY_TYPE::PropItem, id));
    }
}

int main()
{
    std::srand(std::time(nullptr));
    without_project();
    with_project();

    return 0;
}