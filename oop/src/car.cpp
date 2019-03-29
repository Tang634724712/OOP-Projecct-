#include <iostream>
#include "car.h"
#include "header.h"
using namespace std;
car::car()
{
        NumberPlate="default";
        year=1999;
        FuelType="gas";
        kms=1000.0;
        RentalPricePerDay=1;
		

}
car::car(string a,int b,string c,float d,int e)
{
        NumberPlate=a;
        year=b;
        if(c=="gas"||"diesel"||"hybrid"||"electric"){
            FuelType=c;
        }else {throw FuelTypeError;}
        kms=d;
        RentalPricePerDay=e;


}
car::~car()
{

}

void car::setNumberPlate(string a){
    NumberPlate=a;
}
void car::setyear(int a){
    year=a;
}
void car::setFuelType(string c){
   if(c=="gas"||"diesel"||"hybrid"||"electric"){
            FuelType=c;
        }else {throw FuelTypeError;}
}
void car::setkms(float a){
    kms=a;
}
void car::setRentalPricePerDay(int a){
    RentalPricePerDay=a;
}

string car::getNumberPlate(void){
    return NumberPlate;
}
int car::getyear(void){
    return year;
}
string car::getFuelType(void){
    return FuelType;
}
float car::getkms(void){
    return kms;
}
int car::getRentalPricePerDay(void){
    return RentalPricePerDay;
}

float car::operator+(const float &data)const{
    return (kms+data);
}

//bus class:
bus::bus(){
        NumberPlate="default";
        year=1999;
        FuelType="gas";
        kms=1000.0;
        RentalPricePerDay=1;
        capacity=10;

}
bus::bus(string a,int b,string c,float d,int e,int f):car(a,b,c,d,e),capacity(f){

}
bus::~bus()
{

}
void bus::setcapacity(int c){
    capacity=c;
}
int bus::getcapacity(void){
    return capacity;
}


rental::rental()
{
    StartDate=0;
    EndDate=1;
    RentedCar="AAAAAA";
}
rental::rental(int a,int b,string c){

    StartDate=a;
    EndDate=b;
    RentedCar=c;
    if(a>b) {throw DateError;}
}
//rental::rental(int a,int b,string d,int e,string f,float g,int h):StartDate(a),EndDate(b),car(d,e,f,g,h){

//}

rental::~rental()
{

}
void rental::setStartDate(int a){
    StartDate=a;
}
void rental::setEndDate(int b){
    EndDate=b;
    if(StartDate>EndDate) throw DateError;
}
void rental::setRentedCar(string c){
    RentedCar=c;
}

int rental::getStartDate(void){
    return StartDate;
}
int rental::getEndDate(void){
    return EndDate;
}
string rental::getRentedCar(void){
    return RentedCar;
}


int rental::length_of_rental(){
    return(EndDate-StartDate);
}

//calculate the rental price with length_of_rental and RentalPricePerDay .
int rental::price(int pri){

    return length_of_rental()*pri;
}
