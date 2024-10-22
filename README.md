# Non-Linear-SVM
## Implementation of flexible Non-Linear SVM using RBF kernel in C++

### Description
#### This project is about a Non-Linear support vector machine (SVM) using Radial Basis Function (RBF) it will classify non-linear classes which is an improvement of the conventional SVM by solving the dual problem and finding the optimal bias for the decision to be accurate  

### Features
####   -RBF Karnel: Calculates the similarity between 2 points
####   -Dual Optimization: Iterates to find the optimal Lagrange multipliers 
####   -Bias: Calculates the Bias to be used for the Decision
####   -Adjusting Gamma,Regulaization and learning Rate

### Example of Data Training:
```cpp
vector<vector<double>> dataTraining = {
    {4.232, 1.342, 7.21, 1},
    {2.21, 1.21, 3.1, -1},
    {1.32, 5.21, 5.132, 1},
    // More dataTraining points...
};
```

### How does it work:
#### 	-Seprates the labels and the Attributes from the Data Training
#### 	-Uses RBF kernel to calculate the similarity between 2 points
#### 	-Uses dual optimaization function to find the optimal Lagrange multipliers ( by using the RBF kernel )
#### 	-Calculates the Bias
#### 	-Predicits the provided input 1 as positive -1 as negative

### Example of Data to be Predicted:
```cpp
vector<vector<double>> PredictionData = {
    {1.32, 6.2, 7.21},
    {2.21, 1.43, 9.1},
    {5.36, 5.21, 7.11},
    {2.36, 1.21, 3.11}
};
```

### Example Output
----------------------------------------------------------------
Alpha 1 : 0.909057,
Alpha 2 : 1,
Alpha 3 : 0.909741
----------------------------------------------------------------
Bias is : 0.156754
----------------------------------------------------------------
----------------------------------------------------------------
Predicte Accuracy : 1
---------------------------------------------------
---------------------------------------------------
1
1
1
-1

### as shown the first line is showing the alphas (Lagrange multipliers), second line is the optimal Bias, third line is the Accuracy, last couple lines are the prediction of unseen Data
