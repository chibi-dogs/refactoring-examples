#include <string>
#include <span>

std::string FoundPerson(std::span<const std::string> people)
{
    for (const auto & person : people)
    {
        if (person == ("Don"))
        {
            return "Don";
        }
        if (person == ("John"))
        {
            return "John";
        }
        if (person == ("Kent"))
        {
            return "Kent";
        }
    }
    return "";
}