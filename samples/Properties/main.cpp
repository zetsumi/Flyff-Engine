#include <iostream>
#include <ctime>

#pragma warning( disable: 4251 )

void propitem_without_project();
void propitem_with_project();

void propctrl_without_project();
void propctrl_with_project();

int main()
{
    std::srand(std::time(nullptr));
    propitem_without_project();
    propitem_with_project();
    propctrl_without_project();
    propctrl_with_project();

    return 0;
}