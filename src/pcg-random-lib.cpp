#include "pcg-random-lib.hpp"

int main()
{

    {
        auto const t1 = std::chrono::steady_clock::now();
        [[maybe_unused]] auto const randomNumbers = GetRandomFloatsFromNormal<Float128>(0, 1, 100'000);
        auto const t2 = std::chrono::steady_clock::now();
        auto const duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        std::cout << "\n" << "Duration for float number generation: " << duration << "us" << "\n";
    }
    {
        auto const t1 = std::chrono::steady_clock::now();
        for (int i = 0; i < 100'000; ++i)
        {
            [[maybe_unused]] const auto randomNumber = GetRandomFloatFromUnifrom(0.0, 1000.0);
            assert(randomNumber >= 0.0);
            assert(randomNumber <= 1000.0);
            // std::cout << randomNumber << "\t";
        }

        auto const t2 = std::chrono::steady_clock::now();
        auto const duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        std::cout << "Duration for float number generation: " << duration << "us" << "\n";
    }

    {
        auto const t1 = std::chrono::steady_clock::now();

        for (int i = 0; i < 100'000; ++i)
        {
            [[maybe_unused]] const auto randomNumber = GetRandomIntegerFromUnifrom(0, 1000);
            assert(randomNumber >= 0);
            assert(randomNumber <= 1000);
            // std::cout << randomNumber << "\t";
        }

        auto const t2 = std::chrono::steady_clock::now();
        auto const duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
        std::cout << "Duration for int number generation: " << duration << "us" << "\n";
    }

    std::cout << std::endl;
    return EXIT_SUCCESS;
}