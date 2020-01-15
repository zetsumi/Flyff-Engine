#include "pch.h"
#include "project_manager.hpp"
#include "reader_json.hpp"
#include "reader_xml.hpp"
#include "prop_karma.hpp"


bool fe::ProjectManager::loadPropKarma(const std::string& fileName, LOADER_MODE mode) noexcept
{
    if (fileName.empty())
        return false;
    switch (mode)
    {
        case fe::LOADER_MODE::JSON:
            loadPropKarmaJson(fileName);
            break;
        case fe::LOADER_MODE::XML:
            loadPropKarmaXml(fileName);
            break;
        default:
            return false;
    }
}


bool fe::ProjectManager::loadPropKarmaJson(const std::string& fileName) noexcept
{
    ReaderJson  reader;
    reader.header = std::forward<ReaderHeader>(header);

    if (reader.load(fileName) == false)
        return false;

    fe::json_object& datas = reader.get<json_object>(reader.root);
    for (auto& it : datas)
    {
        fe::json_object& item = reader.get<fe::json_object>(it.second);
        fe::PropKarma* prop = new fe::PropKarma();

        prop->id = reader.getNumber<fe::type::_int>(item["nGrade"]);
        prop->name = reader.get<std::string>(item["szName"]);
        prop->karmaPoint = reader.getNumber<fe::type::_int>(item["dwKarmaPoint"]);
        prop->grade = reader.getNumber<fe::type::_uint>(item["dwGrade"]);
        prop->color = reader.getNumber<fe::type::_uint>(item["dwColor"]);
        prop->karmaRecoverPoint = reader.getNumber<fe::type::_uint>(item["dwKarmaRecoverPoint"]);
        prop->discountRate = reader.getNumber<fe::type::_uint>(item["dwDiscountRate"]);
        prop->sellPenaltyRate = reader.getNumber<fe::type::_uint>(item["dwSellPenaltyRate"]);
        prop->guardReaction = reader.getNumber<fe::type::_uint>(item["dwGuardReaction"]);
        prop->subtractExpRate = reader.getNumber<fe::type::_int>(item["SubtractExpRate"]);
        prop->dropGoldPercent = reader.getNumber<fe::type::_int>(item["nDropGoldPercent"]);
        prop->dropItem = reader.getNumber<fe::type::_int>(item["nDropItem"]);
        prop->dropPercent = reader.getNumber<fe::type::_int>(item["nDropPercent"]);
        prop->karmaRecoverNum = reader.getNumber<fe::type::_uint>(item["dwKarmaRecoverNum"]);
        prop->statLimitTime = reader.getNumber<fe::type::_uint>(item["dwStatLimitTime"]);
        prop->statLimitNum = reader.getNumber<fe::type::_uint>(item["dwStatLimitNum"]);
        prop->statLimitRate = reader.getNumber<fe::type::_uint>(item["dwStatLimitRate"]);
        prop->comment = reader.get<std::string>(item["szComment"]);

        prop->id += 6;
        propkarma.push(prop->id, prop);

    }
    return true;
}

bool fe::ProjectManager::loadPropKarmaXml(const std::string& fileName) noexcept
{
    ReaderXml reader;
    reader.header = std::forward<ReaderHeader>(header);

    if (reader.load(fileName) == false)
        return false;
    xml::node head = reader.document.child("karmas");
    for (xml::node& karma : head)
    {
        fe::PropKarma* prop = new fe::PropKarma();
        prop->id = reader.getNumber<type::_int>(karma, "nGrade");
        prop->name = reader.getString(karma, "szName");
        prop->karmaPoint = reader.getNumber<type::_uint>(karma, "dwKarmaPoint");
        prop->grade = reader.getNumber<type::_uint>(karma, "dwGrade");
        prop->color = reader.getNumber<type::_uint>(karma, "dwColor");
        prop->karmaRecoverPoint = reader.getNumber<type::_uint>(karma, "dwKarmaRecoverPoint");
        prop->discountRate = reader.getNumber<type::_uint>(karma, "dwDiscountRate");
        prop->sellPenaltyRate = reader.getNumber<type::_uint>(karma, "dwSellPenaltyRate");
        prop->guardReaction = reader.getNumber<type::_uint>(karma, "dwGuardReaction");
        prop->subtractExpRate = reader.getNumber<fe::type::_int>(karma, "SubtractExpRate");
        prop->dropGoldPercent = reader.getNumber<fe::type::_int>(karma, "nDropGoldPercent");
        prop->dropItem = reader.getNumber<fe::type::_int>(karma, "nDropItem");
        prop->dropPercent = reader.getNumber<fe::type::_int>(karma, "nDropPercent");
        prop->karmaRecoverNum = reader.getNumber<type::_uint>(karma, "dwKarmaRecoverNum");
        prop->statLimitTime = reader.getNumber<type::_uint>(karma, "dwStatLimitTime");
        prop->statLimitNum = reader.getNumber<type::_uint>(karma, "dwStatLimitNum");
        prop->statLimitRate = reader.getNumber<type::_uint>(karma, "dwStatLimitRate");
        prop->comment = reader.getString(karma, "szComment");

        prop->id += 6;
        propkarma.push(prop->id, prop);
    }
    return true;
}
