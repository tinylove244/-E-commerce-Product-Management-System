#include "Product.h"

//constructor
Product::Product(int id, string name, double price, int quantity){
        this->id = id;
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

Product::~Product() {}

//Method: print information of product
void Product::printInformation(){
    cout << "Product information: " << name << endl;
    cout << "- Id: " << id << endl;
    cout << "- Price: " << price << endl;
    cout << "- Quantity available: " << quantity << endl;
}

//Phương thức: giảm giá sản phẩm
double Product::applyDiscount(double rate) {
    if (rate < 0 || rate > 1) {
        cout << "Invalid discount rate";
        return price;
    }
    else {
        return price - rate*price;
    }
}

//operator overloading
// dùng trong so sánh 2 sản phẩm
bool Product::operator==(const Product& other) const {
    return (this->name == other.name && this->price == other.price);
}
// để sắp xếp các sản phẩm theo giá tăng dần
bool Product::operator < (const Product& other) const{
    return (this->price < other.price);
}
    
//setter
void Product::updateQuantity(int qty){
    quantity = qty;
}

//getter
int Product::getId() const {
    return id;
}
string Product::getName() const{
    return name;
}
double Product::getPrice() const {
    return price;
}
int Product::getQuantity() const{
    return quantity;
}

