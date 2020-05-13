//
// Created by seonghyeon yun on 2020/04/22.
//

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"
#include "phoneFunc.h"

#define LIST_NUM 100

int numOfData = 0;
//phoneData phoneList[LIST_NUM];
phoneData* phoneList[LIST_NUM];

void InputPhoneData(void)
{
    //phoneData data;
    phoneData* pData;
    int i;

    if(numOfData>=LIST_NUM)
    {
        puts("Out of memory space.");
        return;
    }

    pData = (phoneData *)malloc(sizeof(phoneData));

    fputs("Input Name : ",stdout);
    //gets(data.name);
    gets(pData->name); //gets((*pData).name);과 같음

    fputs("Input phone number : ",stdout);
    //gets(data.phoneNum);
    gets(pData->phoneNum);

    //ADD ver1.4
    for(i=0; i<numOfData; i++)
    {
        //strcmp반환값 2번째 값이 클 때 -1 같을 때 0 1번째 값이 클 때 1
        if(!strcmp(phoneList[i]->name, pData->name) && !strcmp(phoneList[i]->phoneNum, pData->phoneNum))
        {
            puts("Data already entered.");
            free(pData);
            getchar();
            return;
        }
    }

    //phoneList[numOfData] = data;
    phoneList[numOfData] = pData;

    numOfData++;

    StoreDataToFileInStruct();
    puts("The input is complete..");
    getchar();
}

void ShowAllData(void)
{
    int i;

    for(i = 0; i < numOfData; i++)
    {
        //ShowPhoneInfo(phoneList[i]);
        ShowPhoneInfoByPtr(phoneList[i]);
    }

    puts("The output is complete..");
    getchar();
}

// ver 1.2 2020/04/23
void SearchPhoneData(void)
{
    int i;
    int searchSte=0; //찾으면 1, 못 찾으면 0
    char searchName[NAME_LEN];

    fputs("What name are you looking for? ", stdout);
    gets(searchName);

    for(i=0; i<numOfData; i++)
    {
        //if(!strcmp(phoneList[i].name, searchName))
        if(!strcmp(phoneList[i]->name, searchName))
        {
            //ShowPhoneInfo(phoneList[i]);
            ShowPhoneInfoByPtr(phoneList[i]);
            puts("Scan completed..");
            //getchar();
            //return;
            searchSte=1;
        }
    }

    if(searchSte==0)
        puts("Data with the name you are looking for does not exist.");
    else
        puts("Your search has completed.");

    getchar();
}

void DeletePhoneData(void)
{
    int i;
    char delName[NAME_LEN];

    int idxOfMatchingData[LIST_NUM];
    int matchedCount=0;
    int selection=0;
    int delIdx=0;

    fputs("What name are you looking for? ", stdout);
    gets(delName);

//    for(i=0; i<numOfData; i++)
//    {
//        //if(!strcmp(phoneList[i].name, delName)) //같으면 0이 반환 즉 false그래서 !을 붙여서 1 true로 만듬
//        if(!strcmp(phoneList[i]->name, delName))
//        {
//            free(phoneList[i]);
//
//            for(j=i; j<numOfData-1; j++)
//            {
//                phoneList[j]=phoneList[j+1];
//            }
//
//            numOfData--;
//            puts("Deletion has been completed..");
//            getchar();
//            return;
//        }
//    }
//
//    puts("Data with the name you are looking for does not exist.");
//    getchar();


    for(i=0; i<numOfData; i++)
    {
        if(!strcmp(phoneList[i]->name, delName))
            idxOfMatchingData[matchedCount++]=i;
    }
    if(matchedCount==0)
    {
        puts("Data with the name you are looking for does not exist.");
        getchar();
        return;
    }
    else if(matchedCount==1)
    {
        delIdx=idxOfMatchingData[0];
    }
    else
    {
        for(i=0; i<matchedCount; i++)
        {
            printf("NUM. %d \n", i+1);
            ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
        }
        fputs("SELECT : ", stdout);
        scanf("%d", &selection);
        fflush(stdin);

        delIdx=idxOfMatchingData[selection-1];
    }

    free(phoneList[delIdx]);

    for(i=delIdx; i<numOfData-1; i++)
    {
        phoneList[i]=phoneList[i+1];
    }
    numOfData--;

    StoreDataToFileInStruct();
    puts("Deletion is complete.");
    getchar();
}

void StoreDataToFile(void)
{
    int i;
    FILE *fp=fopen("phoneData.dat","w");

    fwrite(&numOfData, sizeof(int), 1, fp); //데이터 총 개수
    for (i = 0; i < numOfData; i++) {
        fprintf(fp, "%s\n%s\n",
                phoneList[i]->name, phoneList[i]->phoneNum);
        free(phoneList[i]);
    }

    fclose(fp);
}

void LoadDataFromFile(void)
{
    int i, sLen;

    FILE *fp=fopen("phoneData.dat", "r");

    if(fp==NULL)
        return;

    fread(&numOfData, sizeof(int), 1, fp);

    for (i = 0; i < numOfData; i++) {
        phoneList[i]=(phoneData*)malloc(sizeof(phoneData));
        fgets(phoneList[i]->name, NAME_LEN, fp);

        sLen=strlen(phoneList[i]->name);
        phoneList[i]->name[sLen-1] = 0;

        fgets(phoneList[i]->phoneNum, PHONE_LEN, fp);

        sLen=strlen(phoneList[i]->phoneNum);
        phoneList[i]->phoneNum[sLen-1]=0;
    }

    fclose(fp);
}

void ChangePhoneData(void)
{
    int i;
    char serchName[NAME_LEN];
    char newPhoneNumber[PHONE_LEN];

    int idxOfMatchingData[LIST_NUM];
    int matchedCount=0;
    int selection=0;
    int delIdx=0;

    fputs("What is the name of the change? ", stdout);
    gets(serchName);


    for(i=0; i<numOfData; i++)
    {
        if(!strcmp(phoneList[i]->name, serchName))
            idxOfMatchingData[matchedCount++]=i;
    }

    if(matchedCount==0)
    {
        puts("Change target name does not exist. ");
        getchar();
        return;
    }
    else if(matchedCount==1)
    {
        delIdx=idxOfMatchingData[0];
    }
    else
    {
        for(i=0; i<matchedCount; i++)
        {
            printf("NUM. %d \n", i+1);
            ShowPhoneInfoByPtr(phoneList[idxOfMatchingData[i]]);
        }

        fputs("Select : ", stdout);
        scanf("%d", &selection);
        fflush(stdin);

        delIdx=idxOfMatchingData[selection-1];
    }

    fputs("What's the phone number you want to change? ", stdout);
    gets(newPhoneNumber);
    strcpy(phoneList[delIdx]->phoneNum, newPhoneNumber);

    StoreDataToFileInStruct();

    puts("The change has been completed. ");
    getchar();
}

void StoreDataToFileInStruct(void)
{
    int i;

    FILE * fp=fopen("phoneDataStruct.dat", "wb");

    fwrite(&numOfData, sizeof(int), 1, fp);

    for(i=0; i<numOfData; i++)
    {
        fwrite(phoneList[i], sizeof(phoneData), 1, fp);
    }

    fclose(fp);
}

void LoadDataFromFileInStruct(void)
{
    int i;

    FILE * fp=fopen("phoneDataStruct.dat", "rb");

    if(fp==NULL)
        return;

    fread(&numOfData, sizeof(int), 1, fp);

    for(i=0; i<numOfData; i++)
    {
        phoneList[i]=(phoneData*)malloc(sizeof(phoneData));
        fread(phoneList[i], sizeof(phoneData), 1, fp);
    }
    fclose(fp);
}