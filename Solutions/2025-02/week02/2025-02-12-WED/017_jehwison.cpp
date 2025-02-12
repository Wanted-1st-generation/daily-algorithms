#include <iostream>
#include <string>

int calculate_super_digit(std::string number) {
    if (number.length() == 1) {
        return std::stoi(number);
    } else {
        int digit_sum = 0;
        for (char digit : number) {
            digit_sum += digit - '0'; 
        }
        return calculate_super_digit(std::to_string(digit_sum));
    }
}

int compute_super_digit(std::string number, int repetitions) {
    long long initial_digit_sum = 0;
    for (char digit : number) {
        initial_digit_sum += digit - '0'; 
    }
    return calculate_super_digit(std::to_string(initial_digit_sum * repetitions));
}

int main(void) {
    std::string number;
    int repetitions;
    std::cin >> number >> repetitions;
    int result = compute_super_digit(number, repetitions);
    std::cout << result << std::endl;
    return 0;
}

