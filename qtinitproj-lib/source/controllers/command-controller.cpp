#include "command-controller.h"

#include <QList>
#include <QDebug>

using namespace qtinitproj::framework;

namespace qtinitproj {
namespace controllers {

class CommandController::Implementation
{
public:
    Implementation(CommandController* _commandController, NavigationController* _navigationController)
        : commandController(_commandController)
        , navigationController(_navigationController)
    {
        Command* dashboardSaveCommand = new Command(commandController, QChar( 0xf0c7 ), "Save");
        QObject::connect(dashboardSaveCommand, &Command::executed, commandController, &CommandController::onDashboardSaveExecuted );
        dashboardViewContextCommands.append(dashboardSaveCommand);
    }

    CommandController* commandController{nullptr};
    NavigationController* navigationController{nullptr};
    QList<Command*> dashboardViewContextCommands{};
};

CommandController::CommandController(QObject* parent, NavigationController* navigationController)
    : QObject(parent)
{
    implementation.reset(new Implementation(this, navigationController));
}

CommandController::~CommandController()
{
}

QQmlListProperty<Command> CommandController::ui_dashboardViewContextCommands()
{
    return QQmlListProperty<Command>(this, implementation->dashboardViewContextCommands);
}

void CommandController::onDashboardSaveExecuted()
{
    qDebug() << "You executed the dashboard Save command!";
}


}}
