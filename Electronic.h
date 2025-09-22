#include "Product.h"

class Electronic : public Product{
private: // Encapsolution
    int warrantyMonths;
    double shippingFee;
    double powerUsage;
public:
    //constructor
    Electronic(int id, string name, double price, int quantity, int warrantyMonts, double shippingFee, double powerUsage);
    // Method: Print information of Product
    void printInformation() ;
    //getter
    int getWarrantyMonths() const;
    double getShippingFee() const;
    double getPowerUsage() const;
    
    // Phương thức: Tính tổng tiền bao gồm phí ship
    double getTotalPrice() const;
    // Phương thức: Tính điện năng tiêu thụ một tháng ( nhập vào số giờ sử dụng / ngày)
    double estimateMonthlyUsage(int hoursPerDay) const;

    // Phương thức: Giảm giá sản phẩm
    double applyDiscount(double rate) override ;

};