#include"config.h"
#include <filesystem>

using namespace std;

config_paraments config("Config.txt");

int main() {
	int num = 1;
	//std::string save_path = config.workpath + "\\m" + to_string(num + 1) + ".png";

	std::string folder_path = config.workpath + "//m" + to_string(num + 1) + "_th";
	
	if (std::filesystem::exists(folder_path) && std::filesystem::is_directory(folder_path)) {//是否存在，是否是文件夹
		std::cout << "The folder exists." << std::endl;
	}
	else {
		std::cout << "The folder does not exist." << std::endl;//不是就创建
		if (!std::filesystem::create_directory(folder_path))
		{
			std::cerr << "Failed to create directory " << folder_path << "\n";
			return 1;
		}
		std::cout << "Directory " << folder_path << " created successfully.\n";

	}
	


	return 0;
}
