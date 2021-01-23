//
// Created by Admin on 14.01.2021.
//

#include "SpellCaster.h"


SpellCaster::SpellCaster(const std::string& name,
                         State* uState,
                         BaseAttack* uAttack,
                         MagicAttack* mAttack,
                         SpellBook* sBook)
    :Unit(name, uAttack) {
    this->mAttack = mAttack;
    this->sBook = sBook;
    this->uState = uState;
}

SpellCaster::~SpellCaster() {
    delete(this->mAttack);
    delete(this->sBook);
}

State& SpellCaster::getState() {
    return *(this->uState);
}

SpellBook& SpellCaster::getSpellBook() const {
    return *(this->sBook);
}

void SpellCaster::spellAttack(Unit* enemy, const std::string& spellName) {
    int mDmg = this->getSpellBook().getSpell(spellName);
    this->mAttack->attack(this, enemy, mDmg);
}

std::ostream& operator<<(std::ostream& out, SpellCaster& spellCaster) {
    out << spellCaster.getName() << ": "<< std::endl;
    out << spellCaster.getState() << std::endl;

    return out;
}