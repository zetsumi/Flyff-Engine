#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

#pragma warning( disable : 4251 )

namespace fe
{
    struct API_DECLSPEC PropMover : PropertyContainer
    {
        fe::type::_uint        id = 0;
        std::string             name = "";
        fe::type::_uint        ai = 0;
        fe::type::_uint        str = 0;
        fe::type::_uint        sta = 0;
        fe::type::_uint        dex = 0;
        fe::type::_uint        intelligent = 0;
        fe::type::_uint        hr = 0;
        fe::type::_uint        er = 0;
        fe::type::_uint        race = 0;
        fe::type::_uint        belligerence = 0;
        fe::type::_uint        gender = 0;
        fe::type::_uint        level = 0;
        fe::type::_uint        filghtLevel = 0;
        fe::type::_uint        size = 0;
        fe::type::_uint        classe = 0;
        bool                    part = false;
        fe::type::_uint        karma = 0;
        fe::type::_uint        useable = 0;
        fe::type::_uint        actionRadius = 0;
        fe::type::_uint        atkMin = 0;
        fe::type::_uint        atkMax = 0;
        fe::type::_uint        atk1 = 0;
        fe::type::_uint        atk2 = 0;
        fe::type::_uint        atk3 = 0;
        fe::type::_uint        horizontalRate = 0;
        fe::type::_uint        verticalRate = 0;
        fe::type::_uint        diagonalRate = 0;
        fe::type::_uint        thrustRate = 0;
        fe::type::_uint        chestRate = 0;
        fe::type::_uint        headRate = 0;
        fe::type::_uint        armRate = 0;
        fe::type::_uint        legRate = 0;
        fe::type::_uint        attackSpeed = 0;
        fe::type::_uint        reAttackDelay = 0;
        fe::type::_uint        addHp = 0;
        fe::type::_uint        addMp = 0;
        fe::type::_uint        naturealArmor = 0;
        fe::type::_int                 abrasion = 0;
        fe::type::_int                 hardness = 0;
        fe::type::_uint        adjAtkDelay = 0;
        PROP_ITEM_ELEMENT       elementType = PROP_ITEM_ELEMENT::NO_PROP;
        fe::type::_uint        elementAtk = 0;
        fe::type::_uint        hideLevel = 0;
        float                   speed = 0.0f;
        fe::type::_uint        shelter = 0;
        bool                    flying = false;
        fe::type::_uint        jumpIng = 0;
        fe::type::_uint        airJump = 0;
        bool                    taming = false;
        fe::type::_uint        resisMagic = 0;
        float                   resistElecricity = 0.0f;
        float                   resistFire = 0.0f;
        float                   resistWind = 0.0f;
        float                   resistWater = 0.0f;
        float                   resistEarth = 0.0f;
        fe::type::_uint        cash = 0;
        fe::type::_uint        sourceMaterial = 0;
        fe::type::_uint        materialAmount = 0;
        fe::type::_uint        cohesion = 0;
        fe::type::_uint        holdingTime = 0;
        fe::type::_uint        correctionValue = 0;
        fe::type::_uint        expValue = 0;
        fe::type::_int                 fxpValue = 0;
        fe::type::_int                 bodyState = 0;
        fe::type::_uint        addAbility = 0;
        bool                    killable = false;
        fe::type::_uint        virtItem1 = 0;
        fe::type::_uint        virtType1 = 0;
        fe::type::_uint        virtItem2 = 0;
        fe::type::_uint        virtType2 = 0;
        fe::type::_uint        virtItem3 = 0;
        fe::type::_uint        virtType3 = 0;
        fe::type::_uint        sndAtk1 = 0;
        fe::type::_uint        sndAtk2 = 0;
        fe::type::_uint        sndDie1 = 0;
        fe::type::_uint        sndDie2 = 0;
        fe::type::_uint        sndDmg1 = 0;
        fe::type::_uint        sndDmg2 = 0;
        fe::type::_uint        sndDmg3 = 0;
        fe::type::_uint        sndIdle1 = 0;
        fe::type::_uint        sndIdle2 = 0;
        std::string             comment = "";

        PropMover(const PropMover* o) : PropMover(*o)
        {
        }

        PropMover() = default;
        PropMover(const PropMover&) = default;
        PropMover(PropMover&&) = default;
        PropMover& operator=(const PropMover&) = default;
        PropMover& operator=(PropMover&&) = default;
        ~PropMover() = default;
    };
}
#pragma warning( default : 4251 )
