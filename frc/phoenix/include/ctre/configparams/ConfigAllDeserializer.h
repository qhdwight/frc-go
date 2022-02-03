#pragma once

#include "nlohmann/json.hpp"

int ConfigAllDeserializer(
	const uint8_t* diagnosticMsg,
	int diagnosticMsgLen,
	const nlohmann::json& configDefs,
	nlohmann::json& output);
