#include <memory>

namespace bird::after
{
    // Types.h
    template <typename T, typename Parameter>
    class NamedType
        {
        public:
            explicit NamedType(T const& value) : value_(value) {}
            explicit NamedType(T&& value) : value_(std::move(value)) {}
            T& get() { return value_; }
            T const& get() const {return value_; }
        private:
            T value_;
        };

    struct SpeedParameter {};
    using Speed = NamedType<double, SpeedParameter>;

    struct LoadParameter {};
    using LoadFactor = NamedType<double, LoadParameter>;

    struct VoltageParameter {};
    using Voltage = NamedType<double, VoltageParameter>;

    struct CoconutParameter {};
    using Coconuts = NamedType<double, CoconutParameter>;

    // Config.h
    // #include "Types.h"
    struct MontyPython
    {
        Voltage voltage;
        bool isNailed;
    };
    struct Config
    {
        Speed baseSpeed;
        LoadFactor loadFactor;
        Coconuts number;
    };

    class IBird
    {
        public:
        virtual ~IBird() = default;
        virtual Speed getSpeed() const = 0;
    };

    class EuropeanBird final : public IBird
    {
        public:
        explicit EuropeanBird(const Config& config) : config_(config) {}
        Speed getSpeed() const override
        {
            return config_.baseSpeed;
        }
        private:
        Config config_;
    };

    class AfricanBird final : public IBird
    {
    public:
        explicit AfricanBird(const Config& config) : config_(config){};
        Speed getSpeed() const override
        {
            return config_.baseSpeed - config_.loadFactor * config_.number;
        }
    private:
        Config config_;
    };

    class NorwegianBlueBird final : public IBird
    {
    public:
        explicit NorwegianBlueBird(const MontyPython& config) : config_(config) {};
        Speed getSpeed() const override
        {
            return config_.isNailed ? Speed{0.0} : config_.isNailed * config_.voltage;
        }
    private:
        MontyPython config_;
    };


    class Bird
    {
    public:
        explicit Bird(std::unique_ptr<IBird> bird) : bird_(std::move(bird)){}

        [[nodiscard]] Speed getSpeed() const
        {
            return bird_->getSpeed();
        }

    private:
        std::unique_ptr<IBird> bird_;
    };
}
