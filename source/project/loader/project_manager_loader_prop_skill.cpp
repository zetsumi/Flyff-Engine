#include "pch_fressource.h"
#include "project_manager.hpp"
#include "reader_json.hpp"
#include "reader_xml.hpp"
#include "prop_skill.hpp"

bool fe::ProjectManager::loadPropSkill(const std::string& fileName, LOADER_MODE mode) noexcept
{
    if (fileName.empty() == true)
        return false;
    switch (mode)
    {
    case fe::LOADER_MODE::JSON:
        return loadPropSkillJson(fileName);
        break;
    case fe::LOADER_MODE::XML:
        return loadPropSkillXml(fileName);
        break;
    default:
        return false;
    }
}


bool fe::ProjectManager::loadPropSkillJson(const std::string& fileName) noexcept
{
    ReaderJson  reader;
    std::cout << __FUNCTION__ << " : " << this->getHeader().has("CI_CHEST01") << " value: " << this->getHeader().get("CI_CHEST01") << std::endl;
    reader.header = getHeader();

    if (reader.load(fileName) == false)
        return false;
    std::cout << __FUNCTION__ << " : " << this->getHeader().has("CI_CHEST01") << " value: " << this->getHeader().get("CI_CHEST01") << std::endl;

    fe::type::json::object& datas = reader.get<fe::type::json::object>(reader.root);
    for (auto& it : datas)
    {
        fe::type::json::object& item = reader.get<fe::type::json::object>(it.second);
        fe::PropSkill* prop = new fe::PropSkill();

        prop->version = reader.getNumber<type::_uint, fe::type::json::value>(item["version"]);
        prop->id = reader.getNumber<type::_uint, fe::type::json::value>(item["dwID"]);
        prop->name = reader.get<std::string>(item["szName"]);
        prop->num = reader.getNumber<type::_uint, fe::type::json::value>(item["dwNum"]);
        prop->packMax = reader.getNumber<type::_uint, fe::type::json::value>(item["dwPackMax"]);
        prop->itemKind1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemKind1"]);
        prop->itemKind2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemKind2"]);
        prop->itemKind3 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemKind3"]);
        prop->itemJob = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemJob"]);
        prop->permanence = reader.getBoolean(item["bPermanence"]);
        prop->useable = reader.getNumber<type::_uint, fe::type::json::value>(item["dwUseable"]);
        prop->itemSex = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemSex"]);
        prop->cost = reader.getNumber<type::_uint, fe::type::json::value>(item["dwCost"]);
        prop->endurance = reader.getNumber<type::_uint, fe::type::json::value>(item["dwEndurance"]);
        prop->abrasion = reader.getNumber<type::_int, fe::type::json::value>(item["nAbrasion"]);
        prop->hardness = reader.getNumber<type::_int, fe::type::json::value>(item["nHardness"]);
        prop->handed = reader.getNumber<type::_uint, fe::type::json::value>(item["dwHanded"]);
        prop->heelH = reader.getNumber<type::_uint, fe::type::json::value>(item["dwHeelH"]);
        prop->parts = reader.getNumber<type::_uint, fe::type::json::value>(item["dwParts"]);
        prop->partsub = reader.getNumber<type::_uint, fe::type::json::value>(item["dwPartsub"]);
        prop->partFile = reader.getBoolean(item["bPartFile"]);
        prop->exclusive = reader.getNumber<type::_uint, fe::type::json::value>(item["dwExclusive"]);
        prop->basePartsIgnore = reader.getNumber<type::_uint, fe::type::json::value>(item["dwBasePartsIgnore"]);
        prop->itemLV = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemLV"]);
        prop->itemRare = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemRare"]);
        prop->shopAble = reader.getNumber<type::_uint, fe::type::json::value>(item["dwShopAble"]);
        prop->log = reader.getBoolean(item["bLog"]);
        prop->charged = reader.getBoolean(item["bCharged"]);
        prop->linkKindBullet = reader.getNumber<type::_uint, fe::type::json::value>(item["dwLinkKindBullet"]);
        prop->linkKind = reader.getNumber<type::_uint, fe::type::json::value>(item["dwLinkKind"]);
        prop->abilityMin = reader.getNumber<type::_uint, fe::type::json::value>(item["dwAbilityMin"]);
        prop->abilityMax = reader.getNumber<type::_uint, fe::type::json::value>(item["dwAbilityMax"]);
        prop->itemType = static_cast<fe::PROP_ITEM_ELEMENT>(reader.getNumber<type::_uint, fe::type::json::value>(item["eItemType"]));
        prop->itemEAtk = reader.getNumber<short, fe::type::json::value>(item["wItemEAtk"]);
        prop->parry = reader.getNumber<type::_uint, fe::type::json::value>(item["dwParry"]);
        prop->blockRating = reader.getNumber<type::_uint, fe::type::json::value>(item["dwBlockRating"]);
        prop->addSkillMin = reader.getNumber<type::_uint, fe::type::json::value>(item["dwAddSkillMin"]);
        prop->addSkillMax = reader.getNumber<type::_uint, fe::type::json::value>(item["dwAddSkillMax"]);
        prop->atkStyle = reader.getNumber<type::_uint, fe::type::json::value>(item["dwAtkStyle"]);
        prop->weaponType = reader.getNumber<type::_uint, fe::type::json::value>(item["dwWeaponType"]);
        prop->itemAtkOrder1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemAtkOrder1"]);
        prop->itemAtkOrder2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemAtkOrder2"]);
        prop->itemAtkOrder3 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemAtkOrder3"]);
        prop->itemAtkOrder4 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwItemAtkOrder4"]);
        prop->continuousPain = reader.getBoolean(item["bContinuousPain"]);
        prop->shellQuantity = reader.getNumber<type::_uint, fe::type::json::value>(item["dwShellQuantity"]);
        prop->recoil = reader.getNumber<type::_uint, fe::type::json::value>(item["dwRecoil"]);
        prop->loadingTime = reader.getNumber<type::_uint, fe::type::json::value>(item["dwLoadingTime"]);
        prop->adjHitRate = reader.getNumber<type::_int, fe::type::json::value>(item["nAdjHitRate"]);
        prop->attackSpeed = reader.getNumber<type::_uint, fe::type::json::value>(item["dwAttackSpeed"]);
        prop->dmgShift = reader.getNumber<type::_uint, fe::type::json::value>(item["dwDmgShift"]);
        prop->attackRange = reader.getNumber<type::_uint, fe::type::json::value>(item["dwAttackRange"]);
        prop->probability = reader.getNumber<type::_uint, fe::type::json::value>(item["dwProbability"]);
        prop->destParam1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwDestParam1"]);
        prop->destParam2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwDestParam2"]);
        prop->destParam3 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwDestParam3"]);
        prop->adjParamVal1 = reader.getNumber<type::_int, fe::type::json::value>(item["nAdjParamVal1"]);
        prop->adjParamVal2 = reader.getNumber<type::_int, fe::type::json::value>(item["nAdjParamVal2"]);
        prop->adjParamVal3 = reader.getNumber<type::_int, fe::type::json::value>(item["nAdjParamVal3"]);
        prop->chgParamVal1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwChgParamVal1"]);
        prop->chgParamVal2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwChgParamVal2"]);
        prop->chgParamVal3 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwChgParamVal3"]);
        prop->destData1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwdestData1"]);
        prop->destData2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwdestData2"]);
        prop->destData3 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwdestData3"]);
        prop->activeskill = reader.getNumber<type::_uint, fe::type::json::value>(item["dwactiveskill"]);
        prop->activeskillLv = reader.getNumber<type::_uint, fe::type::json::value>(item["dwactiveskillLv"]);
        prop->activeskillper = reader.getNumber<type::_uint, fe::type::json::value>(item["dwactiveskillper"]);
        prop->reqMp = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReqMp"]);
        prop->repFp = reader.getNumber<type::_uint, fe::type::json::value>(item["dwRepFp"]);
        prop->reqDisLV = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReqDisLV"]);
        prop->reSkill1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReSkill1"]);
        prop->reSkillLevel1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReSkillLevel1"]);
        prop->reSkill2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReSkill2"]);
        prop->reSkillLevel2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReSkillLevel2"]);
        prop->skillReadyType = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSkillReadyType"]);
        prop->skillReady = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSkillReady"]);
        prop->skillRange = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSkillRange"]);
        prop->sfxElemental = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSfxElemental"]);
        prop->sfxObj = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSfxObj"]);
        prop->sfxObj2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSfxObj2"]);
        prop->sfxObj3 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSfxObj3"]);
        prop->sfxObj4 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSfxObj4"]);
        prop->sfxObj5 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSfxObj5"]);
        prop->useMotion = reader.getNumber<type::_uint, fe::type::json::value>(item["dwUseMotion"]);
        prop->circleTime = reader.getNumber<type::_uint, fe::type::json::value>(item["dwCircleTime"]);
        prop->skillTime = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSkillTime"]);
        prop->exeTarget = reader.getNumber<type::_uint, fe::type::json::value>(item["dwExeTarget"]);
        prop->useChance = reader.getNumber<type::_uint, fe::type::json::value>(item["dwUseChance"]);
        prop->spellRegion = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSpellRegion"]);
        prop->spellType = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSpellType"]);
        prop->referStat1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReferStat1"]);
        prop->referStat2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReferStat2"]);
        prop->referTarget1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReferTarget1"]);
        prop->referTarget2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReferTarget2"]);
        prop->referValue1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReferValue1"]);
        prop->referValue2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReferValue2"]);
        prop->skillType = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSkillType"]);
        prop->itemResistElecricity = reader.getNumber<float, fe::type::json::value>(item["fItemResistElecricity"]);
        prop->itemResistFire = reader.getNumber<float, fe::type::json::value>(item["fItemResistFire"]);
        prop->itemResistWind = reader.getNumber<float, fe::type::json::value>(item["fItemResistWind"]);
        prop->itemResistWater = reader.getNumber<float, fe::type::json::value>(item["fItemResistWater"]);
        prop->itemResistEarth = reader.getNumber<float, fe::type::json::value>(item["fItemResistEarth"]);
        prop->evildoing = reader.getNumber<type::_int, fe::type::json::value>(item["nEvildoing"]);
        prop->expertLV = reader.getNumber<type::_uint, fe::type::json::value>(item["dwExpertLV"]);
        prop->expertMax = reader.getNumber<type::_uint, fe::type::json::value>(item["ExpertMax"]);
        prop->subDefine = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSubDefine"]);
        prop->exp = reader.getNumber<type::_uint, fe::type::json::value>(item["dwExp"]);
        prop->comboStyle = reader.getNumber<type::_uint, fe::type::json::value>(item["dwComboStyle"]);
        prop->flightSpeed = reader.getNumber<float, fe::type::json::value>(item["fFlightSpeed"]);
        prop->flightLRAngle = reader.getNumber<float, fe::type::json::value>(item["fFlightLRAngle"]);
        prop->FlightTBAngle = reader.getNumber<float, fe::type::json::value>(item["fFlightTBAngle"]);
        prop->flightLimit = reader.getNumber<type::_uint, fe::type::json::value>(item["dwFlightLimit"]);
        prop->fFuelReMax = reader.getNumber<type::_uint, fe::type::json::value>(item["dwFFuelReMax"]);
        prop->aFuelReMax = reader.getNumber<type::_uint, fe::type::json::value>(item["dwAFuelReMax"]);
        prop->fuelRe = reader.getNumber<type::_uint, fe::type::json::value>(item["dwFuelRe"]);
        prop->limitLevel1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwLimitLevel1"]);
        prop->reflect = reader.getNumber<type::_uint, fe::type::json::value>(item["dwReflect"]);
        prop->sndAttack1 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSndAttack1"]);
        prop->sndAttack2 = reader.getNumber<type::_uint, fe::type::json::value>(item["dwSndAttack2"]);
        prop->icon = reader.get<std::string>(item["szIcon"]);
        prop->questID = reader.getNumber<type::_uint, fe::type::json::value>(item["dwQuestID"]);
        prop->textFile = reader.get<std::string>(item["szTextFile"]);
        prop->comment = reader.get<std::string>(item["szComment"]);
        propskill.push(prop->id, prop);
    }
    return true;
}


