#include "CLI.h"

int main()
{
    CLI clui;
    int choice;

    do
    {
        choice = clui.mainMenu();
        switch (choice)
        {
        case 1:
            clui.openAccount();
            break;

        case 2:
            clui.balanceEnquiry();
            break;

        case 3:
            clui.deposit();
            break;

        case 4:
            clui.withdraw();
            break;

        case 5:
            clui.close();
            break;

        case 6:
            clui.showAll();
            break;

        case 7:
            break;

        default:
            std::cout << "\nEnter corret choice";
            exit(0);
        }
    } while (choice != 7);
    return 0;
}