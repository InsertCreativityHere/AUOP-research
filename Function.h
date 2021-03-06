
#ifndef FUNCTION_DEF
#define FUNCTION_DEF

#include <vector>

namespace function
{
    class Function
    {
        public:
            virtual double getValue(double position) const = 0;
            virtual Function* negate() const = 0;
            virtual Function* derivative() const = 0;
            virtual double integrateD(double a, double b) const = 0;
            std::vector<double> getValueForAll(const std::vector<double>& positions) const;
    };

    class PolyFunction : public virtual Function
    {
        public:
            PolyFunction(std::vector<double> coefficients);
            double getValue(double position) const;
            PolyFunction* negate() const;
            PolyFunction* derivative() const;
            PolyFunction* integrateI(double c) const;
            double integrateD(double a, double b) const;

        private:
            const std::vector<double> coefficients;
    };

    class PeriodicFunction : public virtual Function
    {
        public:
            PeriodicFunction(Function* generator, double start, double stop);
            double getValue(double position) const;
            PeriodicFunction* negate() const;
            PeriodicFunction* derivative() const;
            double integrateD(double a, double b) const;

        private:
            const Function* generator;
            const double period;
            const double offset;
            const double area;
    };

    class PieceFunction : public virtual Function
    {
        public:
            PieceFunction(std::vector<Function*> functions, std::vector<double> bounds, std::vector<bool> directions);
            double getValue(double position) const;
            PieceFunction* negate() const;
            PieceFunction* derivative() const;
            double integrateD(double a, double b) const;

        private:
            const std::vector<Function*> functions;
            const std::vector<double> bounds;
            const std::vector<bool> directions;
    };
}
#endif
