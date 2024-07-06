#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

// Функція для обчислення факторіалу числа
long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);

    // Приведення всіх літер до нижнього регістру для правильного обчислення
    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    // Масив для підрахунку кількості кожної букви в слові
    int x[26] = { 0 };
    for (int i = 0; i < strlen(word); i++) {
        x[word[i] - 'a']++;
    }

    // Обчислення кількості анаграм
    long total_anagrams = factorial(strlen(word));
    for (int i = 0; i < 26; i++) {
        if (x[i] > 1) {
            total_anagrams /= factorial(x[i]);
        }
    }

    printf("Кількість анаграм: %llu\n", total_anagrams);
    return 0;
}
