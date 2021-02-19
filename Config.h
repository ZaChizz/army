//
// Created by Admin on 29.01.2021.
//

#ifndef ARMY_CONFIG_H
#define ARMY_CONFIG_H

enum class HP {
    SOLDIER = 100,
    ROGUE = 85,
    BERSERKER = 90,
    VAMPIRE = 70,
    WEREWOLF = 60,
    SPELLCASTER = 70
};

enum class DMG {
    SOLDIER = 20,
    ROGUE = 30,
    BERSERKER = 30,
    VAMPIRE = 35,
    WEREWOLF = 25,
    SPELLCASTER = 70
};

enum class MULTIPLE_DMG {
    SOLDIER = 1,
    ROGUE = 1,
    BERSERKER = 1,
    VAMPIRE = 2,
    WEREWOLF = 2,
    SPELLCASTER = 1
};

enum class SWITCH {
    WOLF_HP = 1,
    WOLF_DMG = 10,
    WOLF_MHP = 3
};

enum class MHP {
    SOLDIER = 30,
    ROGUE = 20,
    BERSERKER = 40,
    VAMPIRE = 35,
    WEREWOLF = 40,
    SPELLCASTER = 70
};

enum class SPELLBOOK {
    MAGICHIT10 = 10,
    MAGICHIT5 = 5
};

enum class TYPEUNIT {
    UNDEAD = 0,
    UNIT = 1
};

#endif //ARMY_CONFIG_H
