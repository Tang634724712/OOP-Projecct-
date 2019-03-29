#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include "car.h"
#include <vector>
#include <string>
#include "stdlib.h"
using namespace std;

struct countrent
{
    string Number;
    int countdays;
};

enum error{DateError,FuelTypeError,OpenFileError};




#endif // HEADER_H_INCLUDED
