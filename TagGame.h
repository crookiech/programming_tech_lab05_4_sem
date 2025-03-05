#ifndef TAGGAME_H
#define TAGGAME_H

#include "C:/programming_tech/lab04/log/ILogger.h"
#include "C:/programming_tech/lab04/log/CreateLogger.h"
#include <string>

class TagGame {
private:
    std::string gameName;
public:
    virtual ~TagGame() {};
    void Shuffle();
    void Move(int index, int step);
    virtual void Play();
    virtual void Info();
};

class RateYourMindPal : public TagGame {
protected:
    std::string gameName = "Rate your mind pal";
public:
    RateYourMindPal();
    void Play() override;
    void Info() override;
};
    
class ClassicTagGame : public TagGame {
private:
    std::string gameName = "Classic Tag";
public:
    ClassicTagGame();
    void Play() override;
    void Info() override;
};

#endif
