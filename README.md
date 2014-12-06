## Project Euler in C++

Welcome!  This is my implementation of the [Project Euler problems](http://projecteuler.net) using C++.  I decided to use C++ for this task as it can be computationally as fast as C, and thought it would be fun to attempt some performance related tweaks as well as learn about the `std` library.

### Building the Project

Building the project is simple, and is meant to be built under Linux (or Cygwin in Windows) using `g++`.  You can clone the project directly from this repo and run `make` in the project directory:

	> git clone https://github.com/brendanbates89/project-euler
	> cd project-euler
	> make

The executable and all shared libraries will be available in the `build` folder, and you can run the executable right from the project directory:

	> build/project-euler 

To build a single problem, you can use the following syntax, replacing `1` with the problem number to be built.  The problem loader can also be built individually.

	> make problem1
	> make loader



### Project Architecture

To avoid lengthened build times as the number of problems increased, I used the [`dl*`](http://tldp.org/HOWTO/Program-Library-HOWTO/dl-libraries.html) functions to dynamically link individual problems at runtime.  This allows the option to build individual problems.

#### The AbstractProblem

This architecture is achieved by using an `AbstractProblem` class.  This is a class which all ProjectEuler problems must extend in order to be loaded, and provides a few common methods for the loader to access:


    virtual void GetInputs() = 0;
    virtual void GetAnswer() = 0;
    virtual void Execute() = 0;
    
    std::string* GetProblemName() { return this->ProblemName; }
    uint32_t GetProblemNumber() { return this->ProblemNumber; }
    void SetFunctions(Functions* projectFunctions) { this->ProjectFunctions = projectFunctions; }

In addition, all ProjectEuler problems must implement a global function named `factory`.  The purpose of the factory function is to return a new instance of itself.  A macro was created to easily create a factory for an AbstractProblem class:

	FACTORY(Problem17)

This will provide a `factory` function to create a new instance of the `Problem17` class. 

#### Dynamic Linking 
	
The user chooses the problem to run, and the `.so` file is located and loaded using `dlopen`.

    handle = dlopen(module, RTLD_NOW);	

The `factory` function must then be linked so that a new instance of the class can be created: 

    factory = (FactoryPtr)dlsym(handle, "factory");

Assuming this didn't error, there is now a function pointer to this factory method, and we can use it to get a new instance of the chosen problem.

    selectedProblem = (*factory)();

From here, we can treat the `AbstractFactory` as if it were a normal object and call the virtual functions such as `GetInputs` or `Execute`.
	
    start = time(0);
    selectedProblem->problem->Execute();
    end = time(0);