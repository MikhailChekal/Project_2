#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <array>
#include <vector>
#include "deque"
#include "list"
#include "forward_list"
#include "timer.h"

void winner(int a, int b, int c, int d, int e, int f){
    if (a == f){std::cout << "array";}
    else if (b == f){std::cout << "vector";}
    else if (c == f){std::cout << "deque";}
    else if (d == f){std::cout << "list";}
    else if (e == f){std::cout << "f_list";}
}


int main()
{
    const int length = 100000;
    std::array<int, length> array{};
    std::vector<int> vector{};
    std::deque<int> deque{};
    std::list<int> list{};
    std::forward_list<int> forward_list{};


    srand(4541);
    for (int count = 0; count < length; ++count) {
        array[count] = rand();
        vector.push_back(rand());
        deque.push_back(rand());
        list.push_back(rand());
        forward_list.push_front(rand());
    }

    {
        Timer<std::chrono::microseconds> t;


        std::sort(array.begin(), array.end());
        std::cout << std::setw(15) << "array, mcs: " << std::setfill(' ');
        int a = t.prt();

        std::sort(vector.begin(), vector.end());
        std::cout << std::setw(15) << "vector, mcs: " << std::setfill(' ');
        int b = t.prt();

        std::sort(deque.begin(), deque.end());
        std::cout << std::setw(15) << "deque, mcs: " << std::setfill(' ');
        int c = t.prt();

        list.sort();
        std::cout << std::setw(15) << "list, mcs: " << std::setfill(' ');
        int d = t.prt();

        forward_list.sort();
        std::cout << std::setw(15) << "f_list, mcs: " << std::setfill(' ');
        int e = t.prt();

        std::vector<int> results{a, b, c, d, e};
        int f = *std::min_element(results.begin(), results.end());
        std::cout << "the winner is: " << f << " ";
        winner(a,b,c,d,e,f);
        std::cout << std::endl;

        int g = *std::max_element(results.begin(), results.end());
        std::cout << "the loser is: " << g << " ";
        winner(a,b,c,d,e,g);
        std::cout << std::endl;

    }

}