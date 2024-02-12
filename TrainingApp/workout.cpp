#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "exercise.h"

void populateExercises(string, vector<Exercise>);
string convertFileToTxt(string);
void exerciseList(ofstream &, string);
void populateExerciseVector(vector<Exercise>&, ifstream&);
string readString(ifstream&);

int main() {
    // Vector of exercise objects
    vector<Exercise> workout;

    populateExercises("exercises.txt", workout); //works
    return 0;
}

// Populates vector of exercises
void populateExercises(string exerciseFile, vector<Exercise> workout) {
    ifstream fileReader;
    ofstream fileWriter;
    exerciseFile = convertFileToTxt(exerciseFile);
    fileReader.open(exerciseFile);
    if(!fileReader.is_open()) { //couldn't find file
        exerciseList(fileWriter, exerciseFile);
    }
    populateExerciseVector(workout, fileReader);
    fileReader.close();
}

string convertFileToTxt(string exerciseFile) {
    if(exerciseFile.find(".txt") == string::npos) { //didnt find .txt at the end
        exerciseFile.append(".txt");
    }
    return exerciseFile;
}

void exerciseList(ofstream &fileWriter, string exerciseFile) { // Store as "muscle,exerciseName"
    vector<string> exercises;
    exercises.push_back("quadriceps,squat");
    exercises.push_back("hamstrings,leg_curl");
    exercises.push_back("calves,calf_raise");
    exercises.push_back("glutes,lunge");
    exercises.push_back("chest,bench_press");
    exercises.push_back("triceps,tricep_extension");
    exercises.push_back("biceps,curl");
    exercises.push_back("shoulders,overhead_press");

    int exerciseNum = exercises.size();
    fileWriter.open(exerciseFile);
    cout << "Opened " << exerciseFile << endl;
    for (int i = 0; i < exerciseNum; i++)
    {
        fileWriter << exercises.at(i) << endl;
        cout << "Wrote " << exercises.at(i) << " to " << exerciseFile << endl;
    }
    fileWriter.close();
    cout << "Closed " << exerciseFile << endl;
    
}

void populateExerciseVector(vector<Exercise> &exerciseVector, ifstream& fileReader) {
    
    string output = "";
    stringstream ss;

    while(getline(fileReader, output)) {
        string bodyPart = "";
        string name = "";
        int commaSpot = output.find(',');
        for (int i = 0; i < commaSpot; i++)
        {
            bodyPart += output.at(i);
        }
        for (int i = commaSpot+1; i < int(output.length()); i++)
        {
            name += output.at(i);
        }
        
        Exercise *e = new Exercise(name, bodyPart); // by this point both will be filled
        exerciseVector.push_back(*e); //de-ref e
    }
    
}