#include <iostream>
#include <ctime>

#pragma warning( disable: 4251 )

void propitem_without_project();
bool propitem_load_from_file();

void propctrl_without_project();

int main()
{
    std::srand(std::time(nullptr));
    
    //propitem_without_project();
    propitem_load_from_file();


    //propctrl_without_project();

    return 0;
}