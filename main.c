//
// Created by seonghyeon yun on 2020/04/22.
// IDE : CLion
// Language : C
// Standard : C11
//

#include "common.h"
#include "screenOut.h"
#include "phoneFunc.h"

enum {INPUT = 1, SHOWALL, SEARCH, DELETE, CHANGE, QUIT};

int main() {

    int inputMenu = 0;

    LoadDataFromFile();

    while(1)
    {
        ShowMenu();
        fputs("Please select a menu : ", stdout);
        scanf("%d", &inputMenu);
        fflush(stdin);

        switch (inputMenu) {
            case INPUT:
                InputPhoneData();
                break;
            case SHOWALL:
                ShowAllData();
                break;
            case SEARCH:
                SearchPhoneData();
                break;
            case DELETE:
                DeletePhoneData();
                break;

            case CHANGE:
                ChangePhoneData();
                break;
        }

        if(inputMenu==QUIT)
        {
            StoreDataToFile();
            puts("Thank you");
            break;
        }
    }
    return 0;
}
