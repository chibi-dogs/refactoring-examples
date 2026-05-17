#include <iostream>
#include <format>

void printBanner(){}
std::string getOutstanding() { return "42.00"; }

void printDetails(std::string_view name) {
    printBanner();

    // print details
    std::cout << std::format("name: {}\n", name);
    std::cout << std::format("amount: {}\n",  getOutstanding());
}