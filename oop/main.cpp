#include <iostream>
#include "header.h"
#include "car.h"
#include <string>
#include <fstream>
#include <vector>
#include "stdlib.h"

using namespace std;

void ReadCar(string fl,vector<car> &cars);
void ReadBus(string fl,vector<bus> &buses);
void ReadRentals(string fl,vector<rental> &rentals);
void Example(string fl,vector<car> cars,vector<bus> buses,vector<rental> rentals);

int main()
{
    vector<car> cars;                 //define vectors to store all the information of car, bus and rental
    vector<bus> buses;
    vector<rental> rentals;

    string carsdata="car.txt";        // open the input and output file
    string busdata="bus.txt";
    string rentalsdata="rentals.txt";
    string outputfile="output.txt";


try{
  //read files into vector:
    ReadCar(carsdata,cars);
    ReadBus(busdata,buses);
    ReadRentals(rentalsdata,rentals);
    Example(outputfile,cars,buses,rentals);

}catch(error e){
        if(e==DateError){
            cout<<"The end date should be the same or after the start date"<<endl;
        }
        if(e==OpenFileError){
            cout<<"Unable to open the file."<<endl;
        }
        if(e==FuelTypeError){
            cout<<"The fuel type should only be gas,diesel,hybrid or electric"<<endl;
        }
    }
    return 0;
}




void ReadCar(string fl,vector<car> &cars)
{
   string tmp,tmp2;
   car c;
   size_t pos;
   ifstream file(fl.c_str());
   if(file.is_open()){
        while(!file.eof()){
                getline(file,tmp);
                if(tmp!=""){
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    c.setNumberPlate(tmp2);

                    tmp=tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    c.setyear(atoi(tmp2.c_str()));

                    tmp=tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    c.setFuelType(tmp2);

                    tmp=tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    c.setkms(atof(tmp2.c_str()));

                    tmp=tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    c.setRentalPricePerDay(atoi(tmp2.c_str()));

                    cars.push_back(c);   // put all the information of structure variables to cars vector
                }
        }
  file.close();           // close the file
 }
   else throw OpenFileError;

}



void ReadBus(string fl,vector<bus> &buses)
{
   string tmp,tmp2;
   bus b;
   size_t pos;
   ifstream file(fl.c_str());
   if(file.is_open()){
        while(!file.eof()){
                getline(file,tmp);
                if(tmp!=""){
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    b.setNumberPlate(tmp2);

                    tmp = tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    b.setyear(atoi(tmp2.c_str()));

                    tmp = tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    b.setFuelType(tmp2);

                    tmp = tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    b.setkms(atof(tmp2.c_str()));

                    tmp = tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    b.setRentalPricePerDay(atoi(tmp2.c_str()));
                    //capacity of bus
                    tmp = tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    b.setcapacity(atoi(tmp2.c_str()));

                    buses.push_back(b);   // use vectors to store all the information of bus
                }
    }
   file.close();
 }
   else throw OpenFileError;

}


void ReadRentals(string fl,vector<rental> &rentals)
{
   string tmp,tmp2;
   rental r;
   size_t pos;
   ifstream file(fl.c_str());
   if(file.is_open()){
        while(!file.eof()){
                getline(file,tmp);
                if(tmp!=""){
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    r.setStartDate(atoi(tmp2.c_str()));

                    tmp = tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    r.setEndDate(atoi(tmp2.c_str()));

                    tmp = tmp.substr(pos+1);
                    pos=tmp.find(" ");
                    tmp2=tmp.substr(0,pos);
                    r.setRentedCar(tmp2);

                    rentals.push_back(r);                  //use vectors to store all the information of rentals
                }
        }
   file.close();
   }
   else throw OpenFileError;
}

void Example(string fl,vector<car> cars,vector<bus> buses,vector<rental> rentals)
{

//show an example for working of the following functions and operators :
car car1("AAA666",2008,"gas",2888.8,5000);
rental firstrental(1,6,car1.getNumberPlate());

//a) length_of_rental
    cout<<"The length of rental is : "<<firstrental.length_of_rental()<<endl;
//b) price
    cout<<"The price of rental is : "<<firstrental.price(car1.getRentalPricePerDay())<<endl;
//c) operator+
    cout<<"After adding integer 666, then kms is:"<<666+car1.getkms()<<endl;


//A:How much income did the company have by renting out the cars? (We don't bother about expenses in the task)
int income=0;

unsigned int i=0;
while(i<rentals.size()){
    int IsCar=-1;
    for(unsigned int j=0;j<cars.size();j++){
        if(rentals.at(i).getRentedCar()==cars.at(j).getNumberPlate()){  // when there is car rented
            IsCar=j;                                                    // we assign the value of position of the car to IsCar
        }
    }
    if (IsCar>=0){
        int busprice=rentals.at(i).price(cars.at(IsCar).getRentalPricePerDay());
        income +=busprice;
    }

    i++;
}
cout<<"The income of company is :"<<income<<"  by renting cars."<<endl;

//B:For each car , give the count of days they were rented out :
  vector<countrent> V;
  countrent cc;
  unsigned int p=0;
  while(p<rentals.size()){
    int IsCar=-1;
    for(unsigned int j=0;j<cars.size();j++){
        if(rentals.at(p).getRentedCar()==cars.at(j).getNumberPlate()){
            IsCar=j;
        }
    }
    if (IsCar>=0){
            cc.Number=rentals.at(p).getRentedCar();
            cc.countdays=rentals.at(p).length_of_rental();
            V.push_back(cc);
    }
    p++;
}
for(unsigned int i =0;i<V.size();i++){
    cout<<V.at(i).Number<<"  "<<V.at(i).countdays<<endl;
}

//write to file:

     ofstream output(fl.c_str());
     if(output.is_open())
     {
         output<<"The length of rental is : "<<firstrental.length_of_rental()<<endl;
         output<<"The price of rental is : "<<firstrental.price(car1.getRentalPricePerDay())<<endl;
         output<<"After adding integer 666, kms is:"<<666+car1.getkms()<<endl;
         output<<"The income of company is :"<<income<<"  by renting cars."<<endl;
         for(unsigned int i =0;i<V.size();i++){
           output<<V.at(i).Number<<"  "<<V.at(i).countdays<<endl;
            }
         output.close();
     }
     else {throw OpenFileError;}
}
