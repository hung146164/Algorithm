#include <iostream>
using namespace std;

// Tính a^b theo cách lũy thừa nhị phân
int pow(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b % 2 == 1) result *= a; // Nếu b lẻ
        a *= a;                      // Bình phương cơ số
        b /= 2;                      // Chia đôi số mũ
    }
    return result;
}

int main() {
    int a = 2, b = 10;
    cout << a << "^" << b << " = " << pow(a, b) << endl;
    return 0;
}

