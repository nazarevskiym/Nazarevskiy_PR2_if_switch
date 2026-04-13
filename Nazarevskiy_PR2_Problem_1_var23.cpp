#include <iostream>
#include <cmath>
using namespace std;
void task1() {
    double F, s, a;

    cout << "Task 1" << endl;
    cout << "add F: ";
    cin >> F;
    cout << "add s: ";
    cin >> s;
    cout << "add a: ";
    cin >> a;
    double rad = a * 3.1415 / 180.0;
    double A = F * s * cos(rad);
    cout << " A = " << A  << endl;
}
void task2() {
    int A;
    cout << "Add A" << endl;
    cin >> A;
    if (A<=100 || A>=999) { 
        cout << "Non-three-digit count";
    } else {
        int first_count=A/100;
        int last_count=A%10;
        if (first_count==last_count)
        cout << "Symmetrical";
        else
        cout << "Asymmetrical"; 
    } return;
}

void task3() {
    double a, b, c;

    cout << "Task 3" << endl;
    cout << "add 3 numbers: ";
    cin >> a >> b >> c;

    double maxVal = a;
    double minVal = a;

    if (b > maxVal) maxVal = b;
    if (c > maxVal) maxVal = c;

    if (b < minVal) minVal = b;
    if (c < minVal) minVal = c;

    cout << "max: " << maxVal << endl;
    cout << "min: " << minVal << endl;
}

void task4() {
    double x, y, a;
    cout << "add x" << endl;
    cin >> x;
    cout << "add y" << endl;
    cin >> y;
    cout << "add a" << endl;
    cin >> a;
    if (x >= -a/2 && x <= a/2 && y >= -a/2 && y <= a/2)
    cout << "yes" << endl;
    else
    cout << "no" << endl;
    return;
}

void task5() {
    int seasonNumber;
    cout << "add season number" << endl;
    cin >> seasonNumber;
    switch (seasonNumber) {
        case 1:
            cout << "Winter" << endl;
            break;
        case 2:
            cout << "Spring" << endl;
            break;
        case 3:
            cout << "Summer" << endl;
            break;
        case 4:
            cout << "Autumn" << endl;
            break;
        default:
            cout << "Error!" << endl;
    }
    
    return;
}

int main() {   
int funcSelect = 0;
for (;;) {
       cout << "\n1. Task 1 (A = F * s * cos a)" << endl;
        cout << "2. Cheking of symmetrial of number" << endl;
        cout << "3. Searching for the max and min" << endl;
        cout << "4. Point in square cheking" << endl;
        cout << "5. The season by number" << endl;
        cout << "Add number of task ";
        cin >> funcSelect;

        switch (funcSelect) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 0: cout << "End" << endl; break;
            default:
                cout << "Incorrcet task number. Please enter from 0 to 5.\n" << endl; }
        }
    return 0;
}
