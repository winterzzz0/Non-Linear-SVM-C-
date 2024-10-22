#ifndef _SVM_
#define _SVM_
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
class SVMClass
{
private:
	vector<double> label(const vector<vector<double>> &dataTraining);
	vector<vector<double>> actualAttribute(const vector<vector<double>> &dataTraining);
	double newBias(vector<double> &labels, vector<vector<double>> &ActualAttributes, vector<double> &alpha);
	double RBFkernel(const vector<double> &Attribute1,const vector<double> &Attribute2, double gamma = 0.1);
	vector<double> dualFunction(const vector<vector<double>> &ActualAttributes, const vector<double> labels,double learningRate = 0.001,double regularizationC = 1);
	vector<double> getSupportVectors(vector<double> &alpha);
	
	
public:
	vector<double> alphaVal {};
	vector<double> labelsVal {};
	double bias {};
	void claculateAB(const vector<vector<double>> &dataTraining,double b);
	int inputDecision(vector<double> &alphaVal, vector<double> &labels,const vector<vector<double>> &dataTraining,vector<double> &newData, const double b);
	
	SVMClass();
	~SVMClass();
	

};

#endif 
