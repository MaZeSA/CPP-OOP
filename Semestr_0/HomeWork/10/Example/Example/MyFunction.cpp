#include "MyFunction.h";

void print() {
	cout << "Привіт Іван\n";
}
void print(const char* ch)
{
	cout << ch << endl;
}
void image_compress()
{
	cout << "Стикаємо фото\n";
}
bool image_compress(int width, int height)
{
	cout << "Стикаємо фото до розміру" << width << "x" << height << "\n";
	return true;
}