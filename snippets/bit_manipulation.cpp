/*
 * Bit manipulation techniques.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch2.zip
 */

#include <cmath>
#include <cassert>

#define isOn(S, j) ((S) & (1 << (j)))
#define setBit(S, j) ((S) |= (1 << (j)))
#define clearBit(S, j) ((S) &= ~(1 << (j)))
#define toggleBit(S, j) ((S) ^= (1 << (j)))
#define lowBit(S) ((S) & -(S))
#define setAll(S, n) ((S) = (1 << (n)) - 1)

#define modulo(S, N) ((S) & (N - 1)) // where N is a power of 2
#define isPowerOfTwo(S) (!((S) & ((S) - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)(S)) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & ((S) - 1))
#define turnOnLastZero(S) ((S) | ((S) + 1))
#define turnOffLastConsecutiveBits(S) ((S) & ((S) + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | ((S) - 1))

using namespace std;

int main() {
    int S = 34; // 100010

    // Set/turn on a specific bit
    setBit(S, 3); // 101010
    assert(S == 42);

    // Check if some bits are on
    assert(!isOn(S, 0) && isOn(S, 1) && isOn(S, 3));

    // Clear/turn off a specific bit
    clearBit(S, 1); // 101000
    assert(S == 40);

    // Toggle bits
    toggleBit(S, 2); // 101100
    toggleBit(S, 3); // 100100
    assert(S == 36);

    // Turn on all bits
    setAll(S, 6); // 111111
    assert(S == 63);

    // Other tricks
    assert(modulo(9, 4) == 1);

    assert(isPowerOfTwo(128));
    assert(!isPowerOfTwo(127));

    assert(nearestPowerOfTwo(129) == 128 && nearestPowerOfTwo(12) == 16);

    assert(turnOffLastBit(44) == 40); // 101100 -> 101000

    assert(turnOnLastZero(37) == 39); // 100101 -> 100111

    assert(turnOffLastConsecutiveBits(43) == 40); // 101011 -> 101000

    assert(turnOnLastConsecutiveZeroes(40) == 47); // 101000 -> 101111

    return 0;
}
