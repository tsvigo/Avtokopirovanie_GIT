// Копирование репозитория git c компьютера в Интернет
#include "dialog.h"
#include "ui_dialog.h"

/// \brief Dialog::Dialog
/// \param parent
///
////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include "QFileDialog"
#include <QtWidgets>

#include "dialog.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{

    ui->setupUi(this);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//            QFileDialog dialog(this);
//            dialog.setFileMode(QFileDialog::Directory);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          QFileDialog::Options options;
                  //= QFlag(fileDialogOptionsWidget->value());
            options |= QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
            QString directory = QFileDialog::getExistingDirectory(this,
                                        tr("QFileDialog::getExistingDirectory()"),
                                      //  directoryLabel->text()
                                                   "/home/viktor/test_git"               ,
                                        options
                                                             //     ""
                                                                  );
            if (!directory.isEmpty())
                ui->label->setText(directory);

          QString  comanda_vsia="cd \""+directory +
 "\" && git init && git add --all && git commit -m \"Описание коммита 2\" && hub create && hub push origin";
            system (comanda_vsia.toStdString().c_str() );

// отлично. Теперь можно сделать обход по всем папкам вложенным в папку
            // как бы обходит все вложенные папки и отправляет изменения в репозитории в Интернете

           // {;;}
/////
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::AnyFile);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

