#include "exercise.h"

Exercise::Exercise() {

}

Exercise::Exercise(string name, string bodyPart) {
    this->name = name;
    this-> bodyPart = bodyPart;
    this->sets = 3;
    this->reps = 12;
}

string Exercise::getExerciseName() {
    return this->name;
}

string Exercise::getExerciseBodyPart() {
    return this->bodyPart;
}

float Exercise::getExerciseWeight() {
    return this->weight;
}

int Exercise::getExerciseSets() {
    return this->sets;
}

int Exercise::getExerciseReps() {
    return this->reps;
}

void Exercise::setExerciseName(string name) {
    this->name = name;
}

void Exercise::setExerciseBodyPart(string bodyPart) {
    this->bodyPart = bodyPart;
}

void Exercise::setExerciseWeight(float weight) {
    this->weight = weight;
}

void Exercise::setExerciseSets(int sets) {
    this->sets = sets;
}

void Exercise::setExerciseReps(int reps) {
    this->reps = reps;
}