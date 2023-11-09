#include <iostream>
using namespace std;
int element, counter = 0, arr[100], user, indexreplace, random1, random2, fragment1, fragment2;

int factorial(int);
int timesappeared(int element);
int odd();
int minimum();
int adjacent();
int printindex();
int replace(int indexreplace);
int printfragment(int, int);

int main() {
    // First task
    cout << "Write a number to count a factorial: " << endl;
    cin >> user;
    int result = 1;
    for (int i = 1; i <= user; i++){
        result *= i;
    }
    cout << "Factorial of the number " << user << " equals: " << result << endl;

    // Second task
    int n, k;
    cout << "Type n: ";
    cin >> n;
    cout << "Type k: ";
    cin >> k;

    int m = factorial(n) / ( factorial(k) * factorial(n - k) );
    cout << "Result: " << m << endl;

    // Third task
    char operation = ' ';
    cout << "Type a random borders: ";
    cin >> random1 >> random2;
    srand(time(NULL));
    for (int i = 0; i < 100; i++){
        arr[i] = rand() % random2 + random1;
        cout << arr[i] << "\t";
    }
    cout << endl;

    while (operation == 'a' || operation == 'b' || operation == 'c' || operation == 'd' || operation == 'e' || operation == 'f' || operation == 'g' || operation != 'q'){
        cout << "a - The number of times user's supplied item appeared\n"
                "b - Number of odd elements\n"
                "c - The smallest element and its index\n"
                "d - The pair of adjacent elements with the largest sum\n"
                "e - Printing the element at the index selected by the user\n"
                "f - Replace elements by index selected by user\n"
                "g - Printing a fragment of the array from and to the indexes specified by the user\n"
                "q - To quit\n"
                "Which operation do you want to do: ";
        cin >> operation;
        switch (operation) {
            case 'a':
                timesappeared(element);
                break;
            case 'b':
                odd();
                break;
            case 'c':
                minimum();
                break;
            case 'd':
                adjacent();
                break;
            case 'e':
                printindex();
                break;
            case 'f':
                replace(indexreplace);
                break;
            case 'g':
                printfragment(fragment1, fragment2);
                break;
            case 'q':
                break;
        }
    }
    return 0;
}

int factorial(int a) {
    int result = 1;
    for (int i = 1; i <= a ; i++){
        result *= i;
    }

    return result;
}

int timesappeared(int element){
    cout << "Which element do you want to discover: ";
    cin >> element;
    for (int i = 0; i < 100; i++){
        if (arr[i] == element) counter++;
    }
    cout << "Your element appears " << counter << " times" << endl;
    return counter;
}

int odd() {
    for (int i = 0; i < 100; i++){
        if (arr[i] % 2 != 0) counter++;
    }
    cout << "Number of odd elements: " << counter << endl;
    return counter;
}

int minimum() {
    int min = arr[0];
    for (int i = 0; i < 100; i++){
        if (min > arr[i]) min = arr[i];
    }
    cout << "Minimum: " << min << endl;
    for (int i = 0; i < 100; i++){
        if (min == arr[i]) cout << "Index: " << i << endl;
    }
    return min;
}

int adjacent(){
    int first = 0, second = 0, result = first + second;
    for (int i = 0; i < 100; i++){
        if (arr[i] + arr[i + 1] > result) result = arr[i] + arr[i + 1];
    }
    cout << "The biggest sum of adjacent elements: " << result << endl;
    return result;
}

int printindex(){
    cout << "Which element do you want to get: ";
    cin >> user;
    for (int i = 0; i < 100; i++){
        if (user == i) {
            cout << arr[i];
        }
    }
    cout << endl;
    return 0;
}

int replace(int indexreplace){
    cout << "Enter the index of the element you want to replace: ";
    cin >> indexreplace;
    int result;
    srand(time(NULL));
    for (int i = 0; i < 100; i++){
        if (indexreplace == i) {
            arr[i] = rand() % random2 + random1;
            result = arr[i];
        }
        cout << arr[i] << "\t";
    }
    cout << endl;
    cout << "The number with the index " << indexreplace << " was replaced by the new: " << result << endl;
    cout << "New array: " << endl;
    return result;
}

int printfragment(int, int){
    cout << "Which fragment of the array do you want to print: ";
    cin >> fragment1 >> fragment2;
    for (int i = fragment1; i <= fragment2; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
    return 0;
}