#include "Ship.h";

class Activity
{
public:
	enum class  TypeActyvity
	{
		bullet = 42,//*
		hp = 43,//+
		ammunition = 37,//%
		amor = 35,//#
		none = 32
	};

	Activity(int, int, int);
	void SetNextActivity(Activity*);
	void SetBackActivity(Activity*);
	char GetSymbol();
	void PrintMe();
	void Move();
	bool HitCheck(Ship*);
	void SetState(int, TypeActyvity, Ship*); 
	void SetState(TypeActyvity);
	int GetMoveIndex();
	int GetX();
	int GetY();
	int GetLenght();

	class ObjActivity
	{
	public:
		enum class  AType
		{
			bullet = 42,//*
			hp = 43,//+
			ammunition = 37,//%
			amor = 35,//#
			none = 32
		};
		ObjActivity(AType type_);
		virtual void Action();
		AType GetType();

	private:
		int moveIndex = 0;
		AType typeMe = AType::none;
		Ship* ownerShip = nullptr;
	};

	class Bullet: ObjActivity
	{
		Bullet() : ObjActivity(AType::bullet) {};
	};

private:
	int X = 0,
		Y = 0,
		moveIndex = 0;
	int lenghtFild=0;
	Activity* NextActivity = nullptr;
	Activity* BackActivity = nullptr;
	TypeActyvity typeMe = TypeActyvity::none;
	Ship* ownerShip = nullptr;
};