#include <algorithm>
#include <__utility/unreachable.h>

namespace bird::before
{
    enum class Type
    {
        EUROPEAN,
        AFRICAN,
        NORWEGIAN_BLUE


    };
    struct Config
    {
        double baseSpeed;
        double loadFactor;
        double numberOfCoconuts;
        double voltage;
        bool isNailed;
    };
    class Bird
    {
    public:
        explicit Bird(Type type, const Config& config) : type_{type}, config_(config) {}

        [[nodiscard]] double GetSpeed() const
        {
            switch (type_)
            {
                case Type::EUROPEAN:
                {
                        return config_.baseSpeed;
                }

                case Type::AFRICAN:
                {
                        return config_.baseSpeed - config_.loadFactor * config_.numberOfCoconuts;
                }

            case Type::NORWEGIAN_BLUE:
                {
                        return config_.isNailed ? 0 : config_.isNailed * config_.voltage;
                }

            default:
                std::unreachable();
            }
        }

    private:
        Type type_;
        Config config_;
    };
}
