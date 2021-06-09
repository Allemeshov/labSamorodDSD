#include <iostream>

#include "lab30/lab30.h"
#include "lab32/lab32.h"
#include "lab33/lab33.h"
#include "lab34/lab34.h"

int main() {
    int task = -1;
    bool isFinished = false;

    std::cout << "Hello, this is laboratory works by DSD theme." << std::endl;

    while (!isFinished) {
        std::cout << "\tInput, please, laboratory work number to display: ";
        std::cin >> task;

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
                std::cout << "\t\t30, 31, 32, 33, 34\n\n";
            }
        }
    }


    return 0;
}
