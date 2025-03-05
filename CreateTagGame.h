#ifndef CREATETAGGAME_H
#define CREATETAGGAME_H

#include "TagGame.h"

class CreateTagGame {
public:
    virtual ~CreateTagGame() {};
    virtual TagGame* FactoryMethod() = 0;
    virtual void info();
};

class CreateRateYourMindPal : public CreateTagGame {
public:
    TagGame* FactoryMethod() override;
    virtual void info();
};

class CreateClassicTagGame : public CreateTagGame {
public:
    TagGame* FactoryMethod() override;
    virtual void info();
};

#endif