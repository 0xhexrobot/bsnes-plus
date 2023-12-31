#ifndef SNESCOLORPICKER_H
#define SNESCOLORPICKER_H

#include <QDialog>
#include <QIntValidator>
#include "snescolor.moc.hpp"
#include "colorpreview.moc.hpp"

namespace Ui {
class SnesColorPicker;
}

class SnesColorPicker : public QDialog
{
    Q_OBJECT

public:
    SnesColor* snesColor;
    ColorPreview* colPrev;
    explicit SnesColorPicker(QWidget *parent = nullptr, SnesColor* color = nullptr);
    ~SnesColorPicker();

private slots:
    void onAccepted();
    void onRejected();
    void onSlRgbValueChanged(int value);
    void onRgbTextEdited(const QString &newText);
    void onHueTextEdited(const QString &newText);
    void onSatValueTextEdited(const QString &newText);
    void currentChanged(int index);
    void onSlHueValueChanged(int value);
    void onSlSatValueChanged(int value);
    void onSlValValueChanged(int value);

private:
    Ui::SnesColorPicker *ui;
    QIntValidator* rgbValidator = new QIntValidator(0, 31, this);
    QIntValidator* hueValidator = new QIntValidator(0, 360, this);
    QIntValidator* satValueValidator = new QIntValidator(0, 100, this);
    void updateRgbControls();
    void updateHsvControls();
};

#endif // SNESCOLORPICKER_H
