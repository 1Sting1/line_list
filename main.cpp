#include <iostream>
#include <chrono>
#include "line_list.h"

void josephus(int n, int k) {
    CircularBuffer circle(n);

    int index = 0;
    for (int i = 0; i < n - 1; ++i) {
        index = circle.next(index, k - 1);
        circle.remove(index);
    }

    circle.display();
}

int main() {
    int n = 100;
    int k = 10;

    auto start = std::chrono::high_resolution_clock::now();

    josephus(n, k);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "time: " << duration.count() << " second" << std::endl;

    return 0;
}
