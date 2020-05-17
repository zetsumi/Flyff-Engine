#pragma once

#include <string>
#include "framework_fressource.h"
#include "property.hpp"

#pragma warning( disable : 4251 )

namespace fe
{
    /**
     * @brief Structure representant les SKILL dans flyff
     * fichier "propskill.txt"
     * 
     */
    struct API_DECLSPEC PropSkill : PropertyContainer
    {
        fe::type::_uint     version = 0;
        fe::type::_uint     id = 0;
        std::string         name = "";
        fe::type::_uint    num = 0;
        fe::type::_uint    packMax = 0;
        fe::type::_uint    itemKind1 = 0;
        fe::type::_uint    itemKind2 = 0;
        fe::type::_uint    itemKind3 = 0;
        fe::type::_uint    itemJob = 0;
        bool                permanence = false;
        fe::type::_uint    useable = 0;
        fe::type::_uint    itemSex = 0;
        fe::type::_uint    cost = 0;
        fe::type::_uint    endurance = 0;
        fe::type::_int             abrasion = 0;
        fe::type::_int             hardness = 0;
        fe::type::_uint    handed = 0;
        fe::type::_uint    heelH = 0;
        fe::type::_uint    parts = 0;
        fe::type::_uint    partsub = 0;
        bool                partFile = false;
        fe::type::_uint    exclusive = 0;
        fe::type::_uint    basePartsIgnore = 0;
        fe::type::_uint    itemLV = 0;
        fe::type::_uint    itemRare = 0;
        fe::type::_uint    shopAble = 0;
        bool                log = false;
        bool                charged = false;
        fe::type::_uint    linkKindBullet = 0;
        fe::type::_uint    linkKind = 0;
        fe::type::_uint    abilityMin = 0;
        fe::type::_uint    abilityMax = 0;
        PROP_ITEM_ELEMENT   itemType = PROP_ITEM_ELEMENT::NO_PROP;
        short               itemEAtk = 0;
        fe::type::_uint    parry = 0;
        fe::type::_uint    blockRating = 0;
        fe::type::_uint    addSkillMin = 0;
        fe::type::_uint    addSkillMax = 0;
        fe::type::_uint    atkStyle = 0;
        fe::type::_uint    weaponType = 0;
        fe::type::_uint    itemAtkOrder1 = 0;
        fe::type::_uint    itemAtkOrder2 = 0;
        fe::type::_uint    itemAtkOrder3 = 0;
        fe::type::_uint    itemAtkOrder4 = 0;
        fe::type::_uint    continuousPain = 0;
        fe::type::_uint    shellQuantity = 0;
        fe::type::_uint    recoil = 0;
        fe::type::_uint    loadingTime = 0;
        fe::type::_int      adjHitRate = 0;
        fe::type::_uint    attackSpeed = 0;
        fe::type::_uint    dmgShift = 0;
        fe::type::_uint    attackRange = 0;
        fe::type::_uint    probability = 0;
        fe::type::_uint    destParam1 = 0;
        fe::type::_uint    destParam2 = 0;
        fe::type::_uint    destParam3 = 0;
        fe::type::_int             adjParamVal1 = 0;
        fe::type::_int             adjParamVal2 = 0;
        fe::type::_int             adjParamVal3 = 0;
        fe::type::_uint    chgParamVal1 = 0;
        fe::type::_uint    chgParamVal2 = 0;
        fe::type::_uint    chgParamVal3 = 0;
        fe::type::_uint    destData1 = 0;
        fe::type::_uint    destData2 = 0;
        fe::type::_uint    destData3 = 0;
        fe::type::_uint    activeskill = 0;
        fe::type::_uint    activeskillLv = 0;
        fe::type::_uint    activeskillper = 0;
        fe::type::_uint    reqMp = 0;
        fe::type::_uint    repFp = 0;
        fe::type::_uint    reqDisLV = 0;
        fe::type::_uint    reSkill1 = 0;
        fe::type::_uint    reSkillLevel1 = 0;
        fe::type::_uint    reSkill2 = 0;
        fe::type::_uint    reSkillLevel2 = 0;
        fe::type::_uint    skillReadyType = 0;
        fe::type::_uint    skillReady = 0;
        fe::type::_uint    skillRange = 0;
        fe::type::_uint    sfxElemental = 0;
        fe::type::_uint    sfxObj = 0;
        fe::type::_uint    sfxObj2 = 0;
        fe::type::_uint    sfxObj3 = 0;
        fe::type::_uint    sfxObj4 = 0;
        fe::type::_uint    sfxObj5 = 0;
        fe::type::_uint    useMotion = 0;
        fe::type::_uint    circleTime = 0;
        fe::type::_uint    skillTime = 0;
        fe::type::_uint    exeTarget = 0;
        fe::type::_uint    useChance = 0;
        fe::type::_uint    spellRegion = 0;
        fe::type::_uint    spellType = 0;
        fe::type::_uint    referStat1 = 0;
        fe::type::_uint    referStat2 = 0;
        fe::type::_uint    referTarget1 = 0;
        fe::type::_uint    referTarget2 = 0;
        fe::type::_uint    referValue1 = 0;
        fe::type::_uint    referValue2 = 0;
        fe::type::_uint    skillType = 0;
        float               itemResistElecricity = 0.0f;
        float               itemResistFire = 0.0f;
        float               itemResistWind = 0.0f;
        float               itemResistWater = 0.0f;
        float               itemResistEarth = 0.0f;
        fe::type::_int             evildoing = 0;
        fe::type::_uint    expertLV = 0;
        fe::type::_uint    expertMax = 0;
        fe::type::_uint    subDefine = 0;
        fe::type::_uint    exp = 0;
        fe::type::_uint    comboStyle = 0;
        float               flightSpeed = 0.0f;
        float               flightLRAngle = 0.0f;
        float                FlightTBAngle = 0.0f;
        fe::type::_uint    flightLimit = 0;
        fe::type::_uint    fFuelReMax = 0;
        fe::type::_uint    aFuelReMax = 0;
        fe::type::_uint    fuelRe = 0;
        fe::type::_uint    limitLevel1 = 0;
        fe::type::_uint    reflect = 0;
        fe::type::_uint    sndAttack1 = 0;
        fe::type::_uint    sndAttack2 = 0;
        std::string         icon = "";
        fe::type::_uint    questID = 0;
        std::string         textFile = "";
        std::string         comment = "";

        PropSkill(const PropSkill* o) : PropSkill(*o)
        {
        }

        PropSkill() = default;
        PropSkill(const PropSkill&) = default;
        PropSkill(PropSkill&&) noexcept = default;
        PropSkill& operator=(const PropSkill&) = default;
        PropSkill& operator=(PropSkill&&) = default;
        ~PropSkill() = default;
    };
}
#pragma warning( default : 4251 )
