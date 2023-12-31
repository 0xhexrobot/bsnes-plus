//#include "snescolorpicker.h"
//#include "ui_snescolorpicker.h"
//#include "snescolorpicker.moc"
#include "snescolorpicker.moc"
#include "colorpreview.cpp"
#include "ui_snescolorpicker.cpp"

SnesColorPicker::SnesColorPicker(QWidget *parent, SnesColor* color) :
    QDialog(parent),
    ui(new Ui::SnesColorPicker)
{
    ui->setupUi(this);
    snesColor = color;
    colPrev = ui->wColorPrev;
    colPrev->qColor = QColor(snesColor->getR() * 8, snesColor->getG() * 8, snesColor->getB() * 8);

    // validators
    // rgb
    ui->txtRed->setValidator(rgbValidator);
    ui->txtGreen->setValidator(rgbValidator);
    ui->txtBlue->setValidator(rgbValidator);
    // hsv
    ui->txtHue->setValidator(hueValidator);
    ui->txtSat->setValidator(satValueValidator);
    ui->txtValue->setValidator(satValueValidator);

    updateRgbControls();

    // signals / slots
    // tabs
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &SnesColorPicker::currentChanged);
    // accept, reject
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SnesColorPicker::onAccepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &SnesColorPicker::onRejected);
    // rgb sliders
    connect(ui->slRed, &QSlider::valueChanged, this, &SnesColorPicker::onSlRgbValueChanged);
    connect(ui->slGreen, &QSlider::valueChanged, this, &SnesColorPicker::onSlRgbValueChanged);
    connect(ui->slBlue, &QSlider::valueChanged, this, &SnesColorPicker::onSlRgbValueChanged);
    // rgb line edits
    connect(ui->txtRed, &QLineEdit::textEdited, this, &SnesColorPicker::onRgbTextEdited);
    connect(ui->txtGreen, &QLineEdit::textEdited, this, &SnesColorPicker::onRgbTextEdited);
    connect(ui->txtBlue, &QLineEdit::textEdited, this, &SnesColorPicker::onRgbTextEdited);
    // hsv sliders
    connect(ui->slHue, &QSlider::valueChanged, this, &SnesColorPicker::onSlHueValueChanged);
    connect(ui->slSat, &QSlider::valueChanged, this, &SnesColorPicker::onSlSatValueChanged);
    connect(ui->slValue, &QSlider::valueChanged, this, &SnesColorPicker::onSlValValueChanged);
    // hsv line edits
    connect(ui->txtHue, &QLineEdit::textEdited, this, &SnesColorPicker::onHueTextEdited);
    connect(ui->txtSat, &QLineEdit::textEdited, this, &SnesColorPicker::onSatValueTextEdited);
    connect(ui->txtValue, &QLineEdit::textEdited, this, &SnesColorPicker::onSatValueTextEdited);
    // color preview
    connect(snesColor, &SnesColor::updated, colPrev, &ColorPreview::onSnesColorUpdated);
}

SnesColorPicker::~SnesColorPicker()
{
    delete ui;
}

void SnesColorPicker::onAccepted()
{
    this->accept();
}

void SnesColorPicker::onRejected()
{
    this->reject();
}

void SnesColorPicker::updateRgbControls() {
    ui->slRed->blockSignals(true);
    ui->slGreen->blockSignals(true);
    ui->slBlue->blockSignals(true);

    int r = snesColor->getR();
    int g = snesColor->getG();
    int b = snesColor->getB();

    ui->slRed->setValue(r);
    ui->txtRed->setText(QString::number(r));
    ui->slGreen->setValue(g);
    ui->txtGreen->setText(QString::number(g));
    ui->slBlue->setValue(b);
    ui->txtBlue->setText(QString::number(b));

    ui->slRed->blockSignals(false);
    ui->slGreen->blockSignals(false);
    ui->slBlue->blockSignals(false);
}

