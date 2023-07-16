//
// Created by Owner on 09/11/2021.
//

#include "../include/Trainer.h"
#include "../include/Studio.h"
using namespace std;
Trainer::Trainer(int t_capacity):capacity(t_capacity),open(false),salary(0),realtimecapacity(0),trainerid(-1) {
    //capacity=t_capacity;
    //open= false;
    //customersList=std::vector<Customer*>();
    //orderList=std::vector<OrderPair>();
    //salary=0;
    //realtimecapacity=0;
    trainerid;

}

int Trainer::getCapacity() const {
    return capacity;
}
int Trainer::getrealtimecapacity()const{
    return realtimecapacity;
}

void Trainer::addCustomer(Customer *customer) {
    //we cant add the customer orderlist to the trainer hear because we dont posses the customer orderlist from the customer himself

    this->customersList.push_back(customer);
    realtimecapacity=realtimecapacity+1;

}

void Trainer::removeCustomer(int id) {
int salarytodecrease=0;
  std::vector<Customer*> newcustomer;
  std::vector<OrderPair> neworderlist;
  for(Customer* customer:customersList){
      if(customer!= getCustomer(id)){
          newcustomer.push_back(customer);
      }
  }
    //decreasing salary
    for(OrderPair orderPair:orderList){
        if(orderPair.first==id){
            salarytodecrease=salarytodecrease+orderPair.second.getPrice();
        }
    }
    this->setsalary(getSalary()-salarytodecrease);
  for(OrderPair orderPair:orderList){
      if(orderPair.first!=id){
          neworderlist.push_back(orderPair);
      }
  }
  customersList.clear();
  customersList=newcustomer;
  orderList.clear();
  orderList=neworderlist;
  realtimecapacity=realtimecapacity-1;


}

Customer *Trainer::getCustomer(int id) {
    for(Customer* customer :customersList){
        if(customer->getId()==id){
            return customer;
        }
    }
    throw "customer didnt found";

}

std::vector<Customer *> &Trainer::getCustomers() {

    return customersList;
}

std::vector<OrderPair> &Trainer::getOrders() {
    return orderList;
}

void
Trainer::order(const int customer_id, const std::vector<int> workout_ids, const std::vector<Workout> &workout_options)  {
    for(int i=0;i<workout_ids.size();i++){
        //addneworder(customer_id,workout_options[workout_ids[i]]);
        std::pair<int,Workout> pairtoadd = std::pair<int,Workout>(customer_id,workout_options[workout_ids[i]]);
        orderList.push_back(pairtoadd);
        salary=salary+workout_options[workout_ids[i]].getPrice();
    }

}
void Trainer::openTrainer() {
open= true;
}

void Trainer::closeTrainer() {
open= false;
realtimecapacity=0;
for(int i=customersList.size()-1;i>=0;i--){
    delete customersList[i];
    customersList[i]= nullptr;
    customersList.erase(customersList.begin()+customersList.size()-(i+1));
}
}

int Trainer::getSalary() {
    return salary;
}

bool Trainer::isOpen() {
    return open;
}


void Trainer::addneworder(int id, Workout workout) {
std::pair<int,Workout> pairtoadd = std::pair<int,Workout>(id,workout);
orderList.push_back(pairtoadd);
}

//copy constructor:
Trainer::Trainer(const Trainer &other) {
capacity=other.capacity;
open=other.open;
    customersList=vector<Customer*>();
    for(Customer *customer:other.customersList){
        customersList.push_back(customer->clone());
    }
    for(OrderPair orderPair:other.orderList){
        orderList.push_back(orderPair);
    }
salary=other.salary;
realtimecapacity=other.realtimecapacity;


}
//copy Assigment
Trainer &Trainer::operator=(const Trainer &other) {
    capacity=other.capacity;
    customersList=vector<Customer*>();
    open=other.open;
    for(Customer *customer:other.customersList){
        customersList.push_back(customer->clone());
    }
    for(OrderPair orderPair:other.orderList){
        orderList.push_back(orderPair);
    }

    return *this;
}

// destructor:
Trainer::~Trainer() {
    for(Customer* customer:customersList){
            delete customer;
    }
   orderList.clear();
}
void Trainer::setsalary(int newsalary) {
    salary=newsalary;
}


std::string Trainer::getStatus(bool status) {
    if(status){
        return "open";
    }
    else{
        return "closed";
    }
}

void Trainer::setid(int id) {
    trainerid=id;

}

int Trainer::getid() const {
    return this->trainerid;
}













