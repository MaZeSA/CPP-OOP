#include "MyFunction.h";

void print() {
	cout << "����� ����\n";
}
void print(const char* ch)
{
	cout << ch << endl;
}
void image_compress()
{
	cout << "������� ����\n";
}
bool image_compress(int width, int height)
{
	cout << "������� ���� �� ������" << width << "x" << height << "\n";
	return true;
}