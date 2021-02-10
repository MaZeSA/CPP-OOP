#include "Activity.h"
#include "SetCursor.h"
#include <iostream>

Activity::Activity(int x_, int y_, int l_)
{
    this->X = x_;
    this->Y = y_;
    this->lenghtFild = l_;
}

void Activity::SetNextActivity(Activity* NextActivity_)
{
    this->NextActivity = NextActivity_;
}

void Activity::SetBackActivity(Activity* BackActivity_)
{
    this->BackActivity = BackActivity_;
}

char Activity::GetSymbol()
{
    return (char)this->typeMe;
}

void Activity::PrintMe()
{
    setCursorPosition( X, Y);
    std::cout << (char)this->typeMe;
}

void Activity::Move()
{
    if (this->X > 0 && this->X < 100)
        if (this->moveIndex < 0)
        {
            (*this).BackActivity->SetState(this->moveIndex + 1, this->typeMe, this->ownerShip);
        }
        else if (this->moveIndex > 0)
        {
            (*this).NextActivity->SetState(this->moveIndex + 1, this->typeMe, this->ownerShip);
        }

    this->typeMe = TypeActyvity::none;
    this->ownerShip = nullptr;
    PrintMe();
    this->moveIndex = 0;
}

bool Activity::HitCheck(Ship* ship_)
{
    return ship_->GetEnemy()->HitCheck(this->Y, this->lenghtFild);
}


void Activity::SetState(int moveIndex_, TypeActyvity type_, Ship* ship_)
{
    if (this == NULL)
        return;

    if (this->typeMe == Activity::TypeActyvity::bullet)
    {
        this->moveIndex = 0;
        this->typeMe = Activity::TypeActyvity::none;
    }
    else
    {
        moveIndex = moveIndex_;
        typeMe = type_;
        this->ownerShip = ship_;
    }


    if (ship_ != nullptr)
        if (ship_->GetSide() == Ship::Side::LEFT)
        {
            if (this->GetX() > 95)
                if (HitCheck(this->ownerShip))
                {
                    this->typeMe = TypeActyvity::none;
                    this->ownerShip = nullptr;
                    this->moveIndex = 0;
                }
        }
        else
        {
            if (this->GetX() < 4)
                if (HitCheck(this->ownerShip))
                {
                    this->typeMe = TypeActyvity::none;
                    this->ownerShip = nullptr;
                    this->moveIndex = 0;
                }
        }

    PrintMe();
}

void Activity::SetState(TypeActyvity type_)
{
    SetState(0, type_, this->ownerShip);
}

int Activity::GetMoveIndex()
{
    return this->moveIndex;
}

int Activity::GetX()
{
    return this->X;
}

int Activity::GetY()
{
    return this->Y;
}

int Activity::GetLenght()
{
    return this->lenghtFild;
}
