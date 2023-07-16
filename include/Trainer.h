#ifndef TRAINER_H_
#define TRAINER_H_

#include <vector>
#include "Customer.h"
#include "Workout.h"
#include "Studio.h"

//typedef std::pair<int , Workout> OrderPair;
typedef std::pair<int, Workout> OrderPair;

class Trainer{
public:
    Trainer(int t_capacity);
    int getCapacity() const;
    void addCustomer(Customer* customer);
    void removeCustomer(int id);
    Customer* getCustomer(int id);
    std::vector<Customer*>& getCustomers();
    std::vector<OrderPair>& getOrders();
    void order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout>& workout_options);
    void openTrainer();
    void closeTrainer();
    int getSalary();
    bool isOpen();
    void addneworder(int id,Workout workout);
    void setsalary(int newsalary);
    int getrealtimecapacity() const;
     static std::string getStatus(bool status);
     void setid(int id);
     int getid() const;


// destructor:
    Trainer::~Trainer();
    //copy constructor:
    Trainer(const Trainer &other);
    //copy Assigment;
    Trainer& operator=(const Trainer &other);


private:
    int capacity;
    bool open;
    std::vector<Customer*> customersList;
    std::vector<OrderPair> orderList; //A list of pairs for each order for the trainer - (customer_id, Workout)
    int salary;
    int realtimecapacity;
    int trainerid;


};


#endif