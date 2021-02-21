#include "Activity.h"

Activity::ObjActivity::ObjActivity(AType type_)
{
	this->typeMe = type_;
}

void Activity::ObjActivity::Action()
{

}

Activity::ObjActivity::AType Activity::ObjActivity::GetType()
{
	return this->typeMe;
}
