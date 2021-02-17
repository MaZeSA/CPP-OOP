#include <iostream>
#include "Shooter.h"

int main()
{
    Fortress fortress(new int(4), new int(1));

    ((Archer)fortress).Shot(); 
    ((Archer)fortress).Shot(); 
    ((Archer)fortress).Shot();

    ((Ranger)fortress).Shot();  
    ((Ranger)fortress).Shot();

    ((Catapult)fortress).Shot();
}
