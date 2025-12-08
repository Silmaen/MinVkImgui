#include "baseDefine.h"
#include "core/Application.h"
#include "core/Log.h"
#include "core/utilities.h"

#include <magic_enum/magic_enum.hpp>

// Main code
auto main(const int iArgc, char** iArgv) -> int {
#ifdef MVI_DEBUG
	mvi::Log::init(mvi::Log::Level::Trace);
#else
	mvi::Log::init(mvi::Log::Level::Info);
#endif
	mvi::core::initializeUtilities(iArgc, iArgv);
	mvi::core::loadSettings();
	mvi::core::mergeDefaultSettings();
	const auto settings = mvi::core::getSettings();
	if (!settings->getValue<std::string>("general/log_level", "").empty()) {
		const auto loglevel = settings->getValue<std::string>(
				"general/log_level", std::string(magic_enum::enum_name(mvi::Log::getVerbosityLevel())));
		if (const auto val = magic_enum::enum_cast<mvi::Log::Level>(loglevel); val.has_value()) {
			mvi::Log::setVerbosityLevel(val.value());
		}
	}
	settings->setValue("general/log_level", std::string(magic_enum::enum_name(mvi::Log::getVerbosityLevel())));
	log_info("---------------------------------------------------------------------------------------");
	log_info("Démarrage de l'application {} version {} créée par {}", mvi::MVI_APP, mvi::MVI_VERSION,
			 mvi::MVI_AUTHOR_STR);
	log_info("Chemin d'exécution : {}", mvi::core::getExecPath().string());

	int ret = 0;

	auto app = mvi::core::createApplication(iArgc, iArgv);
	// Runtime
	app->run();
	if (app->getState() == mvi::core::Application::State::Error) {
		ret = 1;
	}
	// Shutdown
	app.reset();

	log_info("Sortie de l'application {} Avec le code {}", mvi::MVI_APP, ret);
	log_info("---------------------------------------------------------------------------------------");
	mvi::core::leaveSettings();
	// Destroy the logger
	mvi::Log::invalidate();
	return ret;
}
