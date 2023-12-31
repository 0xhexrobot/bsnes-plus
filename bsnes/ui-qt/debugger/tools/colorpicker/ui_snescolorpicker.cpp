/********************************************************************************
** Form generated from reading UI file 'snescolorpicker.ui'
**
** Created by: Qt User Interface Compiler version 5.15.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNESCOLORPICKER_H
#define UI_SNESCOLORPICKER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "colorpreview.moc.hpp"

QT_BEGIN_NAMESPACE

class Ui_SnesColorPicker
{
public:
    QVBoxLayout *vLayMain;
    QHBoxLayout *hLayTabsPreview;
    QTabWidget *tabWidget;
    QWidget *tabRGB;
    QVBoxLayout *vLayRgb;
    QHBoxLayout *hLayRed;
    QLabel *lblRed;
    QSlider *slRed;
    QLineEdit *txtRed;
    QHBoxLayout *hLayGreen;
    QLabel *lblGreen;
    QSlider *slGreen;
    QLineEdit *txtGreen;
    QHBoxLayout *hLayBlue;
    QLabel *lblBlue;
    QSlider *slBlue;
    QLineEdit *txtBlue;
    QWidget *tabHsv;
    QVBoxLayout *vLayHsv;
    QHBoxLayout *hLayHue;
    QLabel *lblHue;
    QSlider *slHue;
    QLineEdit *txtHue;
    QHBoxLayout *hLaySat;
    QLabel *lblSat;
    QSlider *slSat;
    QLineEdit *txtSat;
    QHBoxLayout *hLayValue;
    QLabel *lblValue;
    QSlider *slValue;
    QLineEdit *txtValue;
    ColorPreview *wColorPrev;
    QHBoxLayout *hLayButtonBox;
    QSpacerItem *horizontalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SnesColorPicker)
    {
        if (SnesColorPicker->objectName().isEmpty())
            SnesColorPicker->setObjectName(QString::fromUtf8("SnesColorPicker"));
        SnesColorPicker->setWindowModality(Qt::ApplicationModal);
        SnesColorPicker->setEnabled(true);
        SnesColorPicker->resize(400, 205);
        SnesColorPicker->setMinimumSize(QSize(400, 205));
        SnesColorPicker->setMaximumSize(QSize(400, 205));
        SnesColorPicker->setModal(true);
        vLayMain = new QVBoxLayout(SnesColorPicker);
        vLayMain->setSpacing(10);
        vLayMain->setObjectName(QString::fromUtf8("vLayMain"));
        hLayTabsPreview = new QHBoxLayout();
        hLayTabsPreview->setSpacing(10);
        hLayTabsPreview->setObjectName(QString::fromUtf8("hLayTabsPreview"));
        tabWidget = new QTabWidget(SnesColorPicker);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabRGB = new QWidget();
        tabRGB->setObjectName(QString::fromUtf8("tabRGB"));
        vLayRgb = new QVBoxLayout(tabRGB);
        vLayRgb->setObjectName(QString::fromUtf8("vLayRgb"));
        hLayRed = new QHBoxLayout();
        hLayRed->setObjectName(QString::fromUtf8("hLayRed"));
        lblRed = new QLabel(tabRGB);
        lblRed->setObjectName(QString::fromUtf8("lblRed"));

        hLayRed->addWidget(lblRed);

        slRed = new QSlider(tabRGB);
        slRed->setObjectName(QString::fromUtf8("slRed"));
        slRed->setMaximum(31);
        slRed->setOrientation(Qt::Horizontal);

        hLayRed->addWidget(slRed);

        txtRed = new QLineEdit(tabRGB);
        txtRed->setObjectName(QString::fromUtf8("txtRed"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(txtRed->sizePolicy().hasHeightForWidth());
        txtRed->setSizePolicy(sizePolicy);
        txtRed->setMaximumSize(QSize(42, 16777215));
        txtRed->setBaseSize(QSize(0, 0));
        txtRed->setMaxLength(2);
        txtRed->setFrame(true);

        hLayRed->addWidget(txtRed);

        hLayRed->setStretch(1, 8);

        vLayRgb->addLayout(hLayRed);

        hLayGreen = new QHBoxLayout();
        hLayGreen->setObjectName(QString::fromUtf8("hLayGreen"));
        lblGreen = new QLabel(tabRGB);
        lblGreen->setObjectName(QString::fromUtf8("lblGreen"));

        hLayGreen->addWidget(lblGreen);

        slGreen = new QSlider(tabRGB);
        slGreen->setObjectName(QString::fromUtf8("slGreen"));
        slGreen->setMaximum(31);
        slGreen->setOrientation(Qt::Horizontal);

        hLayGreen->addWidget(slGreen);

        txtGreen = new QLineEdit(tabRGB);
        txtGreen->setObjectName(QString::fromUtf8("txtGreen"));
        sizePolicy.setHeightForWidth(txtGreen->sizePolicy().hasHeightForWidth());
        txtGreen->setSizePolicy(sizePolicy);
        txtGreen->setMaximumSize(QSize(42, 16777215));
        txtGreen->setMaxLength(2);

        hLayGreen->addWidget(txtGreen);

        hLayGreen->setStretch(1, 8);

        vLayRgb->addLayout(hLayGreen);

        hLayBlue = new QHBoxLayout();
        hLayBlue->setObjectName(QString::fromUtf8("hLayBlue"));
        lblBlue = new QLabel(tabRGB);
        lblBlue->setObjectName(QString::fromUtf8("lblBlue"));

        hLayBlue->addWidget(lblBlue);

        slBlue = new QSlider(tabRGB);
        slBlue->setObjectName(QString::fromUtf8("slBlue"));
        slBlue->setMaximum(31);
        slBlue->setOrientation(Qt::Horizontal);

        hLayBlue->addWidget(slBlue);

        txtBlue = new QLineEdit(tabRGB);
        txtBlue->setObjectName(QString::fromUtf8("txtBlue"));
        sizePolicy.setHeightForWidth(txtBlue->sizePolicy().hasHeightForWidth());
        txtBlue->setSizePolicy(sizePolicy);
        txtBlue->setMinimumSize(QSize(0, 0));
        txtBlue->setMaximumSize(QSize(42, 16777215));
        txtBlue->setMaxLength(2);

        hLayBlue->addWidget(txtBlue);

        hLayBlue->setStretch(1, 8);

        vLayRgb->addLayout(hLayBlue);

        tabWidget->addTab(tabRGB, QString());
        tabHsv = new QWidget();
        tabHsv->setObjectName(QString::fromUtf8("tabHsv"));
        vLayHsv = new QVBoxLayout(tabHsv);
        vLayHsv->setObjectName(QString::fromUtf8("vLayHsv"));
        hLayHue = new QHBoxLayout();
        hLayHue->setObjectName(QString::fromUtf8("hLayHue"));
        lblHue = new QLabel(tabHsv);
        lblHue->setObjectName(QString::fromUtf8("lblHue"));

        hLayHue->addWidget(lblHue);

        slHue = new QSlider(tabHsv);
        slHue->setObjectName(QString::fromUtf8("slHue"));
        slHue->setMaximum(360);
        slHue->setPageStep(20);
        slHue->setOrientation(Qt::Horizontal);

        hLayHue->addWidget(slHue);

        txtHue = new QLineEdit(tabHsv);
        txtHue->setObjectName(QString::fromUtf8("txtHue"));
        txtHue->setMaximumSize(QSize(42, 16777215));
        txtHue->setMaxLength(3);

        hLayHue->addWidget(txtHue);

        hLayHue->setStretch(1, 8);

        vLayHsv->addLayout(hLayHue);

        hLaySat = new QHBoxLayout();
        hLaySat->setObjectName(QString::fromUtf8("hLaySat"));
        lblSat = new QLabel(tabHsv);
        lblSat->setObjectName(QString::fromUtf8("lblSat"));

        hLaySat->addWidget(lblSat);

        slSat = new QSlider(tabHsv);
        slSat->setObjectName(QString::fromUtf8("slSat"));
        slSat->setMinimum(0);
        slSat->setMaximum(100);
        slSat->setSingleStep(1);
        slSat->setOrientation(Qt::Horizontal);

        hLaySat->addWidget(slSat);

        txtSat = new QLineEdit(tabHsv);
        txtSat->setObjectName(QString::fromUtf8("txtSat"));
        txtSat->setMaximumSize(QSize(42, 16777215));
        txtSat->setMaxLength(3);

        hLaySat->addWidget(txtSat);

        hLaySat->setStretch(1, 8);

        vLayHsv->addLayout(hLaySat);

        hLayValue = new QHBoxLayout();
        hLayValue->setObjectName(QString::fromUtf8("hLayValue"));
        lblValue = new QLabel(tabHsv);
        lblValue->setObjectName(QString::fromUtf8("lblValue"));

        hLayValue->addWidget(lblValue);

        slValue = new QSlider(tabHsv);
        slValue->setObjectName(QString::fromUtf8("slValue"));
        slValue->setMaximum(100);
        slValue->setOrientation(Qt::Horizontal);

        hLayValue->addWidget(slValue);

        txtValue = new QLineEdit(tabHsv);
        txtValue->setObjectName(QString::fromUtf8("txtValue"));
        txtValue->setMaximumSize(QSize(42, 16777215));
        txtValue->setMaxLength(3);

        hLayValue->addWidget(txtValue);

        hLayValue->setStretch(1, 8);

        vLayHsv->addLayout(hLayValue);

        tabWidget->addTab(tabHsv, QString());

        hLayTabsPreview->addWidget(tabWidget);

        wColorPrev = new ColorPreview(SnesColorPicker);
        wColorPrev->setObjectName(QString::fromUtf8("wColorPrev"));
        sizePolicy.setHeightForWidth(wColorPrev->sizePolicy().hasHeightForWidth());
        wColorPrev->setSizePolicy(sizePolicy);
        wColorPrev->setMinimumSize(QSize(100, 100));

        hLayTabsPreview->addWidget(wColorPrev);


        vLayMain->addLayout(hLayTabsPreview);

        hLayButtonBox = new QHBoxLayout();
        hLayButtonBox->setSpacing(8);
        hLayButtonBox->setObjectName(QString::fromUtf8("hLayButtonBox"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayButtonBox->addItem(horizontalSpacer);

        buttonBox = new QDialogButtonBox(SnesColorPicker);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        hLayButtonBox->addWidget(buttonBox);


        vLayMain->addLayout(hLayButtonBox);


        retranslateUi(SnesColorPicker);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SnesColorPicker);
    } // setupUi

    void retranslateUi(QDialog *SnesColorPicker)
    {
        SnesColorPicker->setWindowTitle(QCoreApplication::translate("SnesColorPicker", "Change color...", nullptr));
        lblRed->setText(QCoreApplication::translate("SnesColorPicker", "R", nullptr));
        txtRed->setInputMask(QString());
        lblGreen->setText(QCoreApplication::translate("SnesColorPicker", "G", nullptr));
        lblBlue->setText(QCoreApplication::translate("SnesColorPicker", "B", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRGB), QCoreApplication::translate("SnesColorPicker", "RGB", nullptr));
        lblHue->setText(QCoreApplication::translate("SnesColorPicker", "H", nullptr));
        lblSat->setText(QCoreApplication::translate("SnesColorPicker", "S", nullptr));
        txtSat->setInputMask(QString());
        lblValue->setText(QCoreApplication::translate("SnesColorPicker", "V", nullptr));
        txtValue->setInputMask(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabHsv), QCoreApplication::translate("SnesColorPicker", "HSV", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnesColorPicker: public Ui_SnesColorPicker {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNESCOLORPICKER_H
