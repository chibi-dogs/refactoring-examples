#include <algorithm>
#include <variant>
#include <vector>

//Product.h
struct Product
{
    double quantity;
    double price;
};

//Discounts.h
struct USDiscount {static constexpr double factor{0.85};};
struct RUDiscount {static constexpr double factor{0.75};};
struct CNDiscount {static constexpr double factor{0.9};};

using Discount = std::variant<USDiscount, RUDiscount, CNDiscount>;

template<class... Ts>
struct overloaded : Ts... {
    using Ts::operator()...;
};

//User.h
struct User
{
    Discount discount;
};


// Order.h and Order.cpp if separating header from source
class Order
{
public:
    explicit Order(const User& user, std::vector<Product> products)
        : user_{user}
        , products_(std::move(products))
    {}

    [[nodiscard]] double calculateTotal() const
    {
        const double total = std::ranges::fold_left(products_, 0.0, [](double acc, const auto& product){return acc + (product.price * product.quantity);});
        return applyRegionalDiscounts(total);
    }

    [[nodiscard]] double applyRegionalDiscounts(double total) const
    {
        return std::visit([total](const auto& discount) {
            return total * discount.factor;
        }, user_.discount);
    }

private:
    User user_;
    std::vector<Product> products_;
};