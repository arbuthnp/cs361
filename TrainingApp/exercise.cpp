#include "exercise.h"

Exercise::Exercise() {

}

Exercise::Exercise(string name, string bodyPart) {
    this->name = name;
    this-> bodyPart = bodyPart;
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

void Exercise::setExerciseName(string name) {
    this->name = name;
}

void Exercise::setExerciseBodyPart(string bodyPart) {
    this->bodyPart = bodyPart;
}

void Exercise::setExerciseWeight(float weight) {
    this->weight = weight;
}