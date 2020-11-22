#pragma once
#include<iostream>
using namespace std;

void print();
void print(const char*);

/// <summary>
/// Стискажня зображення
/// </summary>
void image_compress();  //використовується за 1 місць роботи в 27 файлах.
/// <summary>
/// Стискаємо зображення
/// </summary>
/// <param name="width">Ширина зображення</param>
/// <param name="height">Висота зображення</param>
/// <returns>Повертає інформацію про успіх операції над фото</returns>
bool image_compress(int, int);