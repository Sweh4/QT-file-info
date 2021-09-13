#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QString filePath="C:/";

    dir =new QFileSystemModel(this);
    dir->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs);
    dir->setRootPath(filePath);
    ui->treeView->setModel(dir);

        file =new QFileSystemModel(this);
        file->setFilter(QDir::NoDotAndDotDot | QDir::Files);
        file->setRootPath(filePath);
        ui->listView->setModel(file);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_treeView_clicked(const QModelIndex &index)
{
    QString filePath = dir->fileInfo(index).absoluteFilePath();
    ui->listView->setRootIndex(file->setRootPath(filePath));
}
