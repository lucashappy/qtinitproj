#include "master-controller.h"

namespace qtinitproj {
namespace controllers {

class MasterController::Implementation
{
public:
    Implementation(MasterController* _masterController) : masterController(_masterController)
    {
        navigationController = new NavigationController(masterController);
        commandController = new CommandController(masterController, navigationController);
    }

    MasterController* masterController{nullptr};
    NavigationController* navigationController{nullptr};
    CommandController* commandController{nullptr};
    QString welcomeMessage = "Hello World!";
};


MasterController::MasterController(QObject *parent) : QObject(parent)
{
    implementation.reset(new Implementation(this));
}

MasterController::~MasterController() {}

NavigationController* MasterController::navigationController()
{
    return implementation->navigationController;
}

const QString& MasterController::welcomeMessage() const
{
    return implementation->welcomeMessage;
}

CommandController *MasterController::commandController()
{
    return implementation->commandController;
}

}}
