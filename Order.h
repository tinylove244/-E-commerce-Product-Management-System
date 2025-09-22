#pragma once
#include "InventoryList.h"
#include "ShoppingCart.h"
#include "Product.h"

class ShoppingCart;

class Order : public Discountable {
private:
    InventoryList<Product*> items;
    int id;
    string customerName;
    double totalPrice;
    int totalQuantity;
    string status; //Ex: "Pending" , "Confirmed" , "Shipped"
public:
    //constructor
    Order(int id, string Name, const ShoppingCart& cart);
    // Xác nhận đơn hàng
    bool confirmOrder();
    //in đơn hàng
    void displayOrder();
    // Áp dụng giảm giá
    double applyDiscount(double rate) override;

    //setter
    void setStatus(const string& newStatus);

    //getter
    int getId() const;
    string getCustomerName() const;
    string getStatus() const;
    double getTotalPrice() const;
    int getTotalQuantity() const;

};