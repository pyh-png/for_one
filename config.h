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

	

	std::string path_forimage; //ԭʼ��ȫ��·��
	std::string workpath; //�����ļ��У��������������ļ�����
	std::vector<double> scale_image; //ͼƬԭʼ��������Ϊԭʼ����·��
	std::vector<int> is_light; //�Ƿ�Ϊ�⾵ 1Ϊ�ǣ� 0Ϊ����
	std::vector<int> scale; //ͼƬ����������1��������������ʹ��2��4����
	cv::Rect2f ROI;
	int num_image; //�м���ͼƬ
	std::vector<std::vector<int>> paraments_src_th; //ǰ����ȡ�Ĳ������ã��⾵Ϊ3�����羵Ϊ8��

private:
	std::vector<int> string_to_vector(std::string& s); //string����Ϊvector<int>
	std::vector<std::vector<int>> parseStringToVector(const std::string& input); //string����Ϊvector<vector<int>>
	std::vector<double> string_to_vectordouble(std::string & s); 
	cv::Rect2f  string_TO_ROI(std::string & s);
	std::map<std::string, std::string> parameters; //��ֵ���ֵ�
};