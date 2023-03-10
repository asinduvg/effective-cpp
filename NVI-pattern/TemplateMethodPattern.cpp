#include <iostream>

class GameCharacter
{
public:
    int healthValue() const;
private:
    virtual int doHealthValue() const; // could be protected or public (NVI idiom can't be really applied)
};

int GameCharacter::healthValue() const
{
    // do some pre conditioned values 
    // eg: locking mutex, making a log entry
    int retVal = doHealthValue();
    // do dome post conditioned values
    // eg: unlocking mutex
    return retVal;
}

int GameCharacter::doHealthValue() const
{
    std::cout << "GameCharacter::doHealthValue" << std::endl;
    return 10;
    // derived class may redefined this default
    // algorithm for calculating character's health
}

class UniqueCharacter : public GameCharacter
{
private:
    int doHealthValue() const; // this is redefining virtual function. Not overriding
};

int UniqueCharacter::doHealthValue() const
{
    std::cout << "UniqueCharacter::doHealthValue" << std::endl;
    return 20;
}

int main()
{
    GameCharacter gc;
    gc.healthValue();

    UniqueCharacter uq;
    uq.healthValue();

    return 0;
}

/**
 * @brief 
 *  * The basic design - having client call private virtual functions
 *  indirectly through public non-virtual member functions is known as the
 *  non-virtual interface (NVI) idiom.
 *  * Particular manifestation of the more general design pattern called
 *  Template Method
 * 
 */