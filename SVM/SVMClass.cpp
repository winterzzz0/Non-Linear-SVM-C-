#include "SVMClass.h"


vector<double> SVMClass::label(const vector<vector<double>> &dataTraining){
	vector<double> labels;
	if(dataTraining.empty()){
		return labels;
	}
	for(size_t i{}; i<dataTraining.size();i++){
		labels.push_back(dataTraining.at(i).at(dataTraining.at(0).size() -1 ));
	}
	return labels;
}


vector<vector<double>> SVMClass::actualAttribute(const vector<vector<double>> &dataTraining){
	vector<vector<double>> TempactualAttributes {};
	if(dataTraining.empty()){
		return TempactualAttributes;
	}
	for(size_t i{}; i<dataTraining.size();i++){
		TempactualAttributes.push_back(vector<double>());
		for(size_t j{}; j<dataTraining.at(i).size()-1;j++){
			TempactualAttributes.at(i).push_back(dataTraining.at(i).at(j));
		}
	}
	return TempactualAttributes;
}

double SVMClass::RBFkernel(const vector<double> &Attribute1,const vector<double> &Attribute2, double gamma){
	double res {};
	for(size_t i{}; i<Attribute1.size(); i++){
		res += pow(Attribute1[i]-Attribute2[i],2);
	}
	return exp(-gamma * res);
}


vector<double> SVMClass::dualFunction(const vector<vector<double>> &ActualAttributes, const vector<double> labels,double learningRate,double regularizationC){
	vector<double> alpha (ActualAttributes.size(),0.0);
	
	
	for(size_t e{}; e<2000; e++){
		for(size_t i{}; i<ActualAttributes.size(); i++){
			double res {};
			for(size_t j{}; j<ActualAttributes.size(); j++){
				res += alpha[j] * labels[i] * labels[j] * RBFkernel(ActualAttributes[i],ActualAttributes[j]);
			}
			alpha.at(i) = alpha.at(i) + learningRate * (1-res);
			if(alpha.at(i) > regularizationC){
				alpha.at(i) = regularizationC;
			}else if(alpha.at(i) < 0){
				alpha.at(i) = 0;
			}
		}
		
	}
		
	
	return alpha;
	
}


double SVMClass::newBias(vector<double> &labels, vector<vector<double>> &ActualAttributes, vector<double> &alpha){
	double temp2 {};
	for(size_t i{}; i<alpha.size();i++){
		if(alpha[i] > 0){
			temp2 = i;
			break;
		}
	}
	double res {};
	for(size_t i {}; i<ActualAttributes.size();i++){
		res += alpha.at(i) * labels.at(i) * RBFkernel(ActualAttributes.at(i), ActualAttributes.at(temp2));
	}
	return (labels.at(temp2) - res);
}


void SVMClass::claculateAB(const vector<vector<double>> &dataTraining,double b){
	if(dataTraining.empty()){
		cout << "Empty" << endl;
		return;
	}
	vector<double> labels {label(dataTraining)};
	labelsVal = labels;
	vector<vector<double>> actualAttributes {actualAttribute(dataTraining)};
	vector<double> alphas {dualFunction(actualAttributes,labels)};
	b = newBias(labels,actualAttributes,alphas);
	

	cout << "----------------------------------------------------------------" << endl;
	for(size_t i{}; i<alphas.size(); i++){
		cout << "Alpha "<< i+1 << " : " << alphas[i] << endl;
	}
	
	
	
	cout << "----------------------------------------------------------------" << endl;
	cout << "Bias is : " << b << endl;
	cout << "----------------------------------------------------------------" << endl;
	bias = b;
	alphaVal = alphas;
	cout << "----------------------------------------------------------------" << endl;
	int correctPredict {};
	for(size_t i{}; i<alphas.size();i++){
		int temp {inputDecision(alphaVal,labelsVal,dataTraining,actualAttributes[i],bias)};
		if(temp == labels[i]){
			correctPredict++;
		}
	}
	cout << "Predicte Accuracy : " << static_cast<double>(correctPredict)/labels.size() << endl;
}



int SVMClass::inputDecision(vector<double> &alphaVal, vector<double> &labels,const vector<vector<double>> &dataTraining,vector<double> &newData, const double b){
	double res {};
	vector<vector<double>> actualAttributes {actualAttribute(dataTraining)};
	for(size_t i{}; i<alphaVal.size(); i++){
		res += alphaVal[i] * labels[i] * RBFkernel(actualAttributes[i],newData);
	}
	
	res = res + b;
	return res >=0 ? 1 : -1 ;
}



SVMClass::SVMClass()
{
}

SVMClass::~SVMClass()
{
}

