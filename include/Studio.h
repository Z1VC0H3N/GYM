#ifndef STUDIO_H_
#define STUDIO_H_

#include <vector>
#include <string>
#include "Workout.h"
#include "Trainer.h"
#include "Action.h"

class Trainer;

class Studio{		
public:
    Studio();
    Studio(const std::string &configFilePath);
    void start();
    int getNumOfTrainers() const;
    Trainer* getTrainer(int tid);
	const std::vector<BaseAction*>& getActionsLog() const; // Return a reference to the history of actions
    std::vector<Workout>& getWorkoutOptions();
    std::vector<Trainer*>& getTrainers();
    static std::vector<std::string> split(std::string data, const std::string& delimiter) ;
    //destructor
    Studio::~Studio();
    //copy constructor
    Studio(const Studio &s);
    //copy Assigment
    Studio& operator=(const Studio & other);


private:
    bool open;
    std::vector<Trainer*> trainers;
    std::vector<Workout> workout_options;
    std::vector<BaseAction*> actionsLog;
    int idcustomer;


};

#endif