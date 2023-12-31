#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
    connect(ui->pushButtonGET, &QPushButton::clicked,
        this, &MainWindow::on_buttonGetClicked);
    connect(ui->pushButtonPOST, &QPushButton::clicked,
        this, &MainWindow::on_buttonPostClicked);
    connect(ui->actionExit, &QAction::triggered,
        this, &MainWindow::on_actionExitTriggered);
}

void MainWindow::showEvent(QShowEvent* e) {
  QMainWindow::showEvent(e);
  static bool firstStart = true;
  if (firstStart) {
    ui->statusBar->showMessage(QString("qt version: ") + qVersion());
  }
}

void MainWindow::closeEvent(QCloseEvent *e){
    e->accept();
}

void MainWindow::on_buttonGetClicked() {
  QNetworkAccessManager* mgr = new QNetworkAccessManager(this);
  connect(mgr, SIGNAL(finished(QNetworkReply*)), this,
          SLOT(onfinish(QNetworkReply*)));
  connect(mgr, SIGNAL(finished(QNetworkReply*)), mgr, SLOT(deleteLater()));

  QUrl serviceUrl = QUrl(ui->editUrlGet->text());
  if (ui->editPort->text() != "-1") {
    bool ok;
    int p = ui->editPort->text().toInt(&ok);
    if (!ok) {
      QMessageBox::warning(this, QString(appName.c_str()),
                           "incorrect port value", QMessageBox::Close);
      return;
    } else {
      serviceUrl.setPort(p);
    }
  }

  mgr->get(QNetworkRequest(serviceUrl));
}

void MainWindow::on_buttonPostClicked() {
  QUrl serviceUrl = QUrl(ui->editUrlPost->text());
  if (ui->editPort->text() != "-1") {
    bool ok;
    int p = ui->editPort->text().toInt(&ok);
    if (!ok) {
      QMessageBox::warning(this, QString(appName.c_str()),
                           "incorrect port value", QMessageBox::Close);
      return;
    } else {
      serviceUrl.setPort(p);
    }
  }

  QUrlQuery query;
  query.addQueryItem("param1", "string1");
  query.addQueryItem("param2", "string2");

  QByteArray postData = query.toString(QUrl::FullyEncoded).toUtf8();

  QNetworkAccessManager* networkManager = new QNetworkAccessManager(this);
  connect(networkManager, SIGNAL(finished(QNetworkReply*)),
          SLOT(onfinish(QNetworkReply*)));

  QNetworkRequest networkRequest(serviceUrl);
  networkRequest.setHeader(QNetworkRequest::ContentTypeHeader,
                           "application/x-www-form-urlencoded");

  networkManager->post(networkRequest, postData);
}

void MainWindow::onfinish(QNetworkReply* rep) {
  QByteArray bts = rep->readAll();
  QString str(bts);
  qDebug() << str;
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_actionExitTriggered() {
  this->close();
}
