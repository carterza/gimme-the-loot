#ifndef LIGHTNING_BOLT_HPP
#define LIGHTNING_BOLT_HPP

#include "Actor.hpp"
#include "Pickable.hpp"

class LightningBolt : public Pickable {
public:
  float range, damage;
  LightningBolt(float range, float damage);
  bool use(Actor *owner, Actor *wearer);
  void load(const gmtl::Pickable pickable);
  void save(gmtl::Pickable *pickable);
};
#endif
