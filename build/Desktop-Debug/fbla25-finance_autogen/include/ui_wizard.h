/********************************************************************************
** Form generated from reading UI file 'wizard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARD_H
#define UI_WIZARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWizard>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_Wizard
{
public:
    QWizardPage *wizardPage1;
    QGridLayout *gridLayout;
    QLabel *label;
    QWizardPage *wizardPage2;

    void setupUi(QWizard *Wizard)
    {
        if (Wizard->objectName().isEmpty())
            Wizard->setObjectName("Wizard");
        Wizard->resize(583, 456);
        wizardPage1 = new QWizardPage();
        wizardPage1->setObjectName("wizardPage1");
        gridLayout = new QGridLayout(wizardPage1);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(wizardPage1);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Terminus")});
        font.setPointSize(10);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        Wizard->addPage(wizardPage1);
        wizardPage2 = new QWizardPage();
        wizardPage2->setObjectName("wizardPage2");
        Wizard->addPage(wizardPage2);

        retranslateUi(Wizard);

        QMetaObject::connectSlotsByName(Wizard);
    } // setupUi

    void retranslateUi(QWizard *Wizard)
    {
        Wizard->setWindowTitle(QCoreApplication::translate("Wizard", "Wizard", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Wizard: public Ui_Wizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIZARD_H
