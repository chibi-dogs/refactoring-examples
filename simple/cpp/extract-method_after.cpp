#include <print>

void printBanner(){}
std::string getOutstanding() { return "42.00"; }

[[nodiscard]] std::string formatDetails(std::string_view name, std::string_view outstanding)
{
    return std::format("name: {}\namount: {}\n", name, outstanding);
}

void printDetails(std::string_view name) {
    printBanner();
    std::println("{}", formatDetails(name, getOutstanding()));
}