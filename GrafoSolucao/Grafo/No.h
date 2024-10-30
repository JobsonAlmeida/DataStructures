#pragma once

#include<iostream>

using namespace std;

typedef string TipoItem;

class No { // in this case we can use structure or class
public:
	TipoItem valor;
	No* proximo;
};