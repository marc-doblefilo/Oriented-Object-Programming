#include "dados.h"
#include <iostream>
#include <ctime>


Dados::Dados() {
    srand(time(NULL));
    dice1_=1;
    dice2_=1;
    d1_vect_[0] = dice1_;
    d2_vect_[0] = dice2_;
    d1_counter_ = 0;
    d2_counter_ = 0;
    d1_media_ = 0;
    d2_media_ = 0;
};

int Dados::getDado1() {
    return dice1_;
};

int Dados::getDado2() {
    return dice2_;
};

bool Dados::setDado1(int n) {

    if( n > 6 || n < 1) {
        return false;
    }
    dice1_ = n;
    d1_counter_ += 1;
    d1_media_ += dice1_;
    for(int i = 4; i > 0; i--) {
        d1_vect_[i] = d1_vect_[i-1]; 
    }
    d1_vect_[0] = dice1_;
    return true;
};

bool Dados::setDado2(int n) {

    if( n > 6 || n < 1) {
        return false;
    }
    dice2_ = n;
    d2_counter_++;
    d2_media_ += dice2_;
    for(int i = 4; i > 0; i--) {
        d2_vect_[i] = d2_vect_[i-1]; 
    }
    d2_vect_[0] = dice2_;
    return true;
};

int Dados::getSuma() {
    return dice1_ + dice2_;
};

void Dados::lanzamiento() {
    dice1_ = rand() % 6 + 1;
    dice2_ = rand() % 6 + 1;
    d1_counter_++;
    d2_counter_++;
    d1_media_ += dice1_;
    d2_media_ += dice2_;
    for(int i = 4; i > 0; i--) {
        d1_vect_[i] = d1_vect_[i-1]; 
    }
    d1_vect_[0] = dice1_;
    for(int i = 4; i > 0; i--) {
        d2_vect_[i] = d2_vect_[i-1]; 
    }
    d2_vect_[0] = dice2_;
};

int Dados::getDiferencia() {
    if( dice1_ > dice2_ ) {
        return (dice1_ - dice2_);
    } else {
        return (dice2_ - dice1_);
    }
};

int Dados::getLanzamientos1() {
    return d1_counter_;
}

int Dados::getLanzamientos2() {
    return d2_counter_;
}

float Dados::getMedia1() {
    if(d1_counter_ == 0) {
        return d1_media_;
    } else {
        return d1_media_ / d1_counter_;
    }
}

float Dados::getMedia2() {
    if(d2_counter_ == 0) {
        return d2_media_;
    } else { 
        return d2_media_ / d2_counter_;
    }
}

int * Dados::getUltimos1(int arr[]) {
    for(int i = 0; i < 5; i++) {
        arr[i] = d1_vect_[i];
    }
    return arr;
}

int * Dados::getUltimos2(int arr[]) {
    for(int i = 0; i < 5; i++) {
        arr[i] = d2_vect_[i];
    }
    return arr;
}