#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"

#pragma warning( disable : 4251 )

namespace fe
{
    struct API_DECLSPEC PropMover : PropertyContainer
    {
        fe::type::_uint        id;
        std::string             name;
        fe::type::_uint        ai;
        fe::type::_uint        str;
        fe::type::_uint        sta;
        fe::type::_uint        dex;
        fe::type::_uint        intelligent;
        fe::type::_uint        hr;
        fe::type::_uint        er;
        fe::type::_uint        race;
        fe::type::_uint        belligerence;
        fe::type::_uint        gender;
        fe::type::_uint        level;
        fe::type::_uint        filghtLevel;
        fe::type::_uint        size;
        fe::type::_uint        classe;
        bool                    part;
        fe::type::_uint        karma;
        fe::type::_uint        useable;
        fe::type::_uint        actionRadius;
        fe::type::_uint        atkMin;
        fe::type::_uint        atkMax;
        fe::type::_uint        atk1;
        fe::type::_uint        atk2;
        fe::type::_uint        atk3;
        fe::type::_uint        horizontalRate;
        fe::type::_uint        verticalRate;
        fe::type::_uint        diagonalRate;
        fe::type::_uint        thrustRate;
        fe::type::_uint        chestRate;
        fe::type::_uint        headRate;
        fe::type::_uint        armRate;
        fe::type::_uint        legRate;
        fe::type::_uint        attackSpeed;
        fe::type::_uint        reAttackDelay;
        fe::type::_uint        addHp;
        fe::type::_uint        addMp;
        fe::type::_uint        naturealArmor;
        fe::type::_int                 abrasion;
        fe::type::_int                 hardness;
        fe::type::_uint        adjAtkDelay;
        PROP_ITEM_ELEMENT       elementType;
        fe::type::_uint        elementAtk;
        fe::type::_uint        hideLevel;
        float                   speed;
        fe::type::_uint        shelter;
        bool                    flying;
        fe::type::_uint        jumpIng;
        fe::type::_uint        airJump;
        bool                    taming;
        fe::type::_uint        resisMagic;
        float                   resistElecricity;
        float                   resistFire;
        float                   resistWind;
        float                   resistWater;
        float                   resistEarth;
        fe::type::_uint        cash;
        fe::type::_uint        sourceMaterial;
        fe::type::_uint        materialAmount;
        fe::type::_uint        cohesion;
        fe::type::_uint        holdingTime;
        fe::type::_uint        correctionValue;
        fe::type::_uint        expValue;
        fe::type::_int                 fxpValue;
        fe::type::_int                 bodyState;
        fe::type::_uint        addAbility;
        bool                    killable;
        fe::type::_uint        virtItem1;
        fe::type::_uint        virtType1;
        fe::type::_uint        virtItem2;
        fe::type::_uint        virtType2;
        fe::type::_uint        virtItem3;
        fe::type::_uint        virtType3;
        fe::type::_uint        sndAtk1;
        fe::type::_uint        sndAtk2;
        fe::type::_uint        sndDie1;
        fe::type::_uint        sndDie2;
        fe::type::_uint        sndDmg1;
        fe::type::_uint        sndDmg2;
        fe::type::_uint        sndDmg3;
        fe::type::_uint        sndIdle1;
        fe::type::_uint        sndIdle2;
        std::string             comment;

        PropMover() :
            id(),
            name(),
            ai(),
            str(),
            sta(),
            dex(),
            intelligent(),
            hr(),
            er(),
            race(),
            belligerence(),
            gender(),
            level(),
            filghtLevel(),
            size(),
            classe(),
            part(false),
            karma(),
            useable(),
            actionRadius(),
            atkMin(),
            atkMax(),
            atk1(),
            atk2(),
            atk3(),
            horizontalRate(),
            verticalRate(),
            diagonalRate(),
            thrustRate(),
            chestRate(),
            headRate(),
            armRate(),
            legRate(),
            attackSpeed(),
            reAttackDelay(),
            addHp(),
            addMp(),
            naturealArmor(),
            abrasion(),
            hardness(),
            adjAtkDelay(),
            elementType(PROP_ITEM_ELEMENT::NO_PROP),
            elementAtk(),
            hideLevel(),
            speed(),
            shelter(),
            flying(false),
            jumpIng(),
            airJump(),
            taming(false),
            resisMagic(),
            resistElecricity(),
            resistFire(),
            resistWind(),
            resistWater(),
            resistEarth(),
            cash(),
            sourceMaterial(),
            materialAmount(),
            cohesion(),
            holdingTime(),
            correctionValue(),
            expValue(),
            fxpValue(),
            bodyState(),
            addAbility(),
            killable(false),
            virtItem1(),
            virtType1(),
            virtItem2(),
            virtType2(),
            virtItem3(),
            virtType3(),
            sndAtk1(),
            sndAtk2(),
            sndDie1(),
            sndDie2(),
            sndDmg1(),
            sndDmg2(),
            sndDmg3(),
            sndIdle1(),
            sndIdle2(),
            comment()
        {
        }

