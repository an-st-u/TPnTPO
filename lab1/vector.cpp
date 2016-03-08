#include <iostream>
#include <cstdlib>
#define MAX 2147483647.0
#define MIN -2147483648.0

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
    ~Vector();

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

    Vector operator+ (const Vector &B){ //A+B
        Vector buf(Dim);
        for(int i=0; i<Dim; i++)
            buf.x[i] = x[i]+B.x[i];
        return buf;
    }

    float operator, (const Vector &B){ //A,B
        Vector buf(1);
        for(int i=0; i<Dim; i++)
            buf.x[0]+= x[i]*B.x[i];
        return buf.x[0];
    }

    Vector operator- (const Vector &B){ //A-B

        Vector buf(Dim);
        for(int i=0; i<Dim; i++) {
            buf.x[i] = x[i]-B.x[i];
        }
        return buf;
    }

    Vector operator- (){ //-A

        Vector buf(Dim);
        for(int i=0; i<Dim; i++) {
            buf.x[i] = -x[i];
        }
        return buf;
    }


    Vector operator* (const Vector &B){ //A*B
        Vector buf(Dim);
        double test;
        for(int i=0; i<Dim; i++) {
            test = x[i]*B.x[i];
            if ((test < MIN) || (test > MAX)) {
              cout << "Выход за диапазон"<<endl;
              exit(1);
            }
            buf.x[i]=test;
        }
        return buf;
    }

    Vector operator* (int t){ //B*C
        Vector buf(Dim);
        for(int i=0; i<Dim; i++) {
            buf.x[i] = x[i]*t;
        }
        return buf;
    }

    friend void operator<<(ostream& os, const Vector &B);
    friend Vector operator*(int t, const Vector &B);

};

Vector::Vector(int D){
    Dim = D;
    x = new float[Dim];
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

Vector operator* (int t, const Vector &B){ //C*B
        Vector buf(B.Dim);
        for(int i=0; i<B.Dim; i++)
            buf.x[i] = t*B.x[i];
        return buf;
    }

void operator<<(ostream& os, const Vector &B) {
    for (int i=0;i<B.Dim;i++)
        os << B.x[i] << " ";
    os << endl;
}

int  main()
{
    float x[]={3, 5, 2, 6};
    float y[]={1, 1, 1, -1.4};
    int d = 4;
    Vector A(d, x),B(d, y),C(d);
    C=-A+2*A-A+B*2;
    cout << C;
    C[0]=(A,B);
    cout << C[0] << endl;
    C[6] = 1;
    return 0;
}
