
#include <iostream>

using namespace std;

int univSet[10] = { 1,2,3,4,5,6,7,8,9,10 };   //Universal Set

bool universalSet[10] = { 1,1,1,1,1,1,1,1,1,1 };   //Set A
bool evenSet[10] = { 0,1,0,1,0,1,0,1,0,1 };   //Set B
bool oddSet[10] = { 1,0,1,0,1,0,1,0,1,0 };    //Set C
bool primeSet[10] = { 1,1,1,0,1,0,1,0,0,0 };  //Set D

int arrSize;
bool result[10];
bool* r = result;
bool* intResult(bool*, bool*);
bool* unResult(bool*, bool*);
bool* notResult(bool*);
bool* minusResult(bool*, bool*);
int resSize(bool*);
void printRes(bool*, int);


int main() {
    cout << "Set A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }  - Universal Set " << endl;
    cout << "Set B = {2,4,6,8,10}   - Even numbers in U" << endl;
    cout << "Set C = {1,3,5,7,9}   - Odd numbers in U" << endl;
    cout << "Set D = {1,2,3,5,7}   - Prime numbers in U" << endl;
    cout << endl;

    cout << "Problem 1:  A " << char(239) << " D " << endl;
    cout << "\t\t";
    r = intResult(universalSet, primeSet);
    arrSize = resSize(result);
    printRes(result, arrSize);
    arrSize = 0;


    cout << "Problem 2:  (B U C) " << char(239) << " A " << endl;
    cout << "\t\t";
    r = intResult(unResult(evenSet, oddSet), universalSet);
    arrSize = resSize(result);
    printRes(result, arrSize);
    arrSize = 0;

    cout << "Problem 3:  (!C U C) " << char(239) << " A " << endl;
    cout << "\t\t";
    bool* r1 = notResult(oddSet);
    r = intResult(unResult(r1, oddSet), universalSet);
    arrSize = resSize(result);
    printRes(result, arrSize);
    arrSize = 0;

    cout << "Problem 4:  A - D " << endl;
    cout << "\t\t";
    r = minusResult(universalSet, primeSet);
    arrSize = resSize(result);
    printRes(result, arrSize);
    arrSize = 0;


    cout << "Problem 5:  N(!A U (C U D)) " << endl;
    cout << "\t\t";
    bool* temp = notResult(universalSet);
    r = unResult(temp, unResult(oddSet, primeSet));
    arrSize = resSize(r);
    cout << arrSize << endl;
    arrSize = 0;

    cout << "Problem 6:  D " << char(239) << " C " << endl;
    cout << "\t\t";
    r = intResult(primeSet, oddSet);
    arrSize = resSize(result);
    printRes(result, arrSize);
    arrSize = 0;

    cout << "Problem 7:  N(B " << char(239) << " C) " << endl;
    cout << "\t\t";
    r = intResult(evenSet, oddSet);
    arrSize = resSize(result);
    cout << arrSize << endl;
    arrSize = 0;

    cout << "Problem 8:  A U B U C U D " << endl;
    cout << "\t\t";
    r = unResult(primeSet, unResult(oddSet, unResult(universalSet, evenSet)));
    arrSize = resSize(result);
    printRes(result, arrSize);
    arrSize = 0;

}

bool* intResult(bool* a, bool* b) {    //INTERSECTION function
    for (int i = 0; i < 10; i++) {
        if (a[i] == 1 && b[i] == 1) {
            result[i] = 1;
        }
        else {
            result[i] = 0;
        }
    }
    return result;
}
bool* unResult(bool* a, bool* b) {    //UNION function
    for (int i = 0; i < 10; i++) {
        result[i] = (a[i] || b[i]);
    }
    return result;
}
bool* notResult(bool* a) {            //INVERSE function
    for (int i = 0; i < 10; i++) {
        result[i] = !(a[i]);         //resulting array is opposite of array entered
    }
    return result;
}
bool* minusResult(bool* a, bool* b) {   //REMOVAL function
    for (int i = 0; i < 10; i++) {
        if (!(a[i]) || (a[i] && b[i])) {    //if minuend is 0 or minuend AND subtrahend are equal, element is 0 (to be removed)
            result[i] = 0;
        }
        else {
            result[i] = 1;                   //if element is not present in subtrahend set, minuend remains
        }
    }
    return result;
}
int resSize(bool* res) {            //MAGNITUDE calculation (number of elements that are "true")
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        if (res[i] != 0) {
            count += 1;
        }
    }
    return count;
}
void printRes(bool* r, int count) {
    cout << "{";
    for (int j = 0; j < 10; ++j) {
        if (r[j] != 0) {
            if (count > 1) {
                cout << univSet[j] << ", ";
                count = count - 1;
            }
            else if (count == 1) {
                cout << univSet[j];
                count = count - 1;
            }
            else {
                break;
            }
        }
    }
    cout << "}" << endl;
}