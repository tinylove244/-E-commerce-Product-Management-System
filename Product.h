#pragma once
#include <iostream>
#include <string>
#include "Discountable.h"

// Lớp cha của Electronics
class Product : public Discountable{
protected:
    int id;
    string name;
    double price;
    int quantity;
public:
    // Constructor
    Product(int id, string name, double price, int quantity);

    virtual ~Product();
    
    // Method: display
    void printInformation(); // ghi đè

    //getter
    int getId() const;
    string getName() const;
    double getPrice() const;
    int getQuantity() const;

    //setter
    void updateQuantity(int qty);

    // Phương thức: Giảm giá sản phẩm
    double applyDiscount(double rate) override ;

    // operator overloading
    bool operator==(const Product& other) const ; // dùng trong so sánh 2 sản phẩm
    bool operator < (const Product& other) const; // để sắp xếp các sản phẩm theo giá tăng dần
    
};