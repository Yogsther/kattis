#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Variable{
    public:
        string name;
        int value;
};

vector<Variable> variables;


/**
 * Return index of variable with that name, if it's missing, the index will be -1.
 */

int getVariable(string name){
    for(int i = 0; i < variables.size(); i++){
        if(variables.at(i).name == name) return i;
    }
    return -1;
}

int getVariable(int value){
    for(int i = 0; i < variables.size(); i++){
        if(variables.at(i).value == value) return i;
    }
    return -1;
}


int main(){

    while(cin){
        string input;
        cin >> input;

        /**
         *  Define a variable
         */ 
        if(input == "def"){
            string name;
            int value;
            cin >> name >> value;
            int index = getVariable(name);
            if(index == -1){
                Variable variable;
                variable.name = name;
                variable.value = value;
                variables.push_back(variable);
            } else {
                variables.at(index).value = value;
            }

        } else if(input == "calc"){
            int total = 0;
            bool failed = false;
            string totalString;
            string lastOperator = "+";

            while(cin){

                string input;
                cin >> input;
                
                if(input == "+" || input == "-"){
                    lastOperator = input;
                    totalString+=" " + input + " ";
                } else if(input == "="){
                    string answerWord = "unknown";
                    int answerIndex = getVariable(total);
                    if(!failed && answerIndex != -1) answerWord = variables.at(answerIndex).name;
                    totalString += " = " + answerWord;
                    cout << totalString << endl; // Answer
                    break;
                } else {
                    int index = getVariable(input);
                    if(index != -1){
                        if(lastOperator == "+") total += variables.at(getVariable(input)).value;
                        if(lastOperator == "-") total -= variables.at(getVariable(input)).value;
                    } else {
                        failed = true;
                    }
                    totalString +=input;
                } 
            }
        } else if(input == "clear"){
            variables.clear();
        }
    }

}


