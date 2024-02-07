#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Exercise {
    private:
        string name; // Name of the exercise (eg. barbell_curls)
        string bodyPart; // Body Part that the exercise targets (eg. Biceps)
        float weight; // Weight that the user is using on the exercise (eg. 20lbs - choose units later?)
    public:

        Exercise();
        Exercise(string name, string bodyPart);
        // Getters
        string getExerciseName();
        string getExerciseBodyPart();
        float getExerciseWeight();

        // Setters
        void setExerciseName(string);
        void setExerciseBodyPart(string); // Eventually change this to a bodyPart object maybe?
        void setExerciseWeight(float);

        // Functions

};