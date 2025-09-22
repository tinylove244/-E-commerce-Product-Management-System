#pragma once
#include "Product.h"
#include "InventoryList.h"
#include <vector>
#include <cmath>

class Order; // forward declaration

class ShoppingCart{
private:
    InventoryList<Product*> items;
    double totalPrice = 0;
    int totalQuantity;
public:
    ShoppingCart(){
        totalPrice = 0;
        totalQuantity = 0;
    } 
    // operator overloading
    ShoppingCart& operator += (Product* a);
    ShoppingCart& operator -= (Product* a);
    // print all items and total price and total quantity
    void showCart();
    // xóa toàn bộ giỏ hàng
    void clearCart();

    void removeProduct(Product* p);

    Order checkout();

    //getter
    double getTotalPrice() const;
    int getTotalQuantity() const;
    InventoryList<Product*> getItems() const;
};