#include <fstream>
#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>

int main()
{
    bool isRunning = true;
    std::vector<std::string> dataBase; 
    int currIndex = 0;
    bool printOutDataBase = false;
    std::string UserInput;   
    std::string filename = "dataBase.txt";
    std::ifstream inFile(filename);
    if (inFile.is_open()) {

        std::string line;
        while (getline(inFile, line)) 
        {
            dataBase.push_back(line);
        }
        inFile.close();
        } 
        else {
        std::cout << "Unable to open file, please check to make sure you have dataBase.txt";
    }
    while(isRunning == true)
    {
    std::cout << "Would you like to add or read from the data base. Type no if you want to quit.? type read or write" << std::endl;
    std::getline(std::cin, UserInput);
    if (UserInput == "read")
    {
        std::cout << "who would you like to search for?" << std::endl;
        std::getline(std::cin, UserInput);
        std::transform(UserInput.begin(), UserInput.end(), UserInput.begin(), ::tolower);
        for (std::string x : dataBase) 
        {
            
            
            if (UserInput == x)
            {

                std::cout << "Age: " << dataBase[currIndex+1] << std::endl;
                std::cout << "What they Do: " <<dataBase[currIndex+2] << std::endl;
                std::cout << "Where they live: " <<dataBase[currIndex+3] << std::endl;


                break;
            }
            currIndex++;
        }
    }
    else if( UserInput == "write")
    {
        std::ofstream myfile;  
        myfile.open ("dataBase.txt", std::ios::app);  // Open file in append mode
        std::cout << "who would you like to add?: "; 
        std::getline(std::cin, UserInput);
        std::cout << std::endl;
        std::transform(UserInput.begin(), UserInput.end(), UserInput.begin(), ::tolower);
        myfile << UserInput << "\n";

        std::cout << "how old is the person your adding? ";
        std::getline(std::cin, UserInput);
        myfile << UserInput << "\n";

        std::cout << "what does the person like to do? ";
        std::getline(std::cin, UserInput);
        myfile << UserInput << "\n";
        std::cout << "where does the person live ?";
        std::getline(std::cin, UserInput);
        myfile << UserInput << "\n";
        myfile << "\n";
        myfile.close();


    
    }
    else if (UserInput == "no")
    {
        isRunning = false;
    } 
    }
    return 0;

}