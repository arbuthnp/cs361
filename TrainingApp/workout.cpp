#include <iostream>
#include <fstream>
#include <string>
#include "exercise.h"

void populateExercises(string);
string convertFileToTxt(string);
void exerciseList(ofstream &, string);
void populateExerciseVector(vector<Exercise*>);

int main() {
    // Vector of exercise objects
    vector<Exercise*> workout;

    populateExercises("exercises.txt"); //works



    return 0;
}

// Populates vector of exercises
void populateExercises(string exerciseFile) {
    ifstream fileReader;
    ofstream fileWriter;
    exerciseFile = convertFileToTxt(exerciseFile);
    fileReader.open(exerciseFile);
    if(!fileReader.is_open()) { //couldn't find file
        exerciseList(fileWriter, exerciseFile);
    }
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

string readString(ifstream &fileReader) {
    char buf[256];
    fileReader.getline(&(buf[0]), 256, ',');
    return string(buf);
}

void populateExerciseVector(vector<Exercise> &workout, ifstream& fileReader, string exerciseFile) {
    fileReader.open(exerciseFile);
    if(fileReader.is_open()) {
        while(1) {
            int i = 0;
            string exercisePart = readString(fileReader);
            if (fileReader.eof()) { // at the end of file
                break;
            }
            Exercise* e = new Exercise(exercisePart, exercisePart); //this wont work now
            if (i % 2 == 0) {

            }
            
        }
    }
}