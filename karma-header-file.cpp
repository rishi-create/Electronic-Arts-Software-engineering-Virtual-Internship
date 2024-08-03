#ifndef KARMASYSTEM_H
#define KARMASYSTEM_H

#include <bits/stdc++.h>
//all classes are enclosed within the KarmaSytem
namespace KarmaSystem {

//single point of karma
class KarmaPoint {
public:
    KarmaPoint(int value); //  constructor

private:
    int value;
};

//General karma power that can be activated
class KarmaPower {
public:
    KarmaPower(const std::string& name, const std::string& type, int cost);
    virtual void activate(); // method for power activation

protected:
    std::string name;
    std::string type;
    int cost;
};

//combination of multiple karma power
class KarmaComboPower : public KarmaPower {
public:
    KarmaComboPower(const std::vector<KarmaPower*>& componentPowers);
    void combine(const std::vector<KarmaPower*>& powers);

private:
    std::vector<KarmaPower*> componentPowers;
    int totalCost;
};

//challenges can be completed for karma rewards
class KarmaChallenge {
public:
    KarmaChallenge(const std::string& description, int rewardPoints);

    void complete();
    int getRewardPoints() const;

private:
    std::string description;
    int rewardPoints;
    bool isCompleted;
};

//events triggered by karma powers
class KarmaEvent {
public:
    KarmaEvent(const std::string& description, int duration, const std::string& effectType);

    void start();
    void end();

private:
    std::string description;
    int duration;
    std::string effectType;
};

//pool of kamra points
class KarmaPool {
public:
    KarmaPool();

    void deposit(int points);
    void withdraw(int points);
    float calculateMultiplier() const;
    int getTotalPoints() const;

private:
    int totalPoints;
    float multiplier;
    std::vector<KarmaPoint*> karmaPoints;
};

//player in game
class Player {
public:
    Player(const std::string& name);
    
    void addKarmaPoints(int points);
    void useKarmaPower(KarmaPower* power);
    void completeChallenge(KarmaChallenge* challenge);

private:
    std::string name;
    KarmaPool* karmaPool;
    std::vector<KarmaChallenge*> activeChallenges;
    std::vector<KarmaEvent*> completedEvents;
};

} // namespace KarmaSystem

#endif // KARMASYSTEM_H
