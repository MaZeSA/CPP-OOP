#include <string>
#include <iostream>
#include <time.h>
#include <vector>
#include <Windows.h>
using namespace std;
void Game(short i);
void Menu();
void SetColor(int text, int background);

enum class eUnitTypes
{
    None,
    Swordsman,
    Archer,
    Mage
};

bool theEnd = true;

class Unit
{
private:
    string unitType = "unit"; 
    
public:
    int hp = 0;
    int damage = 0;
    int dodge = 0;

    Unit(string typeUnit)
    {
        this->unitType = typeUnit;
    }
   
    virtual void Me_Attacked(int damage)
    {
        SetLife(-damage);
    } 
    void SetLife(int life)
    {
        cout << " >> Атака на юніта " << this->GetUnitType() << " наносить " << to_string(life) << " пошкоджень\n";
        this->hp += life;
        if (this->hp <= 0)
            cout << "    >> Юніт мертвий!\n";
    }
    virtual int GetDamage()
    {
        return this->damage;
    }
    void Attack(shared_ptr<Unit>Victim)
    {
        Unit* unitVictim = static_cast<Unit*>(Victim.get());
        unitVictim->Me_Attacked(this->GetDamage());
    }

    virtual eUnitTypes GetType() const
    {
        return eUnitTypes::None;
    } 
    virtual string GetUnitType()
    {
        return this->unitType;
    }
    int GetHp()
    {
        return this->hp;
    } 
  };

class Swordsman : public Unit ////У мечника 15 хіт - поінтів(життів), пошкодження при атаці 5, шанс ухилятись 60 % .
{
private:
    int amor = 4;

public:
    Swordsman():Unit("Мечник")
    {
        this->hp = 15;
        this->damage = 5;
        this->dodge = 60;
    }
    void Me_Attacked(int damage) override
    {
        if ((rand() % 101) > 60)
        {
            int amor = rand() % this->amor + 1;
            cout << " >> Броня заблокувала " << amor << " пошкоджень.\n";
            SetLife(-(damage - amor));
        }
        else
            cout << "   >> Юніт " << this->GetUnitType() << " уникнув атаки!\n";
    }
    virtual eUnitTypes GetType() const
    {
        return eUnitTypes::Swordsman;
    }
};
class Archer : public Unit ///Лучник: 12 hp, 4 dmg, 40 % dodge
{
private:
    int criticalDamage = 10;
    int chanceCritical = 10;

public:
    Archer() : Unit( "Лучник")
    {
        this->hp = 12;
        this->damage = 4;
        this->dodge = 40;
    }
   
    void Me_Attacked(int damage) override
    {
        if ((rand() % 101) > 40)
        {
            SetLife(-damage);
        }
        else
            cout << "   >> Юніт " << this->GetUnitType() << " уникнув атаки!\n";
    }
    int GetDamage() override
    {
        int crit = 0;

        if (rand() % this->chanceCritical <= 10)
        {
            crit = rand() % this->criticalDamage + 1;
            cout << " >> Лучник наносить критичний урон " << damage + crit << endl;
        }
        return this->damage + crit;
    }
    virtual eUnitTypes GetType() const
    {
        return eUnitTypes::Archer;
    }
};
class Mage :public Unit ///Маг : 8 hp, 10 dmg, 30 % dodge
{
    int hpRegeneration = 6;
    int normalHp = 8;

    void UnitRegeneration()
    {
        if (this->hp < 8) {
            int regHp = rand() % this->hpRegeneration +1;
            cout << " +++ Юніт відновлює " << regHp << " здоровя!" << endl;

            this->hp += regHp;
            if (this->hp > normalHp) this->hp = normalHp;
        }
    }

public:
    Mage() :Unit("Маг")
    {
        this->hp = 8;
        this->damage = 10;
        this->dodge = 30;
    }
   
    void Me_Attacked(int damage) override
    {
        if ((rand() % 101) > 30)
        {
            SetLife(-damage);
        }
        else
            cout << "   >> Юніт "<< this->GetUnitType() <<" уникнув атаки!\n";
    }
    int GetDamage() override
    {
        UnitRegeneration();
        return this->damage;
    }
    virtual eUnitTypes GetType() const
    {
        return eUnitTypes::Mage;
    }
};

class Teams
{
    int celectUnit = -1;
    string nameTeams = "";
    int coutUnit = 3;
    int deadUnit = 0;
    void SetDeadUnit(int i)
    {
        deadUnit += i;
        if (deadUnit == coutUnit)
        {
            theEnd = false;
            cout <<"\n      КОМАНДА " << nameTeams << " ПРОГРАЛА!!!!\n";
            system("pause");
            Menu();
        }
    }
public: 
    vector <shared_ptr<Unit>> listUnit;
    Teams(string name)
    {
        this->nameTeams = name;
        GenerateComand(this->coutUnit);
    }
  
