#include <iostream>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()
template <bool... digits> struct ReversedBinaryValue;

template <>
struct ReversedBinaryValue<> {
    static constexpr int value = 0;
};

template <bool first,bool... digits>
struct ReversedBinaryValue<first,digits...> {
    static constexpr int value = first + 2*ReversedBinaryValue<digits...>::value;
};

template <bool...digits>
int reversed_binary_value()
{
    return ReversedBinaryValue<digits...>::value;
}


template <int n, bool...digits>
struct CheckValues {
    static void check(int x, int y)
    {
        CheckValues<n-1, 0, digits...>::check(x, y);
        CheckValues<n-1, 1, digits...>::check(x, y);
    }
};

template <bool...digits>
struct CheckValues<0, digits...> {
    static void check(int x, int y)
    {
        int z = reversed_binary_value<digits...>();
        std::cout << (z+64*y==x);
    }
};

int main()
{
    int t; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int x, y;
        cin >> x >> y;
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}
