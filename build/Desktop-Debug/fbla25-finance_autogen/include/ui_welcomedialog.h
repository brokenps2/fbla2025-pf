/********************************************************************************
** Form generated from reading UI file 'welcomedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEDIALOG_H
#define UI_WELCOMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_WelcomeDialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *WelcomeDialog)
    {
        if (WelcomeDialog->objectName().isEmpty())
            WelcomeDialog->setObjectName("WelcomeDialog");
        WelcomeDialog->resize(400, 152);
        gridLayout = new QGridLayout(WelcomeDialog);
        gridLayout->setObjectName("gridLayout");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 1);

        label_2 = new QLabel(WelcomeDialog);
        label_2->setObjectName("label_2");
        QFont font;
        font.setFamilies({QString::fromUtf8("Terminus")});
        font.setPointSize(16);
        font.setBold(true);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);

        label = new QLabel(WelcomeDialog);
        label->setObjectName("label");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Terminus")});
        font1.setPointSize(10);
        font1.setBold(false);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        buttonBox = new QDialogButtonBox(WelcomeDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Close);
        buttonBox->setCenterButtons(false);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 1);


        retranslateUi(WelcomeDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, WelcomeDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, WelcomeDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(WelcomeDialog);
    } // setupUi

    void retranslateUi(QDialog *WelcomeDialog)
    {
        WelcomeDialog->setWindowTitle(QCoreApplication::translate("WelcomeDialog", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("WelcomeDialog", "Simple Student Budget Program", nullptr));
        label->setText(QCoreApplication::translate("WelcomeDialog", "SSBP v1.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WelcomeDialog: public Ui_WelcomeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEDIALOG_H
