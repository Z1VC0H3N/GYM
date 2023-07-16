//
// Created by Owner on 09/11/2021.
//

#include "../include/Customer.h"

using namespace std;

Customer::Customer(std::string c_name, int c_id) :name(c_name), id(c_id) {
}

std::string Customer::getName() const {
    return name;
}

int Customer::getId() const {
    return id;
}

Customer::~Customer() {
//dont touch!!!!!!!
}

SweatyCustomer::SweatyCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> SweatyCustomer::order(const std::vector<Workout> &workout_options) {
    vector<int> swt= vector<int>();
    for(Workout workout:workout_options){
        if(workout.getType()==CARDIO){
            swt.push_back(workout.getId());
        }
    }
    return swt;
}

std::string SweatyCustomer::toString() const {
    return "swt";
}

SweatyCustomer *SweatyCustomer::clone() {
    return new SweatyCustomer(*this);
}

CheapCustomer::CheapCustomer(std::string name, int id) : Customer(name, id) {


}

std::vector<int> CheapCustomer::order(const std::vector<Workout> &workout_options) {
    vector<int> chp = vector<int>();
    int id=0;
    int findcheap =workout_options[0].getPrice();
    for (Workout workout: workout_options)
         {
        if(workout.getPrice()<findcheap) {
            findcheap = workout.getPrice();
            id=workout.getId();
        }
        }
   chp.push_back(id);
    return chp;
}

std::string CheapCustomer::toString() const {
    return "chp";
}

CheapCustomer *CheapCustomer::clone() {
    return new CheapCustomer(*this);
}

HeavyMuscleCustomer::HeavyMuscleCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> HeavyMuscleCustomer::order(const std::vector<Workout> &workout_options) {
    vector<int> mcl = vector<int>();
    vector<int> tosort=vector<int>();
    int x=0;
    int i=0;
    for(Workout workout:workout_options){
        if(workout.getType()==ANAEROBIC){
            tosort.push_back(workout.getPrice());
            x++;

        }
        i=i+1;
    }
    vector<int> realarr=vector<int>();
    for(int k=0;k<x;k++){
        realarr.push_back(tosort[k]);
    }
sort(realarr,0,x-1);
    for(int k=x-1;k>=0;k--){
        for(Workout workout:workout_options){
            if(realarr[k]==workout.getPrice() & workout.getType()==ANAEROBIC){
                mcl.push_back(workout.getId());
            }
        }
    }
    
    return mcl;
}

std::string HeavyMuscleCustomer::toString() const {
    return "mcl";
}

void HeavyMuscleCustomer::sort(vector<int> arr, int x, int y) {
    int pivot = arr[x];
    int p = x + 1;
    int q = y;

    while (p < q) {
        while (arr[q] > pivot && p < q)
            q--;
        while (arr[p] <= pivot && p < q)
            p++;
        swap(arr, p, q);

    }
    swap(arr,x,p);

}

void HeavyMuscleCustomer::swap(vector<int> a, int x, int y) {
    int temp=a[x];
    a[x]=a[y];
    a[y]=temp;
}

HeavyMuscleCustomer *HeavyMuscleCustomer::clone() {
    return new HeavyMuscleCustomer(*this);
}

FullBodyCustomer::FullBodyCustomer(std::string name, int id) : Customer(name, id) {

}

std::vector<int> FullBodyCustomer::order(const std::vector<Workout> &workout_options) {
    vector<int> fbd = vector<int>();
    int chipestcardio=0;
    int chipcardioId=0;
    int mostexpensivemixed=0;
    int expensivemixedId=0;
    int chipesterobi=0;
    int chiperobiId=0;
    for(Workout workout:workout_options){
        if(workout.getType()==CARDIO){
            chipestcardio=workout.getPrice();
            break;
        }
    }
    for(Workout workout:workout_options){
        if(workout.getType()==MIXED){
            mostexpensivemixed=workout.getPrice();
            break;
        }
    }
    for(Workout workout:workout_options){
        if(workout.getType()==ANAEROBIC){
            chipesterobi=workout.getPrice();
            break;
        }
    }
    for(Workout workout:workout_options){
        if(workout.getType()==CARDIO & workout.getPrice()<chipestcardio){
            chipestcardio=workout.getPrice();
            chipcardioId=workout.getId();
        }
    }
    for(Workout workout:workout_options){
        if(workout.getType()==MIXED & workout.getPrice()>mostexpensivemixed){
            mostexpensivemixed=workout.getPrice();
            expensivemixedId=workout.getId();
        }
    }
    for(Workout workout:workout_options){
        if(workout.getType()==ANAEROBIC & workout.getPrice()<chipesterobi){
            chipesterobi=workout.getPrice();
            chiperobiId=workout.getId();
        }
    }
    fbd.push_back(chipcardioId);
    fbd.push_back(expensivemixedId);
    fbd.push_back(chiperobiId);
    return fbd;

}

std::string FullBodyCustomer::toString() const {
    return "fbd";
}

FullBodyCustomer *FullBodyCustomer::clone() {
    return new FullBodyCustomer(*this);
}


