#include "QApplication"
#include "ChooseDlg.h"
#include "MainWnd.h"
#include <QTime>
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QTime t = QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    ChooseDlg dlg;
    dlg.setWindowTitle(QStringLiteral("YES I DO"));
    dlg.setMinimumSize(300,100);//设置登录窗口的初始化大小，最小情况
    if(dlg.exec() != QDialog::Accepted)
        return 0;

    MainWnd wnd(dlg._selected);
    wnd.setWindowTitle(QStringLiteral("恭喜发财"));//设置主程序的窗口标题
    wnd.show();




    return app.exec();
}
