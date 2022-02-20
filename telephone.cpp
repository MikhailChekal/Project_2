//
// Created by misha on 14.02.2022.
//
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <vector>
#include <random>
#include <iomanip>

int main(){
    std::random_device rd;
    std::mt19937 g(rd());

    std::multimap<std::string, int> phone_book;

    phone_book.emplace("Verstappen", 658191);
    phone_book.emplace("Smith", 435496);
    //phone_book.emplace("Harrison", 812606);
    //phone_book.emplace("Ford", 788865);
    //phone_book.emplace("Maclaren", 384953);
    //phone_book.emplace("Hudson", 934548);
    //phone_book.emplace("Douglas", 434779);
    //phone_book.emplace("McDonnell", 512245);


    typedef std::vector<std::pair<std::string, int>> Vector_of_keys;
    Vector_of_keys vect(phone_book.size());
    std::copy(phone_book.begin(), phone_book.end(), vect.begin());

    std::cout << "Enter number of operations: "; int m; std::cin >> m;
    for (int i = 0; i < m; i++) {


        std::cout << "Enter your command: " << std::endl << "1, to get a random number" << std::endl
                  << "2, to get a number by surname" << std::endl << "3, to get sorted list" << std::endl
                  << "4, to add new number" <<
                  std::endl << "5, to delete a number"
                  << std::endl;
        int n;
        std::cin >> n;


        if (n == 1) {
            std::shuffle(vect.begin(), vect.end(), g);
            //Vector_of_keys::iterator it = vect.begin();
            //std::cout << it->first << " " << it->second << std::endl;

            for (Vector_of_keys::iterator it = vect.begin(); it != vect.end(); it++) {
                std::cout << it->first << ": " << it->second << std::endl;
            }


        } else if (n == 2) {
            std::cout << "Enter a surname: " << std::endl;
            std::string surname;
            std::cin >> surname;
            auto[left, right] = phone_book.equal_range(surname);
            for (auto it = left; it != right; it++) {
                std::cout << it->first << ": " << it->second << std::endl;
            }
        } else if (n == 3) {
            for (const auto&[surname, number]: phone_book) {
                std::cout << std::setw(10) << surname << std::setfill(' ') << ": " << number << std::endl;
            }
            std::cout << std::endl;
        } else if (n == 4) {
            std::cout << "Enter a surname: ";
            std::string new_surname;
            std::cin >> new_surname;
            std::cout << "Enter a number: ";
            int new_number;
            std::cin >> new_number;
            phone_book.emplace(new_surname, new_number);
            vect.push_back(std::make_pair(new_surname, new_number));
        } else if (n == 5) {
            std::cout << "Enter a surname: "; std::string surname_to_delete; std::cin >> surname_to_delete;
            std::multimap <std::string, int> :: iterator full_name;
            full_name = phone_book.find(surname_to_delete);
            phone_book.erase(full_name);
            std::remove(vect.begin(),vect.end(), std::make_pair(full_name->first, full_name->second));
            // тут что-то неправильно работает при удалении из вектора
        } else if (n == 0){
            exit(0);
        }
    }
    return 0;

}