#include "pch.h"
#include "project_manager.hpp"
#include "reader_json.hpp"


bool    fe::ProjectManager::loadPropItem(const std::string& fileName, LOADER_MODE mode) noexcept
{
    try
    {
        if (fileName.empty())
            return false;

        switch (mode)
        {
            case fe::LOADER_MODE::JSON:
                loadPropItemJson(fileName);
                break;
            case fe::LOADER_MODE::XML:
                break;
            default:
                return false;
        }
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}

const fe::ReaderHeader& fe::ProjectManager::getHeader() const
{
    return std::ref(header);
}

bool fe::ProjectManager::loadPropItemJson(const std::string& fileName) noexcept
{
    ReaderJson  reader;
    reader.header = &header;

    if (reader.load(fileName) == false)
        return false;
    fe::json_object& datas = reader.get<json_object>(reader.root);
    for (auto& it : datas)
    {
        fe::json_object& item = reader.get<fe::json_object>(it.second);
        fe::PropItem* prop = new fe::PropItem();

        prop->version = reader.getNumber<type::_uint, fe::json_value>(item["version"]);
        prop->id = reader.getNumber<type::_uint, fe::json_value>(item["dwID"]);
        prop->name = reader.get<std::string>(item["szName"]);
        prop->num = reader.getNumber<type::_uint, fe::json_value>(item["dwNum"]);
        prop->packMax = reader.getNumber<type::_uint, fe::json_value>(item["dwPackMax"]);
        prop->itemKind1 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemKind1"]);
        prop->itemKind2 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemKind2"]);
        prop->itemKind3 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemKind3"]);
        prop->itemJob = reader.getNumber<type::_uint, fe::json_value>(item["dwItemJob"]);
        prop->permanence = reader.getBoolean(item["bPermanence"]);
        prop->useable = reader.getNumber<type::_uint, fe::json_value>(item["dwUseable"]);
        prop->itemSex = reader.getNumber<type::_uint, fe::json_value>(item["dwItemSex"]);
        prop->cost = reader.getNumber<type::_uint, fe::json_value>(item["dwCost"]);
        prop->endurance = reader.getNumber<type::_uint, fe::json_value>(item["dwEndurance"]);
        prop->abrasion = reader.getNumber<type::_int, fe::json_value>(item["nAbrasion"]);
        prop->maxRepair = reader.getNumber<type::_int, fe::json_value>(item["nMaxRepair"]);
        prop->handed = reader.getNumber<type::_uint, fe::json_value>(item["dwHanded"]);
        prop->flag = reader.getNumber<type::_uint, fe::json_value>(item["dwFlag"]);
        prop->parts = reader.getNumber<type::_uint, fe::json_value>(item["dwParts"]);
        prop->partsub = reader.getNumber<type::_uint, fe::json_value>(item["dwPartsub"]);
        prop->partFile = reader.getBoolean(item["bPartFile"]);
        prop->exclusive = reader.getNumber<type::_uint, fe::json_value>(item["dwExclusive"]);
        prop->basePartsIgnore = reader.getNumber<type::_uint, fe::json_value>(item["dwBasePartsIgnore"]);
        prop->itemLV = reader.getNumber<type::_uint, fe::json_value>(item["dwItemLV"]);
        prop->itemRare = reader.getNumber<type::_uint, fe::json_value>(item["dwItemRare"]);
        prop->shopAble = reader.getNumber<type::_uint, fe::json_value>(item["dwShopAble"]);
        prop->log = reader.getBoolean(item["bLog"]);
        prop->charged = reader.getBoolean(item["bCharged"]);
        prop->linkKindBullet = reader.getNumber<type::_uint, fe::json_value>(item["dwLinkKindBullet"]);
        prop->linkKind = reader.getNumber<type::_uint, fe::json_value>(item["dwLinkKind"]);
        prop->abilityMin = reader.getNumber<type::_uint, fe::json_value>(item["dwAbilityMin"]);
        prop->abilityMax = reader.getNumber<type::_uint, fe::json_value>(item["dwAbilityMax"]);
        prop->itemType = static_cast<fe::PROP_ITEM_ELEMENT>(reader.getNumber<type::_uint, fe::json_value>(item["eItemType"]));
        prop->itemEAtk = reader.getNumber<short, fe::json_value>(item["wItemEAtk"]);
        prop->parry = reader.getNumber<type::_uint, fe::json_value>(item["dwParry"]);
        prop->blockRating = reader.getNumber<type::_uint, fe::json_value>(item["dwBlockRating"]);
        prop->addSkillMin = reader.getNumber<type::_uint, fe::json_value>(item["dwAddSkillMin"]);
        prop->addSkillMax = reader.getNumber<type::_uint, fe::json_value>(item["dwAddSkillMax"]);
        prop->atkStyle = reader.getNumber<type::_uint, fe::json_value>(item["dwAtkStyle"]);
        prop->weaponType = reader.getNumber<type::_uint, fe::json_value>(item["dwWeaponType"]);
        prop->itemAtkOrder1 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemAtkOrder1"]);
        prop->itemAtkOrder2 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemAtkOrder2"]);
        prop->itemAtkOrder3 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemAtkOrder3"]);
        prop->itemAtkOrder4 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemAtkOrder4"]);
        prop->continuousPain = reader.getBoolean(item["bContinuousPain"]);
        prop->shellQuantity = reader.getNumber<type::_uint, fe::json_value>(item["dwShellQuantity"]);
        prop->recoil = reader.getNumber<type::_uint, fe::json_value>(item["dwRecoil"]);
        prop->loadingTime = reader.getNumber<type::_uint, fe::json_value>(item["dwLoadingTime"]);
        prop->adjHitRate = reader.getNumber<type::_int, fe::json_value>(item["nAdjHitRate"]);
        prop->attackSpeed = reader.getNumber<type::_uint, fe::json_value>(item["dwAttackSpeed"]);
        prop->dmgShift = reader.getNumber<type::_uint, fe::json_value>(item["dwDmgShift"]);
        prop->attackRange = reader.getNumber<type::_uint, fe::json_value>(item["dwAttackRange"]);
        prop->probability = reader.getNumber<type::_uint, fe::json_value>(item["dwProbability"]);
        prop->destParam1 = reader.getNumber<type::_uint, fe::json_value>(item["dwDestParam1"]);
        prop->destParam2 = reader.getNumber<type::_uint, fe::json_value>(item["dwDestParam2"]);
        prop->destParam3 = reader.getNumber<type::_uint, fe::json_value>(item["dwDestParam3"]);
        prop->adjParamVal1 = reader.getNumber<type::_int, fe::json_value>(item["nAdjParamVal1"]);
        prop->adjParamVal2 = reader.getNumber<type::_int, fe::json_value>(item["nAdjParamVal2"]);
        prop->adjParamVal3 = reader.getNumber<type::_int, fe::json_value>(item["nAdjParamVal3"]);
        prop->chgParamVal1 = reader.getNumber<type::_uint, fe::json_value>(item["dwChgParamVal1"]);
        prop->chgParamVal2 = reader.getNumber<type::_uint, fe::json_value>(item["dwChgParamVal2"]);
        prop->chgParamVal3 = reader.getNumber<type::_uint, fe::json_value>(item["dwChgParamVal3"]);
        prop->destData1 = reader.getNumber<type::_uint, fe::json_value>(item["dwdestData1"]);
        prop->destData2 = reader.getNumber<type::_uint, fe::json_value>(item["dwdestData2"]);
        prop->destData3 = reader.getNumber<type::_uint, fe::json_value>(item["dwdestData3"]);
        prop->activeskill = reader.getNumber<type::_uint, fe::json_value>(item["dwactiveskill"]);
        prop->activeskillLv = reader.getNumber<type::_uint, fe::json_value>(item["dwactiveskillLv"]);
        prop->activeskillper = reader.getNumber<type::_uint, fe::json_value>(item["dwactiveskillper"]);
        prop->reqMp = reader.getNumber<type::_uint, fe::json_value>(item["dwReqMp"]);
        prop->repFp = reader.getNumber<type::_uint, fe::json_value>(item["dwRepFp"]);
        prop->reqDisLV = reader.getNumber<type::_uint, fe::json_value>(item["dwReqDisLV"]);
        prop->reSkill1 = reader.getNumber<type::_uint, fe::json_value>(item["dwReSkill1"]);
        prop->reSkillLevel1 = reader.getNumber<type::_uint, fe::json_value>(item["dwReSkillLevel1"]);
        prop->reSkill2 = reader.getNumber<type::_uint, fe::json_value>(item["dwReSkill2"]);
        prop->reSkillLevel2 = reader.getNumber<type::_uint, fe::json_value>(item["dwReSkillLevel2"]);
        prop->skillReadyType = reader.getNumber<type::_uint, fe::json_value>(item["dwSkillReadyType"]);
        prop->skillReady = reader.getNumber<type::_uint, fe::json_value>(item["dwSkillReady"]);
        prop->skillRange = reader.getNumber<type::_uint, fe::json_value>(item["dwSkillRange"]);
        prop->sfxElemental = reader.getNumber<type::_uint, fe::json_value>(item["dwSfxElemental"]);
        prop->sfxObj = reader.getNumber<type::_uint, fe::json_value>(item["dwSfxObj"]);
        prop->sfxObj2 = reader.getNumber<type::_uint, fe::json_value>(item["dwSfxObj2"]);
        prop->sfxObj3 = reader.getNumber<type::_uint, fe::json_value>(item["dwSfxObj3"]);
        prop->sfxObj4 = reader.getNumber<type::_uint, fe::json_value>(item["dwSfxObj4"]);
        prop->sfxObj5 = reader.getNumber<type::_uint, fe::json_value>(item["dwSfxObj5"]);
        prop->useMotion = reader.getNumber<type::_uint, fe::json_value>(item["dwUseMotion"]);
        prop->circleTime = reader.getNumber<type::_uint, fe::json_value>(item["dwCircleTime"]);
        prop->skillTime = reader.getNumber<type::_uint, fe::json_value>(item["dwSkillTime"]);
        prop->exeTarget = reader.getNumber<type::_uint, fe::json_value>(item["dwExeTarget"]);
        prop->useChance = reader.getNumber<type::_uint, fe::json_value>(item["dwUseChance"]);
        prop->spellRegion = reader.getNumber<type::_uint, fe::json_value>(item["dwSpellRegion"]);
        prop->spellType = reader.getNumber<type::_uint, fe::json_value>(item["dwSpellType"]);
        prop->referStat1 = reader.getNumber<type::_uint, fe::json_value>(item["dwReferStat1"]);
        prop->referStat2 = reader.getNumber<type::_uint, fe::json_value>(item["dwReferStat2"]);
        prop->referTarget1 = reader.getNumber<type::_uint, fe::json_value>(item["dwReferTarget1"]);
        prop->referTarget2 = reader.getNumber<type::_uint, fe::json_value>(item["dwReferTarget2"]);
        prop->referValue1 = reader.getNumber<type::_uint, fe::json_value>(item["dwReferValue1"]);
        prop->referValue2 = reader.getNumber<type::_uint, fe::json_value>(item["dwReferValue2"]);
        prop->skillType = reader.getNumber<type::_uint, fe::json_value>(item["dwSkillType"]);
        prop->itemResistElecricity = reader.getNumber<float, fe::json_value>(item["fItemResistElecricity"]);
        prop->itemResistFire = reader.getNumber<float, fe::json_value>(item["fItemResistFire"]);
        prop->itemResistWind = reader.getNumber<float, fe::json_value>(item["fItemResistWind"]);
        prop->itemResistWater = reader.getNumber<float, fe::json_value>(item["fItemResistWater"]);
        prop->itemResistEarth = reader.getNumber<float, fe::json_value>(item["fItemResistEarth"]);
        prop->evildoing = reader.getNumber<type::_int, fe::json_value>(item["nEvildoing"]);
        prop->expertLV = reader.getNumber<type::_uint, fe::json_value>(item["dwExpertLV"]);
        prop->expertMax = reader.getNumber<type::_uint, fe::json_value>(item["ExpertMax"]);
        prop->subDefine = reader.getNumber<type::_uint, fe::json_value>(item["dwSubDefine"]);
        prop->exp = reader.getNumber<type::_uint, fe::json_value>(item["dwExp"]);
        prop->comboStyle = reader.getNumber<type::_uint, fe::json_value>(item["dwComboStyle"]);
        prop->flightSpeed = reader.getNumber<float, fe::json_value>(item["fFlightSpeed"]);
        prop->flightLRAngle = reader.getNumber<float, fe::json_value>(item["fFlightLRAngle"]);
        prop->flightTBAngle = reader.getNumber<float, fe::json_value>(item["fFlightTBAngle"]);
        prop->flightLimit = reader.getNumber<type::_uint, fe::json_value>(item["dwFlightLimit"]);
        prop->fFuelReMax = reader.getNumber<type::_uint, fe::json_value>(item["dwFFuelReMax"]);
        prop->aFuelReMax = reader.getNumber<type::_uint, fe::json_value>(item["dwAFuelReMax"]);
        prop->fuelRe = reader.getNumber<type::_uint, fe::json_value>(item["dwFuelRe"]);
        prop->limitLevel1 = reader.getNumber<type::_uint, fe::json_value>(item["dwLimitLevel1"]);
        prop->reflect = reader.getNumber<type::_uint, fe::json_value>(item["dwReflect"]);
        prop->sndAttack1 = reader.getNumber<type::_uint, fe::json_value>(item["dwSndAttack1"]);
        prop->sndAttack2 = reader.getNumber<type::_uint, fe::json_value>(item["dwSndAttack2"]);
        prop->icon = reader.get<std::string>(item["szIcon"]);
        prop->questID = reader.getNumber<type::_uint, fe::json_value>(item["dwQuestID"]);
        prop->textFile = reader.get<std::string>(item["szTextFile"]);
        prop->comment = reader.get<std::string>(item["szComment"]);

        propitem.push(prop->id, prop);
    }

    return true;
}
