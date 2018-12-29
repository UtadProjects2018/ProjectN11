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
        printf("TList Value %d\n", i == 0 ? numberFromFile.First() : numberFromFile.Next());
    }
    
    numberFromFile.Reset();
    
    /*
     Logs
     File was read success!
     Read: 1,2,3,4,5,6
     
     TList Value 1
     TList Value 2
     TList Value 3
     TList Value 4
     TList Value 5
     TList Value 6
     */
    
    return 0;
}
