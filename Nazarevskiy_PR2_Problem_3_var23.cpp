#include <iostream>
#include <cmath>
using namespace std; 
int main(){
int a,b,c,d;
cout << "Enter 4 numbers";
cin >> a >> b >> c >> d;

int max = (a>=b && a>=c && a>=d) ? a:
          (b>=a && b>=c && b> d) ? b:
          (c>=a && c>=b && c>=d) ? c: d;

int second=(max==a)?((b>=c&&b>=d)?b:(c>=b&&c>=d)?c:d):
           (max==b)?((a>=c&&a>=d)?a:(c>=a&&c>=d)?c:d):
           (max==c)?((a>=b&&a>=d)?a:(b>=a&&b>=d)?b:d):
                     ((a>=b&&a>=c)?a:(b>=a&&b>=c)?b:c);
int diff=max-second;
cout<<"Difference: "<<diff<<endl;
}