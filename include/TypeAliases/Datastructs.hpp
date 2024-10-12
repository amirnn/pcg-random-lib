#pragma once

#include <map>
#include <optional>
#include <utility>
#include <vector>

template <typename... T> using Vector = std::vector<T...>;
template <typename... T> using Array = std::array<T...>;
template <typename T, typename U> using Pair = std::pair<T, U>;
template <typename... T> using Optional = std::optional<T...>;

template <typename... T> using Map = std::map<T...>;
