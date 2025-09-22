#include "Order.h"

//constructor
Order::Order(int id, string Name,const ShoppingCart& cart){
    this->id = id;
    this->customerName = Name;
    this->items = cart.getItems();
    this->totalPrice = cart.getTotalPrice();
    this->totalQuantity = cart.getTotalQuantity();
    this->status = "Pending";
}
// Xác nhận đơn hàng
bool Order::confirmOrder(){
    if (status == "Pending"){
        status = "Confirmed";
        return true;
    }
    else {
        cout << "Order already confirmed or shipped." << endl;
        return false;
    }
}
//in đơn hàng
void Order::displayOrder(){
    cout << "Order Information: " << endl;
    cout << "- Order ID: " << id << endl;
    cout << "- Customer Name: " << customerName << endl;
    cout << "- Status: " << status << endl;
    cout << "- Total Quantity: " << totalQuantity << endl;
    cout << "- Total Price: " << totalPrice << endl;
    cout << "- Items in Order: " << endl;
    items.printAll();
    cout << endl;
}
// Áp dụng giảm giá
double Order::applyDiscount(double rate) {
    totalPrice = totalPrice * (1 - rate);
    return totalPrice;
}

//setter
void Order::setStatus(const string& newStatus){
    status = newStatus;
}   

//getter
int Order::getId() const {
    return id;
}
string Order::getCustomerName() const {
    return customerName;
}
string Order::getStatus() const {
    return status;
}
double Order::getTotalPrice() const {
    return totalPrice;
}
int Order::getTotalQuantity() const {
    return totalQuantity;
}