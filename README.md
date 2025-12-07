MLP Neural Network – C++ Implementation
------------------------------------------------------------

This project is an academic implementation of a Multilayer Perceptron (MLP) neural network in C++.
It includes matrix operations, activation functions, dense layers, and an inference module, all written in a modular and object-oriented design.

Project Structure
-----------------
Activation.h / Activation.cpp – Implementation of activation functions (ReLU, Softmax)  
Dense.h / Dense.cpp – Dense layer class, including weights, bias, and activation  
Matrix.h / Matrix.cpp – Custom Matrix class with basic linear algebra operations  
MlpNetwork.h / MlpNetwork.cpp – End-to-end neural network inference module  
Makefile – Build script for compiling the project

Features
--------
- Custom Matrix class supporting mathematical operations  
- ReLU and Softmax activation functions  
- Dense (fully connected) layer abstraction  
- Forward pass implementation through a four-layer neural network  
- Modular, extensible, and object-oriented C++ design

Compilation
-----------
To build the project, run the following command:

make mlpnetwork

This will compile all source files and generate the network executable as defined in the Makefile.

Notes
-----
- The main.cpp file used for testing is intentionally not included, following assignment requirements.  
- This project was developed as part of an academic exercise focusing on memory management, modularity, and clean C++ software design.

Author
------
Laura Bensimon  
Computer Science and Data Science student  
Hebrew University of Jerusalem
