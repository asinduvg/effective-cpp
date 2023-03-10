#include <iostream>

class GameCharacter
{
public:
    virtual int healthValue() const; // not pure virtual, default algo to calculate health
};

int GameCharacter::healthValue() const
{
    // do some pre conditioned values 
    // eg: locking mutex, making a log entry
    // calculating health
    std::cout << "GameCharacter::doHealthValue" << std::endl;
    return 10;
    // do dome post conditioned values
    // eg: unlocking mutex
}

class UniqueCharacter : public GameCharacter
{
public:
    int healthValue() const override; // this is method overring, not redefining
};

// Not a good practice to allow clients to call virtual functions directly
int UniqueCharacter::healthValue() const
{
    // do some pre conditioned values 
    // eg: locking mutex, making a log entry
    // calculating health
    std::cout << "UniqueCharacter::doHealthValue" << std::endl;
    GameCharacter::healthValue();
    return 20;
    // do dome post conditioned values
    // eg: unlocking mutex
}

int main()
{
    GameCharacter gc;
    gc.healthValue();

    UniqueCharacter uq;
    uq.healthValue();
    

    return 0;
}