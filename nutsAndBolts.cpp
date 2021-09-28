#include <iostream>

using namespace std;

void matchNutsAndBolts(int n, char* nuts, char* bolts)
{
    sort(nuts, nuts + n);
    
    // no need to sort bolts as one to one mapping
    // sort(bolts, bolts + n);
    
    cout << nuts <<"\n";
    cout << nuts <<"\n";
}

int main() {
    char nuts[] = {'@', '%', '$', '#', '^'};  // can take input as array of char
    char bolts[] = "%@#$^";   // or string itself

    matchNutsAndBolts(sizeof(nuts)/sizeof(nuts[0]), nuts, bolts);
    return 0;
}