#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H

#include <QObject>

#include <qtinitproj-lib_global.h>

namespace qtinitproj {
namespace controllers {

/**
 * @brief The NavigationController class defines
 * all routing available to the UI
 */
class QTINITPROJLIB_EXPORT NavigationController : public QObject
{
    Q_OBJECT

public:
    explicit NavigationController(QObject* parent = nullptr) : QObject(parent){}

signals:
    void goDashboardView();
    void pop();

};

}
}

#endif
