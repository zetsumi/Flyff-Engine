#include <iostream>
#include <ctime>
#include "reader.hpp"

#pragma warning( disable: 4251 )

void propitem_without_project();
bool propitem_load_from_file();

void propctrl_without_project();
bool propctrl_load_from_file(fe::LOADER_MODE mode);

bool propskill_load_from_file();

bool propkarma_load_from_file();

int main()
{
    std::srand(std::time(nullptr));
    
    //propitem_without_project();
    //propitem_load_from_file();


    //propctrl_without_project();
    //propctrl_load_from_file(fe::LOADER_MODE::JSON);
    propctrl_load_from_file(fe::LOADER_MODE::XML);

    //propskill_load_from_file();

    //propkarma_load_from_file();

    return 0;
}