#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
// функция проверки корректности ввода целого числа
bool UserInputInt(string input) {
    if (input.empty()) return false;
    try {
        size_t pos;
        stoi(input, &pos);
        return pos == input.length();
     } 
    catch (...) {
        return false;
    }
}

bool UserInputDouble(string input) {
    if (input.empty()) return false;
    try {
        size_t pos;
        stod(input, &pos);
        return pos == input.length();
    } 
    catch (...) {
        return false;
    }
}
// функция ввода (для целых чисел)
int EnterInt(string label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while (!UserInputInt(raw_input)) {
        cout << "Error! " << label;
        getline(cin, raw_input);
    }
    return stoi(raw_input);
}
// функция ввода (для вещественных чисел)
double EnterDouble(string label) {
    string raw_input;
    cout << label;
    getline(cin, raw_input);
    while (!UserInputDouble(raw_input)) {
        cout << "Error! " << label;
        getline(cin, raw_input);
    }
    return stod(raw_input);
}
void task1() {
    cout << "add 3 numbers: ";
    double a=EnterDouble("add a: ");
    double b=EnterDouble("add b: ");
    double c=EnterDouble("add c: ");
    
    if (a == b || a == c || b == c) {
        cout << "Yes, there is pair of equal numbers" << endl;
    } else {
        cout << "No, all numbers are different" << endl;
    }
    return;
}
void task2() {
    cout << "add 4 numbers: ";
    int a = EnterInt("Enter first number: ");
    int b = EnterInt("Enter second number: ");
    int c = EnterInt("Enter third number: ");
    int d = EnterInt("Enter fourth number: ");
    
    int max = a;
    int ost1, ost2, ost3; // оставшиеся числа, кроме максимального
    if (a >= b && a >= c && a >= d) {
        max=a;
        ost1=b; ost2=c; ost3=d;
    }
    else if (b >= a && b >= c && b >= d) {
        max=b;
        ost1=a; ost2=c; ost3=d;
    }
    else if (c >= a && c >= b && c >= d) {
        max=c;
        ost1=a; ost2=b; ost3=d;
    }
    else {
        max=d;
        ost1=a; ost2=b; ost3=c;
    }
    int second=ost1;
    if (ost2 > second) second=ost2;
    if (ost3 > second) second=ost3;
    int diff=max-second;
    cout << "Difference: " << diff << endl;
    return;
}
void task3(){
    cout << "Enter month";
    int m = EnterInt("Enter month number (1-12): ");
    if (m<1 || m>12) {
        cout << "Error! Month must be 1-12" << endl;
        return;
    }
    
    switch(m) {
        case 3:
        case 6:
        case 9:
        case 12:
            cout << "Month " << m << " IS the last month of the quarter" << endl;
            break;
        default:
            cout << "Month " << m << " is NOT the last month of the quarter" << endl;
    } return;
}
void task4(){
    cout << "Enter year, month and day. ";
    int g = EnterInt("Enter year: ");
    int m = EnterInt("Enter month (1-12): ");
    int d = EnterInt("Enter day: ");
    
    while (m < 1 || m > 12) {
        cout << "Error! Month must be between 1 and 12!" << endl;
        m = EnterInt("Enter month (1-12): ");
    }
    
    // Проверка високосности
    int visokos = 0;
    if ((g % 4 == 0 && g % 100 != 0) || (g % 400 == 0)) {
        visokos = 1;
    }
    
    // Сколько дней в месяце
    int days;
    if (m == 2) {
        if (visokos == 1) days = 29;
        else days = 28;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11) {
        days = 30;
    } else {
        days = 31;
    }
    
    while (d < 1 || d > days) {
        cout << "Error! " << endl;
        d = EnterInt("Enter day: ");
    }
    
    // Previous day
    int pred_g, pred_m, pred_d;
    if (d > 1) {
        pred_d = d - 1;
        pred_m = m;
        pred_g = g;
    } else {
        if (m > 1) {
            pred_m = m - 1;
            pred_g = g;
            if (pred_m == 2) {
                int pred_visokos = 0;
                if ((pred_g % 4 == 0 && pred_g % 100 != 0) || (pred_g % 400 == 0)) {
                    pred_visokos = 1;
                }
                if (pred_visokos == 1) pred_d = 29;
                else pred_d = 28;
            } else if (pred_m == 4 || pred_m == 6 || pred_m == 9 || pred_m == 11) {
                pred_d = 30;
            } else {
                pred_d = 31;
            }
        } else {
            pred_d = 31;
            pred_m = 12;
            pred_g = g - 1;
        }
    }
    
    // Next day
    int sled_g, sled_m, sled_d;
    if (d < days) {
        sled_d = d + 1;
        sled_m = m;
        sled_g = g;
    } else {
        if (m < 12) {
            sled_d = 1;
            sled_m = m + 1;
            sled_g = g;
        } else {
            sled_d = 1;
            sled_m = 1;
            sled_g = g + 1;
        }
    }
    
    cout << "\nPrevious day: " << pred_d << "." << pred_m << "." << pred_g << endl;
    cout << "Next day:     " << sled_d << "." << sled_m << "." << sled_g << endl;
}
int main() {   
int funcSelect = 0;
string input;
for (;;) {
       cout << "\n1. Task 1" << endl;
        cout << "2. Task 2" << endl;
        cout << "3. Task 3" << endl;
        cout << "4. Task 4" << endl;
        cout << "Enter 0 to Exit" << endl;
        cout << "Add number of task ";
        getline(cin, input);
        while (!UserInputInt(input)) {
            cout << "Error! Enter task number (0-4): ";
            getline(cin, input);
        }
        funcSelect = stoi(input);
        
        switch (funcSelect) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 0: 
                cout << "End! " << endl;
                return 0;
            default:
                cout << "Incorrect task number. Please enter from 0 to 4." << endl;
        }
    }
    return 0;
}