#pragma once
#include<iostream>
using namespace std;

void print();
void print(const char*);

/// <summary>
/// ��������� ����������
/// </summary>
void image_compress();  //��������������� �� 1 ���� ������ � 27 ������.
/// <summary>
/// �������� ����������
/// </summary>
/// <param name="width">������ ����������</param>
/// <param name="height">������ ����������</param>
/// <returns>������� ���������� ��� ���� �������� ��� ����</returns>
bool image_compress(int, int);