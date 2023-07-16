//
// Created by Owner on 23/11/2021.
//

#include <sstream>
#include "../include/PrintWorkoutOptions.h"
#include "../include/Studio.h"
PrintWorkoutOptions::PrintWorkoutOptions() = default;

void PrintWorkoutOptions::act(Studio &studio) {
    vector<Workout> workoutvector = studio.getWorkoutOptions();
    for (Workout workout: workoutvector) {
        stringstream price;
        price << workout.getPrice();
        string output = "";
        price >> output;
        if (workout.getType() == ANAEROBIC) {
            cout << workout.getName() + "," + " " + "ANAEROBIC" + "," + " " + output;
        }
        if (workout.getType() == MIXED) {
            cout << workout.getName() + "," + " " + "Mixed" + "," + " " + output;
        }
        if (workout.getType() == CARDIO) {
            cout << workout.getName() + "," + " " + "Cardio" + "," + " " + output;
        }
    }
    complete();
}

std::string PrintWorkoutOptions::toString() const {

    return "workout_options";
}

BaseAction *PrintWorkoutOptions::clone() {
    return new PrintWorkoutOptions(*this);
}

PrintWorkoutOptions::~PrintWorkoutOptions() = default;
