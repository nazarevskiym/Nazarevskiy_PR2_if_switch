#include <iostream>
#include <cmath>
using namespace std;
void task1() {
    double a, b, c;
    cout << "add 3 numbers: ";
    cin >> a >> b >> c;
    if (a == b || a == c || b == c) {
        cout << "Yes, there is pair of equal numbers" << endl;
    } else {
        cout << "No, all numbers are different" << endl;
    }
    return;
}
void task2() {
    int a, b, c, d;
    cout << "add 4 numbers: ";
    cin >> a >> b >> c >> d;
    
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
    int m;
    cout << "add number 1 <= m <= 12: ";
    cin >> m;
    if (1>m & m>12) {
        cout << "Error!" << endl;
        return;
    }
    if (m%3==0){
        cout << "This month " << m << " IS the end of quarter" << endl;
    } else {
        cout << "This month " << m << " is NOT the end of quarter" << endl;
    }
    return;
    }
void task4(){
    int g, m, d;
    int pred_g, pred_m, pred_d;
    int sled_g, sled_m, sled_d;
    cout << "Enter year, month and day, for example 2026 04 07: ";
    cin >> g >> m >> d;
    int visokos=0;
    if (g % 4 == 0) { // проверка високосности 
        visokos=1;
    }
    int days;
    if (m==2){
        if (visokos==1) {
            days=29;
        }
        else {
            days=28;
        }
    }
    else if (m==4 || m==6 || m==9 || m==11) {
        days = 30;
    } else {
        days = 31;
    }
    if (d < 1 || d > days) { // проверка ввода дня 
        cout << "Error!" << endl;
        return;
    }
    if (d > 1) {
        pred_d=d-1;
        pred_m=m;
        pred_g=g;
    } else {
        if (m > 1) {
            pred_m=m-1;
            pred_g=g;
            if (pred_m==2) {
                if (visokos==1) pred_d=29;
                else pred_d=28;
            } else if (pred_m==4 || pred_m==6 || pred_m==9 || pred_m==11) {
                pred_d= 0;
            } else {
                pred_d=31;
            }
        } else {
            // 01.01.XXXX
            pred_d=31;
            pred_m=12;
            pred_g=g-1;
        }
    } 
     if (d < days) {
        sled_d=d+1;
        sled_m=m;
        sled_g=g;
    } else {
        if (m < 12) {
            sled_d=1;
            sled_m=m+1;
            sled_g=g;
        } else {
            // 31.12.XXXX
            sled_d=1;
            sled_m=1;
            sled_g=g+1;
        }
    }
    cout << "\nPrevious day: " << pred_d << "." << pred_m << "." << pred_g << endl;
    cout << "Next day:     " << sled_d << "." << sled_m << "." << sled_g << endl;
}
int main() {   
int funcSelect = 0;
for (;;) {
       cout << "\n1. Task 1" << endl;
        cout << "2. Task 2" << endl;
        cout << "3. Task 3" << endl;
        cout << "4. Task 4" << endl;
        cout << "Add number of task ";
        cin >> funcSelect;

        switch (funcSelect) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            default:
                cout << "Incorrcet task number. Please enter frim 1 to 5.\n" << endl; }
        }
    return 0;
}