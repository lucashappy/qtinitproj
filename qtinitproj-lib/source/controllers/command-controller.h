#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>
#include <QtQml/QQmlListProperty>

#include <qtinitproj-lib_global.h>
#include <framework/command.h>
#include <controllers/navigation-controller.h>

namespace qtinitproj {
namespace controllers {

class QTINITPROJLIB_EXPORT CommandController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<qtinitproj::framework::Command> ui_dashboardViewContextCommands READ ui_dashboardViewContextCommands CONSTANT)


public:
    explicit CommandController(QObject* _parent = nullptr, controllers::NavigationController* navigationController = nullptr);
    ~CommandController();

    QQmlListProperty<framework::Command> ui_dashboardViewContextCommands();


public slots:
    void onDashboardSaveExecuted();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}

#endif
