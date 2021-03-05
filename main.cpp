#include <iostream>
#include <vector>
// global vars
std::uint32_t g_steps = 0;
std::uint64_t g_largest = 0;
// prototypes
auto collatz (const std::uint64_t& n) -> std::vector<std::uint64_t>;
// driver code
auto main() -> int
{
    std::cout << "enter a number: ";
    std::uint64_t n = 0;
    std::cin >> n;
    //
    for (const auto& i : collatz(n))
    {
        std::cout << i << ' ';
    }
    std::cout << '\n' << '\n';
    std::cout << "Steps: " << g_steps << '\n'
    << "Largest number: " << g_largest << '\n';
}
// implementation
auto collatz (const std::uint64_t& n) -> std::vector<std::uint64_t>
{
    std::vector<std::uint64_t> vec;
    // added n to the vector vec
    vec.push_back(n);
    //check if the vec is not empty then check if the lastest element is 1 then stop
    while (!vec.empty() && vec.back() != 1)
    {
        // store the latest element to a void multiple calling
        std::uint64_t latest = vec.back();
        // if the lastest element is even ...
        if (latest % 2 == 0)
        {
            // then divide it with 2
            vec.push_back(latest / 2);
        }
        else 
        {
            // else triple it  add 1 then divide it by 2
            vec.push_back((3 * latest) + 1); // 3n + 1 / 2 for less steps
        }
        g_steps++;
        if (latest > g_largest) g_largest = latest;
    }
    return vec;
}