    void GenerateComand(int count)
    {
        if (count == 0)return;
        int ran = rand() % 3;
        if (ran == 0)
        {
            listUnit.push_back(make_shared<Swordsman>());
        }
        else if (ran == 1)
        {
            listUnit.push_back(make_shared<Archer>());
        }
        else if (ran == 2)
        {
            listUnit.push_back(make_shared<Mage>());
        }
        GenerateComand(count - 1);
    }
    void ShowComand()
    {
        int count = 1;
        for (auto& it : listUnit)
        {
            Unit* unit = static_cast<Unit*>(it.get());
            cout << count << ". " << unit->GetUnitType();
            if (unit->GetHp() > 0)
            {
                cout << " (" << unit->GetHp() << "hp)" << endl;
            }
            else
                cout << " (dead)\n";
            count++;
        }
    }
    int CelectUnit()
    {
        if (deadUnit < coutUnit)
            for (int i = 0; i < this->coutUnit; i++)
            { 
                this->celectUnit++;   
                if (this->celectUnit >= 3) this->celectUnit = 0;
              
                Unit* unit = static_cast<Unit*>(listUnit[this->celectUnit].get());

                if (unit->GetHp() > 0)
                    return  this->celectUnit;
            }
        return -1;
    }
    void MoveHomoSapien(Teams& enemy)
    {
        CelectUnit();
        Unit* unit = static_cast<Unit*>(listUnit[this->celectUnit].get());

        cout << "Хід за юнітом > " << unit->GetUnitType() << " (" << unit->GetHp() << "hp)" << " (" << to_string(this->celectUnit) << ")\n"
            << "  Введіть \"9\" щоб переглянути власну армію\n"
            << " Кого атакувати?\n";
        enemy.ShowComand();

        int c = 0;
        cin >> c;

        if (c == 9) {
            cout << "  Власна армія:\n";
            this->ShowComand();
            celectUnit--;
            this->MoveHomoSapien(enemy);
        }
        else if(c <= this->coutUnit)
        {
            Unit* unit = static_cast<Unit*>(enemy.listUnit[c-1].get());
            if (unit->GetHp() <= 0)
            {
                cout << "  Юніт вже мертвий!\n";
                celectUnit--;
                this->MoveHomoSapien(enemy);
            }
            else
            AttackUnit(listUnit[this->celectUnit], enemy.listUnit[c-1], enemy);
        }
        else
        {
            cout << "  Такого юніта не існує!\n";
            celectUnit--;
            this->MoveHomoSapien(enemy);
        }
    }
    void MoveII(Teams& enemy)
    {
        //У мечника 15 хіт - поінтів(життів), пошкодження при атаці 5, шанс ухилятись 60 % .
        //Лучник: 12 hp, 4 dmg, 40 % dodge
        // Маг : 8 hp, 10 dmg, 30 % dodge    
        CelectUnit();
        Unit* MoveUnit = static_cast<Unit*>(listUnit[this->celectUnit].get());

        shared_ptr<Unit> unit= nullptr;
        if (SelectVictum(unit, enemy))
        {
            AttackUnit(listUnit[this->celectUnit], unit, enemy);
        }
    

   }
    bool SelectVictum(shared_ptr<Unit >&unit, Teams& enemy)
    {
        int selectUnit[2] = { -1,-1 };

        int short i = 0;
        for (auto& it : enemy.listUnit)
        {
            Unit* unitSelect = static_cast<Unit*>(it.get());

            if (unitSelect->GetHp() > 0)
                if (selectUnit[0] == -1)
                {
                    selectUnit[0] = i;
                    selectUnit[1] = unitSelect->GetHp();
                }
                else if (unitSelect->GetHp() < selectUnit[1])
                {
                    selectUnit[0] = i;
                    selectUnit[1] = unitSelect->GetHp();
                }
            i++;
        }
        if (selectUnit[0] != -1)
        {
            unit = enemy.listUnit[selectUnit[0]];
            return true;
        }
        else
            return false;
    }
    void AttackUnit(shared_ptr<Unit>Agressor, shared_ptr<Unit>Victim, Teams& enemy)
    {
        Unit* unitAgressor = static_cast<Unit*>(Agressor.get());  
       
        cout << "Юніт " << unitAgressor->GetUnitType() << " атакує...\n";
        unitAgressor->Attack(Victim);

        if ((static_cast<Unit*>(Victim.get())->GetHp() <= 0))
           enemy.SetDeadUnit(1);
    } 
  
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned int)time(0)); 
    
    Menu();
}

void Menu()
{
    SetColor(15, 0);
    system ("cls");

    while (true)
    {
        short c = 0;

        cout << "     Почати гру\n"
            << " 1. Два гравці - люди\n"
            << " 2. Людина проти II\n"
            << " 3. Показати характеристики юнітів\n"
            << " 0. Вийти\n";

        cin >> c;

        switch (c)
        {
        case 1:
        case 2:
        {
            theEnd = true;
            Game(c);
            break;
        }
        case 3:
        {
            cout << "Характеристики юнітів:\n\n"
                << " Воїн      Здоровя   Сила   Шанс відвороту        Здатність\n" 
                << " Мечник:      15      5         60%               Броня 1-4\n"
                << " Лучник:      12      4         40%               Крит 1-10/10% \n"
                << " Маг:         8       10        30%               Регенерація 1-6\n\n";
            break;
        }
        case 0:
        {
            exit(0);
        }
        }
    }
}
void Game(short i)
{
    Teams Red("Червоні");
    Teams Black("Чорні");

    cout << "Армія Червоних:\n";
    Red.ShowComand(); 
    cout << "\nАрмія Чорних:\n";
    Black.ShowComand();

    if (rand() % 2 == 0)
    {
        cout << "\nПерший хід за Червоними\n";
        while (theEnd)
        {
            SetColor(12, 0);
            cout << "\n----------Хід Червоних\n";
            Red.MoveHomoSapien(Black);
           
            SetColor(8, 0);
            cout << "\n----------Хід Чорних\n";
            if (i == 2) {
                Black.MoveII(Red);
                system("pause");
            }
            else
                Black.MoveHomoSapien(Red);
        }
    }
    else
    {
        cout << "\nПерший хід за Чорними\n";
        while (theEnd)
        {
            SetColor(8, 0);
            cout << "\n----------Хід Чорних\n";
            if (i == 2)
            {
                Black.MoveII(Red);
                system("pause"); 
            }
            else
                Black.MoveHomoSapien(Red);
           
            SetColor(12, 0);
            cout << "\n----------Хід Червоних\n";
            Red.MoveHomoSapien(Black);
        }
    }
}

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}