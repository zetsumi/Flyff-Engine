#include <iostream>
#include <ctime>

#include "framework.h"
#include "prop_ctrl.hpp"
#include "property_manager.hpp"

template<class C>
static C* create()
{
    C* prop = new C();
    prop->id = std::rand() % 1000 + 1;
    prop->name.assign("weapon");
    return prop;
}

void    propctrl_without_project()
{
    fe::PropertyManager managerItems;


    std::vector<unsigned __int64> listIdItems;
    for (uint64_t i = 0; i < 10; ++i)
    {
        auto p = create<fe::PropCtrl>();
        managerItems.push(p->id, p);
        listIdItems.push_back(p->id);
    }

    for (auto id : listIdItems)
    {
        fe::PropCtrl* p = dynamic_cast<fe::PropCtrl*>(managerItems.get(id));
        if (p != nullptr)
            std::cout << "p : " << p->id << " " << p->name << std::endl;
        else
            std::cerr << "item " << id << " not found" << std::endl;

        fe::PropCtrl* p2 = managerItems.get<fe::PropCtrl*>(id);
        if (p2 != nullptr)
            std::cout << "p2 : " << p2->id << " " << p2->name << std::endl;
        else
            std::cerr << "item " << id << " not found" << std::endl;
    }
}
