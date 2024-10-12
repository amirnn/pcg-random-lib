#pragma once

#include <random>

#include "TypeAliases/Primitives.hpp"
#include "TypeAliases/Datastructs.hpp"
#include "../libs/pcg-cpp/include/pcg_random.hpp"

/**
 *
 * @param a lower bound included
 * @param b upper bound included
 * @return a random number in the range [a, b]
 */
[[nodiscard]] inline Int64 GetRandomIntegerFromUnifrom(Int64 const a, Int64 const b)
{
    // Seed with a real random value, if available
    pcg_extras::seed_seq_from<std::random_device> seed_source;

    // Make a random number engine
    pcg64 rng(seed_source);

    std::uniform_int_distribution<Int64> uniform_dist(a, b);
    Int64 const randomNumber = uniform_dist(rng);
    return randomNumber;
}

/**
 *
 * @param a lower bound included
 * @param b upper bound included
 * @param count number of integers returned
 * @return numbers in the range [a, b]
 */
[[nodiscard]] inline Vector<Int64> GetRandomIntegersFromUniform(Int64 const a, Int64 const b, Int64 const count)
{
    // Seed with a real random value, if available
    pcg_extras::seed_seq_from<std::random_device> seed_source;

    // Make a random number engine
    pcg64 rng(seed_source);

    std::uniform_int_distribution<Int64> uniform_dist(a, b);

    Vector<Int64> randomNumbers(count);

    for (Int64 i = 0; i < count; ++i)
    {
        randomNumbers.at(i) = uniform_dist(rng);
    }
    return randomNumbers;
}

/**
 *
 * @param a lower bound included
 * @param b upper bound included
 * @return a random number in the range [a, b]
 */
template <typename T>
[[nodiscard]] T GetRandomFloatFromUnifrom(T const a, T const b)
{
    // Seed with a real random value, if available
    pcg_extras::seed_seq_from<std::random_device> seed_source;

    // Make a random number engine
    pcg64 rng(seed_source);

    std::uniform_real_distribution<T> uniform_dist(a, b);
    T const randomNumber = uniform_dist(rng);
    return randomNumber;
}

/**
 *
 * @param a lower bound included
 * @param b upper bound included
 * @param count number of integers returned
 * @return numbers in the range [a, b]
 */
template <typename T>
[[nodiscard]] inline Vector<T> GetRandomFloatsFromUniform(T const a, T const b, Int64 const count)
{
    // Seed with a real random value, if available
    pcg_extras::seed_seq_from<std::random_device> seed_source;

    // Make a random number engine
    pcg64 rng(seed_source);

    std::uniform_int_distribution<T> uniform_dist(a, b);

    Vector<T> randomNumbers(count);

    for (Int64 i = 0; i < count; ++i)
    {
        randomNumbers.at(i) = uniform_dist(rng);
    }
    return randomNumbers;
}

/**
 *
 * @param a lower bound included
 * @param b upper bound included
 * @return a random number in the range [a, b]
 */
template <typename T>
[[nodiscard]] T GetRandomFloatFromNormal(T const mean, T const stddev)
{
    // Seed with a real random value, if available
    pcg_extras::seed_seq_from<std::random_device> seed_source;

    // Make a random number engine
    pcg64 rng(seed_source);

    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::lognormal_distribution<T> normal_distribution{mean, stddev};
    T const randomNumber = normal_distribution(rng);
    return randomNumber;
}

/**
 *
 * @param mean lower bound included
 * @param stddev upper bound included
 * @param count number of integers returned
 * @return numbers in the range [a, b]
 */
template <typename T>
[[nodiscard]] inline Vector<T> GetRandomFloatsFromNormal(T const mean, T const stddev, Int64 const count)
{
    // Seed with a real random value, if available
    pcg_extras::seed_seq_from<std::random_device> seed_source;

    // Make a random number engine
    pcg64 rng(seed_source);

    std::lognormal_distribution<T> normal_distribution(mean, stddev);

    Vector<T> randomNumbers(count);

    for (Int64 i = 0; i < count; ++i)
    {
        randomNumbers.at(i) = normal_distribution(rng);
    }
    return randomNumbers;
}