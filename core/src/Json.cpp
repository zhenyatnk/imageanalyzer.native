#include <imageanalyzer.native/core/TColorJson.hpp>
#include <imageanalyzer.native/core/TMetaImageJson.hpp>

#include <fstream>

namespace imageanalyzer {
namespace native {
namespace core {

void to_json(nlohmann::json& j, const TColor& p)
{
    j = p.To_RGBA();
}

void from_json(const nlohmann::json& j, TColor& p)
{
    p = TColor::FromRGBA(j.get<unsigned long>());
}

void to_json(nlohmann::json& j, const TMetaImage& p)
{
    j["histograms"] = p.m_Histograms;
}

void from_json(const nlohmann::json& j, TMetaImage& p)
{
    p.m_Histograms = j["histograms"].get<TMetaImage::TContainerHistograms>();
}

void to_json(nlohmann::json& j, const THistogram& p)
{
    j["data"] = p.m_Data;
}
void from_json(const nlohmann::json& j, THistogram& p)
{
    p.m_Data = j["data"].get<THistogram::TContainerColor>();
}

TMetaImage CreateTMetaImageFromFile(const std::wstring &aFileName)
{
    std::ifstream data(aFileName);
    nlohmann::json j_data;
    data >> j_data;
    return j_data.get<TMetaImage>();
}

}
}
}