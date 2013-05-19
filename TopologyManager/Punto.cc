#include <Punto.h>
#include <math.h>


Punto::Punto()
{
    coordinataX=0;
    coordinataY=0;
}

Punto::Punto(double X,double Y)
{
    coordinataX=X;
    coordinataY=Y;
}

void Punto::setX(double X)
{
    coordinataX=X;
}

void Punto::setY(double Y)
{
    coordinataY=Y;
}

double Punto::getX()
{
    return coordinataX;
}

double Punto::getY()
{
    return coordinataY;
}

double Punto::calcDist(Punto p)
{
    double l;
    double h;
    double dist;
    l=fabs(p.coordinataX-coordinataX);
    h=fabs(p.coordinataY-coordinataY);
    dist=sqrt(l*l+h*h);
    return dist;
}
