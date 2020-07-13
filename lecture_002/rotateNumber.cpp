#include<iostream>

using namespace std;

    int digits(int n) {
        int dig = 0;
        while (n != 0) {
            dig++;
            n /= 10;
        }
        return dig;
    }

    int rotate(int n, int r) {
        int digit = digits(n);
        r %=digit;
        r = (r < 0)?(r + digit) : r;
        int mul = 1;
        int divd = 1;
        for (int i = 1; i <= digit; i++) {
            if (i <= r) {
                mul *= 10;
            }
            else {
                divd *= 10;
            }
        }
            int leftdigits = n / divd; // in 12345 to rotate by 2, 12:leftdigits, 345:rightdigits
            int rightdigits = n % divd;
            return ((rightdigits * mul) + leftdigits);    
    }


int main(int args, char **argv) {
    int num,r;
    cout<<"Enter number to rotate..";
    cin>>num;    
    cout<<"Rotate by how much..?";
    cin>>r;
    cout<<"Rotated number is..";
    int rotated=rotate(num, r);
    cout<<rotated;
    return 0;
}


 