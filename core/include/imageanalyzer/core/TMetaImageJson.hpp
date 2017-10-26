#pragma once

#include <imageanalyzer/core/TMetaImage.hpp>
#include <imageanalyzer/nlohmann_json/json.hpp>

#include <memory>

namespace imageanalyzer {
namespace core {

IMAGEANALYZER_CORE_EXPORT void to_json(nlohmann::json& j, const TMetaImage& p);
IMAGEANALYZER_CORE_EXPORT void from_json(const nlohmann::json& j, TMetaImage& p);

IMAGEANALYZER_CORE_EXPORT void to_json(nlohmann::json& j, const TMetaImage::Ptr& p);
IMAGEANALYZER_CORE_EXPORT void from_json(const nlohmann::json& j, TMetaImage::Ptr& p);

IMAGEANALYZER_CORE_EXPORT void to_json(nlohmann::json& j, const THistogram& p);
IMAGEANALYZER_CORE_EXPORT void from_json(const nlohmann::json& j, THistogram& p);

}
}