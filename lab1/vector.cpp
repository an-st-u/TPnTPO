#include <iostream>
#include <stdio.h>

using namespace std;

class Vector {

private:

    int Dim;
    float *x;
public:

    Vector(){Dim=0; x=NULL;}
    Vector(int Dim);
    Vector(Vector& V);
    Vector(int Dim, float x[]);
    float& operator[](int j){
        if(j < 0 || j >= Dim){
            cout << "выход за диапазон";
        }
        return x[j];
    }

    Vector& operator= (const Vector& V) {
        if(Dim!=V.Dim){
            cout << "Error in dimensions";
        }
        Dim=V.Dim;
        for(int i=0; i<Dim; i++)
            x[i] = V.x[i];
        return (*this);
    }
    ~Vector();
    Vector operator+ (const Vector &B){ //a+B
        Vector buf(Dim);
        for(int i=0; i<Dim; i++)
            buf.x[i] = x[i]+B.x[i];
        return buf;
    }

    /*float& operator, (const Vector &B){ //a+B
        Vector buf(Dim);
        for(int i=0; i<Dim; i++)
            buf.x[0] += x[i]*B.x[i];
        return buf.x[0];
    }*/


    void show() {
        for(int i=0;i<Dim;i++)
            cout << x[i] << endl;
    }


};

Vector::Vector(int Dim){
    this->Dim = Dim;
    x = new float(Dim);
};

Vector::~Vector(){
    delete[] x;
}

Vector::Vector(int Dim, float x[]) {
    this->Dim = Dim;
    this->x = new float[Dim];
    for (int i=0; i<Dim ; i++){
        this->x[i] = x[i];
    }
}


int  main()
{
    float x[]={3, 5, 2, 6};
    float y[]={1, 1, 1, -1.4};
    int d = sizeof(x)/4;
    Vector A(d, x),B(d,y),C(d);
    C=A+B;
    // C[6] = 1; ошибка!!
    C.show();
    return 0;
}
