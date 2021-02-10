#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <algorithm>

using namespace std; 

void Create_v1(vector<int>* v1_);
void Create_v3(vector<int>& v3_);
void CopyVector(const vector<int>* vector1_, vector<int>* vector2_, int start_, int end_);
void PrintVector(const vector<int>* v_);
void Write_ToFile(vector<int>* v_);
void Change_v2(vector<int>* v2_);
void Dublicat_v4(vector<int>* v4_);
void Change_v5(vector<int>* v5_, const vector<int>* v4_);
void Interchange(vector<int>* v4_, vector<int>* v5_);

int main()
{
	srand((unsigned int)time(0));

	vector<int> v1;//v1 – порожній, ввести елементи з клавіатури;
	Create_v1(&v1);

	vector<int> v2(10, 0);//v2 – 10 нульових елементів;

	vector<int> v3;//v3 – кількість ввести з клавіатури, елементи згенерувати випадковим чином;
	Create_v3(v3);
	
	vector<int> v4;
	CopyVector(&v1, &v4, 0, v1.size());//v4 – скопіювати всі елементи v1;

	vector<int> v5;//v5 – скопіювати від другого до передостаннього елементи v3.
	CopyVector(&v3, &v5, 1, v3.size() - 1);

	cout << "   V3 \n";
	PrintVector(&v3);//2. Вивести всі елементи вектора v3 на екран

	Write_ToFile(&v1);//Вивести всі елементи вектора v1 у зворотньому порядку у файл ‘Numbers.txt’.

	Change_v2(&v2); //Заповнити елементи вектора v2 числами 1, 2, 3, ..., 10.
			 	    //Перетасувати елементи вектора v2,
			     	//видалити другий та останній елементи,
			 	    //вивести елементи результуючого вектора на екран.

	Dublicat_v4(&v4);//Подвоїти кожен елемент вектора v4.Наприклад, (12, 10, 35) –(12, 12, 10, 10, 35, 35).

	Change_v5(&v5, &v4); //Видалити всі елементи вектора v5,
						 //cкопіювати у v5 лише парні елементи v4,
						 //зменшити значення кожного елемента v5 удвічі,
						 //вивести на екран результуючий вектор.

	Interchange( &v4, &v5);//    6. Обміняти елементи векторів v4 та v5.

}
void Create_v1(vector<int>* v1_)
{
	int act = 1;
	while (act)
	{
		cout << "Enter '0' to next step\n"
			<< " Or Enter int item to vector_v1 ->";

		cin >> act;
		v1_->push_back(act);
	}
}
void Create_v3(vector<int>& v3_)
{
	int count_v3 = 0;
	cout << "Enter size vector_v3 ->";
	cin >> count_v3;
	v3_ = *new vector<int>(count_v3);

	for (int i = 0; i < count_v3; i++)
		v3_[i] = rand() % 100;
}
void CopyVector(const vector<int>* vector1_, vector<int>* vector2_, int start_, int end_)
{
	for (vector<int>::const_iterator it = vector1_->begin(); it != vector1_->end(); ++it) 
		vector2_->push_back(*it);
	
}
void PrintVector(const vector<int>* v_)
{
	for (vector<int>::const_iterator it = v_->begin(); it != v_->end(); ++it) 
		cout << *it << ' ';
	cout << endl;
}
void Write_ToFile(vector<int>* v_)
{
	ofstream file("Numbers.txt");
	if (file.is_open())
	{
		for (int i = v_->size()-1; i > -1; i--)
			file << (*v_)[i] << " ";
		file.close();
	}
}
void Change_v2(vector<int>* v2_)
{
	for (int i = 1; i < 11; i++)  //Заповнити елементи вектора v2 числами 1, 2, 3, ..., 10.
		(*v2_)[i - 1] = i;

	random_shuffle((*v2_).begin(), (*v2_).end());//Перетасувати елементи вектора v2,

	v2_->erase(v2_->begin() + 1);//видалити другий та останній елементи,
	v2_->erase(v2_->end()-1);
	
	cout << "   V2 \n";
	PrintVector(v2_);
}
void Dublicat_v4(vector<int>* v4_)
{
	for (int i = 0; i < v4_->size(); i+=2)//Подвоїти кожен елемент вектора v4.Наприклад, (12, 10, 35) –(12, 12, 10, 10, 35, 35).
		v4_->insert(v4_->begin() + i, (*v4_)[i]);
}
void Change_v5(vector<int>* v5_, const vector<int>* v4_)
{
	v5_->clear(); //Видалити всі елементи вектора v5,

	for (vector<int>::const_iterator it = v4_->begin(); it != v4_->end(); ++it)//cкопіювати у v5 лише парні елементи v4,
		if (*it % 2 == 0)
			v5_->push_back(*it);

	for (int i = 0; i < v5_->size(); i++)//зменшити значення кожного елемента v5 удвічі,
		(*v5_)[i] /= 2;
	
	cout << "   V5 \n";
	PrintVector(v5_);
}
void Interchange(vector<int>* v4_, vector<int>* v5_)
{
	vector<int> &nt = *new vector<int>();
	for (vector<int>::const_iterator it = v4_->begin(); it != v4_->end(); ++it)
		nt.push_back(*it);

	v4_->clear();

	for (vector<int>::const_iterator it = v5_->begin(); it != v5_->end(); ++it)
		v4_->push_back(*it);

	(*v5_) = nt;
}
