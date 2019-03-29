#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "header.h"
using namespace std;


class car
{
    public:
        car();
        car(string,int,string,float,int);
        virtual ~car();
        //getters and setters
        void setNumberPlate(string);
        void setyear(int);
        void setFuelType(string);
        void setkms(float);
        void setRentalPricePerDay(int);

        string getNumberPlate(void);
        int getyear(void);
        string getFuelType(void);
        float getkms(void);
        int getRentalPricePerDay(void);

      //+operator: adds an integer parameter to the kms data member
        float operator+(const float &)const;


    protected:
        string NumberPlate;
        int year;
        string FuelType;      //can only be {"gas","diesel","hybrid","electric"};
        float kms;
        int RentalPricePerDay;



    private:

};



class bus : public car{
    public:
        bus();
        bus(string,int,string,float,int,int);
        virtual ~bus();
        void setcapacity(int);
        int getcapacity(void);
    private:
        int capacity;

};

class rental
{
    public:
        rental();
        rental(int,int,string);
        rental(int,int,string,int,string,float,int);
        virtual ~rental();
        //getters and setters:
        void setStartDate(int);
        void setEndDate(int);
        void setRentedCar(string);

        int getStartDate(void);
        int getEndDate(void);
        string getRentedCar(void);
        //length of rental:
        int length_of_rental();
        int price(int);

    protected:


    private:
        int StartDate;
        int EndDate;
        string RentedCar;


};

#endif // CAR_H
