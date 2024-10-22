#include "SVMClass.h"


int main() {
	cout << boolalpha;
		SVMClass SVM;
		
	vector<vector<double>> dataTraining = {
    {4.232, 1.342, 7.21, 1},
    {2.21, 1.21, 3.1, -1},
    {1.32, 5.21, 5.132, 1},
    // More dataTraining points...
};

	vector<vector<double>> PredictionData = {
    {1.32, 6.2, 7.21},
    {2.21, 1.43, 9.1},
    {5.36, 5.21, 7.11},
	{2.36, 1.21, 3.11}
};
		SVM.claculateAB(dataTraining,0);
		cout << "---------------------------------------------------" << "\n" << "---------------------------------------------------" << endl;
			for(size_t i{}; i<PredictionData.size(); i++){
			cout<<SVM.inputDecision(SVM.alphaVal,SVM.labelsVal,dataTraining,PredictionData[i],SVM.bias) << endl;
		}


	return 0;
}