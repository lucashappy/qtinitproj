#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <controllers/master-controller.h>
#include <controllers/navigation-controller.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<qtinitproj::controllers::MasterController>("QTINITPROJ", 1, 0, "MasterController");
    qmlRegisterType<qtinitproj::controllers::NavigationController>("QTINITPROJ", 1, 0, "NavigationController");

    qtinitproj::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.rootContext()->setContextProperty("masterController", &masterController);
    const QUrl url(QStringLiteral("qrc:/views/MasterView.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
