#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

#pragma warning( disable : 4251 )

namespace fe
{
    struct API_DECLSPEC PropSkill : PropertyContainer
    {
        fe::type::_uint     version;
        fe::type::_uint     id;
        std::string         name;
        fe::type::_uint    num;
        fe::type::_uint    packMax;
        fe::type::_uint    itemKind1;
        fe::type::_uint    itemKind2;
        fe::type::_uint    itemKind3;
        fe::type::_uint    itemJob;
        bool                permanence;
        fe::type::_uint    useable;
        fe::type::_uint    itemSex;
        fe::type::_uint    cost;
        fe::type::_uint    endurance;
        fe::type::_int             abrasion;
        fe::type::_int             hardness;
        fe::type::_uint    handed;
        fe::type::_uint    heelH;
        fe::type::_uint    parts;
        fe::type::_uint    partsub;
        bool                partFile;
        fe::type::_uint    exclusive;
        fe::type::_uint    basePartsIgnore;
        fe::type::_uint    itemLV;
        fe::type::_uint    itemRare;
        fe::type::_uint    shopAble;
        bool                log;
        bool                charged;
        fe::type::_uint    linkKindBullet;
        fe::type::_uint    linkKind;
        fe::type::_uint    abilityMin;
        fe::type::_uint    abilityMax;
        PROP_ITEM_ELEMENT   itemType;
        short               itemEAtk;
        fe::type::_uint    parry;
        fe::type::_uint    blockRating;
        fe::type::_uint    addSkillMin;
        fe::type::_uint    addSkillMax;
        fe::type::_uint    atkStyle;
        fe::type::_uint    weaponType;
        fe::type::_uint    itemAtkOrder1;
        fe::type::_uint    itemAtkOrder2;
        fe::type::_uint    itemAtkOrder3;
        fe::type::_uint    itemAtkOrder4;
        fe::type::_uint    continuousPain;
        fe::type::_uint    shellQuantity;
        fe::type::_uint    recoil;
        fe::type::_uint    loadingTime;
        fe::type::_int             adjHitRate;
        fe::type::_uint    attackSpeed;
        fe::type::_uint    dmgShift;
        fe::type::_uint    attackRange;
        fe::type::_uint    probability;
        fe::type::_uint    destParam1;
        fe::type::_uint    destParam2;
        fe::type::_uint    destParam3;
        fe::type::_int             adjParamVal1;
        fe::type::_int             adjParamVal2;
        fe::type::_int             adjParamVal3;
        fe::type::_uint    chgParamVal1;
        fe::type::_uint    chgParamVal2;
        fe::type::_uint    chgParamVal3;
        fe::type::_uint    destData1;
        fe::type::_uint    destData2;
        fe::type::_uint    destData3;
        fe::type::_uint    activeskill;
        fe::type::_uint    activeskillLv;
        fe::type::_uint    activeskillper;
        fe::type::_uint    reqMp;
        fe::type::_uint    repFp;
        fe::type::_uint    reqDisLV;
        fe::type::_uint    reSkill1;
        fe::type::_uint    reSkillLevel1;
        fe::type::_uint    reSkill2;
        fe::type::_uint    reSkillLevel2;
        fe::type::_uint    skillReadyType;
        fe::type::_uint    skillReady;
        fe::type::_uint    skillRange;
        fe::type::_uint    sfxElemental;
        fe::type::_uint    sfxObj;
        fe::type::_uint    sfxObj2;
        fe::type::_uint    sfxObj3;
        fe::type::_uint    sfxObj4;
        fe::type::_uint    sfxObj5;
        fe::type::_uint    useMotion;
        fe::type::_uint    circleTime;
        fe::type::_uint    skillTime;
        fe::type::_uint    exeTarget;
        fe::type::_uint    useChance;
        fe::type::_uint    spellRegion;
        fe::type::_uint    spellType;
        fe::type::_uint    referStat1;
        fe::type::_uint    referStat2;
        fe::type::_uint    referTarget1;
        fe::type::_uint    referTarget2;
        fe::type::_uint    referValue1;
        fe::type::_uint    referValue2;
        fe::type::_uint    skillType;
        float               itemResistElecricity;
        float               itemResistFire;
        float               itemResistWind;
        float               itemResistWater;
        float               itemResistEarth;
        fe::type::_int             evildoing;
        fe::type::_uint    expertLV;
        fe::type::_uint    expertMax;
        fe::type::_uint    subDefine;
        fe::type::_uint    exp;
        fe::type::_uint    comboStyle;
        float               flightSpeed;
        float               flightLRAngle;
        float                FlightTBAngle;
        fe::type::_uint    flightLimit;
        fe::type::_uint    fFuelReMax;
        fe::type::_uint    aFuelReMax;
        fe::type::_uint    fuelRe;
        fe::type::_uint    limitLevel1;
        fe::type::_uint    reflect;
        fe::type::_uint    sndAttack1;
        fe::type::_uint    sndAttack2;
        std::string         icon;
        fe::type::_uint    questID;
        std::string         textFile;
        std::string         comment;

