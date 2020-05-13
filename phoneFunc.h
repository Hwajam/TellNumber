//
// Created by seonghyeon yun on 2020/04/22.
//

#ifndef TELLNUMBER_PHONEFUNC_H
#define TELLNUMBER_PHONEFUNC_H

#include "phoneData.h"

void InputPhoneData(void);
void ShowAllData(void);

void SearchPhoneData(void);
void DeletePhoneData(void);

void ChangePhoneData(void);

void StoreDataToFile(void);
void LoadDataFromFile(void);

void StoreDataToFileInStruct(void);
void LoadDataFromFileInStruct(void);

#endif //TELLNUMBER_PHONEFUNC_H
