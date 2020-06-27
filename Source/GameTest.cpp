
#include <iostream>
#include "json/json.h"
#include "Common/Help.h"

#include "GameTest.h"
#include "GameTest2.h"
#include "Engine.h"
#include "FileManager.h"

void jsonFun(const std::string nameFile) {
	Json::Value jsonValue;

	GameTest2::loadJson(jsonValue, nameFile);

	if (!jsonValue.empty()) {
		help::log("json [" + nameFile + "]:");
		help::log(help::stringFroJson(jsonValue));

		if (jsonValue.isObject()) {
			int width = jsonValue["window"]["width"].asInt();
			int height = jsonValue["window"]["height"].asInt();

			width += 10;
			height += 10;

			jsonValue["window"]["width"] = width;
			jsonValue["window"]["height"] = height;

			help::log("json [" + nameFile + "]: AFTER CHANGE");
			help::log(help::stringFroJson(jsonValue));

			GameTest2::saveJson(jsonValue, nameFile);
		}
	}
}

void GameTest::exe() {
	std::cout << "GameTest2::exe()" << std::endl;
	GameTest2::fun();

	Engine::FileManager::setResourcesDir("..\\..\\Source\\Resources");
	jsonFun("Base/Setting_FAIL.json");
	jsonFun("Base/Setting.json");

	Engine::exeForGame();
}