        PropSkill() :
            version(0),
            id(0),
            name(""),
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

        PropSkill(PropSkill* o) :
            version(o->version),
            id(o->id),
            name(o->name),
            num(o->num),
            packMax(o->packMax),
            itemKind1(o->itemKind1),
            itemKind2(o->itemKind2),
            itemKind3(o->itemKind3),
            itemJob(o->itemJob),
            permanence(o->permanence),
            useable(o->useable),
            itemSex(o->itemSex),
            cost(o->cost),
            endurance(o->endurance),
            abrasion(o->abrasion),
            hardness(o->hardness),
            handed(o->handed),
            heelH(o->heelH),
            parts(o->parts),
            partsub(o->partsub),
            partFile(o->partFile),
            exclusive(o->exclusive),
            basePartsIgnore(o->basePartsIgnore),
            itemLV(o->itemLV),
            itemRare(o->itemRare),
            shopAble(o->shopAble),
            log(o->log),
            charged(o->charged),
            linkKindBullet(o->linkKindBullet),
            linkKind(o->linkKind),
            abilityMin(o->abilityMin),
            abilityMax(o->abilityMax),
            itemType(o->itemType),
            itemEAtk(o->itemEAtk),
            parry(o->parry),
            blockRating(o->blockRating),
            addSkillMin(o->addSkillMin),
            addSkillMax(o->addSkillMax),
            atkStyle(o->atkStyle),
            weaponType(o->weaponType),
            itemAtkOrder1(o->itemAtkOrder1),
            itemAtkOrder2(o->itemAtkOrder2),
            itemAtkOrder3(o->itemAtkOrder3),
            itemAtkOrder4(o->itemAtkOrder4),
            continuousPain(o->continuousPain),
            shellQuantity(o->shellQuantity),
            recoil(o->recoil),
            loadingTime(o->loadingTime),
            adjHitRate(o->adjHitRate),
            attackSpeed(o->attackSpeed),
            dmgShift(o->dmgShift),
            attackRange(o->attackRange),
            probability(o->probability),
            destParam1(o->destParam1),
            destParam2(o->destParam2),
            destParam3(o->destParam3),
            adjParamVal1(o->adjParamVal1),
            adjParamVal2(o->adjParamVal2),
            adjParamVal3(o->adjParamVal3),
            chgParamVal1(o->chgParamVal1),
            chgParamVal2(o->chgParamVal2),
            chgParamVal3(o->chgParamVal3),
            destData1(o->destData1),
            destData2(o->destData2),
            destData3(o->destData3),
            activeskill(o->activeskill),
            activeskillLv(o->activeskillLv),
            activeskillper(o->activeskillper),
            reqMp(o->reqMp),
            repFp(o->repFp),
            reqDisLV(o->reqDisLV),
            reSkill1(o->reSkill1),
            reSkillLevel1(o->reSkillLevel1),
            reSkill2(o->reSkill2),
            reSkillLevel2(o->reSkillLevel2),
            skillReadyType(o->skillReadyType),
            skillReady(o->skillReady),
            skillRange(o->skillRange),
            sfxElemental(o->sfxElemental),
            sfxObj(o->sfxObj),
            sfxObj2(o->sfxObj2),
            sfxObj3(o->sfxObj3),
            sfxObj4(o->sfxObj4),
            sfxObj5(o->sfxObj5),
            useMotion(o->useMotion),
            circleTime(o->circleTime),
            skillTime(o->skillTime),
            exeTarget(o->exeTarget),
            useChance(o->useChance),
            spellRegion(o->spellRegion),
            spellType(o->spellType),
            referStat1(o->referStat1),
            referStat2(o->referStat2),
            referTarget1(o->referTarget1),
            referTarget2(o->referTarget2),
            referValue1(o->referValue1),
            referValue2(o->referValue2),
            skillType(o->skillType),
            itemResistElecricity(o->itemResistElecricity),
            itemResistFire(o->itemResistFire),
            itemResistWind(o->itemResistWind),
            itemResistWater(o->itemResistWater),
            itemResistEarth(o->itemResistEarth),
            evildoing(o->evildoing),
            expertLV(o->expertLV),
            expertMax(o->expertMax),
            subDefine(o->subDefine),
            exp(o->exp),
            comboStyle(o->comboStyle),
            flightSpeed(o->flightSpeed),
            flightLRAngle(o->flightLRAngle),
            FlightTBAngle(o->FlightTBAngle),
            flightLimit(o->flightLimit),
            fFuelReMax(o->fFuelReMax),
            aFuelReMax(o->aFuelReMax),
            fuelRe(o->fuelRe),
            limitLevel1(o->limitLevel1),
            reflect(o->reflect),
            sndAttack1(o->sndAttack1),
            sndAttack2(o->sndAttack2),
            icon(o->icon),
            questID(o->questID),
            textFile(o->textFile),
            comment(o->comment)
        {
        }

