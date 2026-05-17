#include <algorithm>
#include <optional>
#include <string>
#include <span>
#include <array>

std::optional<std::string> FoundPerson(std::span<const std::string> people){
    static constexpr std::array<std::string_view, 3> candidates{"Don", "John", "Kent"};

    if (const auto it = std::ranges::find_first_of(people, candidates); it != people.end()) {
        return *it;
    }
    return std::nullopt;
}