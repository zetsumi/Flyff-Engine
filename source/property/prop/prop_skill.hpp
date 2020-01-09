#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

namespace fe
{
    struct API_DECLSPEC PropSkill : PropertyContainer
    {
        unsigned __int64    version;
        unsigned __int64    id;
        std::string         name;
        unsigned __int64    num;
        unsigned __int64    packMax;
        unsigned __int64    itemKind1;
        unsigned __int64    itemKind2;
        unsigned __int64    itemKind3;
        unsigned __int64    itemJob;
        bool                permanence;
        unsigned __int64    useable;
        unsigned __int64    itemSex;
        unsigned __int64    cost;
        unsigned __int64    endurance;
        __int64             abrasion;
        __int64             hardness;
        unsigned __int64    handed;
        unsigned __int64    heelH;
        unsigned __int64    parts;
        unsigned __int64    partsub;
        bool                partFile;
        unsigned __int64    exclusive;
        unsigned __int64    basePartsIgnore;
        unsigned __int64    itemLV;
        unsigned __int64    itemRare;
        unsigned __int64    shopAble;
        bool                log;
        bool                charged;
        unsigned __int64    linkKindBullet;
        unsigned __int64    linkKind;
        unsigned __int64    abilityMin;
        unsigned __int64    abilityMax;
        PROP_ITEM_ELEMENT   itemType;
        short               itemEAtk;
        unsigned __int64    parry;
        unsigned __int64    blockRating;
        unsigned __int64    addSkillMin;
        unsigned __int64    addSkillMax;
        unsigned __int64    atkStyle;
        unsigned __int64    weaponType;
        unsigned __int64    itemAtkOrder1;
        unsigned __int64    itemAtkOrder2;
        unsigned __int64    itemAtkOrder3;
        unsigned __int64    itemAtkOrder4;
        unsigned __int64    continuousPain;
        unsigned __int64    shellQuantity;
        unsigned __int64    recoil;
        unsigned __int64    loadingTime;
        __int64             adjHitRate;
        unsigned __int64    attackSpeed;
        unsigned __int64    dmgShift;
        unsigned __int64    attackRange;
        unsigned __int64    probability;
        unsigned __int64    destParam1;
        unsigned __int64    destParam2;
        unsigned __int64    destParam3;
        __int64             adjParamVal1;
        __int64             adjParamVal2;
        __int64             adjParamVal3;
        unsigned __int64    chgParamVal1;
        unsigned __int64    chgParamVal2;
        unsigned __int64    chgParamVal3;
        unsigned __int64    destData1;
        unsigned __int64    destData2;
        unsigned __int64    destData3;
        unsigned __int64    activeskill;
        unsigned __int64    activeskillLv;
        unsigned __int64    activeskillper;
        unsigned __int64    reqMp;
        unsigned __int64    repFp;
        unsigned __int64    reqDisLV;
        unsigned __int64    reSkill1;
        unsigned __int64    reSkillLevel1;
        unsigned __int64    reSkill2;
        unsigned __int64    reSkillLevel2;
        unsigned __int64    skillReadyType;
        unsigned __int64    skillReady;
        unsigned __int64    skillRange;
        unsigned __int64    sfxElemental;
        unsigned __int64    sfxObj;
        unsigned __int64    sfxObj2;
        unsigned __int64    sfxObj3;
        unsigned __int64    sfxObj4;
        unsigned __int64    sfxObj5;
        unsigned __int64    useMotion;
        unsigned __int64    circleTime;
        unsigned __int64    skillTime;
        unsigned __int64    exeTarget;
        unsigned __int64    useChance;
        unsigned __int64    spellRegion;
        unsigned __int64    spellType;
        unsigned __int64    referStat1;
        unsigned __int64    referStat2;
        unsigned __int64    referTarget1;
        unsigned __int64    referTarget2;
        unsigned __int64    referValue1;
        unsigned __int64    referValue2;
        unsigned __int64    skillType;
        float               itemResistElecricity;
        float               itemResistFire;
        float               itemResistWind;
        float               itemResistWater;
        float               itemResistEarth;
        __int64             evildoing;
        unsigned __int64    expertLV;
        unsigned __int64    expertMax;
        unsigned __int64    subDefine;
        unsigned __int64    exp;
        unsigned __int64    comboStyle;
        float               flightSpeed;
        float               flightLRAngle;
        float                FlightTBAngle;
        unsigned __int64    flightLimit;
        unsigned __int64    fFuelReMax;
        unsigned __int64    aFuelReMax;
        unsigned __int64    fuelRe;
        unsigned __int64    limitLevel1;
        unsigned __int64    reflect;
        unsigned __int64    sndAttack1;
        unsigned __int64    sndAttack2;
        std::string         icon;
        unsigned __int64    questID;
        std::string         textFile;
        std::string         comment;

