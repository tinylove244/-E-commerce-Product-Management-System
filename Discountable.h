#pragma once
#include <iostream>
using namespace std;

// đây là interface: quy định về các phương thức giảm giá 
class Discountable{
public:
    virtual double applyDiscount(double rate) = 0;
};