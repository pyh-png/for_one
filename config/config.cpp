#include"config.h"

config_paraments::config_paraments()
{
}

config_paraments::config_paraments(const std::string & filename)
{
	//std::map<std::string, std::string> parameters;
	std::ifstream file(filename);
	if (!file) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return;
	}

	std::string line;
	std::string section;

	while (std::getline(file, line)) {
		std::stringstream ss(line);

		std::string key;
		std::string value;

		std::getline(ss, key, '=');
		std::getline(ss, value);

		if (!key.empty() && !value.empty()) {
			// Remove leading/trailing whitespaces from key and value
			key.erase(0, key.find_first_not_of(" \t"));
			key.erase(key.find_last_not_of(" \t") + 1);
			value.erase(0, value.find_first_not_of(" \t"));
			value.erase(value.find_last_not_of(" \t") + 1);

			parameters[key] = value;
		}
	}
	//��������
	num_image = std::stoi(parameters["num_image"]);
	path_forimage = parameters["path_forimage"];
	workpath = parameters["workpath"];

	scale_image = string_to_vectordouble(parameters["scale_image"]);
	if (scale_image.size() != num_image) {
		std::cerr << "Failed to dowm scale_image " << std::endl;

	}

	is_light = string_to_vector(parameters["is_light"]);
	if (is_light.size() != num_image) {
		std::cerr << "Failed to dowm is_light " << std::endl;
	}

	scale = string_to_vector(parameters["scale"]);
	if (scale.size() != num_image) {
		std::cerr << "Failed to dowm scale " << std::endl;
	}


	paraments_src_th = parseStringToVector(parameters["paraments"]);
	if (paraments_src_th.size() != num_image) {
		std::cerr << "Failed to dowm paraments_src_th " << std::endl;
	}
	ROI = string_TO_ROI(parameters["ROI"]);

}


config_paraments::~config_paraments()
{
}
std::vector<double> config_paraments::string_to_vectordouble(std::string& s) {
	std::vector<double> vec;
	// ȥ���ַ����еĴ�����
	std::string str = s.substr(1, s.length() - 2);

	// ʹ��stringstream��������ַ����е���������ӵ�vector��
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, ',')) {
		double value = std::stod(token);
		vec.push_back(value);
	}

	
	return vec;
}

cv::Rect2f config_paraments::string_TO_ROI(std::string & s)
{
	
	cv::Point2f p1;
	cv::Point2f p2;
	char c;
	std::stringstream ss(s);
	ss >> c; // ����������
	ss >> c; // ����������
	ss >> p1.x;
	ss >> c; // ��������
	ss >> p1.y;
	ss >> c; // ����������
	ss >> c; // ��������
	ss >> c; // ����������
	ss >> p2.x;
	ss >> c; // ��������
	ss >> p2.y;
	cv::Rect2f Visa(p1,p2);
	return Visa;
}

std::vector<int> config_paraments::string_to_vector(std::string& s) {
	std::vector<int> vec;
	// ȥ���ַ����еĴ�����
	std::string str = s.substr(1, s.length() - 2);

	// ʹ��stringstream��������ַ����е���������ӵ�vector��
	std::stringstream ss(str);
	std::string token;
	while (std::getline(ss, token, ',')) {
		int value = std::stoi(token);
		vec.push_back(value);
	}

	return vec;
}


std::vector<std::vector<int>> config_paraments::parseStringToVector(const std::string& input) {
	std::vector<std::vector<int>> result;
	std::string str = input.substr(1, input.length() - 2);
	std::istringstream iss(str);
	std::string token;

	// �ָ��ⲿ������

	while (std::getline(iss, token, ';')) {
		std::vector<int> innerVector;

		// �ָ��ڲ�С����
		std::string in = token.substr(1, token.length() - 2);
		std::istringstream innerIss(in);
		std::string innerToken;

		while (std::getline(innerIss, innerToken, ',')) {
			// ת��Ϊ��������ӵ��ڲ�����
			innerVector.push_back(std::stoi(innerToken));
		}

		// ���ڲ�������ӵ��������
		result.push_back(innerVector);
	}


	return result;
}


std::map<std::string, std::string> parseFileParameters(const std::string& filename) {
	std::map<std::string, std::string> parameters;
	std::ifstream file(filename);
	if (!file) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return parameters;
	}

	std::string line;
	std::string section;

	while (std::getline(file, line)) {
		std::stringstream ss(line);

		std::string key;
		std::string value;

		std::getline(ss, key, '=');
		std::getline(ss, value);

		if (!key.empty() && !value.empty()) {
			// Remove leading/trailing whitespaces from key and value
			key.erase(0, key.find_first_not_of(" \t"));
			key.erase(key.find_last_not_of(" \t") + 1);
			value.erase(0, value.find_first_not_of(" \t"));
			value.erase(value.find_last_not_of(" \t") + 1);

			parameters[key] = value;
		}
	}

	return parameters;
}