#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->comboBox->addItem("ipv4");
    ui->comboBox->addItem("ipv6");
    ui->comboBox_2->addItem(tr("随机"));

    ui->comboBox_2->addItem(tr("3选1"));
    ui->comboBox_2->addItem(tr("BP"));

    ui->comboBox_3->addItem(tr("6人局"));
    ui->comboBox_3->addItem(tr("4人局"));
    ui->lineEdit->setText("50000");

   connect(ui->buttonBox->button(QDialogButtonBox::Ok),SIGNAL(clicked()), this, SLOT(onOK()));

}

void Dialog::onOK()
{
    int playerNum;
    if(ui->comboBox_3->currentIndex()==0)
        playerNum=6;
    else
        playerNum=4;
    server=new Server(0,ui->comboBox->currentIndex(),ui->lineEdit->text().toInt(),ui->comboBox_2->currentIndex(),playerNum);
}

Dialog::~Dialog()
{
    delete ui;
}
