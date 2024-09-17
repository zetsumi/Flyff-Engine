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

        prop->id = reader.getNumber<int64_t>(item["nGrade"]);
        prop->name = reader.get<std::string>(item["szName"]);
        prop->karmaPoint = reader.getNumber<int64_t>(item["dwKarmaPoint"]);
        prop->grade = reader.getNumber<uint64_t>(item["dwGrade"]);
        prop->color = reader.getNumber<uint64_t>(item["dwColor"]);
        prop->karmaRecoverPoint = reader.getNumber<uint64_t>(item["dwKarmaRecoverPoint"]);
        prop->discountRate = reader.getNumber<uint64_t>(item["dwDiscountRate"]);
        prop->sellPenaltyRate = reader.getNumber<uint64_t>(item["dwSellPenaltyRate"]);
        prop->guardReaction = reader.getNumber<uint64_t>(item["dwGuardReaction"]);
        prop->subtractExpRate = reader.getNumber<int64_t>(item["SubtractExpRate"]);
        prop->dropGoldPercent = reader.getNumber<int64_t>(item["nDropGoldPercent"]);
        prop->dropItem = reader.getNumber<int64_t>(item["nDropItem"]);
        prop->dropPercent = reader.getNumber<int64_t>(item["nDropPercent"]);
        prop->karmaRecoverNum = reader.getNumber<uint64_t>(item["dwKarmaRecoverNum"]);
        prop->statLimitTime = reader.getNumber<uint64_t>(item["dwStatLimitTime"]);
        prop->statLimitNum = reader.getNumber<uint64_t>(item["dwStatLimitNum"]);
        prop->statLimitRate = reader.getNumber<uint64_t>(item["dwStatLimitRate"]);
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
        prop->id = reader.getNumber<int64_t>(karma, "nGrade");
        prop->name = reader.getString(karma, "szName");
        prop->karmaPoint = reader.getNumber<uint64_t>(karma, "dwKarmaPoint");
        prop->grade = reader.getNumber<uint64_t>(karma, "dwGrade");
        prop->color = reader.getNumber<uint64_t>(karma, "dwColor");
        prop->karmaRecoverPoint = reader.getNumber<uint64_t>(karma, "dwKarmaRecoverPoint");
        prop->discountRate = reader.getNumber<uint64_t>(karma, "dwDiscountRate");
        prop->sellPenaltyRate = reader.getNumber<uint64_t>(karma, "dwSellPenaltyRate");
        prop->guardReaction = reader.getNumber<uint64_t>(karma, "dwGuardReaction");
        prop->subtractExpRate = reader.getNumber<int64_t>(karma, "SubtractExpRate");
        prop->dropGoldPercent = reader.getNumber<int64_t>(karma, "nDropGoldPercent");
        prop->dropItem = reader.getNumber<int64_t>(karma, "nDropItem");
        prop->dropPercent = reader.getNumber<int64_t>(karma, "nDropPercent");
        prop->karmaRecoverNum = reader.getNumber<uint64_t>(karma, "dwKarmaRecoverNum");
        prop->statLimitTime = reader.getNumber<uint64_t>(karma, "dwStatLimitTime");
        prop->statLimitNum = reader.getNumber<uint64_t>(karma, "dwStatLimitNum");
        prop->statLimitRate = reader.getNumber<uint64_t>(karma, "dwStatLimitRate");
        prop->comment = reader.getString(karma, "szComment");

        prop->id += 6;
        propkarma.push(prop->id, prop);
    }
    return true;
}

