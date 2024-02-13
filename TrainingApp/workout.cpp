#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "exercise.h"

bool populateExercises(string, vector<Exercise>&);
string convertFileToTxt(string);
void exerciseList(ofstream &, string);
void populateExerciseVector(vector<Exercise>&, ifstream&);
string readString(ifstream&);
void do_it_yourself(vector<Exercise>&);
void do_it_yourself_responses(string, vector<Exercise>&);
void do_it_yourself_resp_1(vector<Exercise>&);
void tutorial_response_2();
void tutorial_response_3();
void tutorial_response_4();
void tutorial_response_5();
void create_workout_program(int, int, int, vector<Exercise>&);

int main() {
    // Vector of exercise objects
    vector<Exercise> workout;
    populateExercises("exercises.txt", workout); //works

    //tutorial
    string resp = "";
    cout << "Hello! Would you like to go through a tutorial or play around for yourself? (tutorial/self): ";
    cin >> resp;
    for (int i = 0; i < int(resp.length()); i++)
    {
        resp.at(i) = toupper(resp.at(i));
    }
    if(resp == "SELF" || resp == "S") {
        do_it_yourself(workout);
    }
    return 0;
}

// Populates vector of exercises
bool populateExercises(string exerciseFile, vector<Exercise> &workout) {
    ifstream fileReader;
    ofstream fileWriter;
    exerciseFile = convertFileToTxt(exerciseFile);
    fileReader.open(exerciseFile);
    bool run_before = fileReader.is_open();
    if(!run_before) { //couldn't find file
        exerciseList(fileWriter, exerciseFile);
    }
    populateExerciseVector(workout, fileReader);
    fileReader.close();
    return !run_before;
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
// Runs do it yourself
void do_it_yourself(vector<Exercise> &exercises) {
    string resp = "0";
    cout << "1. Create a New Workout Program (Helps you do it!)" << endl;
    // cout << "2. Edit Existing Workout Program (Made a mistake? Fix it!)" << endl;
    // cout << "3. Import External Workout Program (We're flexible, but verify the results)" << endl;
    // cout << "4. Give Feedback on Existing Workout Program (Something Wrong?)" << endl;
    // cout << "5. Create Program Without Help (Explore for yourself, but be careful!)" << endl;
    cin >> resp;
    do_it_yourself_responses(resp, exercises);
}

void do_it_yourself_responses(string resp, vector<Exercise> &exercises) {
    if(resp == "1") { //Create new program
        //call func for resp1 here
        do_it_yourself_resp_1(exercises);
    }
     else if(resp == "2") { //Edit program
        // call func for resp2 here
        cout << "Still in progress" << endl;
    } else if(resp == "3") { //Import external program
        // call func for resp3 here
        cout << "Still in progress" << endl;
    } else if(resp == "4") { //feedback on existing program
        //call func for resp4 here
        cout << "Still in progress" << endl;
    } else if (resp == "5") {
        //call func for resp5 here
        cout << "Still in progress" << endl;
    }
    else { //invalid input
        do_it_yourself(exercises);
    }
}

// Create New Program
void do_it_yourself_resp_1(vector<Exercise> &exercises) {
    int resp1 = 0, resp2 = 0, resp3 = 0;
    cout << "How many days per week can you make it to the gym FOR SURE? (1-7): " << endl;
    cin >> resp1;
    while(resp1 > 7 || resp1 < 1) {
        cout << "Response must be from 1-7 days inclusive: " << endl;
        cin >> resp1;
    }
    cout << "How long would you like each workout to last? (30-90 minutes): " << endl;
    cin >> resp2;
    while(resp2 > 90 || resp2 < 30) {
        cout << "Response must be from 30-90 minutes inclusive" << endl;
        cin >> resp2;
    }
    cout << "How many exercises would you like to do? (2-5): " << endl;
    cin >> resp3;
    while(resp3 > 5 || resp3 < 2) {
        cout << "Response must be from 2-5 exercises inclusive: " << endl;
        cin >> resp3;
    }
    create_workout_program(resp1, resp2, resp3, exercises);
}

void create_workout_program(int days, int minutes, int numExercises, vector<Exercise> &exercises) {
    string workoutDays = "";
    vector<char> dayList;
    vector<vector<Exercise> > fullWorkout;
    //time estimation = sets * 3 minutes * numexercises
    cout << "Which days would you like to workout on?: (M,Tu,W,Th,F,Sa,Su = 0,1,2,3,4,5,6)" << endl;
    cout << "Example Input: \"0,2,4\" <-- (M,W,F)" << endl;
    cin >> workoutDays;
    for (int i = 0; i < int(workoutDays.length()); i++)
    {
        if(workoutDays.at(i) == ',') {
            dayList.push_back(workoutDays.at(i-1));
        }
        if(i == int(workoutDays.length()) - 1) {
            dayList.push_back(workoutDays.at(i));
        }
    }
    srand(time(NULL));
    for (int i = 0; i < days-1; i++)
    {
        fullWorkout.resize(days-1);
        for (int j = 0; j < numExercises; j++) {  
            int randomExerciseNum = rand() % (exercises.size() - 1);
            Exercise e = exercises.at(randomExerciseNum);
            fullWorkout.at(i).push_back(e);
    }
    }
    cout << "+=+=+ Workout Program +=+=+" << endl;
    for (int i = 0; i < days-1; i++)
    {
        cout << "Day " << i+1 << ": "<< endl;
        int length = 0;
        for (int j = 0; j < numExercises; j++)
        {
            cout << "   Exercise: " << fullWorkout.at(i).at(j).getExerciseName() << "   Sets: " << fullWorkout.at(i).at(j).getExerciseSets() << "   Reps: " << fullWorkout.at(i).at(j).getExerciseReps() << endl;
            length += fullWorkout.at(i).at(j).getExerciseSets();
        }
        length *= 3; // average set rest time is 3 minutes, so each set will have 3 minute rest time
        cout << " Day " << i+1 << " Length: " << length << " minutes" << endl;
    }
    cout << "+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl;
}

void write_workout_to_file() {

}