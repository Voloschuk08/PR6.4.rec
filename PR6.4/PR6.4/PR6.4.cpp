#include <iostream>
#include <iomanip> 
#include <cstdlib> 
#include <ctime>  
using namespace std;

// Рекурсивна функція для обчислення суми від'ємних елементів
double sumNegative(double* a, int n, int i = 0) 
{
    if (i == n) return 0; 
    if (a[i] < 0)
        return a[i] + sumNegative(a, n, i + 1);
    return sumNegative(a, n, i + 1); // Пропуск позитивних елементів
}

// Рекурсивна функція для пошуку індексу мінімального елемента
int findMinInd(double* a, int n, int i = 0, int minIdx = 0) 
{
    if (i == n) return minIdx;
    if (a[i] < a[minIdx])
        minIdx = i;
    return findMinInd(a, n, i + 1, minIdx); // Рекурсія для пошуку мінімуму
}

// Рекурсивна функція для пошуку індексу максимального елемента
int findMaxIndex(double* a, int n, int i = 0, int maxIdx = 0) 
{
    if (i == n) return maxIdx;
    if (a[i] > a[maxIdx])
        maxIdx = i;
    return findMaxIndex(a, n, i + 1, maxIdx); // Рекурсія для пошуку максимуму
}

// Рекурсивна функція для обчислення добутку елементів між мінімальним і максимальним
double productMinMax(double* a, int minIdx, int maxIdx, int i = 0) 
{
    if (minIdx > maxIdx) swap(minIdx, maxIdx); // Якщо індекси переплутані
    if (i == maxIdx || i == minIdx) return 1; // Пропускаємо самі мінімум і максимум
    if (i > minIdx && i < maxIdx)
        return a[i] * productMinMax(a, minIdx, maxIdx, i + 1);
    return productMinMax(a, minIdx, maxIdx, i + 1);
}

// Рекурсивна функція для сортування парних елементів за зростанням
void sortEvenElements(double* a, int n, int i = 0) 
{
    if (i == n - 1) return; // Базовий випадок: досягли кінця
    if (a[i] != int(a[i]) || int(a[i]) % 2 != 0) 
    {
        sortEvenElements(a, n, i + 1); // Пропуск непарних елементів
        return;
    }
    for (int j = i + 1; j < n; j++) 
    {
        
        if (a[j] == int(a[j]) && int(a[j]) % 2 == 0 && a[j] < a[i]) 
        {
            swap(a[i], a[j]);
        }
    }
    sortEvenElements(a, n, i + 1); // Рекурсія для наступного елемента
}

// Рекурсивна функція для виведення масиву
void printArray(double* a, int n, int i = 0) {
    if (i == n) {
        cout << endl;
        return;
    }
    cout << fixed << setprecision(2) << a[i] << " "; // Форматоване виведення з двома знаками після коми
    printArray(a, n, i + 1); // Рекурсія для наступного елемента
}

int main() 
{
    int n;
    cout << "Enter the size: ";
    cin >> n;

    double* a = new double[n];

    // Генерація випадкових дійсних чисел
    srand((unsigned)time(NULL)); 
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 200 / 10.0 - 10; // Діапазон [-10, 10)
    }

    // Виведення початкового масиву
    cout << "Initial array: ";
    printArray(a, n);

    // 1.1. Обчислення суми від'ємних елементів
    double negativeSum = sumNegative(a, n);
    cout << "Sum of negative elements: " << fixed << setprecision(2) << negativeSum << endl;

    // 1.2. Обчислення добутку елементів між мінімальним і максимальним елементами
    int minIdx = findMinInd(a, n);
    int maxIdx = findMaxIndex(a, n);
    double product = productMinMax(a, minIdx, maxIdx);
    cout << "Product min and max: " << fixed << setprecision(2) << product << endl;

    // 2. Сортування парних елементів масиву за зростанням
    sortEvenElements(a, n);

    // Виведення модифікованого масиву
    cout << "Array after sorting: ";
    printArray(a, n);

    delete[] a; // Звільнення пам'яті
    return 0;
}
