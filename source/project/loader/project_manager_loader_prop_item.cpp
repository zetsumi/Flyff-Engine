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

    if (reader.load(fileName) == false)
        return false;
    fe::json_object& datas = reader.get<json_object>(reader.root);
    for (auto& it : datas)
    {
        fe::json_object& item = reader.get<fe::json_object>(it.second);
        fe::PropItem propitem;

        propitem.version = reader.getNumber<type::_uint, fe::json_value>(item["version"]);
        propitem.id = reader.getNumber<type::_uint, fe::json_value>(item["dwID"]);
        propitem.name = reader.get<std::string>(item["szName"]);
        propitem.num = reader.getNumber<type::_uint, fe::json_value>(item["dwNum"]);
        propitem.packMax = reader.getNumber<type::_uint, fe::json_value>(item["dwPackMax"]);
        propitem.itemKind1 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemKind1"]);
        propitem.itemKind2 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemKind2"]);
        propitem.itemKind3 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemKind3"]);
        propitem.itemJob = reader.getNumber<type::_uint, fe::json_value>(item["dwItemJob"]);
        propitem.permanence = reader.getBoolean(item["bPermanence"]);
        propitem.useable = reader.getNumber<type::_uint, fe::json_value>(item["dwUseable"]);
        propitem.itemSex = reader.getNumber<type::_uint, fe::json_value>(item["dwItemSex"]);
        propitem.cost = reader.getNumber<type::_uint, fe::json_value>(item["dwCost"]);
        propitem.endurance = reader.getNumber<type::_uint, fe::json_value>(item["dwEndurance"]);
        propitem.abrasion = reader.getNumber<type::_int, fe::json_value>(item["nAbrasion"]);
        propitem.maxRepair = reader.getNumber<type::_int, fe::json_value>(item["nMaxRepair"]);
        propitem.handed = reader.getNumber<type::_uint, fe::json_value>(item["dwHanded"]);
        propitem.flag = reader.getNumber<type::_uint, fe::json_value>(item["dwFlag"]);
        propitem.parts = reader.getNumber<type::_uint, fe::json_value>(item["dwParts"]);
        propitem.partsub = reader.getNumber<type::_uint, fe::json_value>(item["dwPartsub"]);
        propitem.partFile = reader.getBoolean(item["bPartFile"]);
        propitem.exclusive = reader.getNumber<type::_uint, fe::json_value>(item["dwExclusive"]);
        propitem.basePartsIgnore = reader.getNumber<type::_uint, fe::json_value>(item["dwBasePartsIgnore"]);
        propitem.itemLV = reader.getNumber<type::_uint, fe::json_value>(item["dwItemLV"]);
        propitem.itemRare = reader.getNumber<type::_uint, fe::json_value>(item["dwItemRare"]);
        propitem.shopAble = reader.getNumber<type::_uint, fe::json_value>(item["dwShopAble"]);
        propitem.log = reader.getBoolean(item["bLog"]);
        propitem.charged = reader.getBoolean(item["bCharged"]);
        propitem.linkKindBullet = reader.getNumber<type::_uint, fe::json_value>(item["dwLinkKindBullet"]);
        propitem.linkKind = reader.getNumber<type::_uint, fe::json_value>(item["dwLinkKind"]);
        propitem.abilityMin = reader.getNumber<type::_uint, fe::json_value>(item["dwAbilityMin"]);
        propitem.abilityMax = reader.getNumber<type::_uint, fe::json_value>(item["dwAbilityMax"]);
        propitem.itemType = static_cast<fe::PROP_ITEM_ELEMENT>(reader.getNumber<type::_uint, fe::json_value>(item["eItemType"]));
        propitem.itemEAtk = reader.getNumber<short, fe::json_value>(item["wItemEAtk"]);
        propitem.parry = reader.getNumber<type::_uint, fe::json_value>(item["dwParry"]);
        propitem.blockRating = reader.getNumber<type::_uint, fe::json_value>(item["dwBlockRating"]);
        propitem.addSkillMin = reader.getNumber<type::_uint, fe::json_value>(item["dwAddSkillMin"]);
        propitem.addSkillMax = reader.getNumber<type::_uint, fe::json_value>(item["dwAddSkillMax"]);
        propitem.atkStyle = reader.getNumber<type::_uint, fe::json_value>(item["dwAtkStyle"]);
        propitem.weaponType = reader.getNumber<type::_uint, fe::json_value>(item["dwWeaponType"]);
        propitem.itemAtkOrder1 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemAtkOrder1"]);
        propitem.itemAtkOrder2 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemAtkOrder2"]);
        propitem.itemAtkOrder3 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemAtkOrder3"]);
        propitem.itemAtkOrder4 = reader.getNumber<type::_uint, fe::json_value>(item["dwItemAtkOrder4"]);
        propitem.continuousPain = reader.getBoolean(item["bContinuousPain"]);
        propitem.shellQuantity = reader.getNumber<type::_uint, fe::json_value>(item["dwShellQuantity"]);
        propitem.recoil = reader.getNumber<type::_uint, fe::json_value>(item["dwRecoil"]);
        propitem.loadingTime = reader.getNumber<type::_uint, fe::json_value>(item["dwLoadingTime"]);
        propitem.adjHitRate = reader.getNumber<type::_int, fe::json_value>(item["nAdjHitRate"]);
        propitem.attackSpeed = reader.getNumber<type::_uint, fe::json_value>(item["dwAttackSpeed"]);
        propitem.dmgShift = reader.getNumber<type::_uint, fe::json_value>(item["dwDmgShift"]);
        propitem.attackRange = reader.getNumber<type::_uint, fe::json_value>(item["dwAttackRange"]);
        propitem.probability = reader.getNumber<type::_uint, fe::json_value>(item["dwProbability"]);
        propitem.destParam1 = reader.getNumber<type::_uint, fe::json_value>(item["dwDestParam1"]);
        propitem.destParam2 = reader.getNumber<type::_uint, fe::json_value>(item["dwDestParam2"]);
        propitem.destParam3 = reader.getNumber<type::_uint, fe::json_value>(item["dwDestParam3"]);
        propitem.adjParamVal1 = reader.getNumber<type::_int, fe::json_value>(item["nAdjParamVal1"]);
        propitem.adjParamVal2 = reader.getNumber<type::_int, fe::json_value>(item["nAdjParamVal2"]);
        propitem.adjParamVal3 = reader.getNumber<type::_int, fe::json_value>(item["nAdjParamVal3"]);
        propitem.chgParamVal1 = reader.getNumber<type::_uint, fe::json_value>(item["dwChgParamVal1"]);
        propitem.chgParamVal2 = reader.getNumber<type::_uint, fe::json_value>(item["dwChgParamVal2"]);
        propitem.chgParamVal3 = reader.getNumber<type::_uint, fe::json_value>(item["dwChgParamVal3"]);

        propitem.destData1 = reader.getNumber<type::_uint, fe::json_value>(item["dwdestData1"]);
        propitem.destData2 = reader.getNumber<type::_uint, fe::json_value>(item["dwdestData2"]);
        propitem.destData3 = reader.getNumber<type::_uint, fe::json_value>(item["dwdestData3"]);
        propitem.activeskill = reader.getNumber<type::_uint, fe::json_value>(item["dwactiveskill"]);
        propitem.activeskillLv = reader.getNumber<type::_uint, fe::json_value>(item["dwactiveskillLv"]);
        propitem.activeskillper = reader.getNumber<type::_uint, fe::json_value>(item["dwactiveskillper"]);
        propitem.reqMp = reader.getNumber<type::_uint, fe::json_value>(item["dwReqMp"]);
        propitem.repFp = reader.getNumber<type::_uint, fe::json_value>(item["dwRepFp"]);
        propitem.reqDisLV = reader.getNumber<type::_uint, fe::json_value>(item["dwReqDisLV"]);
        propitem.reSkill1 = reader.getNumber<type::_uint, fe::json_value>(item["dwReSkill1"]);
        propitem.reSkillLevel1 = reader.getNumber<type::_uint, fe::json_value>(item["dwReSkillLevel1"]);
        propitem.reSkill2 = reader.getNumber<type::_uint, fe::json_value>(item["dwReSkill2"]);
        propitem.reSkillLevel2 = reader.getNumber<type::_uint, fe::json_value>(item["dwReSkillLevel2"]);
        propitem.skillReadyType = reader.getNumber<type::_uint, fe::json_value>(item["dwSkillReadyType"]);
        propitem.skillReady = reader.getNumber<type::_uint, fe::json_value>(item["dwSkillReady"]);
        propitem.skillRange = reader.getNumber<type::_uint, fe::json_value>(item["dwSkillRange"]);
        propitem.sfxElemental = reader.getNumber<type::_uint, fe::json_value>(item["dwSfxElemental"]);
        propitem.sfxObj = reader.getNumber<type::_uint, fe::json_value>(item["dwSfxObj"]);

        //"dwSfxObj2"
        //"dwSfxObj3"
        //"dwSfxObj4"
        //"dwSfxObj5"
        //"dwUseMotion"
        //"dwCircleTime"
        //"dwSkillTime"
        //"dwExeTarget"
        //"dwUseChance"
        //"dwSpellRegion"
        //"dwSpellType"
        //"dwReferStat1"
        //"dwReferStat2"
        //"dwReferTarget1"
        //"dwReferTarget2"
        //"dwReferValue1"
        //"dwReferValue2"
        //"dwSkillType"
        //"fItemResistElecricity"
        //"fItemResistFire"
        //"fItemResistWind"
        //"fItemResistWater"
        //"fItemResistEarth"
        //"nEvildoing"
        //"dwExpertLV"
        //"ExpertMax"
        //"dwSubDefine"
        //"dwExp"
        //"dwComboStyle"
        //"fFlightSpeed"
        //"fFlightLRAngle"
        //"fFlightTBAngle"
        //"dwFlightLimit"
        //"dwFFuelReMax"
        //"dwAFuelReMax"
        //"dwFuelRe"
        //"dwLimitLevel1"
        //"dwReflect"
        //"dwSndAttack1"
        //"dwSndAttack2"
        //"szIcon"
        //"dwQuestID"
        //"szTextFile"
        //"szComment"
    }

    return true;
}
