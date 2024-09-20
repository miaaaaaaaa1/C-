#include <iostream>
using namespace std;

int main()
{
//завдання 1
char a;
std::cout << "Enter a symbol: ";
cin >> a;

if (isalpha(a)) {
    cout << "This is a letter." << endl;
}
else if (isdigit(a)) {
    cout << "This is a number." << endl;
}
else if (ispunct(a)) {
    cout << "This is a punctuation mark." << endl;
}
else if (isspace(a)) {
    cout << "This is a space or other invisible character." << endl;
}
else {
    cout << "This is another symbol." << endl;
}

//завдання 3

int choice;
const double lines = 50.0;  
const double lates = 20.0; 

cout << "Menu:" << endl;
cout << "1. Enter the desired revenue and the number of delays to calculate the number of lines of code." << endl;
cout << "2. Enter the number of lines of code and the desired income to calculate how many times Vasia can be late." << endl;
cout << "3. Enter the number of lines of code and the number of delays to calculate how much money Vasia will be paid." << endl;
cout << "Enter the option number: ";
cin >> choice;

switch (choice) {
case 1: {
    double desired_income;
    int lates;
    cout << "Enter desired income (in $): " << endl;
    cin >> desired_income;
    cout << "Enter the number of delays: " << endl;
    cin >> lates;

    double total_penalty = (lates / 3) * lates;
    double net_income = desired_income + total_penalty;
    int lines_needed = static_cast<int>((net_income / lines) * 100);

    cout << "To receive " << desired_income << "$ Vasia need to write "
        << lines_needed << " lines of code." << endl;
    break;
}
case 2: {
    int lines_written;
    double desired_income;
    cout << "Введіть кількість написаних рядків коду: ";
    cin >> lines_written;
    cout << "Enter the desired amount of salary (in $): ";
    cin >> desired_income;

    double base_salary = (lines_written / 100.0) * lines;
    double remaining_income = base_salary - desired_income;
    int max_lates = 0;

    if (remaining_income >= 0) {
        max_lates = static_cast<int>((remaining_income / lates) * 3);
        cout << "Vasia can be late at most " << max_lates << " time(s)." << endl;
    }
    else {
        cout << "Vasia cannot afford to be late for such a desired income." << endl;
    }
    break;
}
case 3: {
    int lines_written, lates;
    cout << "Enter the number of lines of code written: ";
    cin >> lines_written;
    cout << "Enter the number of delays: ";
    cin >> lates;

    double base_salary = (lines_written / 100.0) * lines;
    double total_penalty = (lates / 3) * lates;
    double final_salary = base_salary - total_penalty;

    if (final_salary > 0) {
        cout << "Vasia will be paid: " << final_salary << "$" << endl;
    }
    else {
        cout << "Vasia will not receive money due to excessive lateness." << endl;
    }
    break;
}
default:
    cout << "Wrong choice. Try again.";
}
}

