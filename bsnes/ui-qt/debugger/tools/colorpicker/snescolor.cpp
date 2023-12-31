#include "snescolor.moc"
#include <math.h>

SnesColor::SnesColor(int value, QObject *parent) : QObject(parent)
{
    r = value & 0x1F;
    g = (value >> 5) & 0x1F;
    b = (value >> 10) & 0x1f;

    calculateHsv();
}

void SnesColor::calculateHsv() {
    float rp = r / 31.0f;
    float gp = g / 31.0f;
    float bp = b / 31.0f;
    float cMax = fmax(fmax(rp,gp), bp);
    float cMin = fmin(fmin(rp,gp), bp);
    float delta = cMax - cMin;

    if(delta == 0)
    {
        hue = 0;
    }
    else if(cMax == rp)
    {
        hue = fmod(((60 * fmod(((gp - bp) / delta), 6)) + 360), 360);
    }
    else if(cMax == gp)
    {
        hue = 60 * ((bp - rp) / delta + 2);
    }
    else if(cMax == bp)
    {
        hue = 60 * ((rp - gp) / delta + 4);
    }

    if(cMax == 0)
    {
        saturation = 0;
    }
    else
    {
        saturation = delta / cMax;
    }

    value = cMax;
}

void SnesColor::calculateRgb()
{
    float c = value * saturation;
    float x = c * (1 - abs(fmod(hue / 60.0f, 2) - 1));
    float m = value - c;
    float rp = 0;
    float gp = 0;
    float bp = 0;

    if(hue >= 0 && hue < 60)
    {
        rp = c;
        gp = x;
        bp = 0;
    }
    else if(hue >= 60 && hue < 120)
    {
        rp = x;
        gp = c;
        bp = 0;
    }
    else if(hue >= 120 && hue < 180)
    {
        rp = 0;
        gp = c;
        bp = x;
    }
    else if(hue >= 180 && hue < 240)
    {
        rp = 0;
        gp = x;
        bp = c;
    }
    else if(hue >= 240 && hue < 300)
    {
        rp = x;
        gp = 0;
        bp = c;
    }
    else if(hue >= 300 && hue <= 360)
    {
        rp = c;
        gp = 0;
        bp = x;
    }

    r = (int)((rp + m) * 255 / 8.0f);
    g = (int)((gp + m) * 255 / 8.0f);
    b = (int)((bp + m) * 255 / 8.0f);
}

QColor SnesColor:: toQColor()
{
    return QColor(r * 8, g * 8, b * 8);
}

void SnesColor::update(int r, int g, int b)
{
    this->r = r;
    this->g = g;
    this->b = b;

    calculateHsv();
}

void SnesColor::setR(int r)
{
    if(this->r != r)
    {
        this->r = r;
        emit updated(r, g, b);
    }
}

void SnesColor::setG(int g)
{
    if(this->g != g)
    {
        this->g = g;
        emit updated(r, g, b);
    }
}

void SnesColor::setB(int b)
{
    if(this->b != b)
    {
        this->b = b;
        emit updated(r, g, b);
    }
}

void SnesColor::setHue(int hue)
{
    if(this->hue != hue)
    {
        this->hue = hue;
        calculateRgb();
        emit updated(r, g, b);
    }
}

void SnesColor::setSaturation(float saturation)
{
    if(this->saturation != saturation)
    {
        this->saturation = saturation;
        calculateRgb();
        emit updated(r, g, b);
    }
}

void SnesColor::setValue(float value)
{
    if(this->value != value)
    {
        this->value = value;
        calculateRgb();
        emit updated(r, g, b);
    }
}

void SnesColor::update(float hue, float saturation, float value)
{
    this->hue = hue;
    this->saturation = saturation;
    this->value = value;

    calculateRgb();
}

int SnesColor::toInt()
{
    return r | (g << 5) | (b << 10);
}

QString SnesColor::toRgbString()
{
    return QString::number(r * 8, 16).rightJustified(2, '0')
           + QString::number(g * 8, 16).rightJustified(2, '0')
           + QString::number(b * 8, 16).rightJustified(2, '0');
}
