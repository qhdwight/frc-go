#pragma once
#include "nlohmann/json.hpp"

int ConfigAllSerializer(
	const nlohmann::json& configDefs,
	const nlohmann::json& userSettings,
	std::vector<uint8_t>& outputFrame);
