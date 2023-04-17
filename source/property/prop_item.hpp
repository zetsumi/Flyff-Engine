#pragma once

#include <string>
#include <framework_fengine.h>
#include <property/property.hpp>


#pragma warning( disable : 4251 )


namespace fe
{
    /**
     * @brief Structure representant les propriété des ITEM dans FLYFF.
     * Fichier "propitem.txt"
     * 
     */
    struct API_DECLSPEC PropItem : public PropertyContainer
    {
        std::uint64_t    version = 0;
        std::uint64_t    id = 0;
        std::string        name = "";
        std::uint64_t    num = 0;
        std::uint64_t    packMax = 0;
        std::uint64_t    itemKind1 = 0;
        std::uint64_t    itemKind2 = 0;
        std::uint64_t    itemKind3 = 0;
        std::uint64_t    itemJob = 0;
        bool               permanence = false;
        std::uint64_t    useable = 0;
        std::uint64_t    itemSex = 0;
        std::uint64_t    cost = 0;
        std::uint64_t    endurance = 0;
        std::int64_t     abrasion = 0;
        std::int64_t     maxRepair = 0;
        std::uint64_t    handed = 0;
        std::uint64_t    flag = 0;
        std::uint64_t    parts = 0;
        std::uint64_t    partsub = 0;
        bool               partFile = false;
        std::uint64_t    exclusive = 0;
        std::uint64_t    basePartsIgnore = 0;
        std::uint64_t    itemLV = 0;
        std::uint64_t    itemRare = 0;
        std::uint64_t    shopAble = 0;
        bool               log = false;
        bool               charged = false;
        std::uint64_t    linkKindBullet = 0;
        std::uint64_t    linkKind = 0;
        std::uint64_t    abilityMin = 0;
        std::uint64_t    abilityMax = 0;
        PROP_ITEM_ELEMENT  itemType = PROP_ITEM_ELEMENT::NO_PROP;
        short              itemEAtk = 0;
        std::uint64_t    parry = 0;
        std::uint64_t    blockRating = 0;
        std::uint64_t    addSkillMin = 0;
        std::uint64_t    addSkillMax = 0;
        std::uint64_t    atkStyle = 0;
        std::uint64_t    weaponType = 0;
        std::uint64_t    itemAtkOrder1 = 0;
        std::uint64_t    itemAtkOrder2 = 0;
        std::uint64_t    itemAtkOrder3 = 0;
        std::uint64_t    itemAtkOrder4 = 0;
        bool                continuousPain = false;
        std::uint64_t    shellQuantity = 0;
        std::uint64_t    recoil = 0;
        std::uint64_t    loadingTime = 0;
        std::int64_t      adjHitRate = 0;
        std::uint64_t    attackSpeed = 0;
        std::uint64_t    dmgShift = 0;
        std::uint64_t    attackRange = 0;
        std::uint64_t    probability = 0;
        std::uint64_t    destParam1 = 0;
        std::uint64_t    destParam2 = 0;
        std::uint64_t    destParam3 = 0;
        std::int64_t      adjParamVal1 = 0;
        std::int64_t      adjParamVal2 = 0;
        std::int64_t      adjParamVal3 = 0;
        std::uint64_t    chgParamVal1 = 0;
        std::uint64_t    chgParamVal2 = 0;
        std::uint64_t    chgParamVal3 = 0;
        std::uint64_t    destData1 = 0;
        std::uint64_t    destData2 = 0;
        std::uint64_t    destData3 = 0;
        std::uint64_t    activeskill = 0;
        std::uint64_t    activeskillLv = 0;
        std::uint64_t    activeskillper = 0;
        std::uint64_t    reqMp = 0;
        std::uint64_t    repFp = 0;
        std::uint64_t    reqDisLV = 0;
        std::uint64_t    reSkill1 = 0;
        std::uint64_t    reSkillLevel1 = 0;
        std::uint64_t    reSkill2 = 0;
        std::uint64_t    reSkillLevel2 = 0;
        std::uint64_t    skillReadyType = 0;
        std::uint64_t    skillReady = 0;
        std::uint64_t    skillRange = 0;
        std::uint64_t    sfxElemental = 0;
        std::uint64_t    sfxObj = 0;
        std::uint64_t    sfxObj2 = 0;
        std::uint64_t    sfxObj3 = 0;
        std::uint64_t    sfxObj4 = 0;
        std::uint64_t    sfxObj5 = 0;
        std::uint64_t    useMotion = 0;
        std::uint64_t    circleTime = 0;
        std::uint64_t    skillTime = 0;
        std::uint64_t    exeTarget = 0;
        std::uint64_t    useChance = 0;
        std::uint64_t    spellRegion = 0;
        std::uint64_t    spellType = 0;
        std::uint64_t    referStat1 = 0;
        std::uint64_t    referStat2 = 0;
        std::uint64_t    referTarget1 = 0;
        std::uint64_t    referTarget2 = 0;
        std::uint64_t    referValue1 = 0;
        std::uint64_t    referValue2 = 0;
        std::uint64_t    skillType = 0;
        float               itemResistElecricity = 0.0f;
        float               itemResistFire = 0.0f;
        float               itemResistWind = 0.0f;
        float               itemResistWater = 0.0f;
        float               itemResistEarth = 0.0f;
        std::int64_t             evildoing = 0;
        std::uint64_t    expertLV = 0;
        std::uint64_t    expertMax = 0;
        std::uint64_t    subDefine = 0;
        std::uint64_t    exp = 0;
        std::uint64_t    comboStyle = 0;
        float               flightSpeed = 0.0f;
        float               flightLRAngle = 0.0f;
        float               flightTBAngle = 0.0f;
        std::uint64_t    flightLimit = 0;
        std::uint64_t    fFuelReMax = 0;
        std::uint64_t    aFuelReMax = 0;
        std::uint64_t    fuelRe = 0;
        std::uint64_t    limitLevel1 = 0;
        std::uint64_t    reflect = 0;
        std::uint64_t    sndAttack1 = 0;
        std::uint64_t    sndAttack2 = 0;
        std::string         icon = "";
        std::uint64_t    questID = 0;
        std::string         textFile = "";
        std::string         comment = "";

        PropItem(const PropItem* o) : PropItem(*o){}
        PropItem() = default;
        PropItem(const PropItem&) = default;
        PropItem(PropItem&&) noexcept = default;
        PropItem& operator=(const PropItem&) = default;
        PropItem& operator=(PropItem&&) = default;
        ~PropItem() = default;
    };

}
#pragma warning( default : 4251 )
