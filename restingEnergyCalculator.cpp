// Copyright (c) 2023 Zak Goneau All rights reserved.
//
// Created by: Zak Goneau
// Date Created: Dec. 6, 2023
// This program calculates the resting energy of the mass
// of something using Einstein's Theory of Relativity.

#include <string>
#include <cmath>
#include <iostream>

// define calculating resting energy function
float CalculateRestingEnergy(float mass) {
    // define energy variable
    float energy;

    // declare speed of light constant
    const int SPEED_OF_LIGHT = 299792458;

    // calculate resting energy
    energy = mass * pow(SPEED_OF_LIGHT, 2);

    // return energy
    return energy;
}

int main() {
    // declare variables
    std::string userMassStr, userAnswer;
    float userMassFloat, restingEnergy;

    // introduce program to user
    std::cout << "Hello, this program will calculate the amount of ";
    std::cout << "resting energy a mass contains using ";
    std::cout << "Einstein's Theory of Relativity." << std::endl;

    // get mass from user
    std::cout << "Please enter a positive mass: ";
    std::cin >> userMassStr;

    try {
        // try casting input string to float
        userMassFloat = std::stof(userMassStr);

        // check if number is bigger than zero
        if (userMassFloat > 0) {

            // call function
            restingEnergy = CalculateRestingEnergy(userMassFloat);

            // display result to user
            std::cout << "The resting mass of something that is ";
            std::cout << userMassFloat << "kg is " << restingEnergy;
            std::cout << " joules." << std::endl;

            // do while loop asking play again
            do {
                // ask to play again
                std::cout << "Do you want to play again? (y or n): ";
                std::cin >> userAnswer;

                // check if valid answer
                if (userAnswer == "y" || userAnswer == "n") {

                    // check if they answer yes specifically
                    if (userAnswer == "y") {

                        // get mass from user
                        std::cout << "Please enter a positive mass: ";
                        std::cin >> userMassStr;

                        // try casting input string to float
                        try {
                            userMassFloat = std::stof(userMassStr);

                            // check if number is bigger than zero
                            if (userMassFloat > 0) {

                                // call function
                                restingEnergy = CalculateRestingEnergy(userMassFloat);

                                // display result to user
                                std::cout << "The resting mass of something ";
                                std::cout << "that is " << userMassFloat;
                                std::cout << "kg is " << restingEnergy;
                                std::cout << " joules." << std::endl;

                            // tell user invalid number
                            } else {
                                std::cout << "Your number must be larger than";
                                std::cout << " zero, which " << userMassFloat;
                                std::cout << " is not." << std::endl;
                            }

                        // catch invalid inputs from user
                        }
                        catch (std::invalid_argument) {
                            std::cout << "" << userMassStr << " is not a valid";
                            std::cout << " positive number." << std::endl;
                        }

                        // end program and thank user
                    } else {
                        std::cout << "Thank you for playing!" << std::endl;
                        break;
                    }

                // tell user invalid response
                } else {
                    std::cout << "Invalid answer you must answer ";
                    std::cout << "y or n. Try again." << std::endl;
                }

            // loop as long as user doesn't say no
            } while (userAnswer != "n");

        // tell user no numbers zero or under
        } else {
            std::cout << "Your number must be larger ";
            std::cout << "than zero, which ";
            std::cout << userMassFloat << " is not." << std::endl;
        }

    // catch invalid inputs
    } catch (std::invalid_argument) {
        std::cout << "" << userMassStr << " is not a valid";
        std::cout << " positive number." << std::endl;
    }
}
