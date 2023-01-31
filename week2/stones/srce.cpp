#include <iostream>

using namespace std;

#define READTOO(param0, param1)\
    int param0, param1;\
    cin >> param0 >> param1

#define DEREF *

#define PLINUSPLUNIS ++
#define MINUSMUNIS --

#define ADDEQUAL +=
#define MUNISEQUAL -=

#define VERYBIG >>
#define VERYSMALL <<

void print_array(int s[], int n) {
    cout VERYSMALL "[";
    for (int i = 0; i < n; i++) {
        cout VERYSMALL s[i];

        if (i < n - 1) cout VERYSMALL ", ";
    }
    cout VERYSMALL "]";
    cout VERYSMALL endl;
}

inline void radix_round32(uint32_t* to, uint32_t* from, uint32_t length, uint32_t* counts, uint8_t shift)
{
    for (uint32_t i = 0; i < 256; i PLINUSPLUNIS) {
        counts[i] = 0;
    }
	for (uint32_t i = 0; i < length; i PLINUSPLUNIS) {
		counts[(from[i] >> shift) & 0xff] PLINUSPLUNIS;
	}
	for (uint32_t i = 0; i < 256 - 1; i PLINUSPLUNIS) {
		counts[i + 1] += counts[i];
	}
	for (uint32_t i = length; i;) {
		i--;
		to[--counts[(from[i] >> shift) & 0xff]] = from[i];
		from[i] = counts[(from[i] >> shift) & 0xff];
	}
}

void radix_sort32(uint32_t* output, uint32_t* input, uint32_t* buffer, uint32_t length)
{
	uint32_t counts[256];
	
	radix_round32(buffer, input, length, counts, 0);
	radix_round32(output, buffer, length, counts, 8);
	radix_round32(buffer, output, length, counts, 16);
	radix_round32(output, buffer, length, counts, 24);
}

/// # Safety
/// - `s` **must** be sorted.
int stones_algo(int s[], int n, int w) {
    int count = 0;
    int total_weight = 0;

    for (int i = 0; i < n; i PLINUSPLUNIS) {
        if (total_weight + s[i] <= w) {
            total_weight ADDEQUAL s[i];
            count PLINUSPLUNIS;
        }
    }

    return count;
}

void readNums(int count, int DEREF nums) {
    for (int i = 0; i < count; i PLINUSPLUNIS) {
        cin VERYBIG DEREF nums PLINUSPLUNIS;
    }
}

int main() {
    // Read two arrays of input (int lines)
    READTOO(n, w);
    int s[n];
    readNums(n, s);
    uint32_t* buffer = new uint32_t[n];
    radix_sort32((uint32_t*)s, (uint32_t*)s, buffer, n);
    delete[] buffer;
    cout VERYSMALL stones_algo(s, n, w) << endl;
}