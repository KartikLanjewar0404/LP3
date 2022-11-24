#include <iostream>
#include <vector>
using namespace std;

int fibRec(int n) {
    if(n <= 1) return n;
    return fibRec(n-1) + fibRec(n-2);
}

int fibNonRec(int n) {
    vector<int> v(n+1);
    v[0] = 0, v[1] = 1;
    for(int i=2; i<=n; i++) {
        v[i] = v[i-1] + v[i-2];
    }
    return v[n];
}

int main(int argc, char const *argv[])
{
    int x; 
    cout << "Enter number : "; cin >> x;
    cout << "Recursive : " << fibRec(x) << endl;
    cout << "Non-Recursive : " << fibNonRec(x) << endl;
    return 0;
}
