#include "contador.h"

Contador::Contador(int valor, int min, int max) {
    if(min<max) {
        min_=min;
        max_=max;
        if(min_<=valor && valor<=max_) {
            valor_=valor;
        }
        else valor_=0;
    } else {
        min_=0;
        max_=1000;
        valor_=0;
    }
}

void Contador::setValor(int newValor) {
    if(newValor <= min_) {
        valor_ = min_;
    } else if(newValor >= max_) {
        valor_ = max_;
    } else {
        valor_ = newValor;
    }
}

Contador Contador::operator=(int valor) {
    values_.push_back(this->valor_);
    setValor(valor);
    return *this;
}

int Contador::operator=(const Contador contador) {
    values_.push_back(this->valor_);
    *this=contador.get();
    return contador.get();
}

Contador Contador::operator++(void) {
    values_.push_back(this->valor_);
    setValor(get() + 1);
    return *this;
}

Contador Contador::operator++(int) {
    values_.push_back(this->valor_);
    Contador aux = *this;
    setValor(get() + 1);
    return aux;
}

Contador Contador::operator--(void) {
    values_.push_back(this->valor_);
    setValor(get() - 1);
    return *this;
}

Contador Contador::operator--(int) {
    values_.push_back(this->valor_);
    Contador aux = *this;
    setValor(get() - 1);
    return aux;
}

Contador operator+(Contador contador, int number) {
    contador.setValor(number + contador.get());
    return contador;
}

Contador operator+(int number, Contador contador) {
    contador.setValor(number + contador.get());
    return contador;
}

Contador operator-(Contador contador, int number) {
    contador.setValor(contador.get() - number);
    return contador;
}

Contador operator-(int number, Contador contador) {
    contador.setValor(number - contador.get());
    return contador;
}

bool Contador::undo(const int nOperations) {
    if(nOperations>(int)values_.size() || nOperations<1) {
        return false;
    }
    for(int i = 0; i < nOperations-1; i++) {
        values_.pop_back();
    }
    this->valor_=values_.back();
    return true;
}