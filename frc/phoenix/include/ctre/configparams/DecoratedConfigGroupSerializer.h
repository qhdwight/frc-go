#pragma once
#include <stdint.h>
/* This sucks, we need to move nlohmann to a proper include directory */
#include "nlohmann/json.hpp"
#include "ctre/configparams/ConfigByteArray.h"

class DecoratedConfigGroupSerializer
{
	public:
		static int Serialize(const std::string& hardwareModel, const ctre::configparams::ConfigByteArray& configByteArray, nlohmann::json& outJson);

		static int Deserialize(const std::string& hardwareModel, const nlohmann::json& json, ctre::configparams::ConfigByteArray& toFill);
	private:
};
