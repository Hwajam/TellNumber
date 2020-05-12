//
// Created by seonghyeon yun on 2020/04/22.
//

#include "common.h"
#include "phoneData.h"
#include <stdlib.h>

void ShowMenu(void)
{
    //system("cls"); //Window
    system("clear"); //MacOS

    printf("----------   MENU   ---------- \n");
    printf(" 1. Input Phone Number \n");
    printf(" 2. Full Information Output \n");
    printf(" 3. Phone number search \n");
    printf(" 4. Delete Phone Number \n");
    printf(" 5. Change phone number \n");
    printf(" 6. EXIT \n");
    printf("------------------------------ \n");
    printf(" SELECT >>  ");
}

//void ShowPhoneInfo(phoneData phone)
//{
//    printf(" ------------------------------ \n     ");
//    printf("   >> NAME : %s \n", phone.name          );
//    printf("   >> TELL NUMBER : %s \n", phone.phoneNum);
//    printf(" ------------------------------ \n\n   ");
//}

//ver 1.3 2020/04/25
void ShowPhoneInfoByPtr(phoneData* pPhone)
{
    printf("--------------------------------- \n"          );
    printf(" >> NAME : %s \n", pPhone->name             );
    printf(" >> Phone Number : %s \n", pPhone->phoneNum );
    printf("--------------------------------- \n\n"        );
}