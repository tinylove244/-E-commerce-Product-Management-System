#include <iostream>
#include "Product.h"
#include "Electronic.h"
#include "ShoppingCart.h"
#include "Order.h"
using namespace std;

int main() {
    // ---------- Test case 1: Tạo sản phẩm và in thông tin ----------
    cout << "===== TEST CASE 1: PRODUCT INFO =====" << endl;
    Product p1(1, "Book", 50000, 10);
    Electronic e1(2, "Laptop", 15000000, 5, 24, 200000, 65);

    p1.printInformation();
    cout << endl;
    e1.printInformation();
    cout << endl;

    // ---------- Test case 2: ShoppingCart add/remove ----------
    cout << "===== TEST CASE 2: SHOPPING CART ADD/REMOVE =====" << endl;
    ShoppingCart cart;
    cart += &p1;   // add book
    cart += &e1;   // add laptop
    cart.showCart();

    cart.removeProduct(&p1); // remove book
    cout << "\nAfter removing Book:" << endl;
    cart.showCart();
    cout << endl;

    // ---------- Test case 3: Apply discount trên Product và Order ----------
    cout << "===== TEST CASE 3: DISCOUNT =====" << endl;
    cout << "Book price before discount: " << p1.getPrice() << endl;
    p1.applyDiscount(0.2); // giảm 20%
    cout << "Book price after 20% discount: " << p1.getPrice() << endl;

    cout << "Laptop price with 50% discount (but max 30% allowed): "
         << e1.applyDiscount(0.5) << endl;
    cout << endl;

    // ---------- Test case 4: Checkout và Order ----------
    cout << "===== TEST CASE 4: CHECKOUT =====" << endl;
    cart += &p1;   // add book again
    cart += &e1;   // add laptop again
    cart.showCart();

    Order order1 = cart.checkout(); // checkout sẽ clear cart
    order1.displayOrder();

    cout << "\nApply 10% discount to order:" << endl;
    order1.applyDiscount(0.1);
    order1.displayOrder();

    return 0;
}