bool fe::ProjectManager::loadPropSkillXml(const std::string& fileName) noexcept
{
    ReaderXml reader;
    reader.header = getHeader();

    if (reader.load(fileName) == false)
        return false;
    fe::type::xml::node head = reader.document.child("skills");
    
    auto fctLoaderItem = [&](fe::type::xml::node& item)
    {
        fe::PropSkill* prop = new fe::PropSkill();
        prop->version = reader.getNumber<type::_uint>(item, "version");
        prop->id = reader.getNumber<type::_uint>(item, "dwID");
        prop->name = reader.getString(item, "szName");
        prop->num = reader.getNumber<type::_uint>(item, "dwNum");
        prop->packMax = reader.getNumber<type::_uint>(item, "dwPackMax");
        prop->itemKind1 = reader.getNumber<type::_uint>(item, "dwItemKind1");
        prop->itemKind2 = reader.getNumber<type::_uint>(item, "dwItemKind2");
        prop->itemKind3 = reader.getNumber<type::_uint>(item, "dwItemKind3");
        prop->itemJob = reader.getNumber<type::_uint>(item, "dwItemJob");
        prop->permanence = reader.getBoolean(item, "bPermanence");
        prop->useable = reader.getNumber<type::_uint>(item, "dwUseable");
        prop->itemSex = reader.getNumber<type::_uint>(item, "dwItemSex");
        prop->cost = reader.getNumber<type::_uint>(item, "dwCost");
        prop->endurance = reader.getNumber<type::_uint>(item, "dwEndurance");
        prop->abrasion = reader.getNumber<type::_int>(item, "nAbrasion");
        prop->hardness = reader.getNumber<type::_int>(item, "nHardness");
        prop->handed = reader.getNumber<type::_uint>(item, "dwHanded");
        prop->heelH = reader.getNumber<type::_uint>(item, "dwHeelH");
        prop->parts = reader.getNumber<type::_uint>(item, "dwParts");
        prop->partsub = reader.getNumber<type::_uint>(item, "dwPartsub");
        prop->partFile = reader.getBoolean(item, "bPartFile");
        prop->exclusive = reader.getNumber<type::_uint>(item, "dwExclusive");
        prop->basePartsIgnore = reader.getNumber<type::_uint>(item, "dwBasePartsIgnore");
        prop->itemLV = reader.getNumber<type::_uint>(item, "dwItemLV");
        prop->itemRare = reader.getNumber<type::_uint>(item, "dwItemRare");
        prop->shopAble = reader.getNumber<type::_uint>(item, "dwShopAble");
        prop->log = reader.getBoolean(item, "bLog");
        prop->charged = reader.getBoolean(item, "bCharged");
        prop->linkKindBullet = reader.getNumber<type::_uint>(item, "dwLinkKindBullet");
        prop->linkKind = reader.getNumber<type::_uint>(item, "dwLinkKind");
        prop->abilityMin = reader.getNumber<type::_uint>(item, "dwAbilityMin");
        prop->abilityMax = reader.getNumber<type::_uint>(item, "dwAbilityMax");
        prop->itemType = static_cast<fe::PROP_ITEM_ELEMENT>(reader.getNumber<type::_uint>(item, "eItemType"));
        prop->itemEAtk = reader.getNumber<short>(item, "wItemEAtk");
        prop->parry = reader.getNumber<type::_uint>(item, "dwParry");
        prop->blockRating = reader.getNumber<type::_uint>(item, "dwBlockRating");
        prop->addSkillMin = reader.getNumber<type::_uint>(item, "dwAddSkillMin");
        prop->addSkillMax = reader.getNumber<type::_uint>(item, "dwAddSkillMax");
        prop->atkStyle = reader.getNumber<type::_uint>(item, "dwAtkStyle");
        prop->weaponType = reader.getNumber<type::_uint>(item, "dwWeaponType");
        prop->itemAtkOrder1 = reader.getNumber<type::_uint>(item, "dwItemAtkOrder1");
        prop->itemAtkOrder2 = reader.getNumber<type::_uint>(item, "dwItemAtkOrder2");
        prop->itemAtkOrder3 = reader.getNumber<type::_uint>(item, "dwItemAtkOrder3");
        prop->itemAtkOrder4 = reader.getNumber<type::_uint>(item, "dwItemAtkOrder4");
        prop->continuousPain = reader.getBoolean(item, "bContinuousPain");
        prop->shellQuantity = reader.getNumber<type::_uint>(item, "dwShellQuantity");
        prop->recoil = reader.getNumber<type::_uint>(item, "dwRecoil");
        prop->loadingTime = reader.getNumber<type::_uint>(item, "dwLoadingTime");
        prop->adjHitRate = reader.getNumber<type::_int>(item, "nAdjHitRate");
        prop->attackSpeed = reader.getNumber<type::_uint>(item, "dwAttackSpeed");
        prop->dmgShift = reader.getNumber<type::_uint>(item, "dwDmgShift");
        prop->attackRange = reader.getNumber<type::_uint>(item, "dwAttackRange");
        prop->probability = reader.getNumber<type::_uint>(item, "dwProbability");
        prop->destParam1 = reader.getNumber<type::_uint>(item, "dwDestParam1");
        prop->destParam2 = reader.getNumber<type::_uint>(item, "dwDestParam2");
        prop->destParam3 = reader.getNumber<type::_uint>(item, "dwDestParam3");
        prop->adjParamVal1 = reader.getNumber<type::_int>(item, "nAdjParamVal1");
        prop->adjParamVal2 = reader.getNumber<type::_int>(item, "nAdjParamVal2");
        prop->adjParamVal3 = reader.getNumber<type::_int>(item, "nAdjParamVal3");
        prop->chgParamVal1 = reader.getNumber<type::_uint>(item, "dwChgParamVal1");
        prop->chgParamVal2 = reader.getNumber<type::_uint>(item, "dwChgParamVal2");
        prop->chgParamVal3 = reader.getNumber<type::_uint>(item, "dwChgParamVal3");
        prop->destData1 = reader.getNumber<type::_uint>(item, "dwdestData1");
        prop->destData2 = reader.getNumber<type::_uint>(item, "dwdestData2");
        prop->destData3 = reader.getNumber<type::_uint>(item, "dwdestData3");
        prop->activeskill = reader.getNumber<type::_uint>(item, "dwactiveskill");
        prop->activeskillLv = reader.getNumber<type::_uint>(item, "dwactiveskillLv");
        prop->activeskillper = reader.getNumber<type::_uint>(item, "dwactiveskillper");
        prop->reqMp = reader.getNumber<type::_uint>(item, "dwReqMp");
        prop->repFp = reader.getNumber<type::_uint>(item, "dwRepFp");
        prop->reqDisLV = reader.getNumber<type::_uint>(item, "dwReqDisLV");
        prop->reSkill1 = reader.getNumber<type::_uint>(item, "dwReSkill1");
        prop->reSkillLevel1 = reader.getNumber<type::_uint>(item, "dwReSkillLevel1");
        prop->reSkill2 = reader.getNumber<type::_uint>(item, "dwReSkill2");
        prop->reSkillLevel2 = reader.getNumber<type::_uint>(item, "dwReSkillLevel2");
        prop->skillReadyType = reader.getNumber<type::_uint>(item, "dwSkillReadyType");
        prop->skillReady = reader.getNumber<type::_uint>(item, "dwSkillReady");
        prop->skillRange = reader.getNumber<type::_uint>(item, "dwSkillRange");
        prop->sfxElemental = reader.getNumber<type::_uint>(item, "dwSfxElemental");
        prop->sfxObj = reader.getNumber<type::_uint>(item, "dwSfxObj");
        prop->sfxObj2 = reader.getNumber<type::_uint>(item, "dwSfxObj2");
        prop->sfxObj3 = reader.getNumber<type::_uint>(item, "dwSfxObj3");
        prop->sfxObj4 = reader.getNumber<type::_uint>(item, "dwSfxObj4");
        prop->sfxObj5 = reader.getNumber<type::_uint>(item, "dwSfxObj5");
        prop->useMotion = reader.getNumber<type::_uint>(item, "dwUseMotion");
        prop->circleTime = reader.getNumber<type::_uint>(item, "dwCircleTime");
        prop->skillTime = reader.getNumber<type::_uint>(item, "dwSkillTime");
        prop->exeTarget = reader.getNumber<type::_uint>(item, "dwExeTarget");
        prop->useChance = reader.getNumber<type::_uint>(item, "dwUseChance");
        prop->spellRegion = reader.getNumber<type::_uint>(item, "dwSpellRegion");
        prop->spellType = reader.getNumber<type::_uint>(item, "dwSpellType");
        prop->referStat1 = reader.getNumber<type::_uint>(item, "dwReferStat1");
        prop->referStat2 = reader.getNumber<type::_uint>(item, "dwReferStat2");
        prop->referTarget1 = reader.getNumber<type::_uint>(item, "dwReferTarget1");
        prop->referTarget2 = reader.getNumber<type::_uint>(item, "dwReferTarget2");
        prop->referValue1 = reader.getNumber<type::_uint>(item, "dwReferValue1");
        prop->referValue2 = reader.getNumber<type::_uint>(item, "dwReferValue2");
        prop->skillType = reader.getNumber<type::_uint>(item, "dwSkillType");
        prop->itemResistElecricity = reader.getNumber<float>(item, "fItemResistElecricity");
        prop->itemResistFire = reader.getNumber<float>(item, "fItemResistFire");
        prop->itemResistWind = reader.getNumber<float>(item, "fItemResistWind");
        prop->itemResistWater = reader.getNumber<float>(item, "fItemResistWater");
        prop->itemResistEarth = reader.getNumber<float>(item, "fItemResistEarth");
        prop->evildoing = reader.getNumber<type::_int>(item, "nEvildoing");
        prop->expertLV = reader.getNumber<type::_uint>(item, "dwExpertLV");
        prop->expertMax = reader.getNumber<type::_uint>(item, "ExpertMax");
        prop->subDefine = reader.getNumber<type::_uint>(item, "dwSubDefine");
        prop->exp = reader.getNumber<type::_uint>(item, "dwExp");
        prop->comboStyle = reader.getNumber<type::_uint>(item, "dwComboStyle");
        prop->flightSpeed = reader.getNumber<float>(item, "fFlightSpeed");
        prop->flightLRAngle = reader.getNumber<float>(item, "fFlightLRAngle");
        prop->FlightTBAngle = reader.getNumber<float>(item, "fFlightTBAngle");
        prop->flightLimit = reader.getNumber<type::_uint>(item, "dwFlightLimit");
        prop->fFuelReMax = reader.getNumber<type::_uint>(item, "dwFFuelReMax");
        prop->aFuelReMax = reader.getNumber<type::_uint>(item, "dwAFuelReMax");
        prop->fuelRe = reader.getNumber<type::_uint>(item, "dwFuelRe");
        prop->limitLevel1 = reader.getNumber<type::_uint>(item, "dwLimitLevel1");
        prop->reflect = reader.getNumber<type::_uint>(item, "dwReflect");
        prop->sndAttack1 = reader.getNumber<type::_uint>(item, "dwSndAttack1");
        prop->sndAttack2 = reader.getNumber<type::_uint>(item, "dwSndAttack2");
        prop->icon = reader.getString(item, "szIcon");
        prop->questID = reader.getNumber<type::_uint>(item, "dwQuestID");
        prop->textFile = reader.getString(item, "szTextFile");
        prop->comment = reader.getString(item, "szComment");
        propskill.push(prop->id, prop);
    };
    auto fctLooper = [&](fe::type::xml::node& head)
    {
        for (fe::type::xml::node& section : head)
        {
            for (fe::type::xml::node& subSection : section)
            {
                if (std::string(subSection.name()) == "skill")
                    fctLoaderItem(subSection);
                else
                {
                    for (fe::type::xml::node& subSubSection : subSection)
                    {
                        if (std::string(subSubSection.name()) == "skill")
                            fctLoaderItem(subSubSection);
                        else
                        {
                            for (fe::type::xml::node& subSubSubSection : subSubSection)
                            {
                                if (std::string(subSubSubSection.name()) == "skill")
                                    fctLoaderItem(subSubSubSection);
                            }
                        }
                    }
                }
            }
        }
    };
    fctLooper(head);
    return true;
}