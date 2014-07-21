#ifndef MONSTER_AI_HPP
#define MONSTER_AI_HPP

#include "Ai.hpp"
#include "Actor.hpp"

class MonsterAi : public Ai {
public:
  MonsterAi();
  ~MonsterAi();
  void update(Actor *owner);
protected:
  int moveCount;
  void moveOrAttack(Actor *owner, int targetx, int targety);
};

class ConfusedMonsterAi : public Ai {
public:
  ConfusedMonsterAi(int nbTurns, Ai *oldAi);
  void update(Actor *owner);
protected:
  int nbTurns;
  Ai *oldAi;
};

#endif
