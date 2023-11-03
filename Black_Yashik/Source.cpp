#include <iostream>
#include <cmath>
#include <complex>
#include <vector>

double checker(double a)
{
    while (true)
    {
        try
        {
            if (!(std::cin >> a))
            {
                std::cin.clear();

                while (std::cin.get() != '\n');

                throw "Value is non digit!";
            }
            else
                if (a == 0 || a < -10 || a > 10)
                    throw "Value is not valid";
                else
                    break;

        }

        catch (const char* exception)
        {
            std::cout << exception << '\n';

            std::cout << "Type new agument value: ";
        }
    }
    return a;
}

double toochecker(double param)
{
    while (true)
    {
        try
        {
            if (!(std::cin >> param))
            {
                std::cin.clear();

                while (std::cin.get() != '\n');

                throw "Value is non digit!";
            }
            else
                if (param < -10 || param > 10)
                    throw "Value is not valid";
                else
                    break;

        }

        catch (const char* exception)
        {
            std::cout << exception << '\n';

            std::cout << "Type new agument value: ";
        }
    }
    return param;
}

std::vector<std::complex<double>> solution(double a, double b, double c, double d)
{
    b /= a;
    c /= a;
    d /= a;

    double f = ((3.0 * c) - (b * b)) / 3.0;
    double g = ((2.0 * (b * b * b)) - (9.0 * b * c) + (27.0 * d)) / 27.0;
    double h = ((g * g) / 4.0) + ((f * f * f) / 27.0);

    std::complex<double> i(0, 1);
    std::complex<double> x1, x2, x3;

    if (h <= 0) {
        double i = sqrt(((g * g) / 4.0) - h);

        double j = cbrt(i);

        double k = acos(-(g / (2 * i)));

        double l = -j;

        double m = cos(k / 3.0);

        double n = sqrt(3) * sin(k / 3.0);

        double p = -(b / (3 * a));

        x1 = 2 * j * cos(k / 3.0) - (b / (3 * a));
        x2 = l * (m + n) + p;
        x3 = l * (m - n) + p;
    }
    else {
        double r = -(g / 2.0) + sqrt(h);

        double s = cbrt(r);

        double t = -(g / 2.0) - sqrt(h);

        double u = cbrt(t);

        x1 = (s + u) - (b / (3 * a));
        x2 = -(s + u) / 2 + (b / (3 * a)) + (i * (s - u) * sqrt(3)) / 2.0;
        x3 = -(s + u) / 2 + (b / (3 * a)) - (i * (s - u) * sqrt(3)) / 2.0;
    }

    std::vector<std::complex<double>> roots{ x1, x2, x3 };

    return roots;
}

void printComplex(const std::complex<double>& c)
{
    std::cout << c.real();
}

int main() {
    double a = 0, b = 0, c = 0, d = 0;

    std::cout << "Type argument a value:";

    a = checker(a);

    std::cout << "Type other arguments value:";

    b = toochecker(b);

    c = toochecker(c);

    d = toochecker(d);

    auto roots = solution(a, b, c, d);

    for (int i = 1; i <= roots.size(); ++i)
    {
        std::cout << "x" << i << ": ";

        printComplex(roots[i - 1]);

        std::cout << "\n";
    }

    return 0;
}
