#include <pch_fressource.h>
#include <project/project_manager.hpp>
#include <io/file/reader_json.hpp>
#include <io/file/reader_xml.hpp>
#include <property/prop_karma.hpp>


bool fe::ProjectManager::loadPropKarma(const std::string& fileName, LOADER_MODE mode) noexcept
{
    if (fileName.empty())
        return false;
    switch (mode)
    {
        case fe::LOADER_MODE::JSON:
            return loadPropKarmaJson(fileName);
            break;
        case fe::LOADER_MODE::XML:
            return loadPropKarmaXml(fileName);
            break;
        default:
            return false;
    }
}


bool fe::ProjectManager::loadPropKarmaJson(const std::string& fileName) noexcept
{
    ReaderJson  reader;
    reader.header = getHeader();

    if (reader.load(fileName) == false)
        return false;

    fe::type::json::object& datas = reader.get<fe::type::json::object>(reader.root);
    for (auto& it : datas)
    {
        fe::type::json::object& item = reader.get<fe::type::json::object>(it.second);
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
    reader.header = getHeader();

    if (reader.load(fileName) == false)
        return false;
    fe::type::xml::node head = reader.document.child("karmas");
    for (fe::type::xml::node& karma : head)
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

