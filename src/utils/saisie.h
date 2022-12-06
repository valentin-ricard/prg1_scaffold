//
// Created by ValentinRicard on 21.11.2022.
//

#ifndef PRG_HEIG_SAISIE_H
#define PRG_HEIG_SAISIE_H

#include <vector>
#include <iostream>
#include <string>

int getInt(
        const std::string &prompt,
        const std::string &errorPrompt,
        int min = std::numeric_limits<int>::min(),
        int max = std::numeric_limits<int>::max(),
        bool (*func)(int) = [](int){ return true; }
        ) {
    int input;
    bool error;

    do {
        // Input and verification
        std::cout << prompt << " [" << min << ".." << max << "] : ";
        error = not(std::cin >> input) or input < min or input > max or not func(input);

        // Check if the input is invalid
        if (error) {
            std::cout << errorPrompt << std::endl;
            std::cin.clear();
        }

        // Clear the buffer (to avoid double inputs in the same line)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (error);

    // return the provided input
    return input;
}

#endif//PRG_HEIG_SAISIE_H