void SnesColorPicker::updateHsvControls() {
    ui->slHue->blockSignals(true);
    ui->slSat->blockSignals(true);
    ui->slValue->blockSignals(true);

    int hue = (int)snesColor->getHue();
    int saturation = snesColor->getSaturation() * 100;
    int value = snesColor->getValue() * 100;

    ui->slHue->setValue(hue);
    ui->txtHue->setText(QString::number(hue));
    ui->slSat->setValue(saturation);
    ui->txtSat->setText(QString::number(saturation));
    ui->slValue->setValue(value);
    ui->txtValue->setText(QString::number(value));

    ui->slHue->blockSignals(false);
    ui->slSat->blockSignals(false);
    ui->slValue->blockSignals(false);
}

void SnesColorPicker::onSlRgbValueChanged(int value)
{
    QObject* sender = QObject::sender();
    QString textValue = QString::number(value);

    if(sender == ui->slRed)
    {
        snesColor->setR(value);
        ui->txtRed->setText(textValue);
    }
    else if(sender == ui->slGreen)
    {
        snesColor->setG(value);
        ui->txtGreen->setText(textValue);
    }
    else if(sender == ui->slBlue)
    {
        snesColor->setB(value);
        ui->txtBlue->setText(textValue);
    }
}

void SnesColorPicker::onSlHueValueChanged(int value)
{
    snesColor->setHue(value);
    ui->txtHue->setText(QString::number(value));
}

void SnesColorPicker::onSlSatValueChanged(int value)
{
    snesColor->setSaturation(value / 100.0f);
    ui->txtSat->setText(QString::number(value));
}

void SnesColorPicker::onSlValValueChanged(int value)
{
    snesColor->setValue(value / 100.0f);
    ui->txtValue->setText(QString::number(value));
}

void SnesColorPicker::currentChanged(int index)
{
    if(index == 0)
    {
        // click on rgb tab
        snesColor->update((float)ui->slHue->value(), ui->slSat->value() / 100.0f, ui->slValue->value() / 100.0f);
        updateRgbControls();
    }
    else if(index == 1)
    {
        // click on hsv tab
        snesColor->update(ui->slRed->value(), ui->slGreen->value(), ui->slBlue->value());
        updateHsvControls();
    }
}

void SnesColorPicker::onRgbTextEdited(const QString &newText)
{
    int pos = 0;
    QString str = newText;
    QValidator::State validation = rgbValidator->validate(str, pos);
    QObject* sender = QObject::sender();

    if(validation == QValidator::Acceptable)
    {
        if(sender == ui->txtRed)
        {
            ui->slRed->blockSignals(true);
            ui->slRed->setValue(str.toInt());
            ui->slRed->blockSignals(false);
            colPrev->qColor.setRed(str.toInt() * 8);
        }
        else if(sender == ui->txtGreen)
        {
            ui->slGreen->blockSignals(true);
            ui->slGreen->setValue(str.toInt());
            ui->slGreen->blockSignals(false);
            colPrev->qColor.setGreen(str.toInt() * 8);
        }
        else if(sender == ui->txtBlue)
        {
            ui->slBlue->blockSignals(true);
            ui->slBlue->setValue(str.toInt());
            ui->slBlue->blockSignals(false);
            colPrev->qColor.setBlue(str.toInt() * 8);
        }

        colPrev->repaint();
    }
}

void SnesColorPicker::onHueTextEdited(const QString &newText)
{
    int pos = 0;
    QString str = newText;
    QValidator::State validation = hueValidator->validate(str, pos);

    if(validation == QValidator::Acceptable)
    {
        ui->slHue->blockSignals(true);
        ui->slHue->setValue(str.toInt());
        ui->slHue->blockSignals(false);

        snesColor->setHue((float)ui->slHue->value());
    }
}

void SnesColorPicker::onSatValueTextEdited(const QString &newText)
{
    int pos = 0;
    QString str = newText;
    QValidator::State validation = satValueValidator->validate(str, pos);
    QObject* sender = QObject::sender();

    if(validation == QValidator::Acceptable)
    {
        if(sender == ui->txtSat)
        {
            ui->slSat->blockSignals(true);
            ui->slSat->setValue(str.toInt());
            ui->slSat->blockSignals(false);

            snesColor->setSaturation(ui->slSat->value() / 100.0f);
        }
        else if(sender == ui->txtValue)
        {
            ui->slValue->blockSignals(true);
            ui->slValue->setValue(str.toInt());
            ui->slValue->blockSignals(false);

            snesColor->setValue(ui->slValue->value() / 100.0f);
        }
    }
}
