#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QNetworkReply>
#include <QCloseEvent>
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
  void on_actionExitTriggered();
  void on_buttonGetClicked();
  void on_buttonPostClicked();
  void onfinish(QNetworkReply* rep);

 private:
  Ui::MainWindow* ui;
  void showEvent(QShowEvent* e);
  void closeEvent(QCloseEvent *e);
};

#endif  // MAINWINDOW_H
