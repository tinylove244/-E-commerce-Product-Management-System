#include "Electronic.h"

//constructor
Electronic::Electronic(int id, string name, double price, int quantity, int warrantyMonths, double shippingFee, double powerUsage) : Product (id, name, price, quantity){
    this->warrantyMonths = warrantyMonths;
    this->shippingFee = shippingFee;
    this->powerUsage = powerUsage;
}

// Method: Print information of Product
void Electronic::printInformation() {
    cout << "Electronic " ;
    Product::printInformation();
    cout << "Warranty: " << warrantyMonths << "monts. " << endl;
    cout << "Shipping Fee: " << shippingFee << "VND " << endl;
    cout << " Power Usage: " << powerUsage << " W" << endl;
}

//getter
int Electronic::getWarrantyMonths() const {
    return warrantyMonths;
}
double Electronic::getShippingFee() const{
    return shippingFee;
}
double Electronic::getPowerUsage() const {
    return powerUsage;
}

// Phương thức: Giảm giá sản phẩm (ghi đè) : đặc biệt, giảm không quá 30% và trả về tổng (có cả phí ship)
double Electronic::applyDiscount(double rate) {
    if (rate < 0 || rate > 1){
        cout << "Invalid discount rate !!! " << endl;
        return price + shippingFee;
    }
    if (rate > 0.3){
        rate = 0.3;
    }
    return price * (1 - rate) + shippingFee;
}

// Phương thức: Tính điện năng tiêu thụ một tháng ( nhập vào số giờ sử dụng / ngày)
double Electronic::estimateMonthlyUsage(int hoursPerDay) const {
    return (powerUsage/1000)*hoursPerDay*30;
}