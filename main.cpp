#include <iostream>

#include "lab30/lab30.h"
#include "lab32/lab32.h"
#include "lab33/lab33.h"
#include "lab34/lab34.h"

bool isValid(std::string input);

int main() {
    int task = -1;
    bool isFinished = false;
    std::string input;

    std::cout << "Hello, this is laboratory works by DSD theme." << std::endl;

    while (!isFinished) {
        std::cout << "\n\n\tInput, please, laboratory work number to display: ";
        std::cin >> input;

        if (input == "exit") {
            std::cout << "\n\tGoodbye!\n";
            return 0;
        }

        if (!isValid(input))
            continue;

        task = std::stoi(input);

        switch (task) {
            case 30:
            case 31: {
                lab30();
                break;
            }
            case 32: {
                lab32();
                break;
            }
            case 33: {
                lab33();
                break;
            }
            case 34: {
                lab34();
                break;
            }
            case -1: {
                isFinished = true;
                break;
            }
            default: {
                std::cout << "\n\tError! Your task number is invalid!\n\tPlease, input any number from the list:";
                std::cout << std::endl;
                std::cout << "\t\t30, 31, 32, 33, 34\n";
                std::cout << "\tTo quite input 'exit'\n\n";
            }
        }
    }


    return 0;
}

bool isValid(std::string input) {
    bool res = true;
    for (int i = 0;; ++i) {
        if (input[i] == '\0') {
            break;
        } else if (!isdigit(input[i])) {
            res = false;
            break;
        }
    }
    return res;
}
