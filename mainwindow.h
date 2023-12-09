#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QNetworkReply>
#include <QUrlQuery>

extern std::string appName;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

 private slots:
  void on_actionExit_triggered();
  void on_pushButtonGET_clicked();
  void on_pushButtonPOST_clicked();
  void onfinish(QNetworkReply* rep);

 private:
  Ui::MainWindow* ui;
  void showEvent(QShowEvent* e);
};

#endif  // MAINWINDOW_H
