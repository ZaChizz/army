//
// Created by Admin on 02.01.2021.
//

#include "State.h"

State::State (int hp, int dmg, int mHp, int type){
    this->damage = dmg;
    this->hitPoints = hp;
    this->hitPointsLimit = hp;
    this->magicHitPoints = mHp;
    this->magicHitPointsLimit = mHp;
    this->typeUnit = type;
    this->dead = false;
}

State::~State() {}

void State::isAlive() {
    if ( this->hitPoints == 0 || this->magicHitPoints == 0 ) {
        this->dead = true;
        return;
        //throw new UnitIsDead("I ma dead!");
    }
}

int State::getDamage() const {
    return this->damage;
}

int State::getHitPoints() const {
    return this->hitPoints;
}

int State::getMagicHitPoints() const {
    return this->magicHitPoints;
}

int State::getHitPointsLimit() const {
    return this->hitPointsLimit;
}

int State::getMagicHitPointsLimit() const {
    return this->magicHitPointsLimit;
}

int State::getTypeUnit() const {
    return this->typeUnit;
}

bool State::getDead() const {
    return this->dead;
}

void State::updateTypeUnit(const int type) {
    this->typeUnit = type;
}

void State::updateDamage(const int dmg) {
    if ( dmg >= this->damage ) {
        this->damage = 0;
    } else {
        this->damage -= dmg;
    }
}

void State::setHitPoints(const int hp) {
    this->isAlive();

    this->hitPoints += hp;
    if ( this->hitPoints > this->hitPointsLimit ) {
        this->hitPoints = this->hitPointsLimit;
    }
}

void State::setMagicHitPoints(const int mHp) {
    this->isAlive();

    this->magicHitPoints += mHp;
    if ( this->magicHitPoints > this->magicHitPointsLimit ) {
        this->magicHitPoints = this->magicHitPointsLimit;
    }
}

void State::takeDamage(const int dmg) {
    this->isAlive();

    if ( dmg >= this->hitPoints ) {
        this->hitPoints = 0;
    } else {
        this->hitPoints -= dmg;
    }
}

const void State::takeMagicDamage(const int mDmg) {
    this->isAlive();

    if ( mDmg >= this->magicHitPoints ) {
        this->magicHitPoints = 0;
    } else {
        this->magicHitPoints -= mDmg;
    }
}

std::ostream& operator<<(std::ostream& out, const State& state) {
    if ( state.getHitPoints() == 0 || state.getMagicHitPoints() == 0 ) {
        out << " Dead " << std::endl;
    } else {
        out << "HitPoints - " << state.getHitPoints() << std::endl;
        out << "MagicHitPoints - " << state.getMagicHitPoints() << std::endl;
        out << "Damage - " << state.getDamage() << std::endl;
    }
    if ( state.getTypeUnit() == 0 ) {
        out << "Unit UNDEAD" << std::endl;
    }
    return out;
}

