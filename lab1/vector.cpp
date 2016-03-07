#include <iostream>
#include <cstdlib>

using namespace std;

class Vector {

public:
    int Dim;
    float *x;
    Vector(){Dim=0; x=NULL;}
    Vector(int Dim);
    Vector(Vector& V);
    Vector(int Dim, float x[]);
    float& operator[](int j){
        if(j < 0 || j >= Dim){
            cout << "Out of range"<<endl;
            exit(1);
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
    Vector operator+ (const Vector &B){ //A+B
        Vector buf(Dim);
        for(int i=0; i<Dim; i++)
            buf.x[i] = x[i]+B.x[i];
        return buf;
    }

    Vector operator- (const Vector &B){ //A-B
        Vector buf(Dim);
        for(int i=0; i<Dim; i++)
            buf.x[i] = x[i]-B.x[i];
        return buf;
    }

    Vector operator* (const Vector &B){ //A*B
        Vector buf(Dim);
        for(int i=0; i<Dim; i++)
            buf.x[i] = x[i]*B.x[i];
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

    friend Vector operator*(int t, const Vector &B);
    friend Vector operator-(int t, const Vector &B);
    friend Vector operator+(int t, const Vector &B);

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

Vector operator* (int t, const Vector &B){
        Vector buf(B.Dim);
        for(int i=0; i<B.Dim; i++)
            buf.x[i] = (float)t*B.x[i];
        return buf;
    }

Vector operator+ (int t, const Vector &B){ //a+B
        Vector buf(B.Dim);
        for(int i=0; i<B.Dim; i++)
            buf.x[i] = (float)t+B.x[i];
        return buf;
    }

Vector operator- (int t, const Vector &B){ //a+B
        Vector buf(B.Dim);
        for(int i=0; i<B.Dim; i++)
            buf.x[i] = (float)t-B.x[i];
        return buf;
    }


int  main()
{
    float x[]={3, 5, 2, 6};
    float y[]={1, 1, 1, -1.4};
    int d = sizeof(x)/4;
    Vector A(d, x),B(d,y),C(d);
    C=A*B;
    C.show();
    C[6] = 1;
    return 0;
}