        PropSkill(PropSkill& o) :
            version(o.version),
            id(o.id),
            name(o.name),
            num(o.num),
            packMax(o.packMax),
            itemKind1(o.itemKind1),
            itemKind2(o.itemKind2),
            itemKind3(o.itemKind3),
            itemJob(o.itemJob),
            permanence(o.permanence),
            useable(o.useable),
            itemSex(o.itemSex),
            cost(o.cost),
            endurance(o.endurance),
            abrasion(o.abrasion),
            hardness(o.hardness),
            handed(o.handed),
            heelH(o.heelH),
            parts(o.parts),
            partsub(o.partsub),
            partFile(o.partFile),
            exclusive(o.exclusive),
            basePartsIgnore(o.basePartsIgnore),
            itemLV(o.itemLV),
            itemRare(o.itemRare),
            shopAble(o.shopAble),
            log(o.log),
            charged(o.charged),
            linkKindBullet(o.linkKindBullet),
            linkKind(o.linkKind),
            abilityMin(o.abilityMin),
            abilityMax(o.abilityMax),
            itemType(o.itemType),
            itemEAtk(o.itemEAtk),
            parry(o.parry),
            blockRating(o.blockRating),
            addSkillMin(o.addSkillMin),
            addSkillMax(o.addSkillMax),
            atkStyle(o.atkStyle),
            weaponType(o.weaponType),
            itemAtkOrder1(o.itemAtkOrder1),
            itemAtkOrder2(o.itemAtkOrder2),
            itemAtkOrder3(o.itemAtkOrder3),
            itemAtkOrder4(o.itemAtkOrder4),
            continuousPain(o.continuousPain),
            shellQuantity(o.shellQuantity),
            recoil(o.recoil),
            loadingTime(o.loadingTime),
            adjHitRate(o.adjHitRate),
            attackSpeed(o.attackSpeed),
            dmgShift(o.dmgShift),
            attackRange(o.attackRange),
            probability(o.probability),
            destParam1(o.destParam1),
            destParam2(o.destParam2),
            destParam3(o.destParam3),
            adjParamVal1(o.adjParamVal1),
            adjParamVal2(o.adjParamVal2),
            adjParamVal3(o.adjParamVal3),
            chgParamVal1(o.chgParamVal1),
            chgParamVal2(o.chgParamVal2),
            chgParamVal3(o.chgParamVal3),
            destData1(o.destData1),
            destData2(o.destData2),
            destData3(o.destData3),
            activeskill(o.activeskill),
            activeskillLv(o.activeskillLv),
            activeskillper(o.activeskillper),
            reqMp(o.reqMp),
            repFp(o.repFp),
            reqDisLV(o.reqDisLV),
            reSkill1(o.reSkill1),
            reSkillLevel1(o.reSkillLevel1),
            reSkill2(o.reSkill2),
            reSkillLevel2(o.reSkillLevel2),
            skillReadyType(o.skillReadyType),
            skillReady(o.skillReady),
            skillRange(o.skillRange),
            sfxElemental(o.sfxElemental),
            sfxObj(o.sfxObj),
            sfxObj2(o.sfxObj2),
            sfxObj3(o.sfxObj3),
            sfxObj4(o.sfxObj4),
            sfxObj5(o.sfxObj5),
            useMotion(o.useMotion),
            circleTime(o.circleTime),
            skillTime(o.skillTime),
            exeTarget(o.exeTarget),
            useChance(o.useChance),
            spellRegion(o.spellRegion),
            spellType(o.spellType),
            referStat1(o.referStat1),
            referStat2(o.referStat2),
            referTarget1(o.referTarget1),
            referTarget2(o.referTarget2),
            referValue1(o.referValue1),
            referValue2(o.referValue2),
            skillType(o.skillType),
            itemResistElecricity(o.itemResistElecricity),
            itemResistFire(o.itemResistFire),
            itemResistWind(o.itemResistWind),
            itemResistWater(o.itemResistWater),
            itemResistEarth(o.itemResistEarth),
            evildoing(o.evildoing),
            expertLV(o.expertLV),
            expertMax(o.expertMax),
            subDefine(o.subDefine),
            exp(o.exp),
            comboStyle(o.comboStyle),
            flightSpeed(o.flightSpeed),
            flightLRAngle(o.flightLRAngle),
            FlightTBAngle(o.FlightTBAngle),
            flightLimit(o.flightLimit),
            fFuelReMax(o.fFuelReMax),
            aFuelReMax(o.aFuelReMax),
            fuelRe(o.fuelRe),
            limitLevel1(o.limitLevel1),
            reflect(o.reflect),
            sndAttack1(o.sndAttack1),
            sndAttack2(o.sndAttack2),
            icon(o.icon),
            questID(o.questID),
            textFile(o.textFile),
            comment(o.comment)
        {
        }

        ~PropSkill()
        {
        }

    };
}
#pragma warning( default : 4251 )
