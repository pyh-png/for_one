#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

class config_paraments
{
public:
	config_paraments();
	config_paraments(const std::string& str);
	~config_paraments();

	

	std::string path_forimage; //原始的全部路径
	std::string workpath; //工作文件夹，后续操作均在文件夹中
	std::vector<double> scale_image; //图片原始放缩比例为原始操作路径
	std::vector<int> is_light; //是否为光镜 1为是， 0为不是
	std::vector<int> scale; //图片放缩比例，1代表不放锁，建议使用2，4比例
	cv::Rect2f ROI;
	int num_image; //有几张图片
	std::vector<std::vector<int>> paraments_src_th; //前景提取的参数设置，光镜为3个，电镜为8个

private:
	std::vector<int> string_to_vector(std::string& s); //string解析为vector<int>
	std::vector<std::vector<int>> parseStringToVector(const std::string& input); //string解析为vector<vector<int>>
	std::vector<double> string_to_vectordouble(std::string & s); 
	cv::Rect2f  string_TO_ROI(std::string & s);
	std::map<std::string, std::string> parameters; //键值对字典
};