        PropSkill() :
            version(0),
            id(0),
            name(0),
            num(0),
            packMax(0),
            itemKind1(0),
            itemKind2(0),
            itemKind3(0),
            itemJob(0),
            permanence(false),
            useable(0),
            itemSex(0),
            cost(0),
            endurance(0),
            abrasion(0),
            hardness(0),
            handed(0),
            heelH(0),
            parts(0),
            partsub(0),
            partFile(false),
            exclusive(0),
            basePartsIgnore(0),
            itemLV(0),
            itemRare(0),
            shopAble(0),
            log(false),
            charged(false),
            linkKindBullet(0),
            linkKind(0),
            abilityMin(0),
            abilityMax(0),
            itemType(PROP_ITEM_ELEMENT::NO_PROP),
            itemEAtk(0),
            parry(0),
            blockRating(0),
            addSkillMin(0),
            addSkillMax(0),
            atkStyle(0),
            weaponType(0),
            itemAtkOrder1(0),
            itemAtkOrder2(0),
            itemAtkOrder3(0),
            itemAtkOrder4(0),
            continuousPain(0),
            shellQuantity(0),
            recoil(0),
            loadingTime(0),
            adjHitRate(0),
            attackSpeed(0),
            dmgShift(0),
            attackRange(0),
            probability(0),
            destParam1(0),
            destParam2(0),
            destParam3(0),
            adjParamVal1(0),
            adjParamVal2(0),
            adjParamVal3(0),
            chgParamVal1(0),
            chgParamVal2(0),
            chgParamVal3(0),
            destData1(0),
            destData2(0),
            destData3(0),
            activeskill(0),
            activeskillLv(0),
            activeskillper(0),
            reqMp(0),
            repFp(0),
            reqDisLV(0),
            reSkill1(0),
            reSkillLevel1(0),
            reSkill2(0),
            reSkillLevel2(0),
            skillReadyType(0),
            skillReady(0),
            skillRange(0),
            sfxElemental(0),
            sfxObj(0),
            sfxObj2(0),
            sfxObj3(0),
            sfxObj4(0),
            sfxObj5(0),
            useMotion(0),
            circleTime(0),
            skillTime(0),
            exeTarget(0),
            useChance(0),
            spellRegion(0),
            spellType(0),
            referStat1(0),
            referStat2(0),
            referTarget1(0),
            referTarget2(0),
            referValue1(0),
            referValue2(0),
            skillType(0),
            itemResistElecricity(0),
            itemResistFire(0),
            itemResistWind(0),
            itemResistWater(0),
            itemResistEarth(0),
            evildoing(0),
            expertLV(0),
            expertMax(0),
            subDefine(0),
            exp(0),
            comboStyle(0),
            flightSpeed(0),
            flightLRAngle(0),
            FlightTBAngle(0),
            flightLimit(0),
            fFuelReMax(0),
            aFuelReMax(0),
            fuelRe(0),
            limitLevel1(0),
            reflect(0),
            sndAttack1(0),
            sndAttack2(0),
            icon(""),
            questID(0),
            textFile(""),
            comment("")
        {}

        ~PropSkill()
        {}

        bool    load(const std::string& fileName) override
        {
            return true;
        }

    };
}