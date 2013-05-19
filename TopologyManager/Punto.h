#ifndef PUNTO_H
#define PUNTO_H


class Punto
{
    public:
        Punto();
        Punto(double X,double Y);
        double calcDist(Punto p);
        double getX();
        double getY();
        void setX(double X);
        void setY(double Y);
        double coordinataX;
        double coordinataY;

};

#endif
