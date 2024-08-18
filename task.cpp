#include <iostream>
#include <map>
#include <string>
#include <iomanip>

void displayMainMenu() {
    std::cout << "Welcome to the Currency Converter! Please choose an option:\n";
    std::cout << "1. Convert Currency\n";
    std::cout << "2. Exit\n";
}

void displayCurrencyMenu(const std::string& prompt) {
    std::cout << prompt << "\n";
    std::cout << "1. USD\n";
    std::cout << "2. EUR\n";
    std::cout << "3. GBP\n";
    std::cout << "Enter your choice: ";
}

std::string getCurrencyName(int choice) {
    switch (choice) {
        case 1: return "USD";
        case 2: return "EUR";
        case 3: return "GBP";
        default: return "";
    }
}

int main() {
    std::map<std::pair<std::string, std::string>, double> conversionRates = {
        {{"USD", "EUR"}, 0.85}, {{"USD", "GBP"}, 0.75},
        {{"EUR", "USD"}, 1.18}, {{"EUR", "GBP"}, 0.88},
        {{"GBP", "USD"}, 1.33}, {{"GBP", "EUR"}, 1.14},
        {{"USD", "USD"}, 1.00}, {{"EUR", "EUR"}, 1.00},
        {{"GBP", "GBP"}, 1.00}
    };

    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;

        if (choice == 1) {
            int sourceChoice, targetChoice;
            double amount;

            displayCurrencyMenu("Choose the source currency:");
            std::cin >> sourceChoice;
            std::string sourceCurrency = getCurrencyName(sourceChoice);
            if (sourceCurrency.empty()) {
                std::cout << "Invalid currency choice.\n";
                continue;
            }

            displayCurrencyMenu("Choose the target currency:");
            std::cin >> targetChoice;
            std::string targetCurrency = getCurrencyName(targetChoice);
            if (targetCurrency.empty()) {
                std::cout << "Invalid currency choice.\n";
                continue;
            }

            std::cout << "Enter amount in " << sourceCurrency << ": ";
            std::cin >> amount;
            if (amount < 0) {
                std::cout << "Amount must be positive.\n";
                continue;
            }

            double rate = conversionRates[{sourceCurrency, targetCurrency}];
            double convertedAmount = amount * rate;

            std::cout << "Converting " << amount << " " << sourceCurrency << " to " << targetCurrency << "…\n";
            std::cout << std::fixed << std::setprecision(2);
            std::cout << amount << " " << sourceCurrency << " is equivalent to " << convertedAmount << " " << targetCurrency << ".\n";

        } else if (choice != 2) {
            std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 2);

    std::cout << "Exiting the application. Goodbye!\n";
    return 0;
}