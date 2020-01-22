#include <iostream>
#include <ctime>
#include "reader.hpp"

#pragma warning( disable: 4251 )

bool sample_project();

void propitem_without_project();
void propctrl_without_project();

bool load_text_json();

bool propitem_load_from_file(fe::LOADER_MODE mode);
bool propctrl_load_from_file(fe::LOADER_MODE mode);
bool propskill_load_from_file(fe::LOADER_MODE mode);
bool propkarma_load_from_file(fe::LOADER_MODE mode);

int main()
{
    std::srand(std::time(nullptr));

    sample_project();
    //load_text_json();

    //propitem_without_project();
    //propitem_load_from_file(fe::LOADER_MODE::JSON);
    //propitem_load_from_file(fe::LOADER_MODE::XML);


    //propctrl_without_project();
    //propctrl_load_from_file(fe::LOADER_MODE::JSON);
    //propctrl_load_from_file(fe::LOADER_MODE::XML);

    //propskill_load_from_file(fe::LOADER_MODE::XML);
    //propskill_load_from_file(fe::LOADER_MODE::JSON);

    //propkarma_load_from_file(fe::LOADER_MODE::XML);
    //propkarma_load_from_file(fe::LOADER_MODE::JSON);

    return 0;
}