        PropMover(PropMover* o) :
            id(o->id),
            name(o->name),
            ai(o->ai),
            str(o->str),
            sta(o->sta),
            dex(o->dex),
            intelligent(o->intelligent),
            hr(o->hr),
            er(o->er),
            race(o->race),
            belligerence(o->belligerence),
            gender(o->gender),
            level(o->level),
            filghtLevel(o->filghtLevel),
            size(o->size),
            classe(o->classe),
            part(o->part),
            karma(o->karma),
            useable(o->useable),
            actionRadius(o->actionRadius),
            atkMin(o->atkMin),
            atkMax(o->atkMax),
            atk1(o->atk1),
            atk2(o->atk2),
            atk3(o->atk3),
            horizontalRate(o->horizontalRate),
            verticalRate(o->verticalRate),
            diagonalRate(o->diagonalRate),
            thrustRate(o->thrustRate),
            chestRate(o->chestRate),
            headRate(o->headRate),
            armRate(o->armRate),
            legRate(o->legRate),
            attackSpeed(o->attackSpeed),
            reAttackDelay(o->reAttackDelay),
            addHp(o->addHp),
            addMp(o->addMp),
            naturealArmor(o->naturealArmor),
            abrasion(o->abrasion),
            hardness(o->hardness),
            adjAtkDelay(o->adjAtkDelay),
            elementType(o->elementType),
            elementAtk(o->elementAtk),
            hideLevel(o->hideLevel),
            speed(o->speed),
            shelter(o->shelter),
            flying(falseo->flying),
            jumpIng(o->jumpIng),
            airJump(o->airJump),
            taming(falseo->taming),
            resisMagic(o->resisMagic),
            resistElecricity(o->resistElecricity),
            resistFire(o->resistFire),
            resistWind(o->resistWind),
            resistWater(o->resistWater),
            resistEarth(o->resistEarth),
            cash(o->cash),
            sourceMaterial(o->sourceMaterial),
            materialAmount(o->materialAmount),
            cohesion(o->cohesion),
            holdingTime(o->holdingTime),
            correctionValue(o->correctionValue),
            expValue(o->expValue),
            fxpValue(o->fxpValue),
            bodyState(o->bodyState),
            addAbility(o->addAbility),
            killable(falseo->killable),
            virtItem1(o->virtItem1),
            virtType1(o->virtType1),
            virtItem2(o->virtItem2),
            virtType2(o->virtType2),
            virtItem3(o->virtItem3),
            virtType3(o->virtType3),
            sndAtk1(o->sndAtk1),
            sndAtk2(o->sndAtk2),
            sndDie1(o->sndDie1),
            sndDie2(o->sndDie2),
            sndDmg1(o->sndDmg1),
            sndDmg2(o->sndDmg2),
            sndDmg3(o->sndDmg3),
            sndIdle1(o->sndIdle1),
            sndIdle2(o->sndIdle2),
            comment(o->comment)
        {
        }

        PropMover(PropMover& o) :
            id(o.id),
            name(o.name),
            ai(o.ai),
            str(o.str),
            sta(o.sta),
            dex(o.dex),
            intelligent(o.intelligent),
            hr(o.hr),
            er(o.er),
            race(o.race),
            belligerence(o.belligerence),
            gender(o.gender),
            level(o.level),
            filghtLevel(o.filghtLevel),
            size(o.size),
            classe(o.classe),
            part(o.part),
            karma(o.karma),
            useable(o.useable),
            actionRadius(o.actionRadius),
            atkMin(o.atkMin),
            atkMax(o.atkMax),
            atk1(o.atk1),
            atk2(o.atk2),
            atk3(o.atk3),
            horizontalRate(o.horizontalRate),
            verticalRate(o.verticalRate),
            diagonalRate(o.diagonalRate),
            thrustRate(o.thrustRate),
            chestRate(o.chestRate),
            headRate(o.headRate),
            armRate(o.armRate),
            legRate(o.legRate),
            attackSpeed(o.attackSpeed),
            reAttackDelay(o.reAttackDelay),
            addHp(o.addHp),
            addMp(o.addMp),
            naturealArmor(o.naturealArmor),
            abrasion(o.abrasion),
            hardness(o.hardness),
            adjAtkDelay(o.adjAtkDelay),
            elementType(o.elementType),
            elementAtk(o.elementAtk),
            hideLevel(o.hideLevel),
            speed(o.speed),
            shelter(o.shelter),
            flying(falseo.flying),
            jumpIng(o.jumpIng),
            airJump(o.airJump),
            taming(falseo.taming),
            resisMagic(o.resisMagic),
            resistElecricity(o.resistElecricity),
            resistFire(o.resistFire),
            resistWind(o.resistWind),
            resistWater(o.resistWater),
            resistEarth(o.resistEarth),
            cash(o.cash),
            sourceMaterial(o.sourceMaterial),
            materialAmount(o.materialAmount),
            cohesion(o.cohesion),
            holdingTime(o.holdingTime),
            correctionValue(o.correctionValue),
            expValue(o.expValue),
            fxpValue(o.fxpValue),
            bodyState(o.bodyState),
            addAbility(o.addAbility),
            killable(falseo.killable),
            virtItem1(o.virtItem1),
            virtType1(o.virtType1),
            virtItem2(o.virtItem2),
            virtType2(o.virtType2),
            virtItem3(o.virtItem3),
            virtType3(o.virtType3),
            sndAtk1(o.sndAtk1),
            sndAtk2(o.sndAtk2),
            sndDie1(o.sndDie1),
            sndDie2(o.sndDie2),
            sndDmg1(o.sndDmg1),
            sndDmg2(o.sndDmg2),
            sndDmg3(o.sndDmg3),
            sndIdle1(o.sndIdle1),
            sndIdle2(o.sndIdle2),
            comment(o.comment)
        {
        }

        ~PropMover()
        {
        }


    };
}
#pragma warning( default : 4251 )
