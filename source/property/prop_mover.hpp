#pragma once

#include <string>
#include <framework_fengine.h>
#include <property/property.hpp>


#pragma warning( disable : 4251 )


namespace fe
{
    /**
     * @brief Structure representant les Mover dans flyff
     * Fichier "propmover.inc"
     * 
     */
    struct API_DECLSPEC PropMover : PropertyContainer
    {
        std::uint64_t        id = 0;
        std::string          name = "";
        std::uint64_t        ai = 0;
        std::uint64_t        str = 0;
        std::uint64_t        sta = 0;
        std::uint64_t        dex = 0;
        std::uint64_t        intelligent = 0;
        std::uint64_t        hr = 0;
        std::uint64_t        er = 0;
        std::uint64_t        race = 0;
        std::uint64_t        belligerence = 0;
        std::uint64_t        gender = 0;
        std::uint64_t        level = 0;
        std::uint64_t        filghtLevel = 0;
        std::uint64_t        size = 0;
        std::uint64_t        classe = 0;
        bool                 part = false;
        std::uint64_t        karma = 0;
        std::uint64_t        useable = 0;
        std::uint64_t        actionRadius = 0;
        std::uint64_t        atkMin = 0;
        std::uint64_t        atkMax = 0;
        std::uint64_t        atk1 = 0;
        std::uint64_t        atk2 = 0;
        std::uint64_t        atk3 = 0;
        std::uint64_t        horizontalRate = 0;
        std::uint64_t        verticalRate = 0;
        std::uint64_t        diagonalRate = 0;
        std::uint64_t        thrustRate = 0;
        std::uint64_t        chestRate = 0;
        std::uint64_t        headRate = 0;
        std::uint64_t        armRate = 0;
        std::uint64_t        legRate = 0;
        std::uint64_t        attackSpeed = 0;
        std::uint64_t        reAttackDelay = 0;
        std::uint64_t        addHp = 0;
        std::uint64_t        addMp = 0;
        std::uint64_t        naturealArmor = 0;
        std::int64_t         abrasion = 0;
        std::int64_t         hardness = 0;
        std::uint64_t        adjAtkDelay = 0;
        PROP_ITEM_ELEMENT    elementType = PROP_ITEM_ELEMENT::NO_PROP;
        std::uint64_t        elementAtk = 0;
        std::uint64_t        hideLevel = 0;
        float                   speed = 0.0f;
        std::uint64_t        shelter = 0;
        bool                    flying = false;
        std::uint64_t        jumpIng = 0;
        std::uint64_t        airJump = 0;
        bool                    taming = false;
        std::uint64_t        resisMagic = 0;
        float                   resistElecricity = 0.0f;
        float                   resistFire = 0.0f;
        float                   resistWind = 0.0f;
        float                   resistWater = 0.0f;
        float                   resistEarth = 0.0f;
        std::uint64_t        cash = 0;
        std::uint64_t        sourceMaterial = 0;
        std::uint64_t        materialAmount = 0;
        std::uint64_t        cohesion = 0;
        std::uint64_t        holdingTime = 0;
        std::uint64_t        correctionValue = 0;
        std::uint64_t        expValue = 0;
        std::int64_t                 fxpValue = 0;
        std::int64_t                 bodyState = 0;
        std::uint64_t        addAbility = 0;
        bool                    killable = false;
        std::uint64_t        virtItem1 = 0;
        std::uint64_t        virtType1 = 0;
        std::uint64_t        virtItem2 = 0;
        std::uint64_t        virtType2 = 0;
        std::uint64_t        virtItem3 = 0;
        std::uint64_t        virtType3 = 0;
        std::uint64_t        sndAtk1 = 0;
        std::uint64_t        sndAtk2 = 0;
        std::uint64_t        sndDie1 = 0;
        std::uint64_t        sndDie2 = 0;
        std::uint64_t        sndDmg1 = 0;
        std::uint64_t        sndDmg2 = 0;
        std::uint64_t        sndDmg3 = 0;
        std::uint64_t        sndIdle1 = 0;
        std::uint64_t        sndIdle2 = 0;
        std::string             comment = "";

        PropMover(const PropMover* o) : PropMover(*o)
        {
        }

        PropMover() = default;
        PropMover(const PropMover&) = default;
        PropMover(PropMover&&) noexcept = default;
        PropMover& operator=(const PropMover&) = default;
        PropMover& operator=(PropMover&&) = default;
        ~PropMover() = default;
    };
}
#pragma warning( default : 4251 )
