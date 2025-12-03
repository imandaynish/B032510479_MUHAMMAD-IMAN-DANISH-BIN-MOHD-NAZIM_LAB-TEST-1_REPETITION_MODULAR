#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes

double getPrice(int roomType);
double calculateDiscount(int nights);
double computeAmount(double pricePerNight, int nights, double discountRate, double& discountAmount);
double applyPromo(double finalPrice, char promoCode);
void displaySummary(double pricePerNight, int nights, double subtotal, double discountAmount, double finalPrice);
void displayMessage(double finalPrice);


int main() {
    char repeat;
    do {
        int roomType, numberOfNights;
        double pricePerNight, discountRate, discountAmount, finalPrice, subtotal;
        char promoCode;

        cout << "\n=========================================\n";
        cout << "\t\n   FTMK GRAND HOTEL BOOKING SYSTEM   \n";
        cout << "\n=========================================\n";

        cout << "\n1. Standard Room - RM 150.00 per night\n";
        cout << "2. Deluxe Room   - RM 200.00 per night\n";
        cout << "3. Suite Room    - RM 300.00 per night\n";

        cout << "\nEnter room type (1-3): ";
        cin >> roomType;

        cout << "Enter number of nights: ";
        cin >> numberOfNights;

        // Function Calls
        
        // Get price per night
        pricePerNight = getPrice(roomType);
        if (pricePerNight == 0.0) return 0; // invalid room type

        // Calculate discount rate
        discountRate = calculateDiscount(numberOfNights);

        // Compute subtotal and final price
        subtotal = pricePerNight * numberOfNights;
        finalPrice = computeAmount(pricePerNight, numberOfNights, discountRate, discountAmount);

        // Promo code
        cout << "\nDo you have promo code? (Y/N): ";
        cin >> promoCode;
        finalPrice = applyPromo(finalPrice, promoCode);

        // Display summary and message
        displaySummary(pricePerNight, numberOfNights, subtotal, discountAmount, finalPrice);
        displayMessage(finalPrice);

        cout << "\nDo you want to make another booking? (Y/N): ";
        cin >> repeat;

    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

// Function Definitions

// Function to get price per night based on room type
double getPrice(int roomType) {
    if (roomType == 1) {
        cout << "\nYou selected Standard Room.\n";
        return 150.00;
    }
    else if (roomType == 2) {
        cout << "\nYou selected Deluxe Room.\n";
        return 200.00;
    }
    else if (roomType == 3) {
        cout << "\nYou selected Suite Room.\n";
        return 300.00;
    }
    else {
        cout << "\nInvalid Room Type. Please Enter A Valid Room Type.\n";
        return 0.0;
    }
}

// Function to calculate discount rate based on nights stayed
double calculateDiscount(int nights) {
    if (nights >= 3 && nights <= 5) {
        return 0.05;
    }
    else if (nights > 5) {
        return 0.10;
    }
    return 0.0;
}

// Function to compute subtotal, discount amount, and final price
double computeAmount(double pricePerNight, int nights, double discountRate, double& discountAmount) {
    double total = pricePerNight * nights;
    discountAmount = total * discountRate;
    return total - discountAmount;
}

// Function to apply promo code discount
double applyPromo(double finalPrice, char promoCode) {
    if (promoCode == 'Y' || promoCode == 'y') {
        finalPrice *= 0.9; // extra 10% discount
        cout << "\nPrice after applying promo code discount: RM"
            << fixed << setprecision(2) << finalPrice << endl;
    }
    return finalPrice;
}

// Function to display booking summary
void displaySummary(double pricePerNight, int nights, double subtotal, double discountAmount, double finalPrice) {
    cout << fixed << setprecision(2);
    cout << "\n------------------ BOOKING SUMMARY ------------------\n";
    cout << "Price per night  : RM " << pricePerNight << endl;
    cout << "Nights Stayed    : " << nights << endl;
    cout << "Subtotal         : RM " << subtotal << endl;
    cout << "Discount         : RM " << discountAmount << endl;
    cout << "Final Total      : RM " << finalPrice << endl;
}

// Function to display VIP/customer message
void displayMessage(double finalPrice) {
    cout << "----------------------------------------------------\n";
    if (finalPrice > 1200) {
        cout << "VIP CUSTOMER: You are eligible for free airport transfer.\n";
    }
    else if (finalPrice < 300) {
        cout << "VIP CUSTOMER: Enjoy your vacation.\n";
    }
    else {
        cout << "Thank you for booking with FTMK Grand Hotel.\n";
    }
    cout << "====================================================\n";
}
