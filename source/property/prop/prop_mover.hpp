#pragma once

#include <string>
#include "framework.h"
#include "property.hpp"


namespace fe
{
	struct API_DECLSPEC PropMover : PropertyContainer
	{
		unsigned __int64        id;
		std::string             name;
		unsigned __int64        ai;
		unsigned __int64        str;
		unsigned __int64        sta;
		unsigned __int64        dex;
		unsigned __int64        intelligent;
		unsigned __int64        hr;
		unsigned __int64        er;
		unsigned __int64        race;
		unsigned __int64        belligerence;
		unsigned __int64        gender;
		unsigned __int64        level;
		unsigned __int64        filghtLevel;
		unsigned __int64        size;
		unsigned __int64        classe;
		bool                    part;
		unsigned __int64        karma;
		unsigned __int64        useable;
		unsigned __int64        actionRadius;
		unsigned __int64        atkMin;
		unsigned __int64        atkMax;
		unsigned __int64        atk1;
		unsigned __int64        atk2;
		unsigned __int64        atk3;
		unsigned __int64        horizontalRate;
		unsigned __int64        verticalRate;
		unsigned __int64        diagonalRate;
		unsigned __int64        thrustRate;
		unsigned __int64        chestRate;
		unsigned __int64        headRate;
		unsigned __int64        armRate;
		unsigned __int64        legRate;
		unsigned __int64        attackSpeed;
		unsigned __int64        reAttackDelay;
		unsigned __int64        addHp;
		unsigned __int64        addMp;
		unsigned __int64        naturealArmor;
		__int64                 abrasion;
		__int64                 hardness;
		unsigned __int64        adjAtkDelay;
		PROP_ITEM_ELEMENT       elementType;
		unsigned __int64        elementAtk;
		unsigned __int64        hideLevel;
		float                   speed;
		unsigned __int64        shelter;
		bool                    flying;
		unsigned __int64        jumpIng;
		unsigned __int64        airJump;
		bool                    taming;
		unsigned __int64        resisMagic;
		float                   resistElecricity;
		float                   resistFire;
		float                   resistWind;
		float                   resistWater;
		float                   resistEarth;
		unsigned __int64        cash;
		unsigned __int64        sourceMaterial;
		unsigned __int64        materialAmount;
		unsigned __int64        cohesion;
		unsigned __int64        holdingTime;
		unsigned __int64        correctionValue;
		unsigned __int64        expValue;
		__int64                 fxpValue;
		__int64                 bodyState;
		unsigned __int64        addAbility;
		bool                    killable;
		unsigned __int64        virtItem1;
		unsigned __int64        virtType1;
		unsigned __int64        virtItem2;
		unsigned __int64        virtType2;
		unsigned __int64        virtItem3;
		unsigned __int64        virtType3;
		unsigned __int64        sndAtk1;
		unsigned __int64        sndAtk2;
		unsigned __int64        sndDie1;
		unsigned __int64        sndDie2;
		unsigned __int64        sndDmg1;
		unsigned __int64        sndDmg2;
		unsigned __int64        sndDmg3;
		unsigned __int64        sndIdle1;
		unsigned __int64        sndIdle2;
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
		{}

		~PropMover() {}

		bool    load(const std::string& fileName) override
		{
			return true;
		}


	};
}