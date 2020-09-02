# My First AI project

## Synopsis

This is a project that I have created to learn and consolidate my knowledge about AI and DQN. It is now still in the work and I want to shear it with whoever is interested (the project is complitly coded by myself and it is all in c++)

## Code Example
This code will allow you to use a pre-trained model or training a agent by yourself in a reinforcement learning environment by self play. The aim of this project is for now to achieve human level skill in Tic_Tac_Toe
Btw I now using a DQN for this is overkill, but I want to learn more and this is the only reason for why I'm doing it 

## Motivation
I'm mostly doing this project as a learning experiences but I also want to shear it with the word

## Installation

**copy the project**
```
git clone https://github.com/Jac-Zac/First_AI_project.git
```
**compile the project (you have to be in the right directory)**
```
make
```
**run the code**
```
./output
```
**clean all component**
```
make clean
```

**To delete the weights file too use**
```
make clean_weights
```

### Usage for testing 
A good easy way to use the program for now is to run the script testing with the command ``` ./testing.sh ```  

The script compiles and run the program and then change the TEST variable. When using this script keep in mind that it is made for MacOS and thus it might cause unexpected behavoiurs on GNU/linux do to the difference of the core utilities (such as ``` sed ``` ).   

### At what point am I ? 🔖

<b>This is my list of GOALS for the foreseeable future <b>

1. I have to look trough the weights file and save them in the right place 
2. I have to figure out how should I copy the network for the Value Net
3. I have to code Back_Prop and than do rigorous testing to make sure it works
4. ... ( There is no point in listing everyithing right now )

<b>this project has just started recently<b>

