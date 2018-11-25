//
//  main.cpp
//  ProjectN10
//
//  Created by pc-laptop on 11/18/18.
//  Copyright © 2018 Ingrid Guerrero. All rights reserved.
//

#include <iostream>

#include "FileUtils.h"
#include "StringUtils.h"


const char numbersStringfileName[] = "Resources/txt/numbers.txt";

int main(int argc, const char * argv[])
{
    TListSystem::TList<int> numberFromFile = FileSystemStringUtils::LoadListFromFile(numbersStringfileName);;
    
    for (int i = 0; i < numberFromFile.Size() ; i++)
    {
        if (i == 0)
        {
            printf("TList Value %d\n", numberFromFile.First());
        }
        else
        {
            printf("TList Value %d\n", numberFromFile.Next());
        }
    }
    
    numberFromFile.Reset();
    
    return 0;
}
