#include <format>
#include <print>
#include <span>
#include <string>

struct User
{
    std::string name;
    std::string age;
};
void printProperties(const std::span<const User> users)
{
    for (const auto& [name, age] : users)
    {
        std::print("{}", std::format("{} {}\n", name, age));
    }
}