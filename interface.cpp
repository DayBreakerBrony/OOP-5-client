#include <sstream>
#include "interface.h"
#include "ui_interface.h"
using namespace std;
QString cof_a, n_counts, str, counter, point_x, cof_a2, n, nom, root;
stringstream req_ss, res_ss; //request and response stringstream

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, 1985);
    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    ui->setupUi(this);
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->line_counter->setVisible(false);
    ui->line_root->setVisible(false);
    ui->line_cof_a->setVisible(false);
    ui->line_index_root->setVisible(false);
    ui->line_value->setVisible(false);
    ui->line_x->setVisible(false);
    ui->line_size->setVisible(false);
    ui->line_cof_a_2->setVisible(false);
    ui->lineEdit->setReadOnly(true);
    ui->text->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotReadyRead()
{
    QHostAddress sender;
    quint16 senderPort;
    QString response; // recieved request stringstream
    qDebug() << "reading";
    while (socket->hasPendingDatagrams()){
        QByteArray datagram;
        datagram.resize(socket->pendingDatagramSize());
        socket->readDatagram(datagram.data(),datagram.size(),&sender,&senderPort);
        response = QString(datagram);
    }
    ui->lineEdit->setText(response);
}

void MainWindow::on_polynom_n_clicked()
{
    ui->label_3->setVisible(true);
    ui->label_4->setVisible(true);
    ui->label_5->setVisible(true);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->line_counter->setVisible(true);
    ui->line_root->setVisible(true);
    ui->line_cof_a->setVisible(true);
    ui->line_index_root->setVisible(false);
    ui->line_value->setVisible(false);
    ui->line_x->setVisible(false);
    ui->line_size->setVisible(false);
    ui->line_cof_a_2->setVisible(false);
    ui->lineEdit->clear();
    ui->text->clear();
}


void MainWindow::on_resize_cof_clicked()
{
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->line_counter->setVisible(false);
    ui->line_root->setVisible(false);
    ui->line_cof_a->setVisible(false);
    ui->line_index_root->setVisible(false);
    ui->line_value->setVisible(false);
    ui->line_x->setVisible(false);
    ui->line_size->setVisible(true);
    ui->line_cof_a_2->setVisible(false);
    ui->lineEdit->clear();
    ui->text->clear();
}


void MainWindow::on_polynom_x_clicked()
{
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->line_counter->setVisible(false);
    ui->line_root->setVisible(false);
    ui->line_cof_a->setVisible(false);
    ui->line_index_root->setVisible(false);
    ui->line_value->setVisible(false);
    ui->line_x->setVisible(true);
    ui->line_size->setVisible(false);
    ui->line_cof_a_2->setVisible(false);
    ui->lineEdit->clear();
    ui->text->clear();
}


void MainWindow::on_change_cof_a_clicked()
{
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->line_counter->setVisible(false);
    ui->line_root->setVisible(false);
    ui->line_cof_a->setVisible(false);
    ui->line_index_root->setVisible(false);
    ui->line_value->setVisible(false);
    ui->line_x->setVisible(false);
    ui->line_size->setVisible(false);
    ui->line_cof_a_2->setVisible(true);
    ui->lineEdit->clear();
    ui->text->clear();
}


void MainWindow::on_change_roots_clicked()
{
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(true);
    ui->label_7->setVisible(true);
    ui->line_counter->setVisible(false);
    ui->line_root->setVisible(false);
    ui->line_cof_a->setVisible(false);
    ui->line_index_root->setVisible(true);
    ui->line_value->setVisible(true);
    ui->line_x->setVisible(false);
    ui->line_size->setVisible(false);
    ui->line_cof_a_2->setVisible(false);
    ui->lineEdit->clear();
    ui->text->clear();
}


void MainWindow::on_polynom_1_clicked()
{
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->line_counter->setVisible(false);
    ui->line_root->setVisible(false);
    ui->line_cof_a->setVisible(false);
    ui->line_index_root->setVisible(false);
    ui->line_value->setVisible(false);
    ui->line_x->setVisible(false);
    ui->line_size->setVisible(false);
    ui->line_cof_a_2->setVisible(false);
}


void MainWindow::on_polynom_2_clicked()
{
    ui->label_3->setVisible(false);
    ui->label_4->setVisible(false);
    ui->label_5->setVisible(false);
    ui->label_6->setVisible(false);
    ui->label_7->setVisible(false);
    ui->line_counter->setVisible(false);
    ui->line_root->setVisible(false);
    ui->line_cof_a->setVisible(false);
    ui->line_index_root->setVisible(false);
    ui->line_value->setVisible(false);
    ui->line_x->setVisible(false);
    ui->line_size->setVisible(false);
    ui->line_cof_a_2->setVisible(false);
}


void MainWindow::on_pushButton_clicked()
{
    req_ss.str(std::string());
    if (ui->polynom_n->isChecked()) {
        req_ss << "1 ";
        counter = ui->line_counter->text();
        if(counter.toStdString()=="0"){
            req_ss << counter.QString::toStdString();
        }
        else {
            req_ss << counter.QString::toStdString() << " ";
            cof_a = ui->line_cof_a->text();
            req_ss<<cof_a.toStdString()<< " ";
            n_counts = ui->line_root->text();
            req_ss<<n_counts.toStdString();
        }
    }
    if (ui->polynom_x->isChecked()) {
        req_ss << "3 ";
        point_x = ui->line_x->text();
        req_ss<< point_x.toStdString();
    }
    if (ui->change_cof_a->isChecked()) {
        req_ss << "4 ";
        cof_a2=ui->line_cof_a_2->text();
        req_ss<<cof_a2.toStdString();
    }
    if (ui->resize_cof->isChecked()) {
        req_ss << "2 ";
        n=ui->line_size->text();
        req_ss<<n.toStdString();
    }
    if (ui->change_roots->isChecked()) {
        req_ss << "5 ";
        nom=ui->line_index_root->text();
        root=ui->line_value->text();
        req_ss<<nom.toStdString() << " " << root.toStdString();
    }
    if (ui->polynom_1->isChecked()) {
        req_ss << "6";
    }
    if (ui->polynom_2->isChecked()) {
        req_ss << "7";
    }

    sendToServer(QString::fromStdString(req_ss.str()));


}

void MainWindow::sendToServer(QString str)
{
    qDebug() << str;
    socket->writeDatagram(str.toUtf8(), QHostAddress::LocalHost,1984);
}
