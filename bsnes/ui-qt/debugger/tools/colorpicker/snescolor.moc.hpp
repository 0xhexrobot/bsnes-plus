#ifndef SNESCOLOR_HPP
#define SNESCOLOR_HPP

#include <QObject>
#include <QColor>

class SnesColor :public QObject
{
    Q_OBJECT

public:
    SnesColor(int value, QObject *parent = nullptr);
    QColor toQColor();
    void update(int r, int g, int b);
    void update(float hue, float saturation, float value);
    int getR() { return r; };
    int getG() { return g; };
    int getB() { return b; };
    float getHue() { return hue; };
    float getSaturation() { return saturation; };
    float getValue() { return value; };
    void setR(int r);
    void setG(int g);
    void setB(int b);
    void setHue(int hue);
    void setSaturation(float saturation);
    void setValue(float value);
    int toInt();
    QString toRgbString();

signals:
    void updated(int r, int g, int b);

private:
    int r;
    int g;
    int b;
    int hue;
    float saturation;
    float value;
    void calculateHsv();
    void calculateRgb();
};

#endif // SNESCOLOR_HPP
