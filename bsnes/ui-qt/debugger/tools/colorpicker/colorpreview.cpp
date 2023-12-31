#include "colorpreview.moc"

#include <QPainter>

ColorPreview::ColorPreview(QWidget* parent) : QWidget(parent) {}

QSize ColorPreview::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize ColorPreview::sizeHint() const
{
    return QSize(100, 100);
}

void ColorPreview::paintEvent(QPaintEvent*)
{
    QRect rect (0, 0, this->width() - 1, this->height() - 1);
    QPainter painter(this);
    QBrush brush = QBrush(qColor);

    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRect(rect);
}

void ColorPreview::setColor(SnesColor color)
{
    qColor = QColor(color.getR(), color.getG(), color.getB());
}

void ColorPreview::onSnesColorUpdated(int r, int g, int b)
{
    qColor.setRed(r * 8);
    qColor.setGreen(g * 8);
    qColor.setBlue(b * 8);

    repaint();
}
