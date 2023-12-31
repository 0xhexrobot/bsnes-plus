#ifndef COLORPREVIEW_H
#define COLORPREVIEW_H

#include<QPaintEvent>
#include<QWidget>

#include "snescolor.moc.hpp"
//#include "snescolor.moc"

class ColorPreview: public QWidget
{
    Q_OBJECT
public:
    QColor qColor;
    ColorPreview(QWidget* parent);
    void paintEvent(QPaintEvent*) override;
    QSize minimumSizeHint() const override;
    QSize sizeHint() const override;
    void setColor(SnesColor color);

public slots:
    void onSnesColorUpdated(int r , int g, int b);
};

#endif // COLORPREVIEW_H
