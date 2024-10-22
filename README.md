# Non-Linear-SVM
## Implementation of flexible Non-Linear SVM using RBF kernel in C++

### Description
#### This project is about a Non-Linear support vector machine (SVM) using Radial Basis Function (RBF) it will classify non-linear classes which is an improvement of the conversional SVM by solving the dual problem and finding the optimal bias for the decision to be accurate  

### Features
###   -RBF Karnel: Calculates the similarity between 2 points
###   -Dual Optimization: Iterates to find the optimal Lagrange multipliers 
###   -Bias: Calculates the Bias to be used for the Decision


```cpp
	vector<vector<double>> dataTraining = {
    {4.232, 1.342, 7.21, 1},
    {2.21, 1.21, 3.1, -1},
    {1.32, 5.21, 5.132, 1},
    // More dataTraining points...
};```
