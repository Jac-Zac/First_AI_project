# My First AI project

## Synopsis

This is a project that I have created to learn and consolidate my knowledge about AI and DQN. It is now still in the work and I want to shear it with whoever is interested (the project is completely coded by myself and it is all in C++)

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
A good easy way to use the program for now is to run the script testing with the command  `` ./testing.sh `` The script compiles and run the program and then change the TEST variable. When using this script keep in mind that it is made for MacOS and thus it might cause unexpected behaviours on GNU/Linux do to the difference of the core utilities (such as `` sed `` ).

### Recently added features 
I have just done a bit of cleaning up of the code and comments. I should maybe fix comments a bit more but I'm almost ready to start with the Loss function and BackProp

### At what point am I ? 🔖

###### This is my list of GOALS for the foreseeable future
> Refresh my konwloedge on DQN 

**I should also add a banner perhaps that I can make in affinity photo of for this project**

1. I have start adding more things to the Gradient file and investigate on which is the best Loss function in this case
2. I have to code a loss function -> the loss function has to be in term of the Bellman equation calculated with respect to the value network 
3. I have to code Back_Prop and than do rigorous testing to make sure it works and then unite everything together 
4. I will also add experience replay
5. ... ( There is no point in listing everyithing right now )


#### To do for the future 

Create a replay buffer class and the related components 
Create a multi-threaded function to call epoch with replay buffers with perhaps a large batch size but I have pay attention to the alive variable 

_When you will have finished try to implement it for different tic tac toe rules like the game NOTAKTO_
