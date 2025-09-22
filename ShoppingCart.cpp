#include "ShoppingCart.h"
#include "Order.h"

// operator overloading
ShoppingCart& ShoppingCart::operator += (Product* a){
    if (a->getQuantity() > 0) {
        items.addItem(a);
        totalPrice += a->getPrice();
        totalQuantity++;
        a->updateQuantity(a->getQuantity() - 1); 
    } else {
        cout << "The product is out of stock!" << endl;
    }
    return *this;
}

ShoppingCart& ShoppingCart::operator -= (Product* a){
    removeProduct(a);
    return *this;
}
// print all items and total price and total quantity
void ShoppingCart::showCart(){
    cout << "Items in Shopping Cart: " << endl;
    items.printAll();
    cout << "Total Price: " << totalPrice << endl;
    cout << "Total Quantity: " << totalQuantity << endl;
}
// xóa toàn bộ giỏ hàng
void ShoppingCart::clearCart(){
    items = InventoryList<Product*>();
    totalPrice = 0;
    totalQuantity = 0;
}

void ShoppingCart::removeProduct(Product* p){
    auto item = items.findItem(p);
    if (item != nullptr){
        totalPrice -= (*item)->getPrice();
        totalQuantity -= 1;
        items.removeItem(*item);
    }
}

Order ShoppingCart::checkout(){
    cout << "Checking out..." << endl;
    static int orderId = 1; 
    Order newOrder(orderId++, "Customer", *this);
    clearCart();
    return newOrder;
}

//getter
double ShoppingCart::getTotalPrice() const{
    return totalPrice;
}
int ShoppingCart::getTotalQuantity() const{
    return totalQuantity;
}
InventoryList<Product*> ShoppingCart::getItems() const{
    return items;
}
