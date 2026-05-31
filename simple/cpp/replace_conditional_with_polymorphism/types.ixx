export module types;

#include <utility>

export template <typename T, typename Parameter>
class NamedType
{
public:
    explicit NamedType(T const& value) : value_(value) {}
    explicit NamedType(T&& value) : value_(std::move(value)) {}

    T& get() { return value_; }
    T const& get() const { return value_; }

private:
    T value_;
};

export struct SpeedParameter {};
export using Speed = NamedType<double, SpeedParameter>;

export struct LoadParameter {};
export using LoadFactor = NamedType<double, LoadParameter>;

export struct VoltageParameter {};
export using Voltage = NamedType<double, VoltageParameter>;

export struct CoconutParameter {};
export using Coconuts = NamedType<double, CoconutParameter>;