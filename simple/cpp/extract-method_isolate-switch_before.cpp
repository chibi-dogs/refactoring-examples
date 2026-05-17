#include <vector>

enum class Country
{
    US,
    RU,
    CN
};

struct User
{
    Country country;
};

struct Product
{
    double quantity;
    double price;
};

class Order
{
public:
    explicit Order(const User& user, std::vector<Product> products)
        : user_{user}
        , products_(std::move(products))
        {}
    [[nodiscard]] double calculateTotal() const
    {
        double total = 0;
        for (const auto& [quantity, price] : products_)
        {
            total += price * quantity;
        }
        switch (user_.country)
        {
        case Country::US: total *= 0.85; break;
        case Country::RU: total *= 0.75; break;
        case Country::CN: total *= 0.9; break;
        }
        return total;
    }

private:
    User user_;
    std::vector<Product> products_;